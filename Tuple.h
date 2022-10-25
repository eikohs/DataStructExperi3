#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemtype;//�˴��������ǵľ�����int���͵ı����洢
#define MALLOC_WRONG 1//���嶯̬�����ڴ�ʧ��
#define TESTFUN 0//��1ʱ���к����Ĳ��ԣ���0��֮

typedef struct TUPLE {
    int i, j;//i:��λ��-1��j:��λ��-1��
    elemtype v;//v:����
}tuple, * TuplePtr;
typedef struct SPARMATTP {
    int m, n, t;//m:����; n:����; t:����Ԫ����Ŀ
    TuplePtr data;
}sparmattp, * SparmatPtr;

SparmatPtr InitSparmat(void);//�ӱ�׼����̨��ȡ���벢��ʼ��һ������Ԫ��洢��ϡ����󣬷���ָ��
SparmatPtr FastTranSpar(SparmatPtr src);//����ת��ϡ����󣬲�����ת�ú����Ԫ���
SparmatPtr MultiSparmat(SparmatPtr Src1, SparmatPtr Src2);
SparmatPtr AddSparmat(SparmatPtr Src1, SparmatPtr Src2);//ִ������������ӣ�������������������̨�����ؿ�ָ�룬���򷵻���ӵĽ��ָ��
int CompTulp(TuplePtr src1, TuplePtr src2);//�ж�������Ԫ���ݵ�ǰ���ϵ��src1��ǰ����1��src1�ں󷵻�-1�����ߴ���ͬһλ�÷���0
void PrintSparmat(SparmatPtr Src);//��ӡ����Ԫ��洢�ľ���
void FreshSparmat(SparmatPtr Src);//��վ����ͷſռ�