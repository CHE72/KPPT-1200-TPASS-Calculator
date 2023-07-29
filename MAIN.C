#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const float ver = 1.1;  // 宣告全域浮點常數：程式版本號
int ID, mode;  // 宣告全域整數變數函數：使用者身分、模式選擇代碼
int tpbus_half_times, tpbus_full_times, tpbus_half_fare, tpbus_full_fare;  
  // 宣告全域整數變數函數：大臺北公車半價次數、大臺北公車全價次數、大臺北公車半價價格、大臺北公車全價價格
int tpmrt_times, tpmrt_fare, tpbus_times, tpbus_fare;  
  // 宣告全域整數變數函數：北捷總搭乘次數、北捷總搭乘價格、大臺北公車總搭乘次數、大臺北公車總搭乘價格
char tpmrt_discount[] = "00%";  // 宣告全域字元陣列：臺北捷運常客優惠折扣
int ntmrt_fare, ntmrt_times, tra_fare, tra_times;
  // 宣告全域整數變數函數：新北捷總搭乘次數、新北捷總搭乘價格、臺鐵總搭乘次數、臺鐵總搭乘價格
int tymrt_fare, tymrt_times, temp_fare, temp_times;
  // 宣告全域整數變數函數：桃捷總搭乘次數、桃捷總搭乘價格、搭乘次數緩存、搭乘價格緩存
int tkbus_fare, tkbus_times, intercity_fare, intercity_times;
  // 宣告全域整數變數函數：桃基公車總搭乘次數、桃基公車總搭乘價格、公路客運總搭乘次數、公路客運總搭乘價格
int total_fare; // 宣告全域整數變數函數：最終總花費

int tpmrt(int def_fare)  // 定義 1：臺北捷運 資料輸入函式，def_fare為在函式內使用的參數，表示 臺北捷運 票價
{
	int times;  // 宣告區域整數變數函數：輸入次數暫存
	fflush(stdin);  // 清除緩衝區資料
	printf("本月搭 臺北捷運 %d 元次數：", def_fare);  // 詢問在 (def_fare) 元下，用戶搭乘 臺北捷運 次數
	scanf_s("%d", &times);  //接收使用者輸入至 區域次數暫存 變數
	if (times > 0)  // 如果 輸入次數 大於0
	{
		printf("本月搭乘 %d 元 臺北捷運 %d 次\n\n", def_fare, times);  // 列印使用者輸入內容
	}
	else if (times == 0)  // 如果 輸入次數 等於0
	{
		printf("這個月沒有搭乘 %d 元 的 臺北捷運\n\n", def_fare);  // 列印使用者輸入內容
	}
	else  // 其他情況
	{
		printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
		system("pause");  // 暫停程式運行
		exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
	}
	return(times);  // 返還得到的次數結果
}

int tpbus(int def_fare)  // 定義 3：大臺北地區公車 資料輸入函式，def_fare為在函式內使用的參數，表示 大臺北地區公車 票價
{
	int times;  // 宣告區域整數變數函數：輸入次數暫存
	fflush(stdin);  // 清除緩衝區資料
	printf("本月搭 大臺北地區公車 %d 元次數：", def_fare);  // 詢問在 (def_fare) 元下，用戶搭乘 大臺北地區公車 次數
	scanf_s("%d", &times);  //接收使用者輸入至 區域次數暫存 變數
	if (times > 0)  // 如果 輸入次數 大於0
	{
		printf("本月搭 %d 元 大臺北地區公車 %d 次\n", def_fare, times);  // 列印使用者輸入內容
	}
	else if (times == 0)  // 如果 輸入次數 等於0
	{
		printf("這個月沒有搭乘 %d 元 的 大臺北地區公車\n", def_fare);  // 列印使用者輸入內容
	}
	else  // 其他情況
	{
		printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
		system("pause");  // 暫停程式運行
		exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
	}
	return(times);  // 返還得到的次數結果
}

void zero_exit()  // 定義常見行為：輸出訊息：以 0 表示返回
{
	printf("以下所有問題請依照提示輸入「半形數字」回答，輸入「0次」或「0元」會返回模式選擇平臺\n\n");
}

void zero_times()  // 定義常見行為：輸出訊息：以 0 表示繼續
{
	printf("以下所有問題請依照提示輸入「半形數字」回答，如沒有次數請輸入「0」\n\n");
}

void pause_exit(exit_code)  // 定義退出程序的函數， exit_code 參數表明退出原因
{
	system("pause");  // 暫停程式運行
	exit(exit_code);  // 退出程序
}

void main()  // 定義主程式區塊
{
	  /* 定義各個運輸工具的 搭乘次數與累積票價 初始值為 0，緩存次數與票價 初始值為 0， */
	ntmrt_fare = ntmrt_times = tra_fare = tra_times = tymrt_fare = tymrt_times = 0;
	tkbus_fare = tkbus_times = intercity_fare = intercity_times = temp_fare = temp_times = 0;

	printf("歡迎您使用「基北北桃1200都會通定期票」計算程式\n");  // 輸出歡迎訊息
	printf("KPPT 1200 TPASS Calculator Ver%g ( C Language ) Made by CHE_72 ZStudio\n", ver);  // 輸出版權訊息
	printf("本程式可用來計算購買「1200都會通定期票」是否划算，程式將計算出結果。\n\n");  // 輸出程式目的
	printf("以下所有問題請依照提示輸入「半形數字」回答\n\n");  // 輸出使用規範

	input_ID:  // 定義 輸入_身分選擇 區塊
	printf("這裡是身分輸入平臺，請問您是用何種卡片？\n");  // 詢問使用者身分
	printf("1：普通卡、2：學生卡、9：完全退出程序 --> ");  // 輸出可使用的選項
	scanf_s("%d", &ID);  //接收使用者輸入至 使用者身分 變數
	switch (ID)  // 根據 使用者身分 變數判斷
	{
	case 0:  // 身分0：小彩蛋身分
		printf("\n恭喜您成功觸發一個小彩蛋，祝您天天 0 煩惱\a\n");  // 輸出小彩蛋訊息， \a 為 溢出字元 警告聲
		printf("現在即將為您重新導引至身分輸入平臺\n\n");  // 輸出功能訊息
		goto input_ID;  // 跳到 身分選擇區塊
	case 1:  // 身分1：普通卡
		printf("您目前正在使用：普通卡\n");  // 輸出使用者身分
		tpbus_half_fare = 7, tpbus_full_fare = 15;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 2:  // 身分2：學生卡
		printf("您目前正在使用：學生卡\n");  // 輸出使用者身分
		tpbus_half_fare = 6, tpbus_full_fare = 12;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 9:  // 身分9：完全退出程序
		printf("\n收到您的請求，正在結束程序\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	default:  // 其他情況
		printf("\n輸入無效，程式即將結束\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_FAILURE);  // 調用退出程序（程式異常退出）
	}

	input_mode:  // 定義 輸入_模式選擇平臺 區塊
	printf("\n這裡是模式選擇平臺，請問您現在要進入何種模式？\n");  // 詢問使用者身分
	printf("0：退出輸入模式，開始計算總金額、1：臺北捷運、2：新北捷運/輕軌、3：大臺北地區公車、4：臺灣鐵路、5：桃園捷運、6：桃園/基隆公車、7：公路客運、9：完全退出程序 --> ");
	  // 詢問使用者欲使用功能
	scanf_s("%d", &mode);  //接收使用者輸入至 模式選擇 變數
	switch (mode)  // 根據 模式選擇 變數判斷
	{
	case 0:  // 模式0：退出輸入模式，開始計算總金額
	{
		printf("\n正在退出輸入模式，進入最終計算\n\n");  // 輸出功能訊息
		goto output_calculate;  // 跳到 輸出_計算 區塊
	}
	case 1:  // 模式1：臺北捷運
	{
		printf("\n目前正在輸入：模式1：臺北捷運\n");  // 列印使用者輸入內容
		printf("以下的輸入內容皆只有 臺北捷運 的原價\n如果有遇上 大臺北地區公車 轉乘優惠 的折扣\n請輸入在 模式2：大臺北地區公車 的半價次數\n");  // 輸出使用規範
		zero_times();  // 輸出 0繼續 訊息
		  /* 調用 臺北捷運 資料輸入函式 */
		for (int tpmrt_out = 20; tpmrt_out <= 65; tpmrt_out = tpmrt_out + 5)
		{
			int tpmrt_in;
			tpmrt_in = tpmrt(tpmrt_out);
			tpmrt_times = tpmrt_times + tpmrt_in;  // 計算用戶搭乘 臺北捷運 的總次數
			tpmrt_fare = tpmrt_fare + tpmrt_in * tpmrt_out;  // 計算用戶搭乘 臺北捷運 的總票價
		}

		if (tpmrt_times != 0)  // 如果 搭乘 臺北捷運 的總次數 不為 0
		{
			printf("請稍後，正在為您計算 臺北捷運 的常客優惠\n");  // 輸出功能訊息
			if (11 <= tpmrt_times <= 20)  // 累計搭乘次數在 11~20 次時，有 10% 回饋
			{
				tpmrt_fare = tpmrt_fare * 9 / 10;  // 總和票價為原總和票價的 90%
				strcpy_s(tpmrt_discount, 5, "10%");  // 更改字元陣列為 10%
			}
			else if (21 <= tpmrt_times <= 30)  // 累計搭乘次數在 21~30 次時，有 15% 回饋
			{
				tpmrt_fare = tpmrt_fare * 17 / 20;  // 總和票價為原總和票價的 85%
				strcpy_s(tpmrt_discount, 5, "15%");  // 更改字元陣列為 15%
			}
			else if (31 <= tpmrt_times <= 40)  // 累計搭乘次數在 31~40 次時，有 20% 回饋
			{
				tpmrt_fare = tpmrt_fare * 4 / 5;  // 總和票價為原總和票價的 80%
				strcpy_s(tpmrt_discount, 5, "20%");  // 更改字元陣列為 20%
			}
			else if (41 <= tpmrt_times <= 50)  // 累計搭乘次數在 41~50 次時，有 25% 回饋
			{
				tpmrt_fare = tpmrt_fare * 3 / 4;  // 總和票價為原總和票價的 75%
				strcpy_s(tpmrt_discount, 5, "25%");  // 更改字元陣列為 25%
			}
			else  // 累計搭乘次數超過50次時，有30% 回饋
			{
				tpmrt_fare = tpmrt_fare * 7 / 10;  // 總和票價為原總和票價的 70%
				strcpy_s(tpmrt_discount, 5, "30%");  // 更改字元陣列為 30%
			}
			/* 列印使用者搭乘臺北捷運的總次數與獲得的常客優惠折扣 */
			printf("本月搭乘 %d 次 臺北捷運，獲得了 ", tpmrt_times);
			for (int i = 0; i < strlen(tpmrt_discount); i++)  // 使用迴圈方式逐一顯示字元
				printf("%c", tpmrt_discount[i]);
			printf(" 的回饋，花費 %d 元\n\n", tpmrt_fare);
		}
		else  // 其他情況
			printf("本月完全沒有搭乘臺北捷運\n\n");  // 列印使用者輸入內容
		goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
	}
	case 2:  // 模式2：新北捷運/輕軌
	{
		printf("\n目前正在輸入：模式2： 新北捷運/輕軌\n");  // 列印使用者輸入內容
		zero_exit();  // 輸出 0退出 訊息
	input_ntmrt:  // 定義 輸入_新北捷運/輕軌 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 新北捷運/輕軌 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n正在為您統計本月搭乘 新北捷運/輕軌 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 新北捷運/輕軌，花費 %d 元\n\n", ntmrt_times, ntmrt_fare);  // 列印使用者輸入內容
			printf("正在返回至模式選擇平臺\n\n");  // 輸出功能訊息
			goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
		}
		else
		{
			fflush(stdin);  // 清除緩衝區資料
			printf("本月搭 新北捷運/輕軌 %d 元次數 ---> ", temp_fare);  // 詢問在 價格緩存 元下，用戶搭乘 新北捷運/輕軌 次數
			scanf_s("%d", &temp_times);  //接收使用者輸入至 次數緩存 變數
			if (temp_times == 0)  // 如果 輸入次數 等於0
			{
				printf("這個月沒有搭乘 %d 元 的 新北捷運/輕軌，正在為您統計數據\n", temp_fare);  // 列印使用者輸入內容
				printf("本月搭乘 %d 次 新北捷運/輕軌，最後花費 %d 元\n\n", ntmrt_times, ntmrt_fare);
				printf("正在返回至運輸工具選擇平臺\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("本月搭 %d 元 新北捷運/輕軌 %d 次\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				ntmrt_times = ntmrt_times + temp_times;  // 計算用戶搭乘 新北捷運/輕軌 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				ntmrt_fare = ntmrt_fare + temp_fare * temp_times;  // 計算用戶搭乘 新北捷運/輕軌 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_ntmrt;  // 跳到 輸入_新北捷運/輕軌 區塊
			}
			else  // 其他情況
			{
				printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}		
		}
	}
	case 3:  // 模式3：大臺北地區公車
	{
		printf("\n目前正在輸入：模式3：大臺北地區公車\n");  // 列印使用者輸入內容
		printf("以下的輸入內容是依據公車搭乘費用\n %d 元為半價， %d 元為全價\n\n", tpbus_half_fare, tpbus_full_fare);  // 輸出功能訊息
		  /* 調用 大臺北地區公車 資料輸入函式 */
		tpbus_half_times = tpbus(tpbus_half_fare);
		tpbus_full_times = tpbus(tpbus_full_fare);
		tpbus_times = tpbus_half_times + tpbus_full_times;  // 計算用戶搭乘公車的總次數
		tpbus_fare = tpbus_half_times * tpbus_half_fare + tpbus_full_times * tpbus_full_fare;  // 計算用戶搭乘公車的總票價
		printf("本月一共搭乘 %d 次 大臺北地區公車，花費 %d 元\n\n", tpbus_times,tpbus_fare);  // 列印使用者搭乘公車的總次數與總票價
		goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
	}
	case 4:  // 模式4：臺灣鐵路
	{
		printf("\n目前正在輸入：模式4： 臺灣鐵路\n");  // 列印使用者輸入內容
		printf("溫馨提示：本 1200定期票 只適用於 進、出站 皆在 基北北桃 的臺鐵車站\n詳情請至臺灣鐵路官方網站查詢\n");  // 輸出提示訊息
		zero_exit();  // 輸出 0退出 訊息
	input_tra:  // 定義 輸入_臺灣鐵路 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 臺灣鐵路 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n正在為您統計本月搭乘 臺灣鐵路 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 臺灣鐵路，花費 %d 元\n\n", tra_times, tra_fare);  // 列印使用者輸入內容
			printf("正在返回至模式選擇平臺\n\n");  // 輸出功能訊息
			goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
		}
		else
		{
			fflush(stdin);  // 清除緩衝區資料
			printf("本月搭 臺灣鐵路 %d 元次數 ---> ", temp_fare);  // 詢問在 價格緩存 元下，用戶搭乘 臺灣鐵路 次數
			scanf_s("%d", &temp_times);  //接收使用者輸入至 次數緩存 變數
			if (temp_times == 0)  // 如果 輸入次數 等於0
			{
				printf("這個月沒有搭乘 %d 元 的 臺灣鐵路，正在為您統計數據\n", temp_fare);  // 列印使用者輸入內容
				printf("本月搭乘 %d 次 臺灣鐵路，最後花費 %d 元\n\n", tra_times, tra_fare);
				printf("正在返回至運輸工具選擇平臺\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("本月搭 %d 元 臺灣鐵路 %d 次\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				tra_times = tra_times + temp_times;  // 計算用戶搭乘 臺灣鐵路 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				tra_fare = tra_fare + temp_fare * temp_times;  // 計算用戶搭乘 臺灣鐵路 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_tra;  // 跳到 輸入_臺灣鐵路 區塊
			}
			else  // 其他情況
			{
				printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 5:  // 模式5：桃園捷運
	{
		printf("\n目前正在輸入：模式5： 桃園捷運\n");  // 列印使用者輸入內容
		zero_exit();  // 輸出 0退出 訊息
	input_tymrt:  // 定義 輸入_桃園捷運 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 桃園捷運 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n正在為您統計本月搭乘 桃園捷運 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 桃園捷運，花費 %d 元\n\n", tymrt_times, tymrt_fare);  // 列印使用者輸入內容
			printf("正在返回至模式選擇平臺\n\n");  // 輸出功能訊息
			goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
		}
		else
		{
			fflush(stdin);  // 清除緩衝區資料
			printf("本月搭 桃園捷運 %d 元次數 ---> ", temp_fare);  // 詢問在 價格緩存 元下，用戶搭乘 桃園捷運 次數
			scanf_s("%d", &temp_times);  //接收使用者輸入至 次數緩存 變數
			if (temp_times == 0)  // 如果 輸入次數 等於0
			{
				printf("這個月沒有搭乘 %d 元 的 桃園捷運，正在為您統計數據\n", temp_fare);  // 列印使用者輸入內容
				printf("本月搭乘 %d 次 桃園捷運，最後花費 %d 元\n\n", tymrt_times, tymrt_fare);
				printf("正在返回至運輸工具選擇平臺\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("本月搭 %d 元 桃園捷運 %d 次\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				tymrt_times = tymrt_times + temp_times;  // 計算用戶搭乘 桃園捷運 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				tymrt_fare = tymrt_fare + temp_fare * temp_times;  // 計算用戶搭乘 桃園捷運 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_tymrt;  // 跳到 輸入_桃園捷運 區塊
			}
			else  // 其他情況
			{
				printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 6:  // 模式6：桃園/基隆公車
	{
		printf("\n目前正在輸入：模式6： 桃園/基隆公車\n");  // 列印使用者輸入內容
		zero_exit();  // 輸出 0退出 訊息
	input_tkbus:  // 定義 輸入_桃園/基隆公車 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 桃園/基隆公車 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n正在為您統計本月搭乘 桃園/基隆公車 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 桃園/基隆公車，花費 %d 元\n\n", tkbus_times, tkbus_fare);  // 列印使用者輸入內容
			printf("正在返回至模式選擇平臺\n\n");  // 輸出功能訊息
			goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
		}
		else
		{
			fflush(stdin);  // 清除緩衝區資料
			printf("本月搭 桃園/基隆公車 %d 元次數 ---> ", temp_fare);  // 詢問在 價格緩存 元下，用戶搭乘 桃園/基隆公車 次數
			scanf_s("%d", &temp_times);  //接收使用者輸入至 次數緩存 變數
			if (temp_times == 0)  // 如果 輸入次數 等於0
			{
				printf("這個月沒有搭乘 %d 元 的 桃園/基隆公車，正在為您統計數據\n", temp_fare);  // 列印使用者輸入內容
				printf("本月搭乘 %d 次 桃園/基隆公車，最後花費 %d 元\n\n", tkbus_times, tkbus_fare);
				printf("正在返回至運輸工具選擇平臺\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("本月搭 %d 元 桃園/基隆公車 %d 次\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				tkbus_times = tkbus_times + temp_times;  // 計算用戶搭乘 桃園/基隆公車 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				tkbus_fare = tkbus_fare + temp_fare * temp_times;  // 計算用戶搭乘 桃園/基隆公車 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_tkbus;  // 跳到 輸入_桃園/基隆公車 區塊
			}
			else  // 其他情況
			{
				printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 7:  // 模式7：公路客運
	{
		printf("\n目前正在輸入：模式7： 公路客運\n");  // 列印使用者輸入內容
		printf("溫馨提示：本 1200定期票 只適用於 上、下車站點 皆在 基北北桃 的公路客運\n\n");  // 輸出提示訊息
		zero_exit();  // 輸出 0退出 訊息
	input_intercity:  // 定義 輸入_公路客運 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 公路客運 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n正在為您統計本月搭乘 公路客運 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 公路客運，花費 %d 元\n\n", intercity_times, intercity_fare);  // 列印使用者輸入內容
			printf("正在返回至模式選擇平臺\n\n");  // 輸出功能訊息
			goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
		}
		else
		{
			fflush(stdin);  // 清除緩衝區資料
			printf("本月搭 公路客運 %d 元次數 ---> ", temp_fare);  // 詢問在 價格緩存 元下，用戶搭乘 公路客運 次數
			scanf_s("%d", &temp_times);  //接收使用者輸入至 次數緩存 變數
			if (temp_times == 0)  // 如果 輸入次數 等於0
			{
				printf("這個月沒有搭乘 %d 元 的 公路客運，正在為您統計數據\n", temp_fare);  // 列印使用者輸入內容
				printf("本月搭乘 %d 次 公路客運，最後花費 %d 元\n\n", intercity_times, intercity_fare);
				printf("正在返回至運輸工具選擇平臺\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("本月搭 %d 元 公路客運 %d 次\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				intercity_times = intercity_times + temp_times;  // 計算用戶搭乘 公路客運 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				intercity_fare = intercity_fare + temp_fare * temp_times;  // 計算用戶搭乘 公路客運 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_intercity;  // 跳到 輸入_公路客運 區塊
			}
			else  // 其他情況
			{
				printf("輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 8:  // 模式8：小彩蛋模式
	{
		printf("\n恭喜您成功觸發一個小彩蛋，祝您天天發發發\n");  // 輸出小彩蛋訊息
		printf("現在即將為您重新導引至模式選擇平臺\n");  // 輸出功能訊息
		goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
	}
	case 9:  // 模式9：完全退出程序
	{
		printf("\n收到您的請求，正在結束程序\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	}
	default:  // 其他情況
	{
		printf("\n輸入無效，程式即將結束\a\n\n");  // 輸出程式退出訊息，\a 為 溢出字元 警告聲
		pause_exit(EXIT_FAILURE);  // 調用退出程序（程式異常退出）
	}
	}

	output_calculate:  // 定義 輸出_計算 區塊
	total_fare = tpmrt_fare + ntmrt_fare + tpbus_fare + tra_fare + tymrt_fare + tkbus_fare + intercity_fare;  // 計算 使用者輸入 的總票價
	if (total_fare == 0)  // 如果 總票價 等於0
	{
		printf("本月不用花錢，正在準備退出程序\a\n\n");  // 沒有計算的必要，直接提示退出程序， \a 為 溢出字元 警告聲
		goto stop_success;  // 跳到 輸出_成功結束 區塊
	}
	  /* 輸出詳細的搭乘次數與總票價，供使用者參考 */
	printf("本月一共搭乘 %d次 臺北捷運，%d次 新北捷運/輕軌，%d次 大臺北地區公車，\n", tpmrt_times, ntmrt_times, tpbus_times);
	printf("%d次 臺灣鐵路，%d次 桃園捷運，%d次 桃園/基隆公車，%d次 公路客運，\n", tra_times, tymrt_times, tkbus_times, intercity_times);
	printf("一共花費 %d 元\n\n", total_fare);
	
	/* 判斷是否購買 基北北桃1200都會通定期票 */
	if (1200 < total_fare)  // 如果總票價 > 1200元
		printf("本月要買定期票，須花費 1200 元，可省下 %d 元\n", total_fare - 1200);  // 建議購買 基北北桃1200都會通定期票
	else if (1200 == total_fare)  // 如果總票價 = 1200元
		printf("本月無論是否購買定期票，皆要花費 1200 元\n");  // 可自由決定是否要購買定期票
	else  // 如果總票價 < 1200元
		printf("本月直接刷卡即可，總共花費 %d 元\n", total_fare);  // 建議不要購買定期票，直接刷卡即可

	printf("計算完成，按下任意鍵以結束程式\a\n\n");  // 提示用戶這個程式已經運行完畢了， \a 為 溢出字元 警告聲
	
	stop_success:  // 定義 輸出_成功結束 區塊
	printf("感謝您使用「基北北桃1200都會通定期票」計算程式\n");  // 輸出感謝訊息
	printf("KPPT 1200 TPASS Calculator Ver%3.1f ( C Language ) Made by CHE_72 ZStudio\a\n\n", ver);  // 輸出版權訊息
	pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
}
