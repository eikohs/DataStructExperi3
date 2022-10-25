#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int elemtype;//此处定义我们的矩阵用int类型的变量存储
#define MALLOC_WRONG 1//定义动态分配内存失败
#define TESTFUN 0//置1时进行函数的测试，置0则反之

typedef struct TUPLE {
    int i, j;//i:行位置-1；j:列位置-1；
    elemtype v;//v:数据
}tuple, * TuplePtr;
typedef struct SPARMATTP {
    int m, n, t;//m:行数; n:列数; t:非零元素数目
    TuplePtr data;
}sparmattp, * SparmatPtr;

SparmatPtr InitSparmat(void);//从标准控制台读取输入并初始化一个用三元组存储的稀疏矩阵，返回指针
SparmatPtr FastTranSpar(SparmatPtr src);//快速转置稀疏矩阵，并返回转置后的三元组表
SparmatPtr MultiSparmat(SparmatPtr Src1, SparmatPtr Src2);
SparmatPtr AddSparmat(SparmatPtr Src1, SparmatPtr Src2);//执行两个矩阵相加，不能相加则输出到控制台并返回空指针，否则返回相加的结果指针
int CompTulp(TuplePtr src1, TuplePtr src2);//判断两个三元数据的前后关系，src1在前返回1，src1在后返回-1，二者处于同一位置返回0
void PrintSparmat(SparmatPtr Src);//打印用三元组存储的矩阵
void FreshSparmat(SparmatPtr Src);//清空矩阵，释放空间