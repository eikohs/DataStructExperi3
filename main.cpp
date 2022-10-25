#include "Tuple.h"

/*假设稀疏矩阵A和B均以三元组表作为存储结构，试写出矩阵相加和相乘的算法，另设三元组表C存放结果矩阵。
*要求：
*从键盘输入稀疏矩阵A和B
*检测A和B能否相加/相乘
*如能，做矩阵相加和相乘运算，并打印运算结果
*如不能，应显示出原因*/

/*
测试用例：
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