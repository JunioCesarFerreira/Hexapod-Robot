#ifndef LEG_HPP
#define LEG_HPP

#include <ServoController.h>

struct ArgsLeg
{
    uint8_t coxia;
    uint8_t femur;
    uint8_t tibia;
};

// Single leg class
class Leg
{
    private:
        // Current positions of leg joints.
        uint8_t positions[3]; // [coxia, femur, tibia]

        // Parameters used in motion task.
        uint8_t task_p_coxia;
        uint8_t task_p_femur;
        uint8_t task_p_tibia;
        uint32_t task_p_vdelay;

    protected:
        // Micro servos motors controller.
        ServoController *servo_control;

        // Leg joints servo indexers.
        uint8_t coxia_joint_i;
        uint8_t femur_joint_i;
        uint8_t tibia_joint_i;
        
        // Parameter used in motion task.
        bool inMotion;


    private:
        static const uint16_t range = SERVO_CONTROL_SUP-SERVO_CONTROL_INF;
        // Normalized position [0 to 100].
        inline uint16_t denormalizes(uint8_t pos)
        {
            pos = (pos*range)/100;
            pos += SERVO_CONTROL_INF;
            return pos;
        }
        inline uint8_t normalizes(uint16_t pos)
        {
            pos -= SERVO_CONTROL_INF;
            pos = 100*pos/range;
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
            // Parameters: coxiaJointPos, femurJointPos, tibiaJointPos, vdelay
            moveTo(task_p_coxia, task_p_femur, task_p_tibia, task_p_vdelay);
        }

    public:
        Leg() 
        { 
            inMotion=false;
        }
        Leg(uint8_t coxiaJoint, uint8_t femurJoint, uint8_t tibiaJoint, ServoController * servoControl)
        {
            inMotion=false;
            coxia_joint_i = coxiaJoint;
            femur_joint_i = femurJoint;
            tibia_joint_i = tibiaJoint;
            servo_control = servoControl;
        }

        bool isInMotion()
        {
            return inMotion;
        }

        void waitMotion()
        {
            while (isInMotion())
            {
                delay(10);
            }
        }

        ArgsLeg argsLeg()
        {
            return ArgsLeg
            {
                .coxia = positions[0],
                .femur = positions[1],
                .tibia = positions[2]
            };
        }

        void moveTo(uint8_t coxiaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos)
        {
            positions[0] = denormalizes(coxiaJointPos);
            positions[1] = denormalizes(femurJointPos);
            positions[2] = denormalizes(tibiaJointPos);
            
            servo_control->set(coxia_joint_i, positions[0]);
            servo_control->set(femur_joint_i, positions[1]);
            servo_control->set(tibia_joint_i, positions[2]);
        }

        void movimentInTask(uint8_t coxiaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint32_t vdelay)
        {
            inMotion=true;
            task_p_coxia=coxiaJointPos;
            task_p_femur=femurJointPos;
            task_p_tibia=tibiaJointPos;
            task_p_vdelay=vdelay;
		    xTaskCreate(
			    motionTask,   // Task function.
			    "motionTask", // String with name of task.
			    2048,         // Stack size in bytes.
			    this,         // Parameter passed as input of the task.
			    2,            // Priority of the task.
			    NULL);        // Task handle.
        }

        void moveTo(uint8_t coxiaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint32_t vdelay)
        {
            uint16_t values[3] = 
            {
                denormalizes(coxiaJointPos), 
                denormalizes(femurJointPos), 
                denormalizes(tibiaJointPos)
            };
            uint8_t *joints[3] = 
            {
                &coxia_joint_i, 
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

class HikingLeg : public Leg
{
    private:
        ArgsLeg lift;
        ArgsLeg lower;
        ArgsLeg push;

    public:
        HikingLeg() 
        { 
            inMotion=false;
        }
        HikingLeg(uint8_t coxiaJoint, uint8_t femurJoint, uint8_t tibiaJoint, ServoController * servoControl)
        {
            inMotion=false;
            coxia_joint_i = coxiaJoint;
            femur_joint_i = femurJoint;
            tibia_joint_i = tibiaJoint;
            servo_control = servoControl;
        }

        // Loads movement parameters for walking.
        void argsToWalk(ArgsLeg up, ArgsLeg down, ArgsLeg backward)
        {
            lift = up;
            lower = down;
            push = backward;
        }

        // Walking cycle liftLeg, lowerLeg, pushGround.
        void liftLeg(uint32_t vel)
        {
            movimentInTask(lift.coxia, lift.femur, lift.tibia, vel);
        }

        // Walking cycle liftLeg, lowerLeg, pushGround.
        void lowerLeg(uint32_t vel)
        {
            movimentInTask(lower.coxia, lower.femur, lower.tibia, vel);
        }

        // Walking cycle liftLeg, lowerLeg, pushGround.
        void pushGround(uint32_t vel)
        {
            movimentInTask(push.coxia, push.femur, push.tibia, vel);
        }
};

// Hexapod legs class
class HexaLegs
{
    private:
        static const uint8_t legs_number=6;

    public:
        HikingLeg R1;
        HikingLeg R2;
        HikingLeg R3;
        HikingLeg L1;
        HikingLeg L2;
        HikingLeg L3;
        HikingLeg *Legs[legs_number] ={ &R1, &R2, &R3, &L1, &L2, &L3 };

        void moveAll(uint8_t coxiaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint32_t vdelay)
        {
            for (uint8_t i=0; i<legs_number; i++)
            {
                Legs[i]->movimentInTask(coxiaJointPos, femurJointPos, tibiaJointPos, vdelay);
            }
        }

        void moveAll(uint8_t coxiaJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos)
        {
            for (uint8_t i=0; i<6; i++)
            {
                Legs[i]->moveTo(coxiaJointPos, femurJointPos, tibiaJointPos);
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