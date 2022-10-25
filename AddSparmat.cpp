#include "Tuple.h"

SparmatPtr AddSparmat(SparmatPtr Src1, SparmatPtr Src2)//执行两个矩阵相加，不能相加则输出到控制台并返回空指针，否则返回相加的结果指针
{
	if (Src1->m != Src2->m || Src1->n != Src2->n)
	{
		puts("Motrix1 and Motrix2 can not be added, cause they are not the same type of Motrix");
		return NULL;
	}
	else
	{
		int coun1 = 0, coun2 = 0;
		TuplePtr TmpData = (TuplePtr)malloc(sizeof(tuple) * (Src1->t + Src2->t));
		SparmatPtr RetPtr = (SparmatPtr)malloc(sizeof(sparmattp));
		if (!TmpData || !RetPtr) exit(MALLOC_WRONG);
		RetPtr->m = Src1->m;
		RetPtr->n = Src2->n;
		RetPtr->t = 0;
		while (coun1 < Src1->t && coun2 < Src2->t)
		{
			switch (CompTulp(&Src1->data[coun1], &Src2->data[coun2]))
			{
			case -1:
			{
				TmpData[RetPtr->t++] = Src2->data[coun2++];
			}break;
			case 1:
			{
				TmpData[RetPtr->t++] = Src1->data[coun1++];
			}break;
			case 0:
			{
				TmpData[RetPtr->t] = Src1->data[coun1++];
				TmpData[RetPtr->t++].v += Src2->data[coun2++].v;
			}break;
			}
		}
		if (coun1 < Src1->t)
		{
			memcpy(TmpData + RetPtr->t, Src1->data + coun1, sizeof(tuple) * (Src1->t - coun1));
			RetPtr->t += (Src1->t - coun1);
		}
		if (coun2 < Src2->t)
		{
			memcpy(TmpData + RetPtr->t, Src2->data + coun2, sizeof(tuple) * (Src2->t - coun2));
			RetPtr->t += (Src2->t - coun2);
		}
		RetPtr->data = (TuplePtr)malloc(sizeof(tuple) * RetPtr->t);
		if (RetPtr->data)
		{
			memcpy(RetPtr->data, TmpData, sizeof(tuple) * RetPtr->t);
			free(TmpData);
		}

		return RetPtr;
	}
}
