#include "Loading.h"

//이미지 파일
const WCHAR* PartialBG = TEXT("/resource/BG.png");
const WCHAR* PartialPlane = TEXT("/resource/PlayerPlane.png");
const WCHAR* PartialPlaneMask = TEXT("/resource/PlayerPlaneMasking.png");
const WCHAR* PartialEngineGlow = TEXT("/resource/ShipGlow.png");
const WCHAR* PartialEngineGlowMask = TEXT("/resource/ShipGlowMask.png");
const WCHAR* PartialProjectilePlayer = TEXT("/resource/ProjectilePlayer.png");
const WCHAR* PartialExplosion = TEXT("/resource/Explosion.png");

const WCHAR* PartialPlayerProjectile = TEXT("/resource/ProjectilePlayer.png");
const WCHAR* PartialEnemyBullet = TEXT("/resource/ProjectileEnemy.png");
extern const WCHAR* PartialPlayerProjectileMasking = TEXT("/resource/ProjectilePlayerMasking.png");
extern const WCHAR* PartialEnemyBulletMasking = TEXT("/resource/ProjectileEnemyMasking.png");
//스크린 크기
const int ScreenSizeX = 800;
const int ScreenSizeY = 600;

//배경 스크롤 속도
const float BgScrollSpeed = 180.f;

//plane speed
const float PlaneSpeed = 5.f;

//projectile speed
const float PlayerProjectileSpeed = 20.f;

//const for GunClass
const int NumBullet = 20;
const int ProjectilePixel[4]{1,1,45,98};