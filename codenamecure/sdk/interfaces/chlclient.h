#pragma once
#include "..\misc.h"
#include "..\client\clientclass.h"
class CGlobalVarsBase;

class IBaseClientDll
{
public:
	// Called once when the client DLL is loaded
	virtual int				Init(create_interface_fn appSystemFactory,create_interface_fn physicsFactory, CGlobalVarsBase* pGlobals) = 0;

	virtual void			PostInit() = 0;

	// Called once when the client DLL is being unloaded
	virtual void			Shutdown(void) = 0;

	// Called once the client is initialized to setup client-side replay interface pointers
	virtual bool			ReplayInit(create_interface_fn replayFactory) = 0;
	virtual bool			ReplayPostInit() = 0;

	// Called at the start of each level change
	virtual void			LevelInitPreEntity(char const* pMapName) = 0;
	// Called at the start of a new level, after the entities have been received and created
	virtual void			LevelInitPostEntity() = 0;
	// Called at the end of a level
	virtual void			LevelShutdown(void) = 0;

	// Request a pointer to the list of client datatable classes
	virtual ClientClass* GetAllClasses(void) = 0;

};