#include "OmniDrive.h"
#include <RobotMap.h>
#include <CommandBase.h>

OmniDrive::OmniDrive()
{
	// Use Requires() here to declare subsystem dependencies
	// eg.Requires(chassis);
    Requires(chassis);
}

// Called just before this Command runs the first time
void OmniDrive::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void OmniDrive::Execute()
{
    double x_hat = double(oi->getJoyHatX()) / HAT_SCALE_DOWN_FACTOR;
    double y_hat = double(oi->getJoyHatY()) / HAT_SCALE_DOWN_FACTOR;
    double x = - oi->getJoyDrvY();
    double y = -oi->getJoyDrvX();
    double z = - oi->getJoyDrvZ();
    double throttle = oi->getJoyDrvThrottle();

    SmartDashboard::PutNumber("X-Hat: ", x_hat);
    SmartDashboard::PutNumber("Y-Hat: ", y_hat);

    bool hat_drive;
    if(x_hat != 0 || y_hat != 0) {
        hat_drive = true;
    }

    chassis->Drive(x, y, z, throttle, Strafe_Motor_Ratio, hat_drive);
}

// Make this return true when this Command no longer needs to run execute()
bool OmniDrive::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void OmniDrive::End()
{
    chassis->Drive(0.0,0.0,0.0,0.0, Strafe_Motor_Ratio);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void OmniDrive::Interrupted()
{
    End();
}
