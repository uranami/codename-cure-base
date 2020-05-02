#include "interfaces.h"

IBaseClientDll* g_client = nullptr;
IClientMode* g_clientmode = nullptr;
IVEngineClient* g_engine = nullptr;
IClientEntityList* g_entitylist = nullptr;

template <typename T>
T* getinterface(const char* module_name, const char* interface_name)
{
	create_interface_fn create_interface = (create_interface_fn)GetProcAddress(GetModuleHandleA(module_name), "CreateInterface");

	return (T*)create_interface(interface_name, nullptr);
}


void setup_interfaces()
{
	g_client = getinterface<IBaseClientDll>("client.dll", "VClient017");
	printf("find g_chlclient at 0x%p\n", g_client);
	g_clientmode = **(IClientMode***)((*(DWORD**)g_client)[10] + 0x5);
	printf("find g_clientmode at 0x%p\n", g_clientmode);
	g_engine = getinterface<IVEngineClient>("engine.dll", "VEngineClient014");
	printf("find g_engine at 0x%p\n", g_engine);
	g_entitylist = getinterface<IClientEntityList>("client.dll", "VClientEntityList003");
	printf("find g_entitylist at 0x%p\n", g_entitylist);
}


