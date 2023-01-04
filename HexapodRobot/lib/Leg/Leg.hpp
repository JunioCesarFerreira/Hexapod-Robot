#ifndef LEG_HPP
#define LEG_HPP

#include <ServoController.h>

// Single leg class
class Leg
{
    private:
        // Micro servos motors controller.
        ServoController *servo_control;

        // Leg joints servo indexers.
        uint8_t coxa_joint_i;
        uint8_t femur_joint_i;
        uint8_t tibia_joint_i;

        // Current positions of leg joints.
        uint8_t positions[3]; // [coxa, femur, tibia]

        // Parameters used in motion task.
        uint8_t taskParameters[4]; // [coxaPos, femurPos, tibiaPos, parameterVel]
        bool inMotion;

    private:
        // Normalized position [0 to 100].
        inline uint16_t denormalizes(uint8_t pos)
        {
            const uint16_t range = SERVO_CONTROL_SUP-SERVO_CONTROL_INF;
            pos = (pos*range)/100;
            pos += SERVO_CONTROL_INF;
            return pos;
        }

        // Absolute distance of positions.
        inline uint8_t positionDistance(uint8_t v1, uint8_t v2)
        {
            return v1>v2 ? v1-v2 : v2-v1;
        }

        // Motion task function.
        static void motionTask(void* p)
        {
            // Recovery leg object
            Leg *leg = (Leg*)p;
            // Set motion
            leg->moveWithTaskParameters();
            leg->inMotion = false;
	        vTaskDelete(NULL);
        }

        // Moves using task parameters array
        inline void moveWithTaskParameters()
        {
            // Parameters: coxaJointPos, femurJointPos, tibiaJointPos, vdelay
            moveTo(taskParameters[0], taskParameters[1], taskParameters[2], taskParameters[3]);
        }

    public:
        Leg() 
        { 
            inMotion=false;
        }
        Leg(uint8_t coxaJoint, uint8_t femurJoint, uint8_t tibiaJoint, ServoController * servoControl)
        {
            inMotion=false;
            coxa_joint_i = coxaJoint;
            femur_joint_i = femurJoint;
            tibia_joint_i = tibiaJoint;
            servo_control = servoControl;
        }

        bool isInMotion()
        {
            return inMotion;
        }

        void moveTo(uint8_t coxaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos)
        {
            positions[0] = denormalizes(coxaJointPos);
            positions[1] = denormalizes(femurJointPos);
            positions[2] = denormalizes(tibiaJointPos);
            
            servo_control->set(coxa_joint_i, positions[0]);
            servo_control->set(femur_joint_i, positions[1]);
            servo_control->set(tibia_joint_i, positions[2]);
        }

        void movimentInTask(uint8_t coxaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint8_t vdelay)
        {
            inMotion=true;
            taskParameters[0]=coxaJointPos;
            taskParameters[1]=femurJointPos;
            taskParameters[2]=tibiaJointPos;
            taskParameters[3]=vdelay;
		    xTaskCreate(
			    motionTask,   // Task function.
			    "motionTask", // String with name of task.
			    2048,         // Stack size in bytes.
			    this,         // Parameter passed as input of the task.
			    2,            // Priority of the task.
			    NULL);        // Task handle.
        }

        void moveTo(uint8_t coxaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint8_t vdelay)
        {
            uint16_t values[3] = 
            {
                denormalizes(coxaJointPos), 
                denormalizes(femurJointPos), 
                denormalizes(tibiaJointPos)
            };
            uint8_t *joints[3] = 
            {
                &coxa_joint_i, 
                &femur_joint_i, 
                &tibia_joint_i
            };
            uint8_t distances[3] =
            {
                positionDistance(positions[0], values[0]),
                positionDistance(positions[1], values[1]),
                positionDistance(positions[2], values[2])
            };

            uint8_t max = 0;
            for (uint8_t i=0; i<3; i++)
            {
                if (max<distances[i]) max = distances[i];
            }
            
            for (uint8_t t=0; t<max; t++)
            {
                for (uint8_t i=0; i<3; i++)
                {
                    if (positions[i]<values[i])
                    {
                        positions[i]++;
                    }
                    else if (positions[i]>values[i])
                    {
                        positions[i]--;
                    }
                    servo_control->set(*joints[i], positions[i]);
                }
                vTaskDelay(pdMS_TO_TICKS(vdelay));
            }
        }
};

// Hexapod legs class
class HexaLegs
{
    private:
        static const uint8_t legs_number=6;

    public:
        Leg R1;
        Leg R2;
        Leg R3;
        Leg L1;
        Leg L2;
        Leg L3;
        Leg *Legs[legs_number] ={ &R1, &R2, &R3, &L1, &L2, &L3 };

        void moveAll(uint8_t coxaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint8_t vdelay)
        {
            for (uint8_t i=0; i<legs_number; i++)
            {
                Legs[i]->movimentInTask(coxaJointPos, femurJointPos, tibiaJointPos, vdelay);
            }
        }

        void moveAll(uint8_t coxaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos)
        {
            for (uint8_t i=0; i<6; i++)
            {
                Legs[i]->moveTo(coxaJointPos, femurJointPos, tibiaJointPos);
            }
        }

        bool isInMotion()
        {
            return R1.isInMotion() || R2.isInMotion() || R3.isInMotion()
                || L1.isInMotion() || L2.isInMotion() || L3.isInMotion();
        }

        void waitMotion()
        {
            while (isInMotion())
            {
                delay(10);
            }
        }
};

#endif