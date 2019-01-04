#pragma once

#include <frc/WPILib.h>

class OI
{
 public:
  OI();
  frc::Joystick& GetJoystick();
 
 private:
  frc::Joystick joystick1{0};

	frc::JoystickButton button1{&joystick1, 1};
	frc::JoystickButton button2{&joystick1, 2};
	frc::JoystickButton button3{&joystick1, 3};
	frc::JoystickButton button4{&joystick1, 4};
	frc::JoystickButton button5{&joystick1, 5};
	frc::JoystickButton button8{&joystick1, 8};
	frc::JoystickButton button9{&joystick1, 9};
	frc::JoystickButton button10{&joystick1, 10};
	frc::JoystickButton button11{&joystick1, 11};
  frc::JoystickButton button12{&joystick1, 12};
};
