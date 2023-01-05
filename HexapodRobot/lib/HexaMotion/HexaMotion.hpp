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

            ArgsLeg up, down, backward;

            up.femur = p.femur.up;
            up.tibia = p.tibia.close;

            down.femur = p.femur.down;
            down.tibia = p.tibia.open;

            backward.femur = p.femur.down;
            backward.tibia = p.tibia.open;

            up.coxa = p.rightCoxa.front.forward;
            down.coxa = p.rightCoxa.front.forward;
            backward.coxa = p.rightCoxa.front.backward;
            hexa_legs->R1.argsToWalk(up, down, backward);

            up.coxa = p.rightCoxa.middle.forward;
            down.coxa = p.rightCoxa.middle.forward;
            backward.coxa = p.rightCoxa.middle.backward;
            hexa_legs->R2.argsToWalk(up, down, backward);
            
            up.coxa = p.rightCoxa.back.forward;
            down.coxa = p.rightCoxa.back.forward;
            backward.coxa = p.rightCoxa.back.backward;
            hexa_legs->R3.argsToWalk(up, down, backward);
            
            up.coxa = p.leftCoxa.front.forward;
            down.coxa = p.leftCoxa.front.forward;
            backward.coxa = p.leftCoxa.front.backward;
            hexa_legs->L1.argsToWalk(up, down, backward);

            up.coxa = p.leftCoxa.middle.forward;
            down.coxa = p.leftCoxa.middle.forward;
            backward.coxa = p.leftCoxa.middle.backward;
            hexa_legs->L2.argsToWalk(up, down, backward);
            
            up.coxa = p.leftCoxa.back.forward;
            down.coxa = p.leftCoxa.back.forward;
            backward.coxa = p.leftCoxa.back.backward;
            hexa_legs->L3.argsToWalk(up, down, backward);
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
            hexa_legs->R1.liftLeg(vel);
            hexa_legs->R3.liftLeg(vel);
            hexa_legs->L2.liftLeg(vel);
            hexa_legs->waitMotion();

            // legs group1 down
            hexa_legs->R1.lowerLeg(vel);
            hexa_legs->R3.lowerLeg(vel);
            hexa_legs->L2.lowerLeg(vel);
            hexa_legs->waitMotion();

            // legs group2 up
            hexa_legs->L1.liftLeg(vel);
            hexa_legs->L3.liftLeg(vel);
            hexa_legs->R2.liftLeg(vel);
            hexa_legs->waitMotion();

            // legs group1 backward
            hexa_legs->R1.pushGround(vel);
            hexa_legs->R3.pushGround(vel);
            hexa_legs->L2.pushGround(vel);
            hexa_legs->waitMotion();

            // legs group2 down
            hexa_legs->L1.lowerLeg(vel);
            hexa_legs->L3.lowerLeg(vel);
            hexa_legs->R2.lowerLeg(vel);
            hexa_legs->waitMotion();

            // legs group2 backward
            hexa_legs->L1.pushGround(vel);
            hexa_legs->L3.pushGround(vel);
            hexa_legs->R2.pushGround(vel);
            hexa_legs->waitMotion();
        }
        
        inline void waveGaitCycle(uint8_t vel=20)
        {
            const uint32_t pushVel = 30*vel;

            hexa_legs->R1.liftLeg(vel);
            hexa_legs->R1.waitMotion();
            hexa_legs->R1.lowerLeg(vel);
            hexa_legs->R1.waitMotion();
            hexa_legs->R1.pushGround(pushVel);
                        
            hexa_legs->R2.liftLeg(vel);
            hexa_legs->R2.waitMotion();
            hexa_legs->R2.lowerLeg(vel);
            hexa_legs->R2.waitMotion();
            hexa_legs->R2.pushGround(pushVel);
            
            hexa_legs->R3.liftLeg(vel);
            hexa_legs->R3.waitMotion();
            hexa_legs->R3.lowerLeg(vel);
            hexa_legs->R3.waitMotion();
            hexa_legs->R3.pushGround(pushVel);
            
            hexa_legs->L1.liftLeg(vel);
            hexa_legs->L1.waitMotion();
            hexa_legs->L1.lowerLeg(vel);
            hexa_legs->L1.waitMotion();
            hexa_legs->L1.pushGround(pushVel);
            
            hexa_legs->L2.liftLeg(vel);
            hexa_legs->L2.waitMotion();
            hexa_legs->L2.lowerLeg(vel);
            hexa_legs->L2.waitMotion();
            hexa_legs->L2.pushGround(pushVel);
            
            hexa_legs->L3.liftLeg(vel);
            hexa_legs->L3.waitMotion();
            hexa_legs->L3.lowerLeg(vel);
            hexa_legs->L3.waitMotion();
            hexa_legs->L3.pushGround(pushVel);
        }
};

#endif