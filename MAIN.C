#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include <string.h>  // 此標頭檔其中定義了 更改字元陣列的函示
#include "Output.h"  // 此標頭檔定義了 各種輸出內容
#include "Exit.h"  // 此標頭檔定義了 程式如何結束
#include "ZH_Input.h"  // 此標頭檔定義了 中文使用者輸入
#include "EN_Input.h"  // 此標頭檔定義了 英文使用者輸入

double ver = 1.234;  // 宣告全域浮點數：程式版本號
int Mode, Funcion;  // 宣告全域整數變數函數：模式選擇代碼、功能選擇代碼
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

//以下內容為函式原型宣告（無）

/*
* 定義 printf 顏色的使用　（ANSI 轉義碼）
* 選擇訊息：\033[38;5;43m  * 提示訊息：\033[38;5;208m  * 退出訊息：\033[38;5;197m
* 輸入結果：\033[38;5;111m  * 小計結果：\033[38;5;45m  * 清除效果：\033[0m
*/

void main()  // 定義主程式區塊
{
	  /* 定義各個運輸工具的 搭乘次數與累積票價 初始值為 0，緩存次數與票價 初始值為 0， */
	ntmrt_fare = ntmrt_times = tra_fare = tra_times = tymrt_fare = tymrt_times = 0;
	tkbus_fare = tkbus_times = intercity_fare = intercity_times = temp_fare = temp_times = 0;

	printf("歡迎您使用「基北北桃1200都會通定期票」計算程式\033[38;5;197m Ver%g \033[0m由 CHE_72 ZStudio 使用 C 語言製作\n", ver);  // 輸出中文歡迎訊息
	printf("Welcome to use KPPT 1200 TPASS Calculator\033[38;5;197m Ver%g \033[0m( C Language ) Made by CHE_72 ZStudio.\n\n", ver);  // 輸出英文歡迎訊息
	printf("\033[38;5;208m中文：本程式可用來計算購買「1200都會通定期票」是否划算，程式將計算出結果。\n");  // 輸出中文程式目的
	printf("以下所有問題請依照提示輸入「半形數字」回答\n\n");  // 輸出中文使用規範
	printf("EN:This program can help you judge whether to buy KPPT 1200 TPASS. We will automatically calculate the result and provide it to you.\n");  // 輸出英文程式目的
	printf("All you have to do is follow this program instructions and input \"Half-width Numbers\".\033[0m\n\n");  // 輸出英文使用規範

	input_Mode:  // 定義 輸入_模式輸入 區塊
	printf("這裡是「模式輸入平臺」，請問您是用何種身分的悠遊卡，或是要瀏覽哪些程式資訊？\n");  // 詢問中文使用者模式
	printf("This is the \"Mode Entry Platform\", what kind of Easycard do you use or what information of this program do you wanna know?\n\n");  // 詢問英文使用者模式
	printf("對於中文用戶：1：普通卡、2：學生卡、5：程式簡介與版權宣告、7：開源許可、9：完全退出程序\n");  // 輸出中文可使用的選項
	printf("for English User: 3:Adult Card, 4:Student Card, 6:Description & Copyright, 8:Open Source License, 9:Exit this Program\n");  // 輸出英文可使用的選項
	printf("請輸入在這裡 / Please input here --> ");
	scanf_s("%d", &Mode);  //接收使用者輸入至 模式輸入 變數
	switch (Mode)  // 根據 模式輸入 變數判斷
	{
	case 0:  // 模式0：小彩蛋模式
	{
		Easter0();  // 調用 第一個彩蛋 函式
		goto input_Mode;  // 跳到 輸入_模式輸入 區塊
	}
	case 1:  // 模式1：普通卡(中文)
	{
		printf("\033[38;5;43m您目前正在使用：普通卡\033[0m\n");  // 輸出中文普通使用者身分
		tpbus_half_fare = 7, tpbus_full_fare = 15;  // 定義 大臺北地區公車 普通半價與全價
		break;  // 離開 switch
	}
	case 2:  // 模式2：學生卡(中文)
		printf("\033[38;5;43m您目前正在使用：學生卡\033[0m\n");  // 輸出使用者身分
		tpbus_half_fare = 6, tpbus_full_fare = 12;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 3:  // 模式3：Adult Card (English)
		printf("\033[38;5;43mYou are now using: Adult Card.\033[0m\n");
		tpbus_half_fare = 7, tpbus_full_fare = 15;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 4:  // 模式4：Student Card (English)
		printf("\033[38;5;43mYou are now using: Student Card.\033[0m\n");
		tpbus_half_fare = 6, tpbus_full_fare = 12;  // 定義 大臺北地區公車 半價與全價
		break;  // 離開 switch
	case 5:  // 模式5：程式簡介與版權宣告(中文)
		ZH_Copyright();
		goto input_Mode;  // 跳到 輸輸入_模式輸入 區塊
	case 6:  // 模式6：Description & Copyright(English)
		EN_Copyright();
		goto input_Mode;  // 跳到 輸輸入_模式輸入 區塊
	case 7:  // 模式7：開源許可(中文)
		ZH_License();
		goto input_Mode;  // 跳到 輸入_模式輸入 區塊
	case 8:  // 模式8：Open Source Licenses(English)
		EN_License();
		goto input_Mode;  // 跳到 輸入_模式輸入 區塊
	case 9:  // 模式9：完全退出程序
		printf("\n\033[38;5;197m收到您的要求，正在結束程序\033[0m\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		printf("\033[38;5;197mWe receive your request, and the program will end soon.\033[0m\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		goto stop_success;  // 跳到 輸出_成功結束 區塊
	default:  // 其他情況
		printf("\n\033[38;5;197m輸入無效，程式即將結束\a\n");  // 輸出程式退出 ZH 訊息， \a 為 溢出字元 警告聲
		printf("\033[38;5;197mYour input is invalid, and the program will end soon.\n\n");  // 輸出程式退出 EN 訊息
		pause_exit(EXIT_FAILURE);  // 調用退出程序（程式異常退出）
	}

input_Funcion:  // 定義 輸入_功能選擇平臺 區塊
	if (Mode == 1 || Mode == 2)
	{
		printf("\n這裡是功能選擇平臺，請問您現在要進入何種功能？\n");  // 詢問使用者身分
		printf("0：退出輸入模式，開始計算總金額、1：臺北捷運、2：新北捷運/輕軌、3：大臺北地區公車、4：臺灣鐵路、5：桃園捷運、6：桃園/基隆公車、7：公路客運、9：完全退出程序 --> ");
		// 詢問使用者欲使用功能
		scanf_s("%d", &Funcion);  //接收使用者輸入至 功能選擇 變數
		switch (Funcion)  // 根據 功能選擇 變數判斷
		{
		case 0:  // 功能0：退出輸入模式，開始計算總金額
		{
			printf("\n\033[38;5;43m正在退出輸入模式，進入最終計算\033[0m\n\n");  // 輸出功能訊息
			goto ZH_output_Result;  // 跳到 輸出_計算 區塊
		}
		case 1:  // 功能1：臺北捷運
		{
			ZH_tpmrt();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 2:  // 功能2：新北捷運/輕軌
		{
			ZH_ntmrt();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 3:  // 功能3：大臺北地區公車
		{
			ZH_tpbus();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 4:  // 功能4：臺灣鐵路
		{
			ZH_tra();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 5:  // 功能5：桃園捷運
		{
			ZH_tymrt();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊

		}
		case 6:  // 功能6：桃園/基隆公車
		{
			ZH_tkbus();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 7:  // 功能7：公路客運
		{
			ZH_intercity();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 8:  // 功能8：小彩蛋功能
		{
			ZH_Easter1();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 9:  // 模式9：完全退出程序
		{
			printf("\n\033[38;5;197m收到您的要求，正在結束程序\033[0m\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
			goto stop_success;  // 跳到 輸出_成功結束 區塊
		}
		default:  // 其他情況
		{
			printf("\n\033[38;5;197m輸入無效，程式即將結束\a\n\n");  // 輸出程式退出訊息，\a 為 溢出字元 警告聲
			pause_exit(EXIT_FAILURE);  // 調用退出程序（程式異常退出）
		}
		}
	ZH_output_Result:  // 定義 中文輸出_計算結果 區塊
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
			printf("本月直接刷悠遊卡即可，總共花費 %d 元\n", total_fare);  // 建議不要購買定期票，直接刷卡即可

		printf("\033[38;5;197m計算完成，按下任意鍵以結束程式\033[0m\a\n\n");  // 提示用戶這個程式已經運行完畢了， \a 為 溢出字元 警告聲
	}
	else if (Mode == 3 || Mode == 4)
	{
		printf("\n\033[38;5;197mThe content has not been fully constructed. Some functions may mork INCORRECTLY.\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
		printf("You are now in Ver%g (Insider Version Program). \033[0m\a\n", ver);
		//goto stop_success;
		printf("\nThis \"Function Selection Platform\". What function do you wanna input now?\n");  // 詢問使用者身分
		printf("0：Exit Function Selection and Calculte Total Fee, 1: Taipei Metro (MRT), 2: New Taipei Metro (MRT) & LRT, 3:Taipei Metropolitan Area Buses,\n4: Taiwan Railways (TRA), 5: Taoyuan Metro (MRT), 6: Taoyuan / Keelung Buses, 7: Intercity Buses, 9:Exit this Program --> ");
		// 詢問使用者欲使用功能
		scanf_s("%d", &Funcion);  //接收使用者輸入至 功能選擇 變數
		switch (Funcion)  // 根據 功能選擇 變數判斷
		{
		case 0:  // 功能0：退出輸入模式，開始計算總金額
		{
			printf("\n\033[38;5;43mWe are now exiting input mode, entering final calculation.\033[0m\n\n");  // 輸出功能訊息
			goto EN_output_Result;  // 跳到 輸出_計算 區塊
		}
		case 1:  // 功能1：臺北捷運
		{
			EN_tpmrt();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 2:  // 功能2：新北捷運/輕軌
		{
			EN_ntmrt();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 3:  // 功能3：大臺北地區公車
		{
			EN_tpbus();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 4:  // 功能4：臺灣鐵路
		{
			EN_tra();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 5:  // 功能5：桃園捷運
		{
			EN_tymrt();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊

		}
		case 6:  // 功能6：桃園/基隆公車
		{
			EN_tkbus();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 7:  // 功能7：公路客運
		{
			EN_intercity();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 8:  // 功能8：小彩蛋功能
		{
			EN_Easter1();
			goto input_Funcion;  // 跳到 輸入_功能選擇平臺 區塊
		}
		case 9:  // 模式9：完全退出程序
		{
			printf("\n\033[38;5;197mWe receive your request, and the program will end soon.\033[0m\a\n\n");  // 輸出程式退出訊息， \a 為 溢出字元 警告聲
			goto stop_success;  // 跳到 輸出_成功結束 區塊
		}
		default:  // 其他情況
		{
			printf("\033[38;5;197mYour input is invalid, and the program will end soon.\n\n");  // 輸出程式退出 EN 訊息
			pause_exit(EXIT_FAILURE);  // 調用退出程序（程式異常退出）
		}
		}
	EN_output_Result:  // 定義 英文輸出_計算結果 區塊
		total_fare = tpmrt_fare + ntmrt_fare + tpbus_fare + tra_fare + tymrt_fare + tkbus_fare + intercity_fare;  // 計算 使用者輸入 的總票價
		if (total_fare == 0)  // 如果 總票價 等於0
		{
			printf("\033[38;5;197mYou spend no money this month, and this program will end soon.\033[0m\a\n\n");  // 沒有計算的必要，直接提示退出程序， \a 為 溢出字元 警告聲
			goto stop_success;  // 跳到 輸出_成功結束 區塊
		}

		/* 判斷是否購買 基北北桃1200都會通定期票 */
		if (1200 < total_fare)  // 如果總票價 > 1200元
			printf("You should buy TPASS this month. You need to spend NT$1200 on it, and it can save you NT$%d.\n", total_fare - 1200);  // 建議購買 基北北桃1200都會通定期票
		else if (1200 == total_fare)  // 如果總票價 = 1200元
			printf("Whether you buy TPASS or not, you need to spend NT$1200 on transportation this month.\n");  // 可自由決定是否要購買定期票
		else  // 如果總票價 < 1200元
			printf("You don't need to buy TPASS and just use your Easy Card, and the total cost will be NT$%d this month.\n", total_fare);  // 建議不要購買定期票，直接刷卡即可

		printf("\033[38;5;197mThe calculation is completed, press any key to end this program.\033[0m\a\n\n");  // 提示用戶這個程式已經運行完畢了， \a 為 溢出字元 警告聲
		goto stop_success;  // 跳到 輸出_成功結束 區塊
	}

	stop_success:  // 定義 輸出_成功結束 區塊
	printf("「基北北桃1200都會通定期票」計算程式\033[38;5;197m Ver%g \033[0m, Copyright (C) 2023-present CHE_72 ZStudio\n", ver);  // 輸出版權訊息
	printf("KPPT 1200 TPASS Calculator\033[38;5;197m Ver%g \033[0m, Copyright (C) 2023-present CHE_72 ZStudio.\a\n\n", ver);  // 輸出版權訊息
	pause_exit(EXIT_SUCCESS);  // 調用退出程序（程式正常退出）
}
