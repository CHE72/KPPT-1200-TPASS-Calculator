#include <stdio.h>
#include <stdlib.h>

int bus_half_times, bus_full_times, bus_half_fare, bus_full_fare;  // �ŧi�����ơG�����b�����ơB�����������ơB�����b������B������������
int metro_times, metro_fare, bus_times, bus_fare;  // �ŧi�����ơG���B�`�f�����ơB���B�`�f������B�����`�f�����ơB�����`�f������
int total_fare; // �ŧi�����ơG�̲��`��O

int metro(int def_fare)  // �w�q���B�禡�Adef_fare���b�禡���ϥΪ��ѼơA��ܱ��B����
{
	int times;
	fflush(stdin);
	printf("����f���B %d �����ơG", def_fare);
	scanf_s("%d", &times);  // �߰ݦb (def_fare) ���U�A�Τ�f�����B����
	if (times > 0)
	{
		printf("����f���B %d �� %d ��\n\n", def_fare, times);  // �C�L�ϥΪ̿�J���e
	}
	else if (times == 0)
	{
		printf("�o�Ӥ�S���f�� %d �������B\n\n", def_fare);  // �C�L�ϥΪ̿�J���e
	}
	else
	{
		printf("��J���e�X�{���~�A�{���Y�N����\a\n\n");
		system("pause");  // �Ȱ��{���B��
		exit(EXIT_FAILURE);  // �h�X�{��
	}
	return(times);  // ���ٱo�쪺���Ƶ��G
}

int bus(int def_fare)  // �w�q���B�禡�Adef_fare���b�禡���ϥΪ��ѼơA��ܱ��B����
{
	int times;
	fflush(stdin);
	printf("����f���� %d �����ơG", def_fare);
	scanf_s("%d", &times);  // �߰ݦb (def_fare) ���U�A�Τ�f�����B����
	if (times > 0)
	{
		printf("����f���� %d �� %d ��\n\n", def_fare, times);  // �C�L�ϥΪ̿�J���e
	}
	else if (times == 0)
	{
		printf("�o�Ӥ�S���f�� %d ��������\n\n", def_fare);  // �C�L�ϥΪ̿�J���e
	}
	else
	{
		printf("��J���e�X�{���~�A�{���Y�N����\a\n\n");
		system("pause");  // �Ȱ��{���B��
		exit(EXIT_FAILURE);  // �h�X�{��
	}
	return(times);  // ���ٱo�쪺���Ƶ��G
}

void main()
{
	printf("�w��ϥΡu1280���@�B��w�����v�p��{�� Made by CHE_72 ZStudio\n");
	printf("���{���i�Ψӭp���ʶR1280���@�B��w�����O�_�E��A�{���N�p��X���G�C\n\n");
	printf("�Ш̥H�U���D��J�u�b�μƦr�v�^���A�p�S�����ƽп�J�u0�v�C\n\n");
	
	int ID;  // �ŧi �ϥΪ̨��� ����ܼ�
	printf("�аݱz�O�Φ�إd���H\n");  // �߰ݨϥΪ̨���
	printf("0�G���q�d�B1�G�ǥͥd -->");
	scanf_s("%d", &ID);
	switch (ID)
	{
		case 0:
			printf("�z�ثe���b�ϥΡG���q�d\n\n");
			bus_half_times = bus(7);
			bus_full_times = bus(15);
			bus_half_fare, bus_full_fare = 7, 15;
			break;
		case 1:
			printf("�z�ثe���b�ϥΡG�ǥͥd\n\n");
			bus_half_times = bus(6);
			bus_full_times = bus(12);
			bus_half_fare, bus_full_fare = 6, 12;
			break;
		default:
			printf("��J�L�ġA�{���Y�N����\a\n\n");  // \a �� ���X�r�� ĵ�i�n
			system("pause");  // �Ȱ��{���B��
			exit(EXIT_FAILURE);  // �h�X�{��
	}
	
	int m20 = metro(20), m25 = metro(25);
	int m30 = metro(30), m35 = metro(35);
	int m40 = metro(40), m45 = metro(45);
	int m50 = metro(50), m55 = metro(55);
	int m60 = metro(60), m65 = metro(65);

	metro_times = m20 + m25 + m30 + m35 + m40 + m45 + m50 + m55 + m60 + m65;  // �p��Τ�f�����B���`����
	bus_times = bus_half_times + bus_full_times;  // �p��Τ�f���������`����
	if (metro_times + bus_times == 0)  // �p�G�f�������α��B���`�M��0��
	{
		printf("���뤣�Ϊ���A���b�ǳưh�X�{��\a\n\n");  // �S���p�⪺���n�A�������ܰh�X�{��
		system("pause");  // �Ȱ��{���B��
		exit(EXIT_SUCCESS);  // �h�X�{��
	}
	printf("����f���B %d ��,���� %d ��\n", metro_times, bus_times);  // �C�L�ϥΪ̷f�������α��B���`����
		
	metro_fare = m20 * 20 + m25 * 25 + m30 * 30 + m35 * 35 + m40 * 40 + m45 * 45 + m50 * 50 + m55 * 55 + m60 * 60 + m65 * 65;
	/* �p��Τ�f�����B���`���� */
	bus_fare = bus_half_times * bus_half_fare + bus_full_times * bus_full_fare;  // �p��Τ�f���������`����

	if (metro_times <= 10)  // �֭p�f������ <= 10�ɡA�S������^�X
		total_fare = metro_fare + bus_fare;
	else if (11 <= metro_times <= 20)  // �֭p�f�����Ʀb11~20���ɡA��10 % �^�X
		total_fare = metro_fare * 9 / 10 + bus_fare;
	else if (21 <= metro_times <= 30)  // �֭p�f�����Ʀb21~30���ɡA��15 % �^�X
		total_fare = metro_fare * 17 / 20 + bus_fare;
	else if (31 <= metro_times <= 40)  // �֭p�f�����Ʀb31~40���ɡA��20 % �^�X
		total_fare = metro_fare * 4 / 5 + bus_fare;
	else if (41 <= metro_times <= 50)  // �֭p�f�����Ʀb41~50���ɡA��25 % �^�X
		total_fare = metro_fare * 3 / 4 + bus_fare;
	else  // �֭p�f�����ƶW�L50���ɡA��30% �^�X
		total_fare = metro_fare * 7 / 10 + bus_fare;

	printf("�@�@��O %d ��\n\n", total_fare);  // �L�X�ثe�p��X���`����

	if (1280 < total_fare)  // �p�G�`���� > 1280��
		printf("����n�R�w�����A����O 1280 ���A�i�٤U %d ��\n", total_fare - 1280);  // ��ĳ�ʶR1280�w����
	else if (1280 == total_fare)  // �p�G�`���� = 1280��
		printf("����L�׬O�_�ʶR�w�����A�ҭn��O 1280 ��\n");  // �i�ۥѨM�w�O�_�n�ʶR�w����
	else  // �p�G�`���� < 1280��
		printf("���몽����d�Y�i�A�`�@��O %d ��\n", total_fare);  // ��ĳ���n�ʶR�w�����A������d�Y�i

	printf("�p�⧹���A���U���N��H�����{��\a\n\n");  // ���ܥΤ�o�ӵ{���w�g�B�槹���F
	printf("�u1280���@�B��w�����v�p��{�� Made by CHE_72 ZStudio\n\n");
	system("pause");  // �Ȱ��{���B��
	exit(EXIT_SUCCESS);  // �h�X�{��
}