#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include <string.h>  // 此標頭檔其中定義了 更改字元陣列的函示
#include "..\ZH_Input.h"  // 此標頭檔定義了 中文使用者輸入
#include "..\Output.h"  // 此標頭檔定義了 各種輸出內容
#include "..\Exit.h"  // 此標頭檔定義了 程式如何結束

void ZH_tpmrt()  // 定義 中文功能1：臺北捷運 資料輸入函式
{
	printf("\n\033[38;5;43m目前正在輸入：功能1：臺北捷運\033[0m\n");  // 列印中文使用者輸入內容
	printf("\033[38;5;208m以下的輸入內容皆只有 臺北捷運 的原價\n如果有遇上 各式其他交通工具 轉乘優惠 的折扣\n請輸入在 對應交通工具 的價錢區域\033[0m\n");  // 輸出中文使用規範
	ZH_zero_times();  // 調用 中文訊息：0表示繼續 輸出函式
	for (int tpmrt_out = 20; tpmrt_out <= 65; tpmrt_out = tpmrt_out + 5)  // 定義輸出給使用者(金額)的區域變數 (使用 for 迴圈以減少資源占用)
	{
		int tpmrt_in;  // 定義讓使用者輸入(次數)的區域變數
		fflush(stdin);  // 清除緩衝區資料
		printf("本月搭 臺北捷運 %d 元次數：", tpmrt_out);  // 詢問在 (tpmrt_out) 元下，用戶搭乘 臺北捷運 次數
		scanf_s("%d", &tpmrt_in);  //接收使用者輸入至 輸入(次數) 區域變數
		if (tpmrt_in > 0)  // 如果 輸入次數 大於0
		{
			printf("\033[38;5;111m本月搭乘 %d 元 臺北捷運 %d 次\033[0m\n\n", tpmrt_out, tpmrt_in);  // 列印使用者輸入內容
		}
		else if (tpmrt_in == 0)  // 如果 輸入次數 等於0
		{
			printf("\033[38;5;111m這個月沒有搭乘 %d 元 的 臺北捷運\033[0m\n\n", tpmrt_out);  // 列印使用者輸入內容
		}
		else  // 其他情況
		{
			printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出中文錯誤訊息， \a 為 溢出字元 警告聲
			system("pause");  // 暫停程式運行
			exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
		}
		tpmrt_times = tpmrt_times + tpmrt_in;  // 計算用戶搭乘 臺北捷運 的總次數
		tpmrt_fare = tpmrt_fare + tpmrt_in * tpmrt_out;  // 計算用戶搭乘 臺北捷運 的總票價
	}

	if (tpmrt_times != 0)  // 如果 搭乘 臺北捷運 的總次數 不為 0
	{
		printf("\033[38;5;45m請稍後，正在為您計算 臺北捷運 的常客優惠\n");  // 輸出中文功能訊息
		if (11 <= tpmrt_times && tpmrt_times <= 20)  // 累計搭乘次數在 11~20 次時，有 10% 回饋
		{
			tpmrt_fare = tpmrt_fare * 9 / 10;  // 總和票價為原總和票價的 90%
			strcpy_s(tpmrt_discount, 5, "10%");  // 更改字元陣列為 10%
		}
		else if (21 <= tpmrt_times && tpmrt_times <= 30)  // 累計搭乘次數在 21~30 次時，有 15% 回饋
		{
			tpmrt_fare = tpmrt_fare * 17 / 20;  // 總和票價為原總和票價的 85%
			strcpy_s(tpmrt_discount, 5, "15%");  // 更改字元陣列為 15%
		}
		else if (31 <= tpmrt_times && tpmrt_times <= 40)  // 累計搭乘次數在 31~40 次時，有 20% 回饋
		{
			tpmrt_fare = tpmrt_fare * 4 / 5;  // 總和票價為原總和票價的 80%
			strcpy_s(tpmrt_discount, 5, "20%");  // 更改字元陣列為 20%
		}
		else if (41 <= tpmrt_times && tpmrt_times <= 50)  // 累計搭乘次數在 41~50 次時，有 25% 回饋
		{
			tpmrt_fare = tpmrt_fare * 3 / 4;  // 總和票價為原總和票價的 75%
			strcpy_s(tpmrt_discount, 5, "25%");  // 更改字元陣列為 25%
		}
		else  // 累計搭乘次數超過50次時，有30% 回饋
		{
			tpmrt_fare = tpmrt_fare * 7 / 10;  // 總和票價為原總和票價的 70%
			strcpy_s(tpmrt_discount, 5, "30%");  // 更改字元陣列為 30%
		}
		/* 列印中文使用者搭乘臺北捷運的總次數與獲得的常客優惠折扣 */
		printf("本月搭乘 %d 次 臺北捷運，獲得了 ", tpmrt_times);
		for (int i = 0; i < strlen(tpmrt_discount); i++)  // 使用迴圈方式逐一顯示字元
			printf("%c", tpmrt_discount[i]);
		printf(" 的回饋，花費 %d 元\033[0m\n\n", tpmrt_fare);
	}
	else  // 其他情況
		printf("\033[38;5;45m本月完全沒有搭乘臺北捷運\033[0m\n\n");  // 列印中文使用者輸入內容
	printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出中文功能訊息
}
