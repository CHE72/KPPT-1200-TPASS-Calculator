#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include "Exit.h"  // 此標頭檔定義了 程式如何結束

void pause_exit(exit_code)  // 定義退出程序的函數， exit_code 參數表明退出原因
{
	system("pause");  // 暫停程式運行
	exit(exit_code);  // 退出程序
}