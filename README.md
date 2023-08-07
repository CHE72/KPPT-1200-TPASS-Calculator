# 「基北北桃1200都會通定期票計算程式 」（使用 C 語言）
## KPPT 1200 TPASS Calculator ( C Language ) Made by CHE_72 ZStudio

## 程式介紹 (Description)
歡迎使用由 CHE_72 ZStudio 使用 C 語言製作而成的「基北北桃1200都會通定期票計算程式 」，本程式可以協助您判斷是否購買由 中華民國政府（臺澎金馬） 於 民國112年 推出的「TPASS行政院通勤月票（基北北桃）」，協助您省下在 基北北桃 區域通勤的花費。
>  本說明文件所有英文內容皆由 Google 翻譯後修改調整而來，造成任何困惑與不便，敬請見諒。

Welcome to use the "KPPT 1200 TPASS Calculator" made by CHE_72 ZStudio in C language. This program can help you judge whether to buy TPASS ( also called Megacity Pass ), which was launched by the government of the Republic of China (Taiwan, Penghu, Kinmen, Matsu) in 112 years of R.O.C. Both TPASS(KPPT) and our awesome program can helps you save commuting costs in Keelung, Taipei, New Taipei, Taoyuan.
>  All texts are translated using Google Translate, sorry for any confusion and inconvenience.

## 使用說明 (Instructions)
第一步：按照程式提示，輸入身分（1：普通卡、2：學生卡）。  
第二步：按照程式提示，選擇功能（1：臺北捷運、2：新北捷運/輕軌、3：大臺北地區公車、4：臺灣鐵路、5：桃園捷運、6：桃園/基隆公車、7：公路客運）。  
第三步：按照程式提示，輸入金額與對應的次數。  
第四步：若此功能輸入完成，可輸入「0（次 / 元）」返回模式選擇平臺。  
第五步：繼續按照程式提示，輸入其他功能的內容。  
第六步：返回模式選擇平臺，按照程式提示，輸入「0」以獲得最終計算結果。  
> 注意：此程式中隱藏了 2 個小彩蛋等待您發現。

Step 1: Follow the program prompts and enter your identity (1: ordinary card, 2: student card).  
Step 2: Follow the program prompts and select the function (1: Taipei Metro (MRT), 2: New Taipei Metro (MRT) & LRT, 3:Taipei Metropolitan Area Buses, 4: Taiwan Railways (TRA), 5: Taoyuan Metro (MRT), 6: Taoyuan / Keelung Buses, 7: Intercity Buses).  
Step 3: Follow the program prompts, enter the amount and the corresponding number of times.  
Step 4: If the input of this function is completed, you can enter "0 (which means 0 times or 0 dollars) " to return to the function selection.  
Step 5: Continue to follow the program prompts and input the content of other transportation.  
Step 6: Back to the function selection, follow the program prompt, and input "0" to get the final calculation result.  
> Note: There are 2 little easter eggs hidden in this program waiting for you to discover.  

## V1.1X 新增 更新 改進 修復 (New Features, Updates, Improvements, Fixed Bugs in V1.1X)
V1.130 新增：printf 函式中首次使用「ANSI 轉義碼」，使得程式的輸出結果能夠顯示出不同的顏色，方便使用者閱讀。  
V1.151 新增：程式初始階段的英文簡介與英文選項，方便外國人使用。  
更新：  
V1.101 改進：在「讀我檔案」中的段落格式部分英文用字遣詞。  
V1.110 改進：在「臺北捷運」中的輸入改用 for 迴圈進行，有效減少資源占用。  
V1.120 改進：使用「函式原型宣告」，將自訂函式放置於 main() 函式之後，方便閱讀及維護。  
V1.131 改進：在「大臺北地區公車」的描述輸出中，新增對於多段票的描述，並調整其他程式輸出的語句。  
V1.132 改進：在「輸出計算結果」的區塊中，調整了顯示方式，現在可以在最終計算時看到各交通工具的花費金額與次數。    
V1.100 修復：在「大臺北地區公車」的結果顯示中，會將公車總搭乘票價誤植為公車總搭乘次數的問題。  
V1.140 修復：多次輸入「大臺北地區公車」的數據資料時，因為沒有加總到之前的紀錄，會導致先前輸入過的資料被消失的問題。  
V1.150 修復：在「臺北捷運」中的常客優惠計算錯誤問題。

Added: The "ANSI escape code" is used for the first time in the printf function, so that the output of the program can be displayed in different colors, which is convenient for users to read.  
Added: Added author and studio introduction to let people understand our purpose of making this program.  
Updated:  
Improved: Some paragraph format and English wording in "Readme.md".  
Improved: The input fuction block in "Taipei MRT" is changed to a "for loop", which effectively reduces resource consumption.  
Improved: Use "Function Prototype Declaration" to place custom functions after the main() function for easy reading and maintenance.  
Improved: In the description output of "Taipei Metropolitan Area Buses", add a description for multi-section tickets, and adjust the output sentences in other places.  
Improved: In the "Output Calculation Result" block, the display method has been adjusted, and now you can see the cost and times of each transportation in the final calculation.  
Fixed: In the result display of "Taipei Metropolitan Area Buses", the total bus fare will be mistakenly planted as the total number of bus rides.  
Fixed: When the data of "Taipei Metropolitan Area Buses" is input multiple times, the previous input data will be lost because the previous records are not summed up.  
Fixed: Frequent Passenger Program discount calculation error in "Taipei MRT".


## 已知問題 (Known Issues)
錯誤：在「身分輸入平臺」，由於內容尚未建置完全，因此3、4、7、8選項都沒有作用，會輸出錯誤訊息並直接退出程序。  
故障：  

Bugs / Errors: In the "Identity Input Platform", since the content has not been fully constructed, options 3, 4, 7, and 8 have no effect, and an error message will be output and the program will exit directly.  
Broken:

## 未來功能 (Future Features)
我們預計會在 V1.2X 時增加開源許可與版權宣告、作者與工作室介紹，並對「身分輸入平臺」的3、4選項進行簡短的未來功能介紹。   
我們預計會在 V2.0X 時添加英文版本程式。

We expect to add open source licenses and copyright announcements, author and studio introductions in V1.2X, and give a brief introduction to the future functions of options 3 and 4 of the "Identity Input Platform".  
We expect to add an English version of the program in V2.0X
