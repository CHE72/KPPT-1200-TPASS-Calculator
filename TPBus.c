#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "TPBus.h"  // �����Y�ɨ䤤�w�q�F �����M�ο�J�禡
#include "Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

int ZH_tpbus_Input(int def_fare)  // �w�q ����\��3�G�j�O�_�a�Ϥ��� ��ƿ�J�禡�Adef_fare���b�禡���ϥΪ��ѼơA��� �j�O�_�a�Ϥ��� ����
{
	int times;  // �ŧi�ϰ����ܼƨ�ơG��J���ƼȦs
	fflush(stdin);  // �M���w�İϸ��
	printf("����f �j�O�_�a�Ϥ��� %d �����ơG", def_fare);  // �߰ݦb (def_fare) ���U�A����Τ�f�� �j�O�_�a�Ϥ��� ����
	scanf_s("%d", &times);  //�����ϥΪ̿�J�� �ϰ즸�ƼȦs �ܼ�
	if (times > 0)  // �p�G ��J���� �j��0
	{
		printf("\033[38;5;111m����f %d �� �j�O�_�a�Ϥ��� %d ��\033[0m\n", def_fare, times);  // �C�L����ϥΪ̿�J���e
	}
	else if (times == 0)  // �p�G ��J���� ����0
	{
		printf("�o�Ӥ�S���f�� %d �� �� �j�O�_�a�Ϥ���\n", def_fare);  // �C�L����ϥΪ̿�J���e
	}
	else  // ��L���p
	{
		printf("\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
		system("pause");  // �Ȱ��{���B��
		exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
	}
	return(times);  // ���ٱo�쪺���Ƶ��G
}

int EN_tpbus_Input(int def_fare)  // �w�q �^��\��3�G�j�O�_�a�Ϥ��� ��ƿ�J�禡�Adef_fare���b�禡���ϥΪ��ѼơA��� �j�O�_�a�Ϥ��� ����
{
	int times;  // �ŧi�ϰ����ܼƨ�ơG��J���ƼȦs
	fflush(stdin);  // �M���w�İϸ��
}