#include "subsystems/Bras.h"

Bras::Bras()
    : PIDSubsystem("Bras", 1.0, 0.0, 0.0)
    {
  // Use these to get going:
  // SetSetpoint() -  Sets where the PID controller should move the system
  //                  to
  // Enable() - Enables the PID controller.
}

double Bras::ReturnPIDInput()
{
  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return 0;
}

void Bras::UsePIDOutput(double output)
{
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
}

void Bras::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
