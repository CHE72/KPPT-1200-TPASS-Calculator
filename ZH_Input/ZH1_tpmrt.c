#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include <string.h>  // �����Y�ɨ䤤�w�q�F ���r���}�C�����
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_tpmrt()  // �w�q ����\��1�G�O�_���B ��ƿ�J�禡
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��1�G�O�_���B\033[0m\n");  // �C�L����ϥΪ̿�J���e
	printf("\033[38;5;208m�H�U����J���e�ҥu�� �O�_���B �����\n�p�G���J�W �U����L��q�u�� �୼�u�f ���馩\n�п�J�b ������q�u�� �������ϰ�\033[0m\n");  // ��X����ϥγW�d
	ZH_zero_times();  // �ե� ����T���G0����~�� ��X�禡
	for (int tpmrt_out = 20; tpmrt_out <= 65; tpmrt_out = tpmrt_out + 5)  // �w�q��X���ϥΪ�(���B)���ϰ��ܼ� (�ϥ� for �j��H��ָ귽�e��)
	{
		int tpmrt_in;  // �w�q���ϥΪ̿�J(����)���ϰ��ܼ�
		fflush(stdin);  // �M���w�İϸ��
		printf("����f �O�_���B %d �����ơG", tpmrt_out);  // �߰ݦb (tpmrt_out) ���U�A�Τ�f�� �O�_���B ����
		scanf_s("%d", &tpmrt_in);  //�����ϥΪ̿�J�� ��J(����) �ϰ��ܼ�
		if (tpmrt_in > 0)  // �p�G ��J���� �j��0
		{
			printf("\033[38;5;111m����f�� %d �� �O�_���B %d ��\033[0m\n\n", tpmrt_out, tpmrt_in);  // �C�L�ϥΪ̿�J���e
		}
		else if (tpmrt_in == 0)  // �p�G ��J���� ����0
		{
			printf("\033[38;5;111m�o�Ӥ�S���f�� %d �� �� �O�_���B\033[0m\n\n", tpmrt_out);  // �C�L�ϥΪ̿�J���e
		}
		else  // ��L���p
		{
			printf("\033[38;5;197m��J���e�X�{���~�A�{���Y�N����\a\n\n");  // ��X������~�T���A \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{�ǡ]�{�����`�h�X�^
		}
		tpmrt_times = tpmrt_times + tpmrt_in;  // �p��Τ�f�� �O�_���B ���`����
		tpmrt_fare = tpmrt_fare + tpmrt_in * tpmrt_out;  // �p��Τ�f�� �O�_���B ���`����
	}

	if (tpmrt_times != 0)  // �p�G �f�� �O�_���B ���`���� ���� 0
	{
		printf("\033[38;5;45m�еy��A���b���z�p�� �O�_���B ���`���u�f\n");  // ��X����\��T��
		if (11 <= tpmrt_times && tpmrt_times <= 20)  // �֭p�f�����Ʀb 11~20 ���ɡA�� 10% �^�X
		{
			tpmrt_fare = tpmrt_fare * 9 / 10;  // �`�M���������`�M������ 90%
			strcpy_s(tpmrt_discount, 5, "10%");  // ���r���}�C�� 10%
		}
		else if (21 <= tpmrt_times && tpmrt_times <= 30)  // �֭p�f�����Ʀb 21~30 ���ɡA�� 15% �^�X
		{
			tpmrt_fare = tpmrt_fare * 17 / 20;  // �`�M���������`�M������ 85%
			strcpy_s(tpmrt_discount, 5, "15%");  // ���r���}�C�� 15%
		}
		else if (31 <= tpmrt_times && tpmrt_times <= 40)  // �֭p�f�����Ʀb 31~40 ���ɡA�� 20% �^�X
		{
			tpmrt_fare = tpmrt_fare * 4 / 5;  // �`�M���������`�M������ 80%
			strcpy_s(tpmrt_discount, 5, "20%");  // ���r���}�C�� 20%
		}
		else if (41 <= tpmrt_times && tpmrt_times <= 50)  // �֭p�f�����Ʀb 41~50 ���ɡA�� 25% �^�X
		{
			tpmrt_fare = tpmrt_fare * 3 / 4;  // �`�M���������`�M������ 75%
			strcpy_s(tpmrt_discount, 5, "25%");  // ���r���}�C�� 25%
		}
		else  // �֭p�f�����ƶW�L50���ɡA��30% �^�X
		{
			tpmrt_fare = tpmrt_fare * 7 / 10;  // �`�M���������`�M������ 70%
			strcpy_s(tpmrt_discount, 5, "30%");  // ���r���}�C�� 30%
		}
		/* �C�L����ϥΪ̷f���O�_���B���`���ƻP��o���`���u�f�馩 */
		printf("����f�� %d �� �O�_���B�A��o�F ", tpmrt_times);
		for (int i = 0; i < strlen(tpmrt_discount); i++)  // �ϥΰj��覡�v�@��ܦr��
			printf("%c", tpmrt_discount[i]);
		printf(" ���^�X�A��O %d ��\033[0m\n\n", tpmrt_fare);
	}
	else  // ��L���p
		printf("\033[38;5;45m���맹���S���f���O�_���B\033[0m\n\n");  // �C�L����ϥΪ̿�J���e
	printf("\033[38;5;43m���b��^�ܼҦ���ܥ��O\033[0m\n\n");  // ��X����\��T��
}
