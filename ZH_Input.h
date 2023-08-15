#pragma once

extern int temp_times, temp_fare;

void ZH_tpmrt();  // 定義 中文功能1：臺北捷運 資料輸入函式 的形式
extern int tpmrt_times, tpmrt_fare;
extern char tpmrt_discount[];

void ZH_ntmrt();  // 定義 中文功能2：新北捷運/輕軌 資料輸入函式 的形式
extern int ntmrt_times, ntmrt_fare;

void ZH_tpbus();  // 定義 中文功能3：大臺北地區公車 資料顯示函式 的形式
extern int tpbus_times, tpbus_fare;
extern int tpbus_half_times, tpbus_full_times, tpbus_half_fare, tpbus_full_fare;

void ZH_tra();  // 定義 中文功能4：臺灣鐵路 資料輸入函式 的形式
extern int tra_times, tra_fare;

void ZH_tymrt();  // 定義 中文功能5：桃園捷運 資料輸入函式 的形式
extern int tymrt_times, tymrt_fare;

void ZH_tkbus();  // 定義 中文功能6：桃園/基隆公車 資料輸入函式 的形式
extern int tkbus_times, tkbus_fare;

void ZH_intercity();  // 定義 中文功能7：公路客運 資料輸入函式 的形式
extern int intercity_times, intercity_fare;
