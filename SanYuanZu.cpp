#include "Tuple.h"

SparmatPtr InitSparmat(void)//�ӱ�׼����̨��ȡ���벢��ʼ��һ������Ԫ��洢��ϡ����󣬷���ָ��
{
	int Count = 0, row, line, tmp;
	printf("Input the numbers of row and line that of the Motrix you want to input((3*4)Motrix, you input ""3 4"")\n");
	scanf("%d %d", &line, &row);
	while (line == 0 || row == 0)
	{
		printf("It's nonsence, please try again\n");
		scanf("%d %d", &line, &row);
	}
	SparmatPtr RetPtr = (SparmatPtr)malloc(sizeof(sparmattp));
	if (!RetPtr) exit(MALLOC_WRONG);
	RetPtr->m = line;
	RetPtr->n = row;
	TuplePtr TmpData = (TuplePtr)malloc(sizeof(tuple) * row * line);
	if (!TmpData) exit(MALLOC_WRONG);

	for (int i = 0; i < line; i++)
	{
		printf("Please input the %dth line with %d elements:\n", i + 1, row);
		for (int j = 0; j < row; j++)
		{
			scanf("%d", &tmp);
			if (tmp)
			{
				TmpData[Count].i = i;
				TmpData[Count].j = j;
				TmpData[Count].v = tmp;
				Count++;
			}
		}
	}
	RetPtr->data = (TuplePtr)malloc(sizeof(tuple) * Count);
	if (!RetPtr->data) exit(MALLOC_WRONG);
	RetPtr->t = Count;
	memcpy(RetPtr->data, TmpData, sizeof(tuple) * Count);
	free(TmpData);
	PrintSparmat(RetPtr);

	return RetPtr;
}
SparmatPtr FastTranSpar(SparmatPtr src)//����ת��ϡ����󣬲�����ת�ú����Ԫ���
{
	SparmatPtr RetPtr = (SparmatPtr)malloc(sizeof(sparmattp));
	if (!RetPtr) exit(MALLOC_WRONG);
	RetPtr->m = src->n;
	RetPtr->n = src->m;
	RetPtr->t = src->t;
	RetPtr->data = (TuplePtr)malloc(sizeof(tuple) * RetPtr->t);
	if (!RetPtr->data) exit(MALLOC_WRONG);
	int* num = (int*)malloc(sizeof(int) * RetPtr->m), * Fcol = (int*)malloc(sizeof(int) * RetPtr->m), Col, Pos;
	if (!num || !Fcol) exit(MALLOC_WRONG);
	memset(num, 0, sizeof(int) * RetPtr->m);
	Fcol[0] = 0;
	for (int i = 0; i < src->t; i++)
		num[src->data[i].j]++;
	for (int i = 1; i < RetPtr->m; i++)
		Fcol[i] = Fcol[i - 1] + num[i - 1];
	for (int i = 0; i < src->t; i++)
	{
		Col = src->data[i].j;
		Pos = Fcol[Col];
		RetPtr->data[Pos].v = src->data[i].v;
		RetPtr->data[Pos].i = Col;
		RetPtr->data[Pos].j = src->data[i].i;
		Fcol[Col]++;
	}

	return RetPtr;
}
int CompTulp(TuplePtr src1, TuplePtr src2)//�ж�������Ԫ���ݵ�ǰ���ϵ��src1��ǰ����1��src1�ں󷵻�-1�����ߴ���ͬһλ�÷���0
{
	if (src1->i < src2->i || (src1->i == src2->i && src1->j < src2->j)) return 1;
	else if (src1->i > src2->i || (src1->i == src2->i && src1->j > src2->j)) return -1;
	else return 0;
}
void PrintSparmat(SparmatPtr Src)//��ӡ����Ԫ��洢�ľ���
{
	int Count = 0;
	for (int v = 0; v < Src->n; v++)
	{
		putchar('-');
		putchar('-');
	}
	putchar('\n');
	for (int i = 0; i < Src->m; i++)
	{
		for (int j = 0; j < Src->n; j++)
		{
			if ((i == Src->data[Count].i) && (j == Src->data[Count].j))
				printf("%d ", Src->data[Count++].v);
			else
				printf("0 ");
		}
		putchar('\n');
	}
}
void FreshSparmat(SparmatPtr Src)//��վ����ͷſռ�
{
	free(Src->data);
	free(Src);
}