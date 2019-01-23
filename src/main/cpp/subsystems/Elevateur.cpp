#include "subsystems/Elevateur.h"

Elevateur::Elevateur() : PIDSubsystem("Elevateur", 1.0, 0.0, 0.0)
{
  // Use these to get going:
  // SetSetpoint() -  Sets where the PID controller should move the system
  //                  to
  // Enable() - Enables the PID controller.
}

double Elevateur::ReturnPIDInput()
{
  // Return your input value for the PID loop
  // e.g. a sensor, like a potentiometer:
  // yourPot->SetAverageVoltage() / kYourMaxVoltage;
  return 0;
}

void Elevateur::UsePIDOutput(double output)
{
  // Use output to drive your system, like a motor
  // e.g. yourMotor->Set(output);
}

void Elevateur::InitDefaultCommand()
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
