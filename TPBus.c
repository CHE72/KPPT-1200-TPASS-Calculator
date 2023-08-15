#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include "TPBus.h"  // 此標頭檔其中定義了 公車專用輸入函式
#include "Exit.h"  // 此標頭檔定義了 程式如何結束

int ZH_tpbus_Input(int def_fare)  // 定義 中文功能3：大臺北地區公車 資料輸入函式，def_fare為在函式內使用的參數，表示 大臺北地區公車 票價
{
	int times;  // 宣告區域整數變數函數：輸入次數暫存
	fflush(stdin);  // 清除緩衝區資料
	printf("本月搭 大臺北地區公車 %d 元次數：", def_fare);  // 詢問在 (def_fare) 元下，中文用戶搭乘 大臺北地區公車 次數
	scanf_s("%d", &times);  //接收使用者輸入至 區域次數暫存 變數
	if (times > 0)  // 如果 輸入次數 大於0
	{
		printf("\033[38;5;111m本月搭 %d 元 大臺北地區公車 %d 次\033[0m\n", def_fare, times);  // 列印中文使用者輸入內容
	}
	else if (times == 0)  // 如果 輸入次數 等於0
	{
		printf("這個月沒有搭乘 %d 元 的 大臺北地區公車\n", def_fare);  // 列印中文使用者輸入內容
	}
	else  // 其他情況
	{
		printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出中文錯誤訊息， \a 為 溢出字元 警告聲
		system("pause");  // 暫停程式運行
		exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
	}
	return(times);  // 返還得到的次數結果
}

int EN_tpbus_Input(int def_fare)  // 定義 英文功能3：大臺北地區公車 資料輸入函式，def_fare為在函式內使用的參數，表示 大臺北地區公車 票價
{
	int times;  // 宣告區域整數變數函數：輸入次數暫存
	fflush(stdin);  // 清除緩衝區資料
}