#pragma once

#include <frc/WPILib.h>
#include <frc/shuffleboard/Shuffleboard.h>

class OI
{
 public:
  OI();
  frc::Joystick& GetJoystick();
 
 private:
  frc::Joystick m_joystick{0};

	frc::JoystickButton m_button1{&m_joystick, 1};
	frc::JoystickButton m_button2{&m_joystick, 2};
	frc::JoystickButton m_button3{&m_joystick, 3};
	frc::JoystickButton m_button4{&m_joystick, 4};
	frc::JoystickButton m_button5{&m_joystick, 5};
	frc::JoystickButton m_button8{&m_joystick, 8};
	frc::JoystickButton m_button9{&m_joystick, 9};
	frc::JoystickButton m_button10{&m_joystick, 10};
	frc::JoystickButton m_button11{&m_joystick, 11};
  frc::JoystickButton m_button12{&m_joystick, 12};
};
