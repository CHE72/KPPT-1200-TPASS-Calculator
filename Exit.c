#include <stdio.h>  // �����Y�ɨ䤤�w�q�F ��X�P��J�\��
#include <stdlib.h>  // �����Y�ɨ䤤�w�q�F �t�μȰ����O
#include "Exit.h"  // �����Y�ɩw�q�F �{���p�󵲧�

void pause_exit(exit_code)  // �w�q�h�X�{�Ǫ���ơA exit_code �Ѽƪ���h�X��]
{
	system("pause");  // �Ȱ��{���B��
	exit(exit_code);  // �h�X�{��
}