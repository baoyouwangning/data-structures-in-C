/*************************************************************************
	> Function: Check the List Is a Arithmetic Sequence
	> Author: wangning
	> Mail: 201207wangning@edu2act.org or winvalx@qq.com
	> Created Time: 2013-09-20 Friday 11:34:50
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int	IntersectAandB(int *a,int *b,int *aLen,int bLen);

int main(void)
{
    //.....
	int *A;
	int *B;
	int aLen = 2;
	int bLen = 2;
	int i;

	A = (int *)malloc(sizeof(int) * 2);
	B = (int *)malloc(sizeof(int) * 2);

	A[1] = 1;
	A[2] = 2;
	B[1] = 3;
	B[2] = 4;

	IntersectAandB(A,B,&aLen,bLen);

	for(i = 0; i < aLen; i++)
	{
		printf("%d\n",A[i]);
	}

	system("pause");
	return 0;
}

/***************************************************************
    函数功能：查找给定线性表中的数据元素能否组成等差数列(数据元素均为整数)
    算法思想：判断数组的长度 当其长度小于2时返回0；
			 当其长度等于2时，则构成等差数列，公差=后一项减前一项；
			 当其长度大于2时，则依次判断L[i] - L[i-1] == L[i-1] - L[i-2] ？
			 成立则 公差 =  L[1] - L[0];
    函数参数：int *L   待检测数组指针
             int len   数组中元素个数
             int *distance   数列公差
    返回值：  若查找成功，则给distance赋值，返回1；
              若查找失败，则直接返回-1.
    时间复杂度：O(n):其中n表示数组中元素个数
    空间复杂度：O(1):没有辅助空间
***************************************************************/
int 	IntersectAandB(int *a,int *b,int *aLen,int bLen)
{
	int *c;
	int cLen = 0;
	int *pc;
	int *pa;
	int *pb;
	int *pa_last;
	int *pb_last;
	int i;

	if(*aLen <= 0 || bLen <= 0)
	{
		return 0;
	}

	c = (int *)malloc(sizeof(int) * (*aLen + bLen));
	if(!c)
	{
		printf("内存开辟失败");
		return 0;
	}

	
	
	pa = a;
	pb = b;
	pa_last = a + *aLen - 1;
	pb_last = b + bLen - 1;
	pc = c;

	while(pa <= pa_last && pb <= pb_last)
	{
		if(*pa <= *pb)
		{
			*pc++ = *pa++;
			cLen++;
		}
		else
		{
			*pc++ = *pb++;
			cLen++;
		}
	}

	while(pa <= pa_last)
	{
		*pc++ = *pa++;
		cLen++;
	}
	while(pb <= pb_last)
	{
		*pc++ = *pb++;
		cLen++;
	}
	
	a = (int *)realloc(a,sizeof(int) * cLen);
	pa = a;
	pc = c;

	c[1] = 1;
	c[2] = 2;
	c[3] = 3;
	c[4] = 4;

	for(i = 0; i < cLen; i++)
	{
		*pa++ = *pc++;
	}

	*aLen = cLen;

	free(c);
	return 1;
} 