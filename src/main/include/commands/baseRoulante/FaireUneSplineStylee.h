#pragma once

#include <frc/commands/Command.h>
#include <pathfinder.h>

class FaireUneSplineStylee : public frc::Command
{
 public:
  FaireUneSplineStylee();
  void Initialize() override;
  void Execute() override;
  bool IsFinished() override;
  void End() override;
  void Interrupted() override;

 private:
  int m_trajectory_length;

  Segment m_trajectoireDroite[1024], m_trajectoireGauche[1024];

  EncoderFollower* m_followerDroite = (EncoderFollower *)malloc(sizeof(EncoderFollower));
  EncoderFollower* m_followerGauche = (EncoderFollower *)malloc(sizeof(EncoderFollower));

  EncoderConfig* m_encoderConfigDroite = (EncoderConfig *)malloc(sizeof(EncoderConfig));
  EncoderConfig* m_encoderConfigGauche = (EncoderConfig *)malloc(sizeof(EncoderConfig));
};
