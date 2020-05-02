#include "..\hook.h"

//cl_move 55 8B EC 83 EC 34 83 3D useless cuz has sv_maxusrcmdprocessticks
bool __stdcall hook::createmove(float sampletime, CUserCmd* cmd)
{
	if (!cmd->command_number)
		return false;
	c_baseplayer* me = reinterpret_cast<c_baseplayer*>(g_entitylist->GetClientEntity(g_engine->GetLocalPlayer()));

	if (cmd->buttons & IN_JUMP && !(me->m_fFlags() & FL_ONGROUND))
		cmd->buttons &= ~IN_JUMP;
	return false;
}