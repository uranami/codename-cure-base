#include "hook.h"


std::unique_ptr<vmthook> clientmodehook;

void hook::setup_hook()
{
	clientmodehook = std::make_unique<vmthook>(g_clientmode);
	if (clientmodehook->hook(hook::createmove, 21))
		printf("hooked clientmode::createmove.\n");
}