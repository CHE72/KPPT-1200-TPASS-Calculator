#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include "..\ZH_Input.h"  // 此標頭檔定義了 中文使用者輸入
#include "..\TPBus.h"  // 此標頭檔定義了 大臺北地區公車 資料輸入
#include "..\Output.h"  // 此標頭檔定義了 各種輸出內容
#include "..\Exit.h"  // 此標頭檔定義了 程式如何結束

void ZH_tpbus()  // 定義 中文功能3：大臺北地區公車 資料顯示函式
{
	printf("\n\033[38;5;43m目前正在輸入：功能3：大臺北地區公車\033[0m\n");  // 列印中文使用者輸入內容
	printf("\033[38;5;208m以下的輸入內容是依據公車搭乘費用\n %d 元為半價， %d 元為全價\n如果乘車情形為兩段票或以上，請作為 2 次一段票輸入\033[0m\n", tpbus_half_fare, tpbus_full_fare);  // 輸出中文功能訊息
	ZH_zero_times();  // 調用 中文訊息：0表示繼續 輸出函式
	/* 調用 中文功能3：大臺北地區公車 資料輸入函式 */
	tpbus_half_times = ZH_tpbus_Input(tpbus_half_fare);
	tpbus_full_times = ZH_tpbus_Input(tpbus_full_fare);
	tpbus_times = tpbus_times + tpbus_half_times + tpbus_full_times;  // 計算用戶搭乘公車的總次數
	tpbus_fare = tpbus_fare + tpbus_half_times * tpbus_half_fare + tpbus_full_times * tpbus_full_fare;  // 計算用戶搭乘公車的總票價
	printf("\033[38;5;45m本月一共搭乘 %d 次 大臺北地區公車，花費 %d 元\033[0m\n\n", tpbus_times, tpbus_fare);  // 列印中文使用者搭乘公車的總次數與總票價
}