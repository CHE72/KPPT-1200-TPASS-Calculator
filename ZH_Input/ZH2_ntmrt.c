#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_ntmrt()  // �w�q ����\��2�G�s�_���B/���y ��ƿ�J�禡
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��2�G�s�_���B/���y\033[0m\n");  // �C�L����ϥΪ̿�J���e
	ZH_zero_exit();  // �ե� ����T���G0��ܪ�^ ��X�禡
input_ntmrt:  // �w�q ��J_�s�_���B/���y �϶�
	printf("�аݱz�Q��J�����h�֤������ --> ");  // �߰ݤ���Τ����J���f�� �s�_���B/���y ���B
	scanf_s("%d", &temp_fare);  //�����ϥΪ̿�J�� ����w�s �ܼ�
	if (temp_fare == 0)  // �p�G ��J���B ����0
	{
		printf("\n\033[38;5;45m���b���z�έp����f�� �s�_���B/���y �ƾ�\n");  // ��X����\��T��
		printf("����f�� %d �� �s�_���B/���y�A��O %d ��\033[0m\n\n", ntmrt_times, ntmrt_fare);  // �C�L����ϥΪ̿�J���e
		printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
	}
	else
	{
		fflush(stdin);  // �M���w�İϸ��
		printf("����f �s�_���B/���y %d ������ ---> ", temp_fare);  // �߰ݦb ����w�s ���U�A����Τ�f�� �s�_���B/���y ����
		scanf_s("%d", &temp_times);  //�����ϥΪ̿�J�� ���ƽw�s �ܼ�
		if (temp_times == 0)  // �p�G ��J���� ����0
		{
			printf("�o�Ӥ�S���f�� %d �� �� �s�_���B/���y�A���b���z�έp�ƾ�\n", temp_fare);  // �C�L����ϥΪ̿�J���e
			printf("\033[38;5;45m����f�� %d �� �s�_���B/���y�A�̫��O %d ��\033[0m\n\n", ntmrt_times, ntmrt_fare);
			printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
		}
		else if (temp_times > 0)  // �p�G ��J���� �j��0
		{
			printf("\033[38;5;111m����f %d �� �s�_���B/���y %d ��\033[0m\n\n", temp_fare, temp_times);  // �C�L����ϥΪ̿�J���e
			ntmrt_times = ntmrt_times + temp_times;  // �p��Τ�f�� �s�_���B/���y ���`���ơ]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			ntmrt_fare = ntmrt_fare + temp_fare * temp_times;  // �p��Τ�f�� �s�_���B/���y ���`�����]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			goto input_ntmrt;  // ���� ��J_�s�_���B/���y �϶�
		}
		else  // ��L���p
		{
			printf("\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
		}
	}
}
