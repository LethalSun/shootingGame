#include "pch.h"
#include "Input.h"


Input::Input()
:byOldKey{0}
{
}


Input::~Input()
{
}

int Input::GetKeyInput()
{
	if (GetKeyboardState(byKey))
	{
		for (int i = 0; i < 256; i++)
		{
			//키가 눌려있을 때
			if (byKey[i] & InputDefine::HOLDKEY)
			{
				//직전에 눌려있지 안았으면
				if (!byOldKey[i])
				{
					//이전에 눌려있다고 체크하고
					byOldKey[i] = 1;
					//지금은 눌리기 시작한상태
					byKey[i] = InputDefine::PUSHKEY;
				}
				//직전에 눌렸으면 홀드 상태
			}
			//눌리지 않았을 때
			else
			{
				//이전 키가 눌려있었다면
				if (byOldKey[i])
				{
					//이전 키는 눌려있지 않다고 하고
					byOldKey[i] = 0;
					//키를 바로 떈 상태
					byKey[i] = InputDefine::PULLKEY;
				}
				//눌려있지 않다면
				else
				{
					//키가 눌리지 않은 상태
					byKey[i] = InputDefine::FREEKEY;
				}
			}
		}
	}

	
	return 0;
}

int Input::interpreteKeyInput()
{
	int bitFlagInput = 0;

	if (byKey['C'] & HOLDKEY)
	{
		bitFlagInput += ATTACK;
		// C가 눌렸다면
	}
	if (byKey['X'] & PUSHKEY)
	{
		bitFlagInput += SKILL1;
		// Z 가 눌렸다면
	}
	if (byKey['Z'] & PUSHKEY)
	{
		bitFlagInput += SKILL2;
		// Z를 눌렀다가 띄었을때
	}

	if (byKey[VK_UP] & HOLDKEY)
	{
		bitFlagInput += TOP;
		// 위쪽 화살표 누르는 중
	}
	else if (byKey[VK_DOWN] & HOLDKEY)
	{
		bitFlagInput += BOTTOM;
		// 아래쪽 화살표 누르는 중
	}

	if (byKey[VK_LEFT] & HOLDKEY)
	{
		bitFlagInput += LEFT;
		// 왼쪽 화살표 누르는 중
	}
	else if (byKey[VK_RIGHT] & HOLDKEY)
	{
		bitFlagInput += RIGHT;
		// 오른쪽 화살표 누르는 중
	}

	return bitFlagInput;
}
