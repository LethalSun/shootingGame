#pragma once
////�̹��� ����

//���
extern const WCHAR* PartialBG;

//�����
extern const WCHAR* PartialPlane;
extern const WCHAR* PartialPlaneMask;
extern const WCHAR* PartialEnemy;
extern const WCHAR* PartialEnemyMasking;
extern const WCHAR* PartialEnemy2;
extern const WCHAR* PartialEnemyMasking2;

//�̻��
extern const WCHAR* PartialEngineGlow;
extern const WCHAR* PartialEngineGlowMask;
extern const WCHAR* PartialProjectilePlayer;
extern const WCHAR* PartialExplosion;

//�Ѿ�
extern const WCHAR* PartialPlayerProjectile;
extern const WCHAR* PartialEnemyBullet;
extern const WCHAR* PartialPlayerProjectileMasking;
extern const WCHAR* PartialEnemyBulletMasking;
extern const WCHAR* PartialEnemyBullet2;
extern const WCHAR* PartialEnemyBulletMasking2;

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
//�÷��̾� �̹��� ������ ����Ʈ �ִϸ��̼ǿ� 
extern const int PlayerPlaneFramePoint[10];
extern const int PlayerPlaneFrameEndPoint[2];
extern const int PlayerCollideRadius[4];
//��ũ�� ũ��
extern const int ScreenSizeX;
extern const int ScreenSizeY;

//��� ��ũ�� �ӵ�
extern const float BgScrollSpeed;

//plane speed
extern const float PlaneSpeed;

//max hp
extern const int MaxHp;
extern const int EnemyHp;
//projectile speed
extern const float PlayerProjectileSpeed;

//const for GunClass
extern const int NumBullet;
extern const float ProjectileFramePoint[16];
extern const float ProjectileMarginForPlayerPlane[2];
extern const float ProjectileMarginForEnemyPlane[2];
extern const float BulletSpeed;
extern const float EnemyProjectileFramePoint[8];

//const for UI

extern const float UiBackGround[4];
extern const float UiBackGroundPos[2];
extern const float UiBarBlack[4];
extern const float UiBarBlood[4];
extern const float UiBarOne[4];
extern const float UiBarZero[4];
extern const float UiHpBarPos[2];

//const for Enemy
extern const float EnemySmallX[12];
extern const float EnemySmallRest[3];

//const for EnemyManagerClass;
extern const float EnemyShipFrame[16];
extern const int EnemyShipRadius[4];
extern const float EnemyBulletFrame[44];
extern const int EnemyBulletRadius[11];
extern const float EnemyBulletMargin[16];

extern const int PlayerBulletRadius[4];