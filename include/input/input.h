#pragma once

#include <pspctrl.h>

class Input
{
public:
    void Init();
    void Update();

    bool IsPressed(unsigned int button);
    bool IsHeld(unsigned int button);
    bool IsReleased(unsigned int button);

    int GetAnalogX();
    int GetAnalogY();

private:
    SceCtrlData currentPad;
    SceCtrlData previousPad;

    float deadZone;
};