#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const double ver = 1.160;  // 宣告全域浮點常數：程式版本號
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

//以下內容為函式原型宣告
int tpbus(int def_fare);
void zero_exit();
void zero_times();
void pause_exit(exit_code);
void en_license();
void zh_license();

/*  * 定義 printf 顏色的使用  ANSI 轉義碼
* 選擇訊息：\033[38;5;43m  * 提示訊息：\033[38;5;208m  * 退出訊息：\033[38;5;197m
* 輸入結果：\033[38;5;111m  * 小計結果：\033[38;5;45m  * 清除效果：\033[0m  */

void main()  // 定義主程式區塊
{
	  /* 定義各個運輸工具的 搭乘次數與累積票價 初始值為 0，緩存次數與票價 初始值為 0， */
	ntmrt_fare = ntmrt_times = tra_fare = tra_times = tymrt_fare = tymrt_times = 0;
	tkbus_fare = tkbus_times = intercity_fare = intercity_times = temp_fare = temp_times = 0;

	printf("歡迎您使用「基北北桃1200都會通定期票」計算程式\033[38;5;197m Ver%g \033[0m由 CHE_72 ZStudio 使用 C 語言製作\n", ver);  // 輸出歡迎訊息
	printf("Welcome to use KPPT 1200 TPASS Calculator\033[38;5;197m Ver%g \033[0m( C Language ) Made by CHE_72 ZStudio.\n\n", ver);  // 輸出版權訊息
	printf("\033[38;5;208m本程式可用來計算購買「1200都會通定期票」是否划算，程式將計算出結果。\n");  // 輸出程式目的
	printf("以下所有問題請依照提示輸入「半形數字」回答\033[0m\n\n");  // 輸出使用規範

	input_ID:  // 定義 輸入_身分選擇 區塊
	printf("這裡是「語言暨身分選擇平臺」，請問您是用何種卡片或是要瀏覽哪些程式資訊？\n");  // 詢問使用者身分
	printf("This is the \"Language and Identity Selection Platform\", what kind of card do you use or what program information do you wanna know ?\n");
	printf("1：普通卡(中文)、2：學生卡(中文)、3：Adult Card (English)、4：Student Card (English)、\n7：開源許可與版權宣告(中文)、8：Open Source Licenses & Copyright(English)、9：完全退出程序 / Exit this Program --> ");  // 輸出可使用的選項
	scanf_s("%d", &ID);  //接收使用者輸入至 使用者身分 變數
	switch (ID)  // 根據 使用者身分 變數判斷
	{
	case 0:  // 身分0：小彩蛋身分
		printf("\n\033[38;5;43m恭喜您成功觸發一個小彩蛋，祝您天天 0 煩惱\a\n");  // 輸出小彩蛋訊息， \a 為 溢出字元 警告聲
		printf("\033[38;5;43mThis is an Easter Egg. Wish you have no trobules every day.\a\n");
		printf("現在即將為您重新導引至身分輸入平臺\033[0m\n\n");  // 輸出功能訊息
		goto input_ID;  // 跳到 身分選擇區塊
	case 1:  // 身分1：普通卡(中文)
		printf("\033[38;5;43m您目前正在使用：普通卡\033[0m\n");  // 輸出使用者身分
		tpbus_half_fare = 7, tpbus_full_fare = 15;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 2:  // 身分2：學生卡(中文)
		printf("\033[38;5;43m您目前正在使用：學生卡\033[0m\n");  // 輸出使用者身分
		tpbus_half_fare = 6, tpbus_full_fare = 12;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 3:  // 身分3：Adult Card (English)
		printf("\n\033[38;5;197mThe content has not been fully constructed.\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	case 4:  // 身分4：Student Card (English)
		printf("\n\033[38;5;197mThe content has not been fully constructed.\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	case 7:  // 身分7：開源許可與版權宣告(中文)
		printf("\n\033[38;5;197mThe content has not been fully constructed.\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	case 8:  // 身分8：Open Source Licenses & Copyright(English)
		en_license();
		goto input_ID;
	case 9:  // 身分9：完全退出程序
		printf("\n\033[38;5;197m收到您的要求，正在結束程序\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	default:  // 其他情況
		printf("\n\033[38;5;197m輸入無效，程式即將結束\a\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		printf("\033[38;5;197mYour input is invalid, and the program will end soon.\a\n\n");
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
		printf("\n\033[38;5;43m正在退出輸入模式，進入最終計算\033[0m\n\n");  // 輸出功能訊息
		goto output_calculate;  // 跳到 輸出_計算 區塊
	}
	case 1:  // 模式1：臺北捷運
	{
		printf("\n\033[38;5;43m目前正在輸入：模式1：臺北捷運\033[0m\n");  // 列印使用者輸入內容
		printf("\033[38;5;208m以下的輸入內容皆只有 臺北捷運 的原價\n如果有遇上 大臺北地區公車 轉乘優惠 的折扣\n請輸入在 模式2：大臺北地區公車 的半價次數\033[0m\n");  // 輸出使用規範
		zero_times();  // 輸出 0繼續 訊息
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
				printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
			tpmrt_times = tpmrt_times + tpmrt_in;  // 計算用戶搭乘 臺北捷運 的總次數
			tpmrt_fare = tpmrt_fare + tpmrt_in * tpmrt_out;  // 計算用戶搭乘 臺北捷運 的總票價
		}

		if (tpmrt_times != 0)  // 如果 搭乘 臺北捷運 的總次數 不為 0
		{
			printf("\033[38;5;45m請稍後，正在為您計算 臺北捷運 的常客優惠\n");  // 輸出功能訊息
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
			/* 列印使用者搭乘臺北捷運的總次數與獲得的常客優惠折扣 */
			printf("本月搭乘 %d 次 臺北捷運，獲得了 ", tpmrt_times);
			for (int i = 0; i < strlen(tpmrt_discount); i++)  // 使用迴圈方式逐一顯示字元
				printf("%c", tpmrt_discount[i]);
			printf(" 的回饋，花費 %d 元\033[0m\n\n", tpmrt_fare);
		}
		else  // 其他情況
			printf("\033[38;5;45m本月完全沒有搭乘臺北捷運\033[0m\n\n");  // 列印使用者輸入內容
		printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出功能訊息
		goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
	}
	case 2:  // 模式2：新北捷運/輕軌
	{
		printf("\n\033[38;5;43m目前正在輸入：模式2： 新北捷運/輕軌\033[0m\n");  // 列印使用者輸入內容
		zero_exit();  // 輸出 0退出 訊息
	input_ntmrt:  // 定義 輸入_新北捷運/輕軌 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 新北捷運/輕軌 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n\033[38;5;45m正在為您統計本月搭乘 新北捷運/輕軌 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 新北捷運/輕軌，花費 %d 元\033[0m\n\n", ntmrt_times, ntmrt_fare);  // 列印使用者輸入內容
			printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出功能訊息
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
				printf("\033[38;5;45m本月搭乘 %d 次 新北捷運/輕軌，最後花費 %d 元\033[0m\n\n", ntmrt_times, ntmrt_fare);
				printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("\033[38;5;111m本月搭 %d 元 新北捷運/輕軌 %d 次\033[0m\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				ntmrt_times = ntmrt_times + temp_times;  // 計算用戶搭乘 新北捷運/輕軌 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				ntmrt_fare = ntmrt_fare + temp_fare * temp_times;  // 計算用戶搭乘 新北捷運/輕軌 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_ntmrt;  // 跳到 輸入_新北捷運/輕軌 區塊
			}
			else  // 其他情況
			{
				printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}		
		}
	}
	case 3:  // 模式3：大臺北地區公車
	{
		printf("\n\033[38;5;43m目前正在輸入：模式3：大臺北地區公車\033[0m\n");  // 列印使用者輸入內容
		printf("\033[38;5;208m以下的輸入內容是依據公車搭乘費用\n %d 元為半價， %d 元為全價\n如果乘車情形為兩段票或以上，請作為 2 次一段票輸入\033[0m\n\n", tpbus_half_fare, tpbus_full_fare);  // 輸出功能訊息
		  /* 調用 大臺北地區公車 資料輸入函式 */
		tpbus_half_times = tpbus(tpbus_half_fare);
		tpbus_full_times = tpbus(tpbus_full_fare);
		tpbus_times = tpbus_times + tpbus_half_times + tpbus_full_times;  // 計算用戶搭乘公車的總次數
		tpbus_fare = tpbus_fare + tpbus_half_times * tpbus_half_fare + tpbus_full_times * tpbus_full_fare;  // 計算用戶搭乘公車的總票價
		printf("\033[38;5;45m本月一共搭乘 %d 次 大臺北地區公車，花費 %d 元\033[0m\n\n", tpbus_times,tpbus_fare);  // 列印使用者搭乘公車的總次數與總票價
		goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
	}
	case 4:  // 模式4：臺灣鐵路
	{
		printf("\n\033[38;5;43m目前正在輸入：模式4： 臺灣鐵路\033[0m\n");  // 列印使用者輸入內容
		printf("\033[38;5;208m溫馨提示：本 1200定期票 只適用於 進、出站 皆在 基北北桃 的臺鐵車站\n");  // 輸出提示訊息
		printf("使用 1200定期票 ，不得搭乘觀光列車、團體列車、太魯閣列車、普悠瑪列車、3000型自強號及其他臺灣鐵路管理局指定列車(具專屬性及不發售無座票之列車)。\n");
		printf("詳情請至臺灣鐵路管理局官方網站查詢\033[0m\n\n");
		zero_exit();  // 輸出 0退出 訊息
	input_tra:  // 定義 輸入_臺灣鐵路 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 臺灣鐵路 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n\033[38;5;45m正在為您統計本月搭乘 臺灣鐵路 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 臺灣鐵路，花費 %d 元\033[0m\n\n", tra_times, tra_fare);  // 列印使用者輸入內容
			printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出功能訊息
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
				printf("\033[38;5;45m本月搭乘 %d 次 臺灣鐵路，最後花費 %d 元\033[0m\n\n", tra_times, tra_fare);
				printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("\033[38;5;111m本月搭 %d 元 臺灣鐵路 %d 次\033[0m\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				tra_times = tra_times + temp_times;  // 計算用戶搭乘 臺灣鐵路 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				tra_fare = tra_fare + temp_fare * temp_times;  // 計算用戶搭乘 臺灣鐵路 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_tra;  // 跳到 輸入_臺灣鐵路 區塊
			}
			else  // 其他情況
			{
				printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 5:  // 模式5：桃園捷運
	{
		printf("\n\033[38;5;43m目前正在輸入：模式5： 桃園捷運\033[0m\n");  // 列印使用者輸入內容
		zero_exit();  // 輸出 0退出 訊息
	input_tymrt:  // 定義 輸入_桃園捷運 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 桃園捷運 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare >= 165)  // 如果 輸入金額 等於0
		{
			printf("\033[38;5;197m您的輸入結果不合理，桃園捷運目前收費最高不超過 160 元\n請您確認好搭乘區間票價後重新輸入\033[0m\n\n");  // 輸出功能訊息
			goto input_tymrt;  // 跳到 輸入_桃園捷運 區塊
		}
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n\033[38;5;45m正在為您統計本月搭乘 桃園捷運 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 桃園捷運，花費 %d 元\033[0m\n\n", tymrt_times, tymrt_fare);  // 列印使用者輸入內容
			printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出功能訊息
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
				printf("\033[38;5;45m本月搭乘 %d 次 桃園捷運，最後花費 %d 元\033[0m\n\n", tymrt_times, tymrt_fare);
				printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("\033[38;5;111m本月搭 %d 元 桃園捷運 %d 次\033[0m\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				tymrt_times = tymrt_times + temp_times;  // 計算用戶搭乘 桃園捷運 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				tymrt_fare = tymrt_fare + temp_fare * temp_times;  // 計算用戶搭乘 桃園捷運 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_tymrt;  // 跳到 輸入_桃園捷運 區塊
			}
			else  // 其他情況
			{
				printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 6:  // 模式6：桃園/基隆公車
	{
		printf("\n\033[38;5;43m目前正在輸入：模式6： 桃園/基隆公車\033[0m\n");  // 列印使用者輸入內容
		zero_exit();  // 輸出 0退出 訊息
	input_tkbus:  // 定義 輸入_桃園/基隆公車 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 桃園/基隆公車 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n\033[38;5;45m正在為您統計本月搭乘 桃園/基隆公車 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 桃園/基隆公車，花費 %d 元\033[0m\n\n", tkbus_times, tkbus_fare);  // 列印使用者輸入內容
			printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出功能訊息
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
				printf("\033[38;5;45m本月搭乘 %d 次 桃園/基隆公車，最後花費 %d 元\033[0m\n\n", tkbus_times, tkbus_fare);
				printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("\033[38;5;111m本月搭 %d 元 桃園/基隆公車 %d 次\033[0m\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				tkbus_times = tkbus_times + temp_times;  // 計算用戶搭乘 桃園/基隆公車 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				tkbus_fare = tkbus_fare + temp_fare * temp_times;  // 計算用戶搭乘 桃園/基隆公車 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_tkbus;  // 跳到 輸入_桃園/基隆公車 區塊
			}
			else  // 其他情況
			{
				printf("\n\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 7:  // 模式7：公路客運
	{
		printf("\n\033[38;5;43m目前正在輸入：模式7： 公路客運\033[0m\n");  // 列印使用者輸入內容
		printf("\033[38;5;208m溫馨提示：本 1200定期票 只適用於 上、下車站點 皆在 基北北桃 的公路客運\033[0m\n\n");  // 輸出提示訊息
		zero_exit();  // 輸出 0退出 訊息
	input_intercity:  // 定義 輸入_公路客運 區塊
		printf("請問您想輸入票價多少元的資料 --> ");  // 詢問用戶欲輸入的搭乘 公路客運 金額
		scanf_s("%d", &temp_fare);  //接收使用者輸入至 價格緩存 變數
		if (temp_fare == 0)  // 如果 輸入金額 等於0
		{
			printf("\n\033[38;5;45m正在為您統計本月搭乘 公路客運 數據\n");  // 輸出功能訊息
			printf("本月搭乘 %d 次 公路客運，花費 %d 元\033[0m\n\n", intercity_times, intercity_fare);  // 列印使用者輸入內容
			printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 輸出功能訊息
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
				printf("\033[38;5;45m本月搭乘 %d 次 公路客運，最後花費 %d 元\033[0m\n\n", intercity_times, intercity_fare);
				printf("\033[38;5;43m正在返回至模式選擇平臺\033[0m\n\n");  // 列印使用者輸入內容
				goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
			}
			else if (temp_times > 0)  // 如果 輸入次數 大於0
			{
				printf("\033[38;5;111m本月搭 %d 元 公路客運 %d 次\033[0m\n\n", temp_fare, temp_times);  // 列印使用者輸入內容
				intercity_times = intercity_times + temp_times;  // 計算用戶搭乘 公路客運 的總次數（若使用者曾輸入過，原數據不會被覆蓋）
				intercity_fare = intercity_fare + temp_fare * temp_times;  // 計算用戶搭乘 公路客運 的總票價（若使用者曾輸入過，原數據不會被覆蓋）
				goto input_intercity;  // 跳到 輸入_公路客運 區塊
			}
			else  // 其他情況
			{
				printf("\n\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
				system("pause");  // 暫停程式運行
				exit(EXIT_FAILURE);  // 退出程序（程式異常退出）
			}
		}
	}
	case 8:  // 模式8：小彩蛋模式
	{
		printf("\n\033[38;5;43m恭喜您成功觸發一個小彩蛋，祝您天天發發發\n");  // 輸出小彩蛋訊息
		printf("\033[38;5;43mThis is an Easter Egg. Wish you have more and more money.\a\n");
		printf("現在即將為您重新導引至模式選擇平臺\033[0m\n");  // 輸出功能訊息
		goto input_mode;  // 跳到 輸入_模式選擇平臺 區塊
	}
	case 9:  // 模式9：完全退出程序
	{
		printf("\n\033[38;5;197m收到您的要求，正在結束程序\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
	}
	default:  // 其他情況
	{
		printf("\n\033[38;5;197m輸入無效，程式即將結束\a\n\n");  // 輸出程式退出訊息，\a 為 溢出字元 警告聲
		pause_exit(EXIT_FAILURE);  // 調用退出程序（程式異常退出）
	}
	}

	output_calculate:  // 定義 輸出_計算 區塊
	total_fare = tpmrt_fare + ntmrt_fare + tpbus_fare + tra_fare + tymrt_fare + tkbus_fare + intercity_fare;  // 計算 使用者輸入 的總票價
	if (total_fare == 0)  // 如果 總票價 等於0
	{
		printf("\033[38;5;197m本月不用花錢，正在準備退出程序\033[0m\a\n\n");  // 沒有計算的必要，直接提示退出程序， \a 為 溢出字元 警告聲
		goto stop_success;  // 跳到 輸出_成功結束 區塊
	}
	  /* 輸出詳細的搭乘次數、金額與總票價，供使用者參考 */
	printf("本月一共搭乘 %d次 臺北捷運 ( %d 元)，%d次 新北捷運/輕軌 ( %d 元)，%d次 大臺北地區公車 ( %d 元)，\n", tpmrt_times, tpmrt_fare, ntmrt_times, ntmrt_fare, tpbus_times, tpbus_fare);
	printf("%d次 臺灣鐵路 ( %d 元)，%d次 桃園捷運 ( %d 元)，%d次 桃園/基隆公車 ( %d 元)，%d次 公路客運 ( %d 元)\n", tra_times, tra_fare, tymrt_times, tymrt_fare, tkbus_times, tkbus_fare, intercity_times, intercity_fare);
	printf("一共花費 %d 元\n\n", total_fare);
	
	/* 判斷是否購買 基北北桃1200都會通定期票 */
	if (1200 < total_fare)  // 如果總票價 > 1200元
		printf("本月要買定期票，須花費 1200 元，可省下 %d 元\n", total_fare - 1200);  // 建議購買 基北北桃1200都會通定期票
	else if (1200 == total_fare)  // 如果總票價 = 1200元
		printf("本月無論是否購買定期票，皆要花費 1200 元\n");  // 可自由決定是否要購買定期票
	else  // 如果總票價 < 1200元
		printf("本月直接刷卡即可，總共花費 %d 元\n", total_fare);  // 建議不要購買定期票，直接刷卡即可

	printf("\033[38;5;197m計算完成，按下任意鍵以結束程式\033[0m\a\n\n");  // 提示用戶這個程式已經運行完畢了， \a 為 溢出字元 警告聲
	
	stop_success:  // 定義 輸出_成功結束 區塊
	printf("「基北北桃1200都會通定期票」計算程式\033[38;5;197m Ver%g \033[0m, Copyright (C) 2023-present CHE_72 ZStudio\n", ver);  // 輸出感謝訊息
	printf("KPPT 1200 TPASS Calculator\033[38;5;197m Ver%g \033[0m, Copyright (C) 2023-present CHE_72 ZStudio.\a\n\n", ver);  // 輸出版權訊息
	pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
}

int tpbus(int def_fare)  // 定義 3：大臺北地區公車 資料輸入函式，def_fare為在函式內使用的參數，表示 大臺北地區公車 票價
{
	int times;  // 宣告區域整數變數函數：輸入次數暫存
	fflush(stdin);  // 清除緩衝區資料
	printf("本月搭 大臺北地區公車 %d 元次數：", def_fare);  // 詢問在 (def_fare) 元下，用戶搭乘 大臺北地區公車 次數
	scanf_s("%d", &times);  //接收使用者輸入至 區域次數暫存 變數
	if (times > 0)  // 如果 輸入次數 大於0
	{
		printf("\033[38;5;111m本月搭 %d 元 大臺北地區公車 %d 次\033[0m\n", def_fare, times);  // 列印使用者輸入內容
	}
	else if (times == 0)  // 如果 輸入次數 等於0
	{
		printf("這個月沒有搭乘 %d 元 的 大臺北地區公車\n", def_fare);  // 列印使用者輸入內容
	}
	else  // 其他情況
	{
		printf("\033[38;5;197m輸入內容出現錯誤，程式即將結束\a\n\n");  // 輸出錯誤訊息， \a 為 溢出字元 警告聲
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

void en_license()
{
	printf("\nGNU General Public License version 2\n\n");
	printf("Copyright (C) 1989, 1991 Free Software Foundation, Inc.\n51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA\n\n");
	printf("Everyone is permitted to copy and distribute verbatim copies of this license document, but changing it is not allowed.\n\n");
	printf("Preamble\n\n");
	printf("The licenses for most software are designed to take away your freedom to share and change it. By contrast, the GNU General Public License is intended to guarantee your freedom to share and change free software–to make sure the software is free for all its users. This General Public License applies to most of the Free Software Foundation’s software and to any other program whose authors commit to using it. (Some other Free Software Foundation software is covered by the GNU Library General Public License instead.) You can apply it to your programs, too.\n\n");
	printf("When we speak of free software, we are referring to freedom, not price. Our General Public Licenses are designed to make sure that you have the freedom to distribute copies of free software (and charge for this service if you wish), that you receive source code or can get it if you want it, that you can change the software or use pieces of it in new free programs; and that you know you can do these things.\n\n");
	printf("To protect your rights, we need to make restrictions that forbid anyone to deny you these rights or to ask you to surrender the rights. These restrictions translate to certain responsibilities for you if you distribute copies of the software, or if you modify it.\n\n");
	printf("For example, if you distribute copies of such a program, whether gratis or for a fee, you must give the recipients all the rights that you have. You must make sure that they, too, receive or can get the source code. And you must show them these terms so they know their rights.\n\n");
	printf("We protect your rights with two steps: (1) copyright the software, and (2) offer you this license which gives you legal permission to copy, distribute and/or modify the software.\n\n");
	printf("Also, for each author’s protection and ours, we want to make certain that everyone understands that there is no warranty for this free software. If the software is modified by someone else and passed on, we want its recipients to know that what they have is not the original, so that any problems introduced by others will not reflect on the original authors’ reputations.\n\n");
	printf("Finally, any free program is threatened constantly by software patents. We wish to avoid the danger that redistributors of a free program will individually obtain patent licenses, in effect making the program proprietary. To prevent this, we have made it clear that any patent must be licensed for everyone’s free use or not licensed at all.\n\n");
	printf("The precise terms and conditions for copying, distribution and modification follow.\n\n");
	system("pause");  // 暫停程式運行
	printf("TERMS AND CONDITIONS FOR COPYING, DISTRIBUTION AND MODIFICATION\n\n");
	printf("0. This License applies to any program or other work which contains a notice placed by the copyright holder saying it may be distributed under the terms of this General Public License. The “Program”, below, refers to any such program or work, and a “work based on the Program” means either the Program or any derivative work under copyright law: that is to say, a work containing the Program or a portion of it, either verbatim or with modifications and/or translated into another language. (Hereinafter, translation is included without limitation in the term “modification”.) Each licensee is addressed as “you”.\n\n");
	printf("Activities other than copying, distribution and modification are not covered by this License; they are outside its scope. The act of running the Program is not restricted, and the output from the Program is covered only if its contents constitute a work based on the Program (independent of having been made by running the Program). Whether that is true depends on what the Program does.\n\n");
	printf("1. You may copy and distribute verbatim copies of the Program’s source code as you receive it, in any medium, provided that you conspicuously and appropriately publish on each copy an appropriate copyright notice and disclaimer of warranty; keep intact all the notices that refer to this License and to the absence of any warranty; and give any other recipients of the Program a copy of this License along with the Program.\n\n");
	printf("You may charge a fee for the physical act of transferring a copy, and you may at your option offer warranty protection in exchange for a fee.\n\n");
	printf("2. You may modify your copy or copies of the Program or any portion of it, thus forming a work based on the Program, and copy and distribute such modifications or work under the terms of Section 1 above, provided that you also meet all of these conditions:\n\n");
	printf("	a) You must cause the modified files to carry prominent notices stating that you changed the files and the date of any change.\n\n");
	printf("	b) You must cause any work that you distribute or publish, that in whole or in part contains or is derived from the Program or any part thereof, to be licensed as a whole at no charge to all third parties under the terms of this License.\n\n");
	printf("	c) If the modified program normally reads commands interactively when run, you must cause it, when started running for such interactive use in the most ordinary way, to print or display an announcement including an appropriate copyright notice and a notice that there is no warranty (or else, saying that you provide a warranty) and that users may redistribute the program under these conditions, and telling the user how to view a copy of this License. (Exception: if the Program itself is interactive but does not normally print such an announcement, your work based on the Program is not required to print an announcement.)\n\n");
	printf("These requirements apply to the modified work as a whole. If identifiable sections of that work are not derived from the Program, and can be reasonably considered independent and separate works in themselves, then this License, and its terms, do not apply to those sections when you distribute them as separate works. But when you distribute the same sections as part of a whole which is a work based on the Program, the distribution of the whole must be on the terms of this License, whose permissions for other licensees extend to the entire whole, and thus to each and every part regardless of who wrote it.\n\n");
	printf("Thus, it is not the intent of this section to claim rights or contest your rights to work written entirely by you; rather, the intent is to exercise the right to control the distribution of derivative or collective works based on the Program.\n\n");
	printf("In addition, mere aggregation of another work not based on the Program with the Program (or with a work based on the Program) on a volume of a storage or distribution medium does not bring the other work under the scope of this License.\n\n");
	system("pause");  // 暫停程式運行
	printf("3. You may copy and distribute the Program (or a work based on it, under Section 2) in object code or executable form under the terms of Sections 1 and 2 above provided that you also do one of the following:\n\n");
	printf("	a) Accompany it with the complete corresponding machine-readable source code, which must be distributed under the terms of Sections 1 and 2 above on a medium customarily used for software interchange; or,\n\n");
	printf("	b) Accompany it with a written offer, valid for at least three years, to give any third party, for a charge no more than your cost of physically performing source distribution, a complete machine-readable copy of the corresponding source code, to be distributed under the terms of Sections 1 and 2 above on a medium customarily used for software interchange; or,\n\n");
	printf("	c) Accompany it with the information you received as to the offer to distribute corresponding source code. (This alternative is allowed only for noncommercial distribution and only if you received the program in object code or executable form with such an offer, in accord with Subsection b above.)\n\n");
	printf("The source code for a work means the preferred form of the work for making modifications to it. For an executable work, complete source code means all the source code for all modules it contains, plus any associated interface definition files, plus the scripts used to control compilation and installation of the executable. However, as a special exception, the source code distributed need not include anything that is normally distributed (in either source or binary form) with the major components (compiler, kernel, and so on) of the operating system on which the executable runs, unless that component itself accompanies the executable.\n\n");
	printf("If distribution of executable or object code is made by offering access to copy from a designated place, then offering equivalent access to copy the source code from the same place counts as distribution of the source code, even though third parties are not compelled to copy the source along with the object code.\n\n");
	printf("4. You may not copy, modify, sublicense, or distribute the Program except as expressly provided under this License. Any attempt otherwise to copy, modify, sublicense or distribute the Program is void, and will automatically terminate your rights under this License. However, parties who have received copies, or rights, from you under this License will not have their licenses terminated so long as such parties remain in full compliance.\n\n");
	printf("5. You are not required to accept this License, since you have not signed it. However, nothing else grants you permission to modify or distribute the Program or its derivative works. These actions are prohibited by law if you do not accept this License. Therefore, by modifying or distributing the Program (or any work based on the Program), you indicate your acceptance of this License to do so, and all its terms and conditions for copying, distributing or modifying the Program or works based on it.\n\n");
	printf("6. Each time you redistribute the Program (or any work based on the Program), the recipient automatically receives a license from the original licensor to copy, distribute or modify the Program subject to these terms and conditions. You may not impose any further restrictions on the recipients’ exercise of the rights granted herein. You are not responsible for enforcing compliance by third parties to this License.\n\n");
	system("pause");  // 暫停程式運行
	printf("7. If, as a consequence of a court judgment or allegation of patent infringement or for any other reason (not limited to patent issues), conditions are imposed on you (whether by court order, agreement or otherwise) that contradict the conditions of this License, they do not excuse you from the conditions of this License. If you cannot distribute so as to satisfy simultaneously your obligations under this License and any other pertinent obligations, then as a consequence you may not distribute the Program at all. For example, if a patent license would not permit royalty-free redistribution of the Program by all those who receive copies directly or indirectly through you, then the only way you could satisfy both it and this License would be to refrain entirely from distribution of the Program.\n\n");
	printf("If any portion of this section is held invalid or unenforceable under any particular circumstance, the balance of the section is intended to apply and the section as a whole is intended to apply in other circumstances.\n\n");
	printf("It is not the purpose of this section to induce you to infringe any patents or other property right claims or to contest validity of any such claims; this section has the sole purpose of protecting the integrity of the free software distribution system, which is implemented by public license practices. Many people have made generous contributions to the wide range of software distributed through that system in reliance on consistent application of that system; it is up to the author/donor to decide if he or she is willing to distribute software through any other system and a licensee cannot impose that choice.\n\n");
	printf("This section is intended to make thoroughly clear what is believed to be a consequence of the rest of this License.\n\n");
	printf("8. If the distribution and/or use of the Program is restricted in certain countries either by patents or by copyrighted interfaces, the original copyright holder who places the Program under this License may add an explicit geographical distribution limitation excluding those countries, so that distribution is permitted only in or among countries not thus excluded. In such case, this License incorporates the limitation as if written in the body of this License.\n\n");
	printf("9. The Free Software Foundation may publish revised and/or new versions of the General Public License from time to time. Such new versions will be similar in spirit to the present version, but may differ in detail to address new problems or concerns.\n\n");
	printf("Each version is given a distinguishing version number. If the Program specifies a version number of this License which applies to it and “any later version”, you have the option of following the terms and conditions either of that version or of any later version published by the Free Software Foundation. If the Program does not specify a version number of this License, you may choose any version ever published by the Free Software Foundation.\n\n");
	printf("10. If you wish to incorporate parts of the Program into other free programs whose distribution conditions are different, write to the author to ask for permission. For software which is copyrighted by the Free Software Foundation, write to the Free Software Foundation; we sometimes make exceptions for this. Our decision will be guided by the two goals of preserving the free status of all derivatives of our free software and of promoting the sharing and reuse of software generally.\n\n");
	printf("NO WARRANTY\n\n");
	printf("11. BECAUSE THE PROGRAM IS LICENSED FREE OF CHARGE, THERE IS NO WARRANTY FOR THE PROGRAM, TO THE EXTENT PERMITTED BY APPLICABLE LAW. EXCEPT WHEN OTHERWISE STATED IN WRITING THE COPYRIGHT HOLDERS AND/OR OTHER PARTIES PROVIDE THE PROGRAM “AS IS” WITHOUT WARRANTY OF ANY KIND, EITHER EXPRESSED OR IMPLIED, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE. THE ENTIRE RISK AS TO THE QUALITY AND PERFORMANCE OF THE PROGRAM IS WITH YOU. SHOULD THE PROGRAM PROVE DEFECTIVE, YOU ASSUME THE COST OF ALL NECESSARY SERVICING, REPAIR OR CORRECTION.\n\n");
	printf("12. IN NO EVENT UNLESS REQUIRED BY APPLICABLE LAW OR AGREED TO IN WRITING WILL ANY COPYRIGHT HOLDER, OR ANY OTHER PARTY WHO MAY MODIFY AND/OR REDISTRIBUTE THE PROGRAM AS PERMITTED ABOVE, BE LIABLE TO YOU FOR DAMAGES, INCLUDING ANY GENERAL, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES ARISING OUT OF THE USE OR INABILITY TO USE THE PROGRAM (INCLUDING BUT NOT LIMITED TO LOSS OF DATA OR DATA BEING RENDERED INACCURATE OR LOSSES SUSTAINED BY YOU OR THIRD PARTIES OR A FAILURE OF THE PROGRAM TO OPERATE WITH ANY OTHER PROGRAMS), EVEN IF SUCH HOLDER OR OTHER PARTY HAS BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.\n\n");
	printf("END OF TERMS AND CONDITIONS\n\n");
	system("pause");  // 暫停程式運行
}

void zh_license()
{

}
