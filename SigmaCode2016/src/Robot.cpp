#include "WPILib.h"

class Robot: public SampleRobot
{
	RobotDrive *myRobot; // robot drive system
	Joystick *lstick,*rstick; // Left and Right Joysticks
	//VictorSP *left1, *left2, *right1, *right2;
	DoubleSolenoid *shifter;

public:
	void RobotInit() override {
		/*
		left1 = new VictorSP(0);
		left2 = new VictorSP(1);
		right1 = new VictorSP(2);
		right2 = new VictorSP(3);
		*/
		myRobot = new RobotDrive(1,2,3,4);
		lstick = new Joystick(0);
		rstick = new Joystick(1);
		//myRobot->SetExpiration(0.1);
	//	std::thread drive(driveTask);
	//	drive.detach();
		shifter = new DoubleSolenoid(0,1);
	}

	void OperatorControl()
	{
		while(IsOperatorControl() && IsEnabled()){
			if(lstick->GetRawButton(1) && rstick->GetRawButton(1)){
				shifter->Set(kForward);
			}
			else{
				shifter->Set(kReverse);
			}
			myRobot->TankDrive(lstick,rstick); // drive with tank style
			Wait(0.005); // wait for a motor update time
		}
	}
};
START_ROBOT_CLASS(Robot)
