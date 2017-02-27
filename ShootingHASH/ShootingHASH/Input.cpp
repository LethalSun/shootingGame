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
			//Ű�� �������� ��
			if (byKey[i] & InputDefine::HOLDKEY)
			{
				//������ �������� �Ⱦ�����
				if (!byOldKey[i])
				{
					//������ �����ִٰ� üũ�ϰ�
					byOldKey[i] = 1;
					//������ ������ �����ѻ���
					byKey[i] = InputDefine::PUSHKEY;
				}
				//������ �������� Ȧ�� ����
			}
			//������ �ʾ��� ��
			else
			{
				//���� Ű�� �����־��ٸ�
				if (byOldKey[i])
				{
					//���� Ű�� �������� �ʴٰ� �ϰ�
					byOldKey[i] = 0;
					//Ű�� �ٷ� �� ����
					byKey[i] = InputDefine::PULLKEY;
				}
				//�������� �ʴٸ�
				else
				{
					//Ű�� ������ ���� ����
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
		// C�� ���ȴٸ�
	}
	if (byKey['X'] & PUSHKEY)
	{
		bitFlagInput += SKILL1;
		// Z �� ���ȴٸ�
	}
	if (byKey['Z'] & PUSHKEY)
	{
		bitFlagInput += SKILL2;
		// Z�� �����ٰ� �������
	}

	if (byKey[VK_UP] & HOLDKEY)
	{
		bitFlagInput += TOP;
		// ���� ȭ��ǥ ������ ��
	}
	else if (byKey[VK_DOWN] & HOLDKEY)
	{
		bitFlagInput += BOTTOM;
		// �Ʒ��� ȭ��ǥ ������ ��
	}

	if (byKey[VK_LEFT] & HOLDKEY)
	{
		bitFlagInput += LEFT;
		// ���� ȭ��ǥ ������ ��
	}
	else if (byKey[VK_RIGHT] & HOLDKEY)
	{
		bitFlagInput += RIGHT;
		// ������ ȭ��ǥ ������ ��
	}

	return bitFlagInput;
}
