#include "Loading.h"

//이미지 파일
const WCHAR* PartialBG = TEXT("/resource/BG.png");
const WCHAR* PartialPlane = TEXT("/resource/PlayerPlaneHalf.png");
const WCHAR* PartialPlaneMask = TEXT("/resource/PlayerPlaneHalfMasking.png");
//const WCHAR* PartialPlane = TEXT("/resource/PlayerPlane.png");
//const WCHAR* PartialPlaneMask = TEXT("/resource/PlayerPlaneMasking.png");
const WCHAR* PartialEngineGlow = TEXT("/resource/ShipGlow.png");
const WCHAR* PartialEngineGlowMask = TEXT("/resource/ShipGlowMask.png");
const WCHAR* PartialProjectilePlayer = TEXT("/resource/ProjectilePlayer.png");
const WCHAR* PartialExplosion = TEXT("/resource/Explosion.png");
const WCHAR* PartialEnemy			=TEXT("/resource/EnemieSmallSheep.png");
const WCHAR* PartialEnemyMasking	=TEXT("/resource/EnemieSmallSheepMasking.png");
const WCHAR* PartialUi			=TEXT("/resource/UI.png");
const WCHAR* PartialUiMasking	=TEXT("/resource/UIMasking.png");

//const WCHAR* PartialPlayerProjectile = TEXT("/resource/ProjectilePlayer.png");
const WCHAR* PartialPlayerProjectile = TEXT("/resource/ProjectilePlayerHalf.png");
const WCHAR* PartialEnemyBullet = TEXT("/resource/EnemySmallSheepBullet.png");
//const WCHAR* PartialPlayerProjectileMasking = TEXT("/resource/ProjectilePlayerMasking.png");
const WCHAR* PartialPlayerProjectileMasking = TEXT("/resource/ProjectilePlayerHalfMasking.png");
const WCHAR* PartialEnemyBulletMasking = TEXT("/resource/EnemySmallSheepBulletMasking.png");

const WCHAR* PartialUiBackground       = TEXT("/resource/UIBackground.png");
const WCHAR* PartialUiHpBarZero        = TEXT("/resource/BarZero.png");
const WCHAR* PartialUiHpBar			   = TEXT("/resource/BarOne.png");
const WCHAR* PartialUiHpRed			   = TEXT("/resource/BarBlood.png");
const WCHAR* partialUiHpBlack		   = TEXT("/resource/BarBlackBack.png");
const WCHAR* PartialUiHpBarZeroMasking = TEXT("/resource/BarZeroMasking.png");
const WCHAR* PartialUiHpBarMasking	   = TEXT("/resource/BarOneMasking.png");

//플레이어 이미지 프레임 포인트
//const int FramePoint[10]{1,153,305,457,609,761,913,1065,1217,1369};
//const int FrameEndPoint[2]{ 150,125 };
const int PlayerPlaneFramePoint[10]{ 1,78,155,232,309,386,463,540,617,694 };
const int PlayerPlaneFrameEndPoint[2]{ 75,63 };

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
//const int ProjectileFramePoint[4]{1,1,45,98};
const float ProjectileFramePoint[16]{ 1,1,23,49
									,26,1,31,53
									,1,56,40,57
									,1,115,50,65 };
const float ProjectileMarginForPlayerPlane[2]{ PlayerPlaneFrameEndPoint[0] - ProjectileFramePoint[3], 0.f };
const float BulletSpeed = 10.f;

const float UiBackGround[4]{1,303,120,600};
const float UiBackGroundPos[2]{664,0};
const float UiBarBlack[4]{1,1,34,300};
const float UiBarBlood[4]{37,1,34,300};
const float UiBarOne[4]{73,1,34,300};
const float UiBarZero[4]{109,1,34,300};
const float UiHpBarPos[2]{689,80};