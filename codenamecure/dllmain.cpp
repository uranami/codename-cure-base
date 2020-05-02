// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "hook/hook.h"
//createmove 21

#include <fstream>

DWORD WINAPI setup(LPVOID module)
{

	AllocConsole();
	SetConsoleTitleA("codename:cure internal console");
	freopen("conin$", "r", stdin);
	freopen("conout$", "w", stdout);

	printf("inject\n");

	setup_interfaces();
	hook::setup_hook();
	return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call,LPVOID lpReserved )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		if (hModule)
			DisableThreadLibraryCalls(hModule);
		CreateThread(nullptr, 0, setup, hModule, 0, nullptr);
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

