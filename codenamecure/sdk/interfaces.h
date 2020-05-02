#pragma once

#include <map>
#include "interfaces/chlclient.h"
#include "interfaces/clientmode.h"
#include "interfaces/engineclient.h"
#include "interfaces/cliententitylist.h"
#include "client/c_baseplayer.h"


extern IBaseClientDll* g_client;
extern IClientMode* g_clientmode;
extern IVEngineClient* g_engine;
extern IClientEntityList* g_entitylist;



extern void setup_interfaces();