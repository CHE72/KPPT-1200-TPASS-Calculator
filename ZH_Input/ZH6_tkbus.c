#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_tkbus()  // �w�q ����\��6�G���/�򶩤��� ��ƿ�J�禡
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��6�G���/�򶩤���\033[0m\n");  // �C�L����ϥΪ̿�J���e
	ZH_zero_exit();  // �ե� ����T���G0��ܪ�^ ��X�禡
input_tkbus:  // �w�q ��J_���/�򶩤��� �϶�
	printf("�аݱz�Q��J�����h�֤������ --> ");  // �߰ݤ���Τ����J���f�� ���/�򶩤��� ���B
	scanf_s("%d", &temp_fare);  //�����ϥΪ̿�J�� ����w�s �ܼ�
	if (temp_fare == 0)  // �p�G ��J���B ����0
	{
		printf("\n\033[38;5;45m���b���z�έp����f�� ���/�򶩤��� �ƾ�\n");  // ��X����\��T��
		printf("����f�� %d �� ���/�򶩤����A��O %d ��\033[0m\n\n", tkbus_times, tkbus_fare);  // �C�L����ϥΪ̿�J���e
		printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
	}
	else
	{
		fflush(stdin);  // �M���w�İϸ��
		printf("����f ���/�򶩤��� %d ������ ---> ", temp_fare);  // �߰ݦb ����w�s ���U�A����Τ�f�� ���/�򶩤��� ����
		scanf_s("%d", &temp_times);  //�����ϥΪ̿�J�� ���ƽw�s �ܼ�
		if (temp_times == 0)  // �p�G ��J���� ����0
		{
			printf("�o�Ӥ�S���f�� %d �� �� ���/�򶩤����A���b���z�έp�ƾ�\n", temp_fare);  // �C�L����ϥΪ̿�J���e
			printf("\033[38;5;45m����f�� %d �� ���/�򶩤����A�̫��O %d ��\033[0m\n\n", tkbus_times, tkbus_fare);
			printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
		}
		else if (temp_times > 0)  // �p�G ��J���� �j��0
		{
			printf("\033[38;5;111m����f %d �� ���/�򶩤��� %d ��\033[0m\n\n", temp_fare, temp_times);  // �C�L����ϥΪ̿�J���e
			tkbus_times = tkbus_times + temp_times;  // �p��Τ�f�� ���/�򶩤��� ���`���ơ]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			tkbus_fare = tkbus_fare + temp_fare * temp_times;  // �p��Τ�f�� ���/�򶩤��� ���`�����]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			goto input_tkbus;  // ���� ��J_���/�򶩤��� �϶�
		}
		else  // ��L���p
		{
			printf("\n\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
		}
	}
}