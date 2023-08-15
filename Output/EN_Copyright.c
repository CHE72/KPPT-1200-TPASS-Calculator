#include <stdio.h>  // 此標頭檔其中定義了 輸出與輸入功能
#include <stdlib.h>  // 此標頭檔其中定義了 系統暫停指令
#include "..\Output.h"  // 此標頭檔定義了 各種輸出內容

void EN_Copyright()  // 定義 模式6：英文簡介與版權
{
	printf("\n\033[38;5;43mKPPT 1200 TPASS Calculator ( C Language )\n");
	printf("This is English Offical Version of \"Description & Copyright\"\033[0m\n");
	printf("\n\033[38;5;45mDescription（程式介紹）\033[0m\n");
	printf("  Welcome to use the \"KPPT 1200 TPASS Calculator\" Program made by CHE_72 ZStudio in C language.\n");
	printf("  This program can help you judge whether to buy TPASS ( also called Megacity Pass ), which was launched by the government of the Republic of China (Taiwan, Penghu, Kinmen, Matsu) in 112 years of R.O.C.\n");
	printf("  Both TPASS(KPPT) and our awesome program can helps you save commuting costs in Keelung, Taipei, New Taipei and Taoyuan.\n");
	printf("    Notice:All texts are manually modified after using Google Translate, sorry for any confusion and inconvenience.\n");
	printf("\n\033[38;5;45mEnvironment Requirement（環境需求）\033[0m\n");
	printf("  The latest version of the Microsoft Visual C++ Redistributable Distribution (X64 architecture)\n");
	printf("  The latest version of the Windows Terminal\n");
	printf("\n\033[38;5;45mInstructions（使用說明）\033[0m\n");
	printf("  Step 1: Follow the program instructions and enter your identity with \"Half-width Numbers\" (3: Adult Card, 4: Student Card).\n");
	printf("\033[38;5;208m      Notice: Concessionaire Card (Child Cards) and Welfare Cards (Senior Citizen Cards) are not applicable to TPASS.\033[0m\n");
	printf("  Step 2: Follow the program instructions and select the function with \"Half-width Numbers\" (1: Taipei Metro (MRT), 2: New Taipei Metro (MRT) & LRT, 3:Taipei Metropolitan Area Buses, 4: Taiwan Railways (TRA), 5: Taoyuan Metro (MRT), 6: Taoyuan / Keelung Buses, 7: Intercity Buses).\n");
	printf("  Step 3: Follow the program instructions, enter the amount and the corresponding number of times with \"Half-width Numbers\".\n");
	printf("  Step 4: If the input of this function is completed, you can enter Half-width \"0 (which means 0 times or 0 dollars) \" to return to the Function Selection Platform.\n");
	printf("  Step 5: Continue to follow the program instructions and input the content of other transportation with \"Half-width Numbers\".\n");
	printf("\033[38;5;208m      Note: It is only necessary to input the transportation that you will use in 30 days, and you don't need to input every function.\033[0m\n");
	printf("  Step 6: Back to the Function Selection Platform, follow the program instruction, and input Half-width \"0\" to get the final calculation result.\n");
	printf("  Step 7: After the program is executed, a .txt text file will be added to the program execution path to record the result. Follow the instructions of the program and press any key to exit and end this program.\n");
	printf("\033[38;5;208m      Note: There are 3 little easter eggs hidden in this program waiting for you to discover.\033[0m\n");
	printf("\n\033[38;5;45mOther Modes（其他模式）\033[0m\a\n");
	printf("  Mode 6:Description & Copyright:It is the page you are on now, including how to use the program, author introduction and program copyright.\n");
	printf("  Mode 8:Open Source License:This program uses the second edition of the GNU General Public License version 2 (GNU GPLv2), which contains an offical English version in mode 8. See Mode 7 for the unofficial Chinese translation.\n");
	printf("  Mode 9:Exit this Program:The program will output a copyright message, press any key at this time to exit and end the program.\n\n");
	system("pause");  // 暫停程式運行
	printf("\n\033[38;5;45mNew Features, Updates, Improvements, Fixed Bugs（新增更新、改進修復）\033[0m\n");
	printf("  Added: According to the functions and types, many .c source code files and .h header files have been added.\n");
	printf("  Added: There is Chinese version program introduction, copyright notice, author and studio introduction.\n");
	printf("  Added: Easter egg +1, now there are 3 Easter eggs in the program.\n");
	printf("  Added: There is English version program introduction, copyright notice, author and studio introduction.\n\n");
	printf("  Updated: Nothing has been updated in this release.\n\n");
	printf("  Improved: Redesign the program in a modular way to improve the readability and maintainability of the program source code.\n");
	printf("  Improved: Modify the program output and introduction to \"Mode Input Platform\" and \"Function Selection Platform\", update the comments of all program sections, and adjust the use of terms to avoid confusion and fragmentation (maintain the same term) .\n");
	printf("  Improved: Modify the output content of the \"Mode Input Platform\", and use the language as the classification standard for the options, so that users can easily find the input options applicable to their language.\n");
	printf("  Improved: Modify the input display of \"Mode Input Platform\" to make user input more intuitive.\n\n");
	printf("  Fixed: Nothing has been fixed in this release.\n");
	printf("\n\033[38;5;45mKnown Issues（已知問題）\033[0m\n");
	printf("  Bugs: In the \"Identity Input Platform\", since the content has not been fully constructed, option 3 & 4 may work INCORRECTLY.\n");
	printf("\n\033[38;5;45mFuture Features（未來功能）\033[0m\n");
	printf("  We expect to add an English option of the program in V1.2X to facilitate the calculation and use of foreigners in the Taipei Megacity, public transportation and commuting.\n");
	printf("  We expect to add the function of exporting results as text files (.txt) in V2.0X, so that user's input results and program's calculation output results can be saved and recorded, which makes it easier for user to use.\n");
	printf("\n\033[38;5;45mAbout US（關於我們）\033[0m\n");
	printf("  CHE_72 ZStudio is a small personal studio, the founder is a prospective college student who is about to study at National Taiwan University of Science and Technology (NTUST).\n");
	printf("  This program was originally a small program I made to solve the needs of commuting in my life and at the same time be familiar with the use of C language.\n");
	printf("  2023-08-15\n");
	printf("\n\033[38;5;45mCopyright（版權宣告）\033[0m\n");
	printf("  KPPT 1200 TPASS Calculator\033[38;5;197m Ver%g \033[0m, Copyright (C) 2023-present CHE_72 ZStudio.\n", ver);
	printf("  This program is free software; you can redistribute it and / or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.\n");
	printf("  Powered by Microsoft Visual Studio 2022\a\n\n");
	printf("\033[38;5;43m  CCCCC  H    H  EEEEE       77777  22222         ZZZZZ   SSSS                    d    i         \033[0m\n");  // 輸出 ASCII 藝術
	printf("\033[38;5;43m  C      H    H  E               7      2            Z   S       t                d              \033[0m\n");
	printf("\033[38;5;43m  C      HHHHHH  EEEEE           7   222            Z     SSS   ttttt  u   u  ddddd    i    ooooo\033[0m\n");
	printf("\033[38;5;43m  C      H    H  E              7   2              Z         S   t     u   u  d   d    i    o   o\033[0m\n");
	printf("\033[38;5;43m  CCCCC  H    H  EEEEE   ___   7    22222         ZZZZZ  SSSS    tttt  uuuuu  ddddd    i    ooooo\033[0m\n\n");
	system("pause");  // 暫停程式運行
}
