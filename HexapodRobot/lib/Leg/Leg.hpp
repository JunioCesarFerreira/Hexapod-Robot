#ifndef LEG_HPP
#define LEG_HPP

#include <ServoController.h>

class Leg
{
    private:
        ServoController *servo_control;
        uint8_t thigh_joint;
        uint8_t femur_joint;
        uint8_t tibia_joint;
        uint8_t positions[3];
        uint8_t parametersTask[4];

    private:
        // Normalized position (0 to 100)
        inline uint16_t convert(uint8_t pos)
        {
            const uint16_t range = SERVO_CONTROL_SUP-SERVO_CONTROL_INF;
            pos = (pos*range)/100;
            pos += SERVO_CONTROL_INF;
            return pos;
        }

        // Abs distance
        inline uint8_t posDistance(uint8_t v1, uint8_t v2)
        {
            return v1>v2 ? v1-v2 : v2-v1;
        }

        static void movimentTask(void* p)
        {
            Leg *leg = (Leg*)p;
            uint8_t thighJointPos = leg->parametersTask[0]; 
            uint8_t femurJointPos = leg->parametersTask[1]; 
            uint8_t tibiaJointPos = leg->parametersTask[2];
            uint8_t vel = leg->parametersTask[3];
            leg->set(thighJointPos, femurJointPos, tibiaJointPos, vel);
	        vTaskDelete(NULL);
        }

    public:
        Leg() { }
        Leg(uint8_t thighJoint, uint8_t femurJoint, uint8_t tibiaJoint, ServoController * servoControl)
        {
            thigh_joint = thighJoint;
            femur_joint = femurJoint;
            tibia_joint = tibiaJoint;
            servo_control = servoControl;
        }

        void set(uint8_t thighJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos)
        {
            positions[0] = convert(thighJointPos);
            positions[1] = convert(femurJointPos);
            positions[2] = convert(tibiaJointPos);
            
            servo_control->set(thigh_joint, positions[0]);
            servo_control->set(femur_joint, positions[1]);
            servo_control->set(tibia_joint, positions[2]);
        }

        void setBackground(uint8_t thighJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint8_t vel)
        {
            parametersTask[0]=thighJointPos;
            parametersTask[1]=femurJointPos;
            parametersTask[2]=tibiaJointPos;
            parametersTask[3]=vel;
		    xTaskCreate(
			    movimentTask, /* Task function. */
			    "movimentTask", /* String with name of task. */
			    2048, /* Stack size in bytes. */
			    this, /* Parameter passed as input of the task */
			    2, /* Priority of the task. */
			    NULL); /* Task handle. */
        }

        void set(uint8_t thighJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint8_t vel)
        {
            uint16_t values[3] = 
            {
                convert(thighJointPos), 
                convert(femurJointPos), 
                convert(tibiaJointPos)
            };
            uint8_t *joints[3] = 
            {
                &thigh_joint, 
                &femur_joint, 
                &tibia_joint
            };
            uint8_t difs[3] =
            {
                posDistance(positions[0], values[0]),
                posDistance(positions[1], values[1]),
                posDistance(positions[2], values[2])
            };

            uint8_t max = 0;
            for (uint8_t i=0; i<3; i++)
            {
                if (max<difs[i]) max = difs[i];
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
                vTaskDelay(pdMS_TO_TICKS(vel));
            }
        }
};

class Legs
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

        void setAll(uint8_t thighJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos, uint8_t vel)
        {
            for (uint8_t i=0; i<legs_number; i++)
            {
                Legs[i]->setBackground(thighJointPos, femurJointPos, tibiaJointPos, vel);
            }
        }

        void setAll(uint8_t thighJointPos, uint8_t femurJointPos, uint8_t tibiaJointPos)
        {
            for (uint8_t i=0; i<6; i++)
            {
                Legs[i]->set(thighJointPos, femurJointPos, tibiaJointPos);
            }
        }
};

#endif