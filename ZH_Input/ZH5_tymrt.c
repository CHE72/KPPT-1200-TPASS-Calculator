#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_tymrt()  // �w�q ����\��5�G��鱶�B ��ƿ�J�禡
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��5�G��鱶�B\033[0m\n");  // �C�L����ϥΪ̿�J���e
	ZH_zero_exit();  // �ե� ����T���G0��ܪ�^ ��X�禡
input_tymrt:  // �w�q ��J_��鱶�B �϶�
	printf("�аݱz�Q��J�����h�֤������ --> ");  // �߰ݤ���Τ����J���f�� ��鱶�B ���B
	scanf_s("%d", &temp_fare);  //�����ϥΪ̿�J�� ����w�s �ܼ�
	if (temp_fare >= 165)  // �p�G ��J���B ����0
	{
		printf("\033[38;5;197m�z����J���G���X�z�A��鱶�B�ثe���O�̰����W�L 160 ��\n�бz�T�{�n�f���϶������᭫�s��J\033[0m\n\n");  // ��X����\��T��
		goto input_tymrt;  // ���� ��J_��鱶�B �϶�
	}
	if (temp_fare == 0)  // �p�G ��J���B ����0
	{
		printf("\n\033[38;5;45m���b���z�έp����f�� ��鱶�B �ƾ�\n");  // ��X����\��T��
		printf("����f�� %d �� ��鱶�B�A��O %d ��\033[0m\n\n", tymrt_times, tymrt_fare);  // �C�L����ϥΪ̿�J���e
		printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
	}
	else
	{
		fflush(stdin);  // �M���w�İϸ��
		printf("����f ��鱶�B %d ������ ---> ", temp_fare);  // �߰ݦb ����w�s ���U�A����Τ�f�� ��鱶�B ����
		scanf_s("%d", &temp_times);  //�����ϥΪ̿�J�� ���ƽw�s �ܼ�
		if (temp_times == 0)  // �p�G ��J���� ����0
		{
			printf("�o�Ӥ�S���f�� %d �� �� ��鱶�B�A���b���z�έp�ƾ�\n", temp_fare);  // �C�L����ϥΪ̿�J���e
			printf("\033[38;5;45m����f�� %d �� ��鱶�B�A�̫��O %d ��\033[0m\n\n", tymrt_times, tymrt_fare);
			printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
		}
		else if (temp_times > 0)  // �p�G ��J���� �j��0
		{
			printf("\033[38;5;111m����f %d �� ��鱶�B %d ��\033[0m\n\n", temp_fare, temp_times);  // �C�L����ϥΪ̿�J���e
			tymrt_times = tymrt_times + temp_times;  // �p��Τ�f�� ��鱶�B ���`���ơ]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			tymrt_fare = tymrt_fare + temp_fare * temp_times;  // �p��Τ�f�� ��鱶�B ���`�����]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			goto input_tymrt;  // ���� ��J_��鱶�B �϶�
		}
		else  // ��L���p
		{
			printf("\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
		}
	}
}