#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_tra()  // �w�q ����\��4�G�O�W�K�� ��ƿ�J�禡
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��4�G�O�W�K��\033[0m\n");  // �C�L����ϥΪ̿�J���e
	printf("\033[38;5;208m���ɴ��ܡG�� 1200�w���� �u�A�Ω� �i�B�X�� �Ҧb ��_�_�� ���O�K����\n");  // ��X���崣�ܰT��
	printf("�ϥ� 1200�w���� �A���o�f���[���C���B����C���B�Ӿ|�զC���B���y���C���B3000���۱j���Ψ�L�O�W�K���޲z�����w�C��(��M�ݩʤΤ��o��L�y�����C��)�C\n");
	printf("�Ա��ЦܻO�W�K���޲z���x������d��\033[0m\n");
	ZH_zero_exit();  // �ե� ����T���G0��ܪ�^ ��X�禡
input_tra:  // �w�q ��J_�O�W�K�� �϶�
	printf("�аݱz�Q��J�����h�֤������ --> ");  // �߰ݤ���Τ����J���f�� �O�W�K�� ���B
	scanf_s("%d", &temp_fare);  //�����ϥΪ̿�J�� ����w�s �ܼ�
	if (temp_fare == 0)  // �p�G ��J���B ����0
	{
		printf("\n\033[38;5;45m���b���z�έp����f�� �O�W�K�� �ƾ�\n");  // ��X����\��T��
		printf("����f�� %d �� �O�W�K���A��O %d ��\033[0m\n\n", tra_times, tra_fare);  // �C�L����ϥΪ̿�J���e
		printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
	}
	else
	{
		fflush(stdin);  // �M���w�İϸ��
		printf("����f �O�W�K�� %d ������ ---> ", temp_fare);  // �߰ݦb ����w�s ���U�A����Τ�f�� �O�W�K�� ����
		scanf_s("%d", &temp_times);  //�����ϥΪ̿�J�� ���ƽw�s �ܼ�
		if (temp_times == 0)  // �p�G ��J���� ����0
		{
			printf("�o�Ӥ�S���f�� %d �� �� �O�W�K���A���b���z�έp�ƾ�\n", temp_fare);;  // �C�L����ϥΪ̿�J���e
			printf("\033[38;5;45m����f�� %d �� �O�W�K���A�̫��O %d ��\033[0m\n\n", tra_times, tra_fare);
			printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
		}
		else if (temp_times > 0)  // �p�G ��J���� �j��0
		{
			printf("\033[38;5;111m����f %d �� �O�W�K�� %d ��\033[0m\n\n", temp_fare, temp_times);  // �C�L����ϥΪ̿�J���e
			tra_times = tra_times + temp_times;  // �p��Τ�f�� �O�W�K�� ���`���ơ]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			tra_fare = tra_fare + temp_fare * temp_times;  // �p��Τ�f�� �O�W�K�� ���`�����]�Y�ϥΪ̴���J�L�A��ƾڤ��|�Q�л\�^
			goto input_tra;  // ���� ��J_�O�W�K�� �϶�
		}
		else  // ��L���p
		{
			printf("\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
		}
	}
}