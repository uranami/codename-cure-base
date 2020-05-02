#pragma once
#include <Windows.h>
#include <memory>
#include <Psapi.h>
#include <chrono>
#include <thread>
#include "math/vector.h"
typedef void* (*create_interface_fn)(const char* name, int* return_code);

struct CUserCmd
{
	virtual ~CUserCmd() {};
	int command_number;
	int tick_count;
	QAngle viewangles;
	float forwardmove;
	float sidemove;
	float upmove;
	int buttons;
	unsigned char impulse;
	int weaponselect;
	int weaponsubtype;
	int random_seed;
	short mousedx;
	short mousedy;
	bool hasbeenpredicted;

};

#define IN_ATTACK					(1 << 0)
#define IN_JUMP						(1 << 1)
#define IN_DUCK						(1 << 2)
#define IN_FORWARD					(1 << 3)
#define IN_BACK						(1 << 4)
#define IN_USE						(1 << 5)
#define IN_CANCEL					(1 << 6)
#define IN_LEFT						(1 << 7)
#define IN_RIGHT					(1 << 8)
#define IN_MOVELEFT					(1 << 9)
#define IN_MOVERIGHT				(1 << 10)
#define IN_ATTACK2					(1 << 11)
#define IN_RUN						(1 << 12)
#define IN_RELOAD					(1 << 13)
#define IN_ALT1						(1 << 14)
#define IN_ALT2						(1 << 15)
#define IN_SCORE					(1 << 16)   /**< Used by client.dll for when scoreboard is held down */
#define IN_SPEED					(1 << 17)	/**< Player is holding the speed key */
#define IN_WALK						(1 << 18)	/**< Player holding walk key */
#define IN_ZOOM						(1 << 19)	/**< Zoom key for HUD zoom */
#define IN_WEAPON1					(1 << 20)	/**< weapon defines these bits */
#define IN_WEAPON2					(1 << 21)	/**< weapon defines these bits */
#define IN_BULLRUSH					(1 << 22)
#define IN_GRENADE1					(1 << 23)	/**< grenade 1 */
#define IN_GRENADE2					(1 << 24)	/**< grenade 2 */
#define IN_ATTACK3					(1 << 25)
// Note: these are only for use with GetEntityFlags and SetEntityFlags
//       and may not match the game's actual, internal m_fFlags values.
// PLAYER SPECIFIC FLAGS FIRST BECAUSE WE USE ONLY A FEW BITS OF NETWORK PRECISION
#define	FL_ONGROUND					(1 << 0)	/**< At rest / on the ground */
#define FL_DUCKING					(1 << 1)	/**< Player flag -- Player is fully crouched */
#define	FL_WATERJUMP				(1 << 2)	/**< player jumping out of water */
#define FL_ONTRAIN					(1 << 3)	/**< Player is _controlling_ a train, so movement commands should be ignored on client during prediction. */
#define FL_INRAIN					(1 << 4)	/**< Indicates the entity is standing in rain */
#define FL_FROZEN					(1 << 5)	/**< Player is frozen for 3rd person camera */
#define FL_ATCONTROLS				(1 << 6)	/**< Player can't move, but keeps key inputs for controlling another entity */
#define	FL_CLIENT					(1 << 7)	/**< Is a player */
#define FL_FAKECLIENT				(1 << 8)	/**< Fake client, simulated server side; don't send network messages to them */
// NOTE if you move things up, make sure to change this value
#define PLAYER_FLAG_BITS		9
// NON-PLAYER SPECIFIC (i.e., not used by GameMovement or the client .dll ) -- Can still be applied to players, though
#define	FL_INWATER					(1 << 9)	/**< In water */
#define	FL_FLY						(1 << 10)	/**< Changes the SV_Movestep() behavior to not need to be on ground */
#define	FL_SWIM						(1 << 11)	/**< Changes the SV_Movestep() behavior to not need to be on ground (but stay in water) */
#define	FL_CONVEYOR					(1 << 12)
#define	FL_NPC						(1 << 13)
#define	FL_GODMODE					(1 << 14)
#define	FL_NOTARGET					(1 << 15)
#define	FL_AIMTARGET				(1 << 16)	/**< set if the crosshair needs to aim onto the entity */
#define	FL_PARTIALGROUND			(1 << 17)	/**< not all corners are valid */
#define FL_STATICPROP				(1 << 18)	/**< Eetsa static prop!		 */
#define FL_GRAPHED					(1 << 19)	/**< worldgraph has this ent listed as something that blocks a connection */
#define FL_GRENADE					(1 << 20)
#define FL_STEPMOVEMENT				(1 << 21)	/**< Changes the SV_Movestep() behavior to not do any processing */
#define FL_DONTTOUCH				(1 << 22)	/**< Doesn't generate touch functions, generates Untouch() for anything it was touching when this flag was set */
#define FL_BASEVELOCITY				(1 << 23)	/**< Base velocity has been applied this frame (used to convert base velocity into momentum) */
#define FL_WORLDBRUSH				(1 << 24)	/**< Not moveable/removeable brush entity (really part of the world, but represented as an entity for transparency or something) */
#define FL_OBJECT					(1 << 25)	/**< Terrible name. This is an object that NPCs should see. Missiles, for example. */
#define FL_KILLME					(1 << 26)	/**< This entity is marked for death -- will be freed by game DLL */
#define FL_ONFIRE					(1 << 27)	/**< You know... */
#define FL_DISSOLVING				(1 << 28)	/**< We're dissolving! */
#define FL_TRANSRAGDOLL				(1 << 29)	/**< In the process of turning into a client side ragdoll. */
#define FL_UNBLOCKABLE_BY_PLAYER	(1 << 30)	/**< pusher that can't be blocked by the player */
#define FL_FREEZING					(1 << 31)	/**< We're becoming frozen! */
