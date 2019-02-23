#pragma once

#include <frc/WPILib.h>

class OI
{
 public:
  OI();
  frc::Joystick& GetJoystick1();
  frc::Joystick& GetJoystick2();

  frc::Joystick m_joystick1{0};
  frc::Joystick m_joystick2{1};

  frc::JoystickButton m_button1{&m_joystick1, 1};
  frc::JoystickButton m_button2{&m_joystick1, 2};
  frc::JoystickButton m_button3{&m_joystick1, 3};
  frc::JoystickButton m_button4{&m_joystick1, 4};
  frc::JoystickButton m_button5{&m_joystick1, 5};
  frc::JoystickButton m_button6{&m_joystick1, 6};
  frc::JoystickButton m_button7{&m_joystick1, 7};
  frc::JoystickButton m_button8{&m_joystick1, 8};
  frc::JoystickButton m_button9{&m_joystick1, 9};
  frc::JoystickButton m_button10{&m_joystick1, 10};
  frc::JoystickButton m_button11{&m_joystick1, 11};
  frc::JoystickButton m_button12{&m_joystick1, 12};

  frc::JoystickButton m_button1Joystick2{&m_joystick2, 1};
  frc::JoystickButton m_button3Joystick2{&m_joystick2, 3};
  frc::JoystickButton m_button5Joystick2{&m_joystick2, 5};
};
