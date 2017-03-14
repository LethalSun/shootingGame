#pragma once
class Input
{
private:
	enum InputDefine
	{
		VK_A =  0x41,
		VK_B =	0x42,
		VK_C =	0x43,
		VK_D =	0x44,
		VK_E =	0x45,
		VK_F =	0x46,
		VK_G =	0x47,
		VK_H =	0x48,
		VK_I =	0x49,
		VK_J =	0x4A,
		VK_K =	0x4B,
		VK_L =	0x4C,
		VK_M =	0x4D,
		VK_N =	0x4E,
		VK_O =	0x4F,
		VK_P =	0x50,
		VK_Q =	0x51,
		VK_R =	0x52,
		VK_S =	0x53,
		VK_T =	0x54,
		VK_U =	0x55,
		VK_V =	0x56,
		VK_W =	0x57,
		VK_X =	0x58,
		VK_Y =	0x59,
		VK_Z =	0x5A,
		FREEKEY	= 0x10,
		PULLKEY	= 0x20,
		PUSHKEY	= 0x40,
		HOLDKEY = 0x80,
	};

	enum State
	{
		TOP = 1,
		RIGHT = 2,
		BOTTOM = 4,
		LEFT = 8,
		ATTACK = 16,
		SKILL1 = 32,
		SKILL2 = 64
	};

public:

	Input();
	~Input();

	int GetInputFlag();

private:
	//member
	int bitFlagInput;
	BYTE	byOldKey[256];
	BYTE	byKey[256];

	//method
	int GetKeyInput();
	int interpreteKeyInput();


};
