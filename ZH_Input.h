#pragma once

extern int temp_times, temp_fare;

void ZH_tpmrt();  // �w�q ����\��1�G�O�_���B ��ƿ�J�禡 ���Φ�
extern int tpmrt_times, tpmrt_fare;
extern char tpmrt_discount[];

void ZH_ntmrt();  // �w�q ����\��2�G�s�_���B/���y ��ƿ�J�禡 ���Φ�
extern int ntmrt_times, ntmrt_fare;

void ZH_tpbus();  // �w�q ����\��3�G�j�O�_�a�Ϥ��� �����ܨ禡 ���Φ�
extern int tpbus_times, tpbus_fare;
extern int tpbus_half_times, tpbus_full_times, tpbus_half_fare, tpbus_full_fare;

void ZH_tra();  // �w�q ����\��4�G�O�W�K�� ��ƿ�J�禡 ���Φ�
extern int tra_times, tra_fare;

void ZH_tymrt();  // �w�q ����\��5�G��鱶�B ��ƿ�J�禡 ���Φ�
extern int tymrt_times, tymrt_fare;

void ZH_tkbus();  // �w�q ����\��6�G���/�򶩤��� ��ƿ�J�禡 ���Φ�
extern int tkbus_times, tkbus_fare;

void ZH_intercity();  // �w�q ����\��7�G�����ȹB ��ƿ�J�禡 ���Φ�
extern int intercity_times, intercity_fare;
