#include "Loading.h"

const WCHAR* PartialBG = TEXT("/resource/BG.png");
const WCHAR* PartialPlane = TEXT("/resource/PlayerPlane.png");
const WCHAR* PartialPlaneMask = TEXT("/resource/PlayerPlaneMasking.png");
const WCHAR* PartialEngineGlow = TEXT("/resource/ShipGlow.png");
const WCHAR* PartialEngineGlowMask = TEXT("/resource/ShipGlowMask.png");
const WCHAR* PartialProjectilePlayer = TEXT("/resource/ProjectilePlayer.png");
const WCHAR* PartialExplosion = TEXT("/resource/Explosion.png");

const int ScreenSizeX = 800;
const int ScreenSizeY = 600;

const float BgScrollSpeed = 180.f;
const float PlaneSpeed = 5.f;

const float PlayerProjectileSpeed = 20.f;
