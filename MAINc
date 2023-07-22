#include <stdio.h>
#include <stdlib.h>

int bus_half_times, bus_full_times, bus_half_fare, bus_full_fare;  // 宣告全域函數：公車半價次數、公車全價次數、公車半價價格、公車全價價格
int metro_times, metro_fare, bus_times, bus_fare;  // 宣告全域函數：捷運總搭乘次數、捷運總搭乘價格、公車總搭乘次數、公車總搭乘價格
int total_fare; // 宣告全域函數：最終總花費

int metro(int def_fare)  // 定義捷運函式，def_fare為在函式內使用的參數，表示捷運票價
{
	int times;
	fflush(stdin);
	printf("本月搭捷運 %d 元次數：", def_fare);
	scanf_s("%d", &times);  // 詢問在 (def_fare) 元下，用戶搭乘捷運次數
	if (times > 0)
	{
		printf("本月搭捷運 %d 元 %d 次\n\n", def_fare, times);  // 列印使用者輸入內容
	}
	else if (times == 0)
	{
		printf("這個月沒有搭乘 %d 元的捷運\n\n", def_fare);  // 列印使用者輸入內容
	}
	else
	{
		printf("輸入內容出現錯誤，程式即將結束\a\n\n");
		system("pause");  // 暫停程式運行
		exit(EXIT_FAILURE);  // 退出程序
	}
	return(times);  // 返還得到的次數結果
}

int bus(int def_fare)  // 定義捷運函式，def_fare為在函式內使用的參數，表示捷運票價
{
	int times;
	fflush(stdin);
	printf("本月搭公車 %d 元次數：", def_fare);
	scanf_s("%d", &times);  // 詢問在 (def_fare) 元下，用戶搭乘捷運次數
	if (times > 0)
	{
		printf("本月搭公車 %d 元 %d 次\n\n", def_fare, times);  // 列印使用者輸入內容
	}
	else if (times == 0)
	{
		printf("這個月沒有搭乘 %d 元的公車\n\n", def_fare);  // 列印使用者輸入內容
	}
	else
	{
		printf("輸入內容出現錯誤，程式即將結束\a\n\n");
		system("pause");  // 暫停程式運行
		exit(EXIT_FAILURE);  // 退出程序
	}
	return(times);  // 返還得到的次數結果
}

void main()
{
	printf("歡迎使用「1280公共運輸定期票」計算程式 Made by CHE_72 ZStudio\n");
	printf("本程式可用來計算購買1280公共運輸定期票是否划算，程式將計算出結果。\n\n");
	printf("請依以下問題輸入「半形數字」回答，如沒有次數請輸入「0」。\n\n");
	
	int ID;  // 宣告 使用者身分 整數變數
	printf("請問您是用何種卡片？\n");  // 詢問使用者身分
	printf("0：普通卡、1：學生卡 -->");
	scanf_s("%d", &ID);
	switch (ID)
	{
		case 0:
			printf("您目前正在使用：普通卡\n\n");
			bus_half_times = bus(7);
			bus_full_times = bus(15);
			bus_half_fare, bus_full_fare = 7, 15;
			break;
		case 1:
			printf("您目前正在使用：學生卡\n\n");
			bus_half_times = bus(6);
			bus_full_times = bus(12);
			bus_half_fare, bus_full_fare = 6, 12;
			break;
		default:
			printf("輸入無效，程式即將結束\a\n\n");  // \a 為 溢出字元 警告聲
			system("pause");  // 暫停程式運行
			exit(EXIT_FAILURE);  // 退出程序
	}
	
	int m20 = metro(20), m25 = metro(25);
	int m30 = metro(30), m35 = metro(35);
	int m40 = metro(40), m45 = metro(45);
	int m50 = metro(50), m55 = metro(55);
	int m60 = metro(60), m65 = metro(65);

	metro_times = m20 + m25 + m30 + m35 + m40 + m45 + m50 + m55 + m60 + m65;  // 計算用戶搭乘捷運的總次數
	bus_times = bus_half_times + bus_full_times;  // 計算用戶搭乘公車的總次數
	if (metro_times + bus_times == 0)  // 如果搭乘公車及捷運的總和為0次
	{
		printf("本月不用花錢，正在準備退出程序\a\n\n");  // 沒有計算的必要，直接提示退出程序
		system("pause");  // 暫停程式運行
		exit(EXIT_SUCCESS);  // 退出程序
	}
	printf("本月搭捷運 %d 次,公車 %d 次\n", metro_times, bus_times);  // 列印使用者搭乘公車及捷運的總次數
		
	metro_fare = m20 * 20 + m25 * 25 + m30 * 30 + m35 * 35 + m40 * 40 + m45 * 45 + m50 * 50 + m55 * 55 + m60 * 60 + m65 * 65;
	/* 計算用戶搭乘捷運的總票價 */
	bus_fare = bus_half_times * bus_half_fare + bus_full_times * bus_full_fare;  // 計算用戶搭乘公車的總票價

	if (metro_times <= 10)  // 累計搭乘次數 <= 10時，沒有任何回饋
		total_fare = metro_fare + bus_fare;
	else if (11 <= metro_times <= 20)  // 累計搭乘次數在11~20次時，有10 % 回饋
		total_fare = metro_fare * 9 / 10 + bus_fare;
	else if (21 <= metro_times <= 30)  // 累計搭乘次數在21~30次時，有15 % 回饋
		total_fare = metro_fare * 17 / 20 + bus_fare;
	else if (31 <= metro_times <= 40)  // 累計搭乘次數在31~40次時，有20 % 回饋
		total_fare = metro_fare * 4 / 5 + bus_fare;
	else if (41 <= metro_times <= 50)  // 累計搭乘次數在41~50次時，有25 % 回饋
		total_fare = metro_fare * 3 / 4 + bus_fare;
	else  // 累計搭乘次數超過50次時，有30% 回饋
		total_fare = metro_fare * 7 / 10 + bus_fare;

	printf("一共花費 %d 元\n\n", total_fare);  // 印出目前計算出的總票價

	if (1280 < total_fare)  // 如果總票價 > 1280元
		printf("本月要買定期票，須花費 1280 元，可省下 %d 元\n", total_fare - 1280);  // 建議購買1280定期票
	else if (1280 == total_fare)  // 如果總票價 = 1280元
		printf("本月無論是否購買定期票，皆要花費 1280 元\n");  // 可自由決定是否要購買定期票
	else  // 如果總票價 < 1280元
		printf("本月直接刷卡即可，總共花費 %d 元\n", total_fare);  // 建議不要購買定期票，直接刷卡即可

	printf("計算完成，按下任意鍵以結束程式\a\n\n");  // 提示用戶這個程式已經運行完畢了
	printf("「1280公共運輸定期票」計算程式 Made by CHE_72 ZStudio\n\n");
	system("pause");  // 暫停程式運行
	exit(EXIT_SUCCESS);  // 退出程序
}
