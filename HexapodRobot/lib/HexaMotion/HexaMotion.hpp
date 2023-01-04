#ifndef HEXAMOTION_HPP
#define HEXAMOTION_HPP

#include <Leg.hpp>

class HexaMotion
{
    private:
        HexaLegs *hexa_legs;

    public:
        HexaMotion(HexaLegs *hexaLegs)
        {
            hexa_legs = hexaLegs;
        }

        inline void checkingTibiaJoint(uint8_t vel=40)
        {
            hexa_legs->moveAll(50,5,1,vel);
            hexa_legs->waitMotion();

            hexa_legs->moveAll(50,5,20,vel);
            hexa_legs->waitMotion();

            delay(3000);

            hexa_legs->moveAll(50,5,50,vel);
            hexa_legs->waitMotion();

            delay(3000);

            hexa_legs->moveAll(50,5,1,vel);
            hexa_legs->waitMotion();
        }
       

        inline void checkingFemurJoint(uint8_t vel=40)
        {
            hexa_legs->moveAll(50,5,1,vel);
            hexa_legs->waitMotion();

            hexa_legs->moveAll(50,50,80,vel);
            hexa_legs->waitMotion();
            
            hexa_legs->moveAll(50,70,80,vel);
            hexa_legs->waitMotion();

            delay(3000);

            hexa_legs->moveAll(50,5,1,vel);
            hexa_legs->waitMotion();
        }

        inline void standingUp(uint8_t vel=20)
        {
            hexa_legs->moveAll(50,50,25,vel);
            hexa_legs->waitMotion();
        }

        inline void retractedPosition(uint8_t vel=20)
        {
            hexa_legs->moveAll(50,5,1,vel);
            hexa_legs->waitMotion();
        }

        inline void tripodGaitCycle(uint8_t vel=20)
        {
            // ---------------------------------------------------
            // parameters used in the movements    
            // right coxa joints
            const uint8_t right_front_coxa_forward = 35;
            const uint8_t right_front_coxa_backward = 25;
            
            const uint8_t right_middle_coxa_forward = 55;
            const uint8_t right_middle_coxa_backward = 45;

            const uint8_t right_back_coxa_forward = 75;
            const uint8_t right_back_coxa_backward = 65;

            // left coxa joints
            const uint8_t left_front_coxa_forward = 65;
            const uint8_t left_front_coxa_backward = 75;
            
            const uint8_t left_middle_coxa_forward = 45;
            const uint8_t left_middle_coxa_backward = 55;

            const uint8_t left_back_coxa_forward = 30;
            const uint8_t left_back_coxa_backward = 40;        
            
            // other joints
            const uint8_t femur_up = 25;
            const uint8_t femur_down = 50;

            const uint8_t tibia_close = 5;
            const uint8_t tibia_open = 20;
            // ---------------------------------------------------

            // tripode cycle 
            hexa_legs->R1.movimentInTask(right_front_coxa_forward, femur_up,tibia_close, vel);
            hexa_legs->R3.movimentInTask(right_back_coxa_forward, femur_up, tibia_close, vel);
            hexa_legs->L2.movimentInTask(left_middle_coxa_forward, femur_up, tibia_close, vel);

            hexa_legs->waitMotion();

            hexa_legs->R1.movimentInTask(right_front_coxa_forward, femur_down, tibia_open, vel);
            hexa_legs->R3.movimentInTask(right_back_coxa_forward, femur_down, tibia_open, vel);
            hexa_legs->L2.movimentInTask(left_middle_coxa_forward, femur_down, tibia_open, vel);
            
            hexa_legs->L1.movimentInTask(left_front_coxa_forward, femur_up, tibia_close, vel);
            hexa_legs->L3.movimentInTask(left_back_coxa_forward, femur_up, tibia_close, vel);
            hexa_legs->R2.movimentInTask(right_middle_coxa_forward, femur_up, tibia_close, vel);

            hexa_legs->waitMotion();

            hexa_legs->R1.movimentInTask(right_front_coxa_backward, femur_down, tibia_open, vel);
            hexa_legs->R3.movimentInTask(right_back_coxa_backward, femur_down, tibia_open, vel);
            hexa_legs->L2.movimentInTask(left_middle_coxa_backward, femur_down, tibia_open, vel);
            
            hexa_legs->L1.movimentInTask(left_front_coxa_forward, femur_down, tibia_open, vel);
            hexa_legs->L3.movimentInTask(left_back_coxa_forward, femur_down, tibia_open, vel);
            hexa_legs->R2.movimentInTask(right_middle_coxa_forward, femur_down, tibia_open, vel);

            hexa_legs->waitMotion();
                        
            hexa_legs->L1.movimentInTask(left_front_coxa_backward, femur_down, tibia_open, vel);
            hexa_legs->L3.movimentInTask(left_back_coxa_backward, femur_down, tibia_open, vel);
            hexa_legs->R2.movimentInTask(right_middle_coxa_backward, femur_down, tibia_open, vel);
        }

};

#endif