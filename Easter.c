#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include "Output.h"  // 此標頭檔定義了 各種輸出內容

void Easter0()  // 定義 模式0：第一個彩蛋 輸出函式
{
	printf("\n\033[38;5;43m恭喜您成功觸發一個小彩蛋，祝您天天 0 煩惱\n");  // 輸出中文小彩蛋訊息
	printf("This is an Easter Egg. Wish you have no trobules every day.\a\n\n");  // 輸出英文小彩蛋訊息， \a 為 溢出字元 警告聲
	printf("現在即將為您重新導引至模式輸入平臺\n");  // 輸出中文功能訊息
	printf("You will now be redirected to the Mode Entry Platform.\033[0m\n\n");  // 輸出英文功能訊息
}

void ZH_Easter1()  // 定義 中文功能8：第二個中文彩蛋 輸出函式
{
	printf("\n\033[38;5;43m恭喜您成功觸發一個小彩蛋，祝您天天發發發\a\n");  // 輸出中文小彩蛋訊息
	printf("現在即將為您重新導引至功能選擇平臺\033[0m\n");  // 輸出中文功能訊息
}

void EN_Easter1()  // 定義 英文功能8：第二個英文彩蛋 輸出函式
{
	printf("\033[38;5;43mThis is an Easter Egg. Wish you have more and more money.\a\n");  // 輸出英文小彩蛋訊息
	printf("You will now be redirected to the Function Selection Platform.\033[0m\n\n");  // 輸出英文功能訊息
}