#ifndef HEXAMOTION_HPP
#define HEXAMOTION_HPP

#include <Leg.hpp>

struct coxaMovimentParameters
{
	uint8_t forward;
	uint8_t backward;
};

struct femurMovimentParameters
{
	uint8_t up;
	uint8_t down;
};

struct tibiaMovimentParameters
{
	uint8_t close;
	uint8_t open;
};

struct coxaParameters
{
	coxaMovimentParameters front;
	coxaMovimentParameters middle;
	coxaMovimentParameters back;	
};

struct motionParameters
{
	coxaParameters rightCoxa;
	coxaParameters leftCoxa;
	femurMovimentParameters femur;	
	tibiaMovimentParameters tibia;
};


class HexaMotion
{
    private:
        HexaLegs *hexa_legs;
		motionParameters p =
		{
			.rightCoxa = {
				.front = {
					.forward = 35,
					.backward = 25
				},
				.middle = {
					.forward = 55,
					.backward = 45
				},
				.back = {
					.forward = 75,
					.backward = 65
				}
			},
			.leftCoxa = {
				.front = {
					.forward = 65,
					.backward = 75
				},
				.middle = {
					.forward = 45,
					.backward = 55
				},
				.back = {
					.forward = 30,
					.backward = 40
				}
			},
			.femur = {
				.up = 25,
				.down = 50
			},
			.tibia = {
				.close = 5,
				.open = 20
			}
		};

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

        // tripode cycle 
        inline void tripodGaitCycle(uint8_t vel=20)
        {
            // legs group1 up
            hexa_legs->R1.movimentInTask(p.rightCoxa.front.forward, p.femur.up, p.tibia.close, vel);
            hexa_legs->R3.movimentInTask(p.rightCoxa.back.forward, p.femur.up, p.tibia.close, vel);
            hexa_legs->L2.movimentInTask(p.leftCoxa.middle.forward, p.femur.up, p.tibia.close, vel);
            hexa_legs->waitMotion();

            // legs group1 down
            hexa_legs->R1.movimentInTask(p.rightCoxa.front.forward, p.femur.down, p.tibia.open, vel);
            hexa_legs->R3.movimentInTask(p.rightCoxa.back.forward, p.femur.down, p.tibia.open, vel);
            hexa_legs->L2.movimentInTask(p.leftCoxa.middle.forward, p.femur.down, p.tibia.open, vel);
            hexa_legs->waitMotion();

            // legs group2 up
            hexa_legs->L1.movimentInTask(p.leftCoxa.front.forward, p.femur.up, p.tibia.close, vel);
            hexa_legs->L3.movimentInTask(p.leftCoxa.back.forward, p.femur.up, p.tibia.close, vel);
            hexa_legs->R2.movimentInTask(p.rightCoxa.middle.forward, p.femur.up, p.tibia.close, vel);
            hexa_legs->waitMotion();

            // legs group1 backward
            hexa_legs->R1.movimentInTask(p.rightCoxa.front.backward, p.femur.down, p.tibia.open, vel);
            hexa_legs->R3.movimentInTask(p.rightCoxa.back.backward, p.femur.down, p.tibia.open, vel);
            hexa_legs->L2.movimentInTask(p.leftCoxa.middle.backward, p.femur.down, p.tibia.open, vel);
            hexa_legs->waitMotion();

            // legs group2 down
            hexa_legs->L1.movimentInTask(p.leftCoxa.front.forward, p.femur.down, p.tibia.open, vel);
            hexa_legs->L3.movimentInTask(p.leftCoxa.back.forward, p.femur.down, p.tibia.open, vel);
            hexa_legs->R2.movimentInTask(p.rightCoxa.middle.forward, p.femur.down, p.tibia.open, vel);
            hexa_legs->waitMotion();

            // legs group2 backward
            hexa_legs->L1.movimentInTask(p.leftCoxa.front.backward, p.femur.down, p.tibia.open, vel);
            hexa_legs->L3.movimentInTask(p.leftCoxa.back.backward, p.femur.down, p.tibia.open, vel);
            hexa_legs->R2.movimentInTask(p.rightCoxa.middle.backward, p.femur.down, p.tibia.open, vel);
            hexa_legs->waitMotion();
        }
};

#endif