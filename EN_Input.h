#pragma once

extern int temp_times, temp_fare;

void EN_tpmrt();
extern int tpmrt_times, tpmrt_fare;
extern char tpmrt_discount[];

void EN_ntmrt();
extern int ntmrt_times, ntmrt_fare;

void EN_tpbus();
extern int tpbus_times, tpbus_fare;
extern int tpbus_half_times, tpbus_full_times, tpbus_half_fare, tpbus_full_fare;

void EN_tra();
extern int tra_times, tra_fare;

void EN_tymrt();
extern int tymrt_times, tymrt_fare;

void EN_tkbus();
extern int tkbus_times, tkbus_fare;

void EN_intercity();
extern int intercity_times, intercity_fare;
