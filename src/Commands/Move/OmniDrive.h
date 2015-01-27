#ifndef OMNIDRIVE_H
#define OMNIDRIVE_H

#include "CommandBase.h"
#include "WPILib.h"

#define HAT_SCALE_DOWN_FACTOR 5

class OmniDrive: public CommandBase
{
  public:
	OmniDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
