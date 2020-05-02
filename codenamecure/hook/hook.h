#pragma once
#include "..\sdk\interfaces.h"
#include "..\tools\vmthook.h"


extern std::unique_ptr<vmthook> clientmodehook;

namespace hook
{
	extern void setup_hook();
	extern bool __stdcall createmove(float sampletime, CUserCmd* cmd);
}

