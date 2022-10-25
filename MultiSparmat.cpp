#include "Tuple.h"

SparmatPtr MultiSparmat(SparmatPtr Src1, SparmatPtr Src2)
{
	if (Src1->n == Src2->m || Src2->n == Src1->m)
	{
		SparmatPtr src1, src2;
		if (Src1->n == Src2->m)
		{
			src1 = Src1;
			src2 = Src2;
		}
		else
		{
			src1 = Src2;
			src2 = Src1;
		}
		puts("Motrix 1:");
		PrintSparmat(src1);
		puts("Motrix 2:");
		PrintSparmat(src2);
		SparmatPtr Transrc2 = FastTranSpar(src2), RetPtr = (SparmatPtr)malloc(sizeof(sparmattp));
		TuplePtr Tmpdata = (TuplePtr)malloc(sizeof(tuple) * src1->m * src2->n);
		//PrintSparmat(Transrc2);
		if (!RetPtr || !Tmpdata) exit(MALLOC_WRONG);
		RetPtr->m = src1->m;
		RetPtr->n = src2->n;
		RetPtr->t = 0;
		Tmpdata->v = 0;
		TuplePtr start = src1->data, end = start, tmptr;
		for (int i = 0; i < src1->m;start = end, i++)
		{
			tmptr = start;
			while (end < src1->data + src1->t && end->i == start->i) end = end + 1;
			for (int j = 0, Tmpi = 0, flag = 0; j < Transrc2->t; j++)
			{
				if (Tmpi != Transrc2->data[j].i)
				{
					Tmpi = Transrc2->data[j].i;
					tmptr = start;
					if (flag == 1)
					{
						Tmpdata[++RetPtr->t].v = 0;
						flag = 0;
					}
				}
				while (tmptr < end && tmptr->j < Transrc2->data[j].j) tmptr = tmptr + 1;
				if (tmptr < end&&tmptr->j == Transrc2->data[j].j)
				{
					flag = 1;
					Tmpdata[RetPtr->t].i = tmptr->i;
					Tmpdata[RetPtr->t].j = Tmpi;
					Tmpdata[RetPtr->t].v += tmptr->v * Transrc2->data[j].v;
				}
			}
			if (Tmpdata[RetPtr->t].v) Tmpdata[++RetPtr->t].v = 0;
		}
		RetPtr->data = (TuplePtr)malloc(sizeof(tuple) * RetPtr->t);
		if (RetPtr->data) memcpy(RetPtr->data, Tmpdata, sizeof(tuple) * RetPtr->t);

		return RetPtr;
	}
	else
	{
		puts("Motrix1 and Motrix2 can not be multiplied, cause they do not fit the struct of ""(a*n) X (n*b)""");
		return NULL;
	}
}