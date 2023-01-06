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

        // Relative (forward or backward) legs names.
        HikingLeg *rel_R1, *rel_R2, *rel_R3, *rel_L1, *rel_L2, *rel_L3;

        inline void setForward()
        {
            ArgsLeg lift, lower, push;

            lift.femur = p.femur.up;
            lift.tibia = p.tibia.close;

            lower.femur = p.femur.down;
            lower.tibia = p.tibia.open;

            push.femur = p.femur.down;
            push.tibia = p.tibia.open;

            lift.coxia = p.rightCoxia.front.forward;
            lower.coxia = p.rightCoxia.front.forward;
            push.coxia = p.rightCoxia.front.backward;
            hexa_legs->R1.argsToWalk(lift, lower, push);

            lift.coxia = p.rightCoxia.middle.forward;
            lower.coxia = p.rightCoxia.middle.forward;
            push.coxia = p.rightCoxia.middle.backward;
            hexa_legs->R2.argsToWalk(lift, lower, push);
            
            lift.coxia = p.rightCoxia.back.forward;
            lower.coxia = p.rightCoxia.back.forward;
            push.coxia = p.rightCoxia.back.backward;
            hexa_legs->R3.argsToWalk(lift, lower, push);
            
            lift.coxia = p.leftCoxia.front.forward;
            lower.coxia = p.leftCoxia.front.forward;
            push.coxia = p.leftCoxia.front.backward;
            hexa_legs->L1.argsToWalk(lift, lower, push);

            lift.coxia = p.leftCoxia.middle.forward;
            lower.coxia = p.leftCoxia.middle.forward;
            push.coxia = p.leftCoxia.middle.backward;
            hexa_legs->L2.argsToWalk(lift, lower, push);
            
            lift.coxia = p.leftCoxia.back.forward;
            lower.coxia = p.leftCoxia.back.forward;
            push.coxia = p.leftCoxia.back.backward;
            hexa_legs->L3.argsToWalk(lift, lower, push);
        }

        inline void setBackward()
        {
            ArgsLeg lift, lower, push;

            lift.femur = p.femur.up;
            lift.tibia = p.tibia.close;

            lower.femur = p.femur.down;
            lower.tibia = p.tibia.open;

            push.femur = p.femur.down;
            push.tibia = p.tibia.open;

            lift.coxia = p.rightCoxia.front.backward;
            lower.coxia = p.rightCoxia.front.backward;
            push.coxia = p.rightCoxia.front.forward;
            hexa_legs->R1.argsToWalk(lift, lower, push);

            lift.coxia = p.rightCoxia.middle.backward;
            lower.coxia = p.rightCoxia.middle.backward;
            push.coxia = p.rightCoxia.middle.forward;
            hexa_legs->R2.argsToWalk(lift, lower, push);
            
            lift.coxia = p.rightCoxia.back.backward;
            lower.coxia = p.rightCoxia.back.backward;
            push.coxia = p.rightCoxia.back.forward;
            hexa_legs->R3.argsToWalk(lift, lower, push);
            
            lift.coxia = p.leftCoxia.front.backward;
            lower.coxia = p.leftCoxia.front.backward;
            push.coxia = p.leftCoxia.front.forward;
            hexa_legs->L1.argsToWalk(lift, lower, push);

            lift.coxia = p.leftCoxia.middle.backward;
            lower.coxia = p.leftCoxia.middle.backward;
            push.coxia = p.leftCoxia.middle.forward;
            hexa_legs->L2.argsToWalk(lift, lower, push);
            
            lift.coxia = p.leftCoxia.back.backward;
            lower.coxia = p.leftCoxia.back.backward;
            push.coxia = p.leftCoxia.back.forward;
            hexa_legs->L3.argsToWalk(lift, lower, push);
        }

        inline void set(bool forward)
        {
            if (forward)
            {
                setForward();
                rel_R1 = &hexa_legs->R1;
                rel_R2 = &hexa_legs->R2;
                rel_R3 = &hexa_legs->R3;
                rel_L1 = &hexa_legs->L1;
                rel_L2 = &hexa_legs->L2;
                rel_L3 = &hexa_legs->L3;
            }
            else
            {
                setBackward();
                rel_R1 = &hexa_legs->L3;
                rel_R2 = &hexa_legs->L2;
                rel_R3 = &hexa_legs->L1;
                rel_L1 = &hexa_legs->R3;
                rel_L2 = &hexa_legs->R2;
                rel_L3 = &hexa_legs->R1;
            }
        }

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
        inline void tripodGaitCycle(uint8_t vel, bool forward)
        {
            set(forward);

            // lift legs group 1 
            rel_R1->liftLeg(vel);
            rel_R3->liftLeg(vel);
            rel_L2->liftLeg(vel);
            hexa_legs->waitMotion();

            // lower legs group 1 
            rel_R1->lowerLeg(vel);
            rel_R3->lowerLeg(vel);
            rel_L2->lowerLeg(vel);
            hexa_legs->waitMotion();

            // lift legs group 2
            rel_L1->liftLeg(vel);
            rel_L3->liftLeg(vel);
            rel_R2->liftLeg(vel);
            hexa_legs->waitMotion();

            // push ground legs group 1
            rel_R1->pushGround(vel);
            rel_R3->pushGround(vel);
            rel_L2->pushGround(vel);
            hexa_legs->waitMotion();

            // lower legs group 2
            rel_L1->lowerLeg(vel);
            rel_L3->lowerLeg(vel);
            rel_R2->lowerLeg(vel);
            hexa_legs->waitMotion();

            // push ground legs group 2
            rel_L1->pushGround(vel);
            rel_L3->pushGround(vel);
            rel_R2->pushGround(vel);
            hexa_legs->waitMotion();
        }
        
        inline void waveGaitCycle(uint8_t vel, bool forward)
        {
            set(forward);

            const uint8_t liftlowerVel = vel/8;
            const uint32_t pushVel = 6*vel;

            rel_R1->liftLeg(liftlowerVel);
            rel_R1->waitMotion();
            rel_R1->lowerLeg(liftlowerVel);
            rel_R1->waitMotion();
            rel_R1->pushGround(pushVel);
                        
            rel_R2->liftLeg(liftlowerVel);
            rel_R2->waitMotion();
            rel_R2->lowerLeg(liftlowerVel);
            rel_R2->waitMotion();
            rel_R2->pushGround(pushVel);
            
            rel_R3->liftLeg(liftlowerVel);
            rel_R3->waitMotion();
            rel_R3->lowerLeg(liftlowerVel);
            rel_R3->waitMotion();
            rel_R3->pushGround(pushVel);
            
            rel_L1->liftLeg(liftlowerVel);
            rel_L1->waitMotion();
            rel_L1->lowerLeg(liftlowerVel);
            rel_L1->waitMotion();
            rel_L1->pushGround(pushVel);
            
            rel_L2->liftLeg(liftlowerVel);
            rel_L2->waitMotion();
            rel_L2->lowerLeg(liftlowerVel);
            rel_L2->waitMotion();
            rel_L2->pushGround(pushVel);
            
            rel_L3->liftLeg(liftlowerVel);
            rel_L3->waitMotion();
            rel_L3->lowerLeg(liftlowerVel);
            rel_L3->waitMotion();
            rel_L3->pushGround(pushVel);
        }
        
        inline void rippleGaitCycle(uint8_t vel, bool forward)
        {
            set(forward);

            const uint8_t liftlowerVel = vel/8;
            rel_R1->liftLeg(liftlowerVel);
            rel_L2->liftLeg(liftlowerVel);
            rel_R1->waitMotion();
            rel_L2->waitMotion();
            rel_R1->lowerLeg(liftlowerVel);
            rel_L2->lowerLeg(liftlowerVel);
            rel_R1->waitMotion();
            rel_L2->waitMotion();
            rel_R1->pushGround(vel);
            rel_L2->pushGround(vel);

            rel_R2->liftLeg(liftlowerVel);
            rel_L3->liftLeg(liftlowerVel);
            rel_R2->waitMotion();
            rel_L3->waitMotion();
            rel_R2->lowerLeg(liftlowerVel);
            rel_L3->lowerLeg(liftlowerVel);
            rel_R2->waitMotion();
            rel_L3->waitMotion();
            rel_R2->pushGround(vel);
            rel_L3->pushGround(vel);
            
            rel_R3->liftLeg(liftlowerVel);
            rel_L1->liftLeg(liftlowerVel);
            rel_R3->waitMotion();
            rel_L1->waitMotion();
            rel_R3->lowerLeg(liftlowerVel);
            rel_L1->lowerLeg(liftlowerVel);
            rel_R3->waitMotion();
            rel_L1->waitMotion();
            rel_R3->pushGround(vel);
            rel_L1->pushGround(vel);
        }
};

#endif