#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_intercity()  // �w�q ����\��7�G�����ȹB ��ƿ�J�禡 ���Φ�
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��7�G�����ȹB\033[0m\n");  // �C�L����ϥΪ̿�J���e
	printf("\033[38;5;208m���ɴ��ܡG�� 1200�w���� �u�A�Ω� �W�B�U�����I �Ҧb ��_�_�� �������ȹB\033[0m\n");  // ��X���崣�ܰT��
	ZH_zero_exit();  // �ե� ����T���G0��ܪ�^ ��X�禡
input_intercity:  // �w�q ��J_�����ȹB �϶�
	printf("�аݱz�Q��J�����h�֤������ --> ");  // �߰ݤ���Τ����J���f�� �����ȹB ���B
	scanf_s("%d", &temp_fare);  //�����ϥΪ̿�J�� ����w�s �ܼ�
	if (temp_fare == 0)  // �p�G ��J���B ����0
	{
		printf("\n\033[38;5;45m���b���z�έp����f�� �����ȹB �ƾ�\n");  // ��X����\��T��
		printf("����f�� %d �� �����ȹB�A��O %d ��\033[0m\n\n", intercity_times, intercity_fare);  // �C�L����ϥΪ̿�J���e
		printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
	}
	else
	{
		fflush(stdin);  // �M���w�İϸ��
		printf("����f �����ȹB %d ������ ---> ", temp_fare);  // �߰ݦb ����w�s ���U�A����Τ�f�� �����ȹB ����
		scanf_s("%d", &temp_times);  //�����ϥΪ̿�J�� ���ƽw�s �ܼ�
		if (temp_times == 0)  // �p�G ��J���� ����0
		{
			printf("�o�Ӥ�S���f�� %d �� �� �����ȹB�A���b���z�έp�ƾ�\n", temp_fare);  // �C�L����ϥΪ̿�J���e
			printf("\033[38;5;45m����f�� %d �� �����ȹB�A�̫��O %d ��\033[0m\n\n", intercity_times, intercity_fare);
			printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
		}
		else if (temp_times > 0)  // �p�G ��J���� �j��0
		{
			printf("\033[38;5;111m����f %d �� �����ȹB %d ��\033[0m\n\n", temp_fare, temp_times);  // �C�L����ϥΪ̿�J���e
			intercity_times = intercity_times + temp_times;  // �p��Τ�f�� �����ȹB ���`���ơ]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			intercity_fare = intercity_fare + temp_fare * temp_times;  // �p��Τ�f�� �����ȹB ���`�����]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			goto input_intercity;  // ���� ��J_�����ȹB �϶�
		}
		else  // ��L���p
		{
			printf("\n\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
		}
	}
}