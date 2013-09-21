/*************************************************************************
	> Function: replace A with merge array A and B
	> Author: wangning
	> Mail: 201207wangning@edu2act.org or winvalx@qq.com
	> Created Time: 2013-09-20 Friday 11:34:50
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int	IntersectAandB(int **a,int *b,int *aLen,int bLen);

int main(void)
{
    //.....
	int i;
	int *A;
	int *B;
	int aLen = 5;
	int bLen = 4;
	
	A = (int *)malloc(sizeof(int) * 5);
	B = (int *)malloc(sizeof(int) * 4);

	A[0] = 1;
	A[1] = 2;
	A[2] = 3;
	A[3] = 3;
	A[4] = 5;
	B[0] = 3;
	B[1] = 4;
	B[2] = 4;
	B[3] = 6;

	IntersectAandB(&A,B,&aLen,bLen);

	for(i = 0; i < aLen; i++)
	{
		printf("%d\n",A[i]);
	}

	system("pause");
	return 0;
}

/***************************************************************
    函数功能：合并数组A和B的交集C并利用A表空间存放C表(数据元素均为整数)
    算法思想：判断数组的长度 当其长度小于1时返回0；
			 当其长度大于1时，先开辟A.size+B.size的空间给C，
			 然后用三个指针分指向数组A，B，C依次移动并判断大小赋值给数组C，
			 然后根据记录的C的长度，重新给A开辟空间，并将C中的元素遍历赋值给A，
			 最后释放临时空间C，
			 返回1
    函数参数：int **a  数组变量A的地址（在函数中*a要改变A的指向）
            int *b   数组变量B指向的地址
			int *aLen 数组A长度的变量的指针
			int bLen  数组B的长度
    返回值： 若合并成功，则返回1，
			若合并失败，则返回0
    时间复杂度：O(n): n = La.size + Lb.size；
    空间复杂度：O(n): n = La.size + Lb.size;
***************************************************************/
int 	IntersectAandB(int **a,int *b,int *aLen,int bLen)
{
	int *c;
	int cLen = 0;
	int *pc;
	int *pa;
	int *pb;
	int *pa_last;
	int *pb_last;
	int i;

	if( *aLen <= 0 || bLen <= 0)
	{
		return 0;
	}

	c = (int *)malloc( sizeof(int) * (*aLen + bLen) );
	if(!c)
	{
		printf("内存开辟失败");
		return 0;
	}
		
	pa = *a;
	pb = b;
	pa_last = *a + *aLen - 1;
	pb_last = b + bLen - 1;
	pc = c;

	while(pa <= pa_last && pb <= pb_last)
	{
		if(*pa <= *pb)
		{
			if( *pa == *(pc-1) )
			{	
				pa++;
			}
			else
			{
				*pc++ = *pa++;
				cLen++;
			}
		}
		else
		{
			if( *pb == *(pc-1) )
			{	
				pb++;
			}
			else
			{
				*pc++ = *pb++;
				cLen++;
			}
		}
	}
	while(pa <= pa_last)
	{
		if(*pa == *(pc-1))
		{
			pa++;
		}
		else 
		{
			*pc++ = *pa++;
			cLen++;
		}
	}
	while(pb <= pb_last)
	{
		if(*pb == *(pc-1))
		{
			pb++;
		}
		else 
		{
			*pc++ = *pb++;
			cLen++;
		}	
	}
	
	*a = (int *)realloc(*a,sizeof(int) * cLen);
	*aLen = cLen;
	pa = *a;
	pc = c;

	for(i = 0; i < cLen; i++)
	{
		*pa++ = *pc++;
	}

	free(c);
	return 1;
} 
