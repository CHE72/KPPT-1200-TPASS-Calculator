#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "..\ZH_Input.h"  // �����Y�ɩw�q�F ����ϥΪ̿�J
#include "..\TPBus.h"  // �����Y�ɩw�q�F �j�O�_�a�Ϥ��� ��ƿ�J
#include "..\Output.h"  // �����Y�ɩw�q�F �U�ؿ�X���e
#include "..\Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void ZH_tpbus()  // �w�q ����\��3�G�j�O�_�a�Ϥ��� �����ܨ禡
{
	printf("\n\033[38;5;43m�ثe���b��J�G�\��3�G�j�O�_�a�Ϥ���\033[0m\n");  // �C�L����ϥΪ̿�J���e
	printf("\033[38;5;208m�H�U����J���e�O�̾ڤ����f���O��\n %d �����b���A %d ��������\n�p�G�������ά���q���ΥH�W�A�Ч@�� 2 ���@�q����J\033[0m\n", tpbus_half_fare, tpbus_full_fare);  // ��X����\��T��
	ZH_zero_times();  // �ե� ����T���G0����~�� ��X�禡
	/* �ե� ����\��3�G�j�O�_�a�Ϥ��� ��ƿ�J�禡 */
	tpbus_half_times = ZH_tpbus_Input(tpbus_half_fare);
	tpbus_full_times = ZH_tpbus_Input(tpbus_full_fare);
	tpbus_times = tpbus_times + tpbus_half_times + tpbus_full_times;  // �p��Τ�f���������`����
	tpbus_fare = tpbus_fare + tpbus_half_times * tpbus_half_fare + tpbus_full_times * tpbus_full_fare;  // �p��Τ�f���������`����
	printf("\033[38;5;45m����@�@�f�� %d �� �j�O�_�a�Ϥ����A��O %d ��\033[0m\n\n", tpbus_times, tpbus_fare);  // �C�L����ϥΪ̷f���������`���ƻP�`����
}