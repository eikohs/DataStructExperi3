#include "Tuple.h"

/*����ϡ�����A��B������Ԫ�����Ϊ�洢�ṹ����д��������Ӻ���˵��㷨��������Ԫ���C��Ž������
*Ҫ��
*�Ӽ�������ϡ�����A��B
*���A��B�ܷ����/���
*���ܣ���������Ӻ�������㣬����ӡ������
*�粻�ܣ�Ӧ��ʾ��ԭ��*/

/*
����������
3 3
1 0 0
0 1 0
0 0 1
3 3
2 2 2
1 1 1
0 0 0

3 4
0 1 1 1
1 1 1 0
1 0 1 1
4 4
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1

4 4
1 0 0 0
0 1 0 0
0 0 1 0
0 0 0 1
3 4
0 1 1 1
1 1 1 0
1 0 1 1

5 5
1 0 0 0 0
0 1 0 0 0
0 0 1 0 0
0 0 0 1 0
0 0 0 0 1
5 5
0 0 0 0 1
0 0 0 1 0
0 0 1 0 0
0 1 0 0 0
1 0 0 0 0

6 6
15 0 0 22 0 -15
0 11 3 0 0 0
0 0 0 -6 0 0
0 0 0 0 0 0
91 0 0 0 0 0
0 0 28 0 0 0
6 6
15 0 0 0 91 0
0 11 0 0 0 0
0 3 0 0 0 28
22 0 -6 0 0 0
0 0 0 0 0 0
-15 0 0 0 0 0

*/
int main(void)
{
#if TESTFUN
	SparmatPtr test = InitSparmat();
	SparmatPtr trantest = FastTranSpar(test);
	PrintSparmat(trantest);
#else
	SparmatPtr Src1 = InitSparmat();
	SparmatPtr Src2 = InitSparmat();

	SparmatPtr Mul = MultiSparmat(Src1, Src2), Add = AddSparmat(Src1, Src2);
	if (Add)
	{
		puts("The result of Motrix1 + Motrix2:");
		PrintSparmat(Add);
	}
	if (Mul)
	{
		puts("The result of Motrix1 * Motrix2:");
		PrintSparmat(Mul);
	}

	FreshSparmat(Src1);
	FreshSparmat(Src2);
#endif
	return 0;
}