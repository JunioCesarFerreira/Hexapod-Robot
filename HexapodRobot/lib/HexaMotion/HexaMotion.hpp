#ifndef HEXAMOTION_HPP
#define HEXAMOTION_HPP

#include <Leg.hpp>

struct coxiaMovimentParameters
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

struct coxiaParameters
{
	coxiaMovimentParameters front;
	coxiaMovimentParameters middle;
	coxiaMovimentParameters back;	
};

struct motionParameters
{
	coxiaParameters rightCoxia;
	coxiaParameters leftCoxia;
	femurMovimentParameters femur;	
	tibiaMovimentParameters tibia;
};


class HexaMotion
{
    private:
        HexaLegs *hexa_legs;
		motionParameters p =
		{
			.rightCoxia = {
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
			.leftCoxia = {
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

            up.coxia = p.rightCoxia.front.forward;
            down.coxia = p.rightCoxia.front.forward;
            backward.coxia = p.rightCoxia.front.backward;
            hexa_legs->R1.argsToWalk(up, down, backward);

            up.coxia = p.rightCoxia.middle.forward;
            down.coxia = p.rightCoxia.middle.forward;
            backward.coxia = p.rightCoxia.middle.backward;
            hexa_legs->R2.argsToWalk(up, down, backward);
            
            up.coxia = p.rightCoxia.back.forward;
            down.coxia = p.rightCoxia.back.forward;
            backward.coxia = p.rightCoxia.back.backward;
            hexa_legs->R3.argsToWalk(up, down, backward);
            
            up.coxia = p.leftCoxia.front.forward;
            down.coxia = p.leftCoxia.front.forward;
            backward.coxia = p.leftCoxia.front.backward;
            hexa_legs->L1.argsToWalk(up, down, backward);

            up.coxia = p.leftCoxia.middle.forward;
            down.coxia = p.leftCoxia.middle.forward;
            backward.coxia = p.leftCoxia.middle.backward;
            hexa_legs->L2.argsToWalk(up, down, backward);
            
            up.coxia = p.leftCoxia.back.forward;
            down.coxia = p.leftCoxia.back.forward;
            backward.coxia = p.leftCoxia.back.backward;
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
            // lift legs group 1 
            hexa_legs->R1.liftLeg(vel);
            hexa_legs->R3.liftLeg(vel);
            hexa_legs->L2.liftLeg(vel);
            hexa_legs->waitMotion();

            // lower legs group 1 
            hexa_legs->R1.lowerLeg(vel);
            hexa_legs->R3.lowerLeg(vel);
            hexa_legs->L2.lowerLeg(vel);
            hexa_legs->waitMotion();

            // lift legs group 2
            hexa_legs->L1.liftLeg(vel);
            hexa_legs->L3.liftLeg(vel);
            hexa_legs->R2.liftLeg(vel);
            hexa_legs->waitMotion();

            // push ground legs group 1
            hexa_legs->R1.pushGround(vel);
            hexa_legs->R3.pushGround(vel);
            hexa_legs->L2.pushGround(vel);
            hexa_legs->waitMotion();

            // lower legs group 2
            hexa_legs->L1.lowerLeg(vel);
            hexa_legs->L3.lowerLeg(vel);
            hexa_legs->R2.lowerLeg(vel);
            hexa_legs->waitMotion();

            // push ground legs group 2
            hexa_legs->L1.pushGround(vel);
            hexa_legs->L3.pushGround(vel);
            hexa_legs->R2.pushGround(vel);
            hexa_legs->waitMotion();
        }
        
        inline void waveGaitCycle(uint8_t vel=80)
        {
            const uint8_t liftlowerVel = vel/8;
            const uint32_t pushVel = 6*vel;

            hexa_legs->R1.liftLeg(liftlowerVel);
            hexa_legs->R1.waitMotion();
            hexa_legs->R1.lowerLeg(liftlowerVel);
            hexa_legs->R1.waitMotion();
            hexa_legs->R1.pushGround(pushVel);
                        
            hexa_legs->R2.liftLeg(liftlowerVel);
            hexa_legs->R2.waitMotion();
            hexa_legs->R2.lowerLeg(liftlowerVel);
            hexa_legs->R2.waitMotion();
            hexa_legs->R2.pushGround(pushVel);
            
            hexa_legs->R3.liftLeg(liftlowerVel);
            hexa_legs->R3.waitMotion();
            hexa_legs->R3.lowerLeg(liftlowerVel);
            hexa_legs->R3.waitMotion();
            hexa_legs->R3.pushGround(pushVel);
            
            hexa_legs->L1.liftLeg(liftlowerVel);
            hexa_legs->L1.waitMotion();
            hexa_legs->L1.lowerLeg(liftlowerVel);
            hexa_legs->L1.waitMotion();
            hexa_legs->L1.pushGround(pushVel);
            
            hexa_legs->L2.liftLeg(liftlowerVel);
            hexa_legs->L2.waitMotion();
            hexa_legs->L2.lowerLeg(liftlowerVel);
            hexa_legs->L2.waitMotion();
            hexa_legs->L2.pushGround(pushVel);
            
            hexa_legs->L3.liftLeg(liftlowerVel);
            hexa_legs->L3.waitMotion();
            hexa_legs->L3.lowerLeg(liftlowerVel);
            hexa_legs->L3.waitMotion();
            hexa_legs->L3.pushGround(pushVel);
        }
        
        inline void rippleGaitCycle(uint8_t vel=80)
        {
            const uint8_t liftlowerVel = vel/8;
            hexa_legs->R1.liftLeg(liftlowerVel);
            hexa_legs->L2.liftLeg(liftlowerVel);
            hexa_legs->R1.waitMotion();
            hexa_legs->L2.waitMotion();
            hexa_legs->R1.lowerLeg(liftlowerVel);
            hexa_legs->L2.lowerLeg(liftlowerVel);
            hexa_legs->R1.waitMotion();
            hexa_legs->L2.waitMotion();
            hexa_legs->R1.pushGround(vel);
            hexa_legs->L2.pushGround(vel);

            hexa_legs->R2.liftLeg(liftlowerVel);
            hexa_legs->L3.liftLeg(liftlowerVel);
            hexa_legs->R2.waitMotion();
            hexa_legs->L3.waitMotion();
            hexa_legs->R2.lowerLeg(liftlowerVel);
            hexa_legs->L3.lowerLeg(liftlowerVel);
            hexa_legs->R2.waitMotion();
            hexa_legs->L3.waitMotion();
            hexa_legs->R2.pushGround(vel);
            hexa_legs->L3.pushGround(vel);
            
            hexa_legs->R3.liftLeg(liftlowerVel);
            hexa_legs->L1.liftLeg(liftlowerVel);
            hexa_legs->R3.waitMotion();
            hexa_legs->L1.waitMotion();
            hexa_legs->R3.lowerLeg(liftlowerVel);
            hexa_legs->L1.lowerLeg(liftlowerVel);
            hexa_legs->R3.waitMotion();
            hexa_legs->L1.waitMotion();
            hexa_legs->R3.pushGround(vel);
            hexa_legs->L1.pushGround(vel);

        }
};

#endif