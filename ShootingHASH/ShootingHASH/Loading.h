#pragma once
////이미지 파일

//배경
extern const WCHAR* PartialBG;
//비행기
extern const WCHAR* PartialPlane;
extern const WCHAR* PartialPlaneMask;
extern const WCHAR* PartialEnemy;
extern const WCHAR* PartialEnemyMasking;
//미사용
extern const WCHAR* PartialEngineGlow;
extern const WCHAR* PartialEngineGlowMask;
extern const WCHAR* PartialProjectilePlayer;
extern const WCHAR* PartialExplosion;

//총알
extern const WCHAR* PartialPlayerProjectile;
extern const WCHAR* PartialEnemyBullet;
extern const WCHAR* PartialPlayerProjectileMasking;
extern const WCHAR* PartialEnemyBulletMasking;

//UI 
extern const WCHAR* PartialUiBackground;
extern const WCHAR* PartialUiHpBarZero;
extern const WCHAR* PartialUiHpBar;
extern const WCHAR* PartialUiHpRed;
extern const WCHAR* partialUiHpBlack;
extern const WCHAR* PartialUiHpBarZeroMasking;
extern const WCHAR* PartialUiHpBarMasking;
extern const WCHAR* PartialUi;
extern const WCHAR* PartialUiMasking;

////const
//플레이어 이미지 프레임 포인트 애니메이션용 
extern const int PlayerPlaneFramePoint[10];
extern const int PlayerPlaneFrameEndPoint[2];

//스크린 크기
extern const int ScreenSizeX;
extern const int ScreenSizeY;

//배경 스크롤 속도
extern const float BgScrollSpeed;

//plane speed
extern const float PlaneSpeed;

//projectile speed
extern const float PlayerProjectileSpeed;

//const for GunClass
extern const int NumBullet;
extern const float ProjectileFramePoint[16];
extern const float ProjectileMarginForPlayerPlane[2];
extern const float BulletSpeed;

//const for UI

extern const float UiBackGround[4];
extern const float UiBackGroundPos[2];
extern const float UiBarBlack[4];
extern const float UiBarBlood[4];
extern const float UiBarOne[4];
extern const float UiBarZero[4];
extern const float UiHpBarPos[2];
