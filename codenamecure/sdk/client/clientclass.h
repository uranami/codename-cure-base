#pragma once
#include "..\misc.h"
class IClientNetworkable;
class RecvTable;

typedef IClientNetworkable* (*createclientclassfn)(int entnum, int serialNum);
typedef IClientNetworkable* (*CreateEventFn)();

class ClientClass
{
public:
	const char* GetName()
	{
		return m_pNetworkName;
	}

public:
	createclientclassfn		m_pCreateFn;
	CreateEventFn			m_pCreateEventFn;	// Only called for event objects.
	const char* m_pNetworkName;
	RecvTable* m_pRecvTable;
	ClientClass* m_pNext;
	int						m_ClassID;	// Managed by the engine.
};


enum classid
{
	CTestTraceline = 187,
	CTEWorldDecal = 188,
	CTESpriteSpray = 185,
	CTESprite = 184,
	CTESparks = 183,
	CTESmoke = 182,
	CTEShowLine = 180,
	CTEProjectedDecal = 178,
	CTEPlayerDecal = 177,
	CTEPhysicsProp = 175,
	CTEParticleSystem = 174,
	CTEMuzzleFlash = 173,
	CTELargeFunnel = 171,
	CTEKillPlayerAttachments = 170,
	CTEImpact = 169,
	CTEGlowSprite = 167,
	CTEShatterSurface = 179,
	CTEFootprintDecal = 165,
	CTEFizz = 164,
	CTEExplosion = 163,
	CTEEnergySplash = 162,
	CTEEffectDispatch = 161,
	CTEDynamicLight = 160,
	CTEDecal = 158,
	CTEClientProjectile = 156,
	CTEBubbleTrail = 155,
	CTEBubbles = 154,
	CTEBSPDecal = 153,
	CTEBreakModel = 152,
	CTEBloodStream = 151,
	CTEBloodSprite = 150,
	CTEBeamSpline = 149,
	CTEBeamRingPoint = 148,
	CTEBeamRing = 147,
	CTEBeamPoints = 146,
	CTEBeamLaser = 145,
	CTEBeamFollow = 144,
	CTEBeamEnts = 143,
	CTEBeamEntPoint = 142,
	CTEBaseBeam = 141,
	CTEArmorRicochet = 140,
	CTEMetalSparks = 172,
	CSteamJet = 132,
	CSmokeStack = 127,
	DustTrail = 225,
	CFireTrail = 53,
	SporeTrail = 231,
	SporeExplosion = 230,
	RocketTrail = 228,
	SmokeTrail = 229,
	CPropVehicleDriveable = 115,
	ParticleSmokeGrenade = 227,
	CParticleFire = 97,
	MovieExplosion = 226,
	CTEGaussExplosion = 166,
	CEnvQuadraticBeam = 46,
	CEmbers = 38,
	CEnvWind = 51,
	CPrecipitation = 110,
	CBaseTempEntity = 23,
	CWeaponStunStick = 223,
	CWeaponSMG1 = 222,
	CWeapon_SLAM = 197,
	CWeaponShotgun = 221,
	CWeaponSentryPlanter = 220,
	CWeaponRPG = 219,
	CLaserDot = 85,
	CWeaponPistol = 218,
	CWeaponPhysCannon = 217,
	CWeaponP228 = 216,
	CWeaponMP5 = 215,
	CWeaponM4S90 = 214,
	CHL2MPIncendiary = 76,
	CBaseHL2MPCombatWeapon = 14,
	CBaseHL2MPBludgeonWeapon = 13,
	CHL2MPMachineGun = 77,
	CWeaponHL2MPBase = 213,
	CHL2MPGrenade = 75,
	CWeaponGlock = 212,
	CWeaponGalil = 211,
	CWeaponG3SG1 = 210,
	CWeaponFrag = 209,
	CWeaponFiveSeven = 208,
	CWeaponElites = 207,
	CWeaponCrowbar = 204,
	CWeaponCrossbow = 203,
	CWeaponChestPlanter = 202,
	CWeaponBombPlanter = 200,
	CBaseHL2MPGrenade = 15,
	CWeaponAR2 = 199,
	CWeapon357 = 196,
	CBaseGrenadeProjectile = 11,
	CTRGameRulesProxy = 189,
	CSVGameRulesProxy = 134,
	CPVPGameRulesProxy = 117,
	CHL2MPGameRulesProxy = 74,
	CGDGameRulesProxy = 69,
	CCSGameRulesProxy = 35,
	CTEHL2MPFireBullets = 168,
	CTEPlayerAnimEvent = 176,
	CHL2MPRagdoll = 78,
	CHL2MP_Player = 73,
	CBGGameRulesProxy = 26,
	CHalfLife2Proxy = 70,
	CCrossbowBolt = 34,
	CWeaponCitizenSuitcase = 0,
	CWeaponCitizenPackage = 0,
	CWeaponAlyxGun = 0,
	CWeaponCubemap = 205,
	CWeaponGaussGun = 0,
	CWeaponAnnabelle = 198,
	CFlaregun = 0,
	CWeaponBugBait = 201,
	CWeaponBinoculars = 0,
	CWeaponCycler = 206,
	CVortigauntEffectDispel = 192,
	CVortigauntChargeToken = 191,
	CNPC_Vortigaunt = 96,
	CPropVehiclePrisonerPod = 116,
	CPropCrane = 114,
	CPropCannon = 0,
	CPropAirboat = 112,
	CFlare = 55,
	CTEConcussiveExplosion = 157,
	CNPC_Strider = 95,
	CScriptIntro = 124,
	CRotorWashEmitter = 122,
	CPropCombineBall = 113,
	CPlasmaBeamNode = 0,
	CNPC_RollerMine = 94,
	CNPC_Manhack = 93,
	CNPC_CombineGunship = 92,
	CNPC_AntlionGuard = 89,
	CInfoTeleporterCountdown = 84,
	CMortarShell = 88,
	CEnvStarfield = 49,
	CEnvHeadcrabCanister = 43,
	CAlyxEmpEffect = 2,
	CCorpse = 33,
	CCitadelEnergyCore = 30,
	CHL2_Player = 72,
	CBaseHLBludgeonWeapon = 16,
	CHLSelectFireMachineGun = 80,
	CHLMachineGun = 79,
	CBaseHelicopter = 12,
	CNPC_Barney = 91,
	CNPC_Barnacle = 90,
	AR2Explosion = 0,
	CTEAntlionDust = 139,
	CBaseHLCombatWeapon = 17,
	CHandleTest = 71,
	CTeamplayRoundBasedRulesProxy = 136,
	CTeamRoundTimer = 137,
	CSpriteTrail = 131,
	CSpriteOriented = 130,
	CSprite = 129,
	CRagdollPropAttached = 120,
	CRagdollProp = 119,
	CPredictedViewModel = 111,
	CPoseController = 109,
	CGameRulesProxy = 68,
	CInfoLadderDismount = 81,
	CFuncLadder = 61,
	CEnvDetailController = 42,
	CWorld = 224,
	CWaterLODControl = 195,
	CWaterBullet = 194,
	CVoteController = 193,
	CVGuiScreen = 190,
	CPropJeep = 0,
	CPropVehicleChoreoGeneric = 0,
	CTest_ProxyToggle_Networkable = 186,
	CTesla = 181,
	CTeamTrainWatcher = 138,
	CBaseTeamObjectiveResource = 22,
	CTeam = 135,
	CSun = 133,
	CParticlePerformanceMonitor = 98,
	CSpotlightEnd = 128,
	CSlideshowDisplay = 126,
	CShadowControl = 125,
	CSceneEntity = 123,
	CRopeKeyframe = 121,
	CRagdollManager = 118,
	CPhysicsPropMultiplayer = 103,
	CPhysBoxMultiplayer = 101,
	CBasePropDoor = 21,
	CDynamicProp = 37,
	CPointCommentaryNode = 108,
	CPointCamera = 107,
	CPlayerResource = 106,
	CPlasma = 105,
	CPhysMagnet = 104,
	CPhysicsProp = 102,
	CPhysBox = 100,
	CParticleSystem = 99,
	CMaterialModifyControl = 87,
	CLightGlow = 86,
	CInfoOverlayAccessor = 83,
	CFuncTrackTrain = 67,
	CFuncSmokeVolume = 66,
	CFuncRotating = 65,
	CFuncReflectiveGlass = 64,
	CFuncOccluder = 63,
	CFuncMonitor = 62,
	CFunc_LOD = 58,
	CTEDust = 159,
	CFunc_Dust = 57,
	CFuncConveyor = 60,
	CBreakableSurface = 29,
	CFuncAreaPortalWindow = 59,
	CFish = 54,
	CEntityFlame = 40,
	CFireSmoke = 52,
	CEnvTonemapController = 50,
	CEnvScreenEffect = 47,
	CEnvScreenOverlay = 48,
	CEnvProjectedTexture = 45,
	CEnvParticleScript = 44,
	CFogController = 56,
	CEntityParticleTrail = 41,
	CEntityDissolve = 39,
	CDynamicLight = 36,
	CColorCorrectionVolume = 32,
	CColorCorrection = 31,
	CBreakableProp = 28,
	CBasePlayer = 19,
	CBaseFlex = 9,
	CBaseEntity = 8,
	CBaseDoor = 7,
	CBaseCombatCharacter = 5,
	CBaseAnimatingOverlay = 4,
	CBoneFollower = 27,
	CBaseAnimating = 3,
	CInfoLightingRelative = 82,
	CAI_BaseNPC = 1,
	CBeam = 25,
	CBaseViewModel = 24,
	CBaseProjectile = 20,
	CBaseParticleEntity = 18,
	CBaseGrenade = 10,
	CBaseCombatWeapon = 6,
};