#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include "Output.h"  // 此標頭檔定義了 各種輸出內容

void ZH_zero_exit()  // 定義 中文訊息：0表示返回 輸出函式
{
	printf("以下所有問題請依照提示輸入「半形數字」回答，輸入「0」會返回模式選擇平臺\n\n");  // 輸出中文提示訊息
}

void ZH_zero_times()  // 定義 中文訊息：0表示繼續 輸出函式
{
	printf("以下所有問題請依照提示輸入「半形數字」回答，如沒有次數請輸入「0」\n\n");  // 輸出中文提示訊息
}

void EN_zero_exit()  // 定義 英文訊息：0表示返回 輸出函式
{
	printf("Please follow the instructions to enter \"Half-width Numbers\" to answer all the following questions, and enter \"0\" to return to the Function Selection Platform\n\n");  // 輸出英文提示訊息
}

void EN_zero_times()  // 定義 英文訊息：0表示繼續 輸出函式
{
	printf("Please follow the instructions to enter \"Half-width Numbers\" to answer all the following questions. If there is no number of times, please enter \"0\" to move on to next question.\n\n");  // 輸出英文提示訊息
}
