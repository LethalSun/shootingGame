#include "Loading.h"

//이미지 파일
const WCHAR* PartialBG = TEXT("/resource/BG.png");

const WCHAR* PartialPlane = TEXT("/resource/PlayerPlaneHalf.png");
const WCHAR* PartialPlaneMask = TEXT("/resource/PlayerPlaneHalfMasking.png");

const WCHAR* PartialProjectilePlayer = TEXT("/resource/ProjectilePlayer.png");
const WCHAR* PartialExplosion = TEXT("/resource/Explosion.png");

const WCHAR* PartialEnemy			=TEXT("/resource/EnemieSmallSheep.png");
const WCHAR* PartialEnemyMasking	=TEXT("/resource/EnemieSmallSheepMasking.png");

const WCHAR* PartialEnemy2 = TEXT("/resource/EnemiesImage.png");
const WCHAR* PartialEnemyMasking2 = TEXT("/resource/EnemiesImageMasking.png");

const WCHAR* PartialUi			=TEXT("/resource/UI.png");
const WCHAR* PartialUiMasking	=TEXT("/resource/UIMasking.png");


const WCHAR* PartialPlayerProjectile = TEXT("/resource/ProjectilePlayerHalf.png");
const WCHAR* PartialPlayerProjectileMasking = TEXT("/resource/ProjectilePlayerHalfMasking.png");

const WCHAR* PartialEnemyBullet = TEXT("/resource/EnemySmallSheepBullet.png");
const WCHAR* PartialEnemyBulletMasking = TEXT("/resource/EnemySmallSheepBulletMasking.png");

const WCHAR* PartialEnemyBullet2 = TEXT("/resource/EnemyBullet.png");
const WCHAR* PartialEnemyBulletMasking2 = TEXT("/resource/EnemyBulletMasking.png");

//플레이어 이미지 프레임 포인트
const int PlayerPlaneFramePoint[10]{ 1,78,155,232,309,386,463,540,617,694 };
const int PlayerPlaneFrameEndPoint[2]{ 75,63 };

const int PlayerCollideRadius[4]{ 60 ,50, 30 ,10 };
//스크린 크기
const int ScreenSizeX = 800;
const int ScreenSizeY = 600;

//배경 스크롤 속도
const float BgScrollSpeed = 180.f;

//plane speed
const float PlaneSpeed = 5.f;

//max hp
const int MaxHp{10};

//projectile speed
const float PlayerProjectileSpeed = 20.f;

//const for GunClass
const int NumBullet = 20;
const float ProjectileFramePoint[16]{ 1,1,23,49
									,26,1,31,53
									,1,56,40,57
									,1,115,50,65 };
const int PlayerBulletRadius[4]{30,32,34,36};

const float ProjectileMarginForPlayerPlane[2]{ PlayerPlaneFrameEndPoint[0] - ProjectileFramePoint[3]
												, 0.f };

const float ProjectileMarginForEnemyPlane[2]{ 12.f,0.f };

const float BulletSpeed = 10.f;
const float EnemyProjectileFramePoint[8]{1,1,28,18,31,1,28,18};

const float UiBackGround[4]{1,303,120,600};
const float UiBackGroundPos[2]{664,0};
const float UiBarBlack[4]{1,1,34,300};
const float UiBarBlood[4]{37,1,34,300};
const float UiBarOne[4]{73,1,34,300};
const float UiBarZero[4]{109,1,34,300};
const float UiHpBarPos[2]{689,80};

//const for Enemy Frame Info

const float EnemySmallX[12]  { 1,51,101,151,201,251,301,351,401,451,501,551 };
const float EnemySmallRest[3] { 1,48,45 };

//const for EnemyManagerClass;
const float EnemyShipFrame[16]
{ 1,1,155,141
,1,144,100,87
,103,144,48,45
,153,144,38,37 };

const int EnemyHp{3};
const int EnemyShipRadius[4]{80,60,30,25};
const float EnemyBulletFrame[44]
{ 1,1,18,28,
21,1,18,28,
41,1,22,22,
1,31,22,22,
25,31,22,22,
1,55,22,22,
25,55,22,22,
1,79,22,22,
25,79,29,22,
1,103,29,22,
32,103,29,22
};
const int EnemyBulletRadius[11]{20,20,15,15,15,15,15,15,20,20,20};
const float EnemyBulletMargin[16]
{69.f,65.f,65.f,61.f,40.f,38.5f,38.5f,35.f
,15.f,12.f,12.f,10.f,10.f,7.f,7.f,4.f};