/*************************************************************************
	> Function: Check the List Is a Arithmetic Sequence
	> Author: wangning
	> Mail: 201207wangning@edu2act.org or winvalx@qq.com
	> Created Time: 2013-09-20 Friday 11:34:50
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int ListIsArithmeticSequence(int *L,int len,int *distance);

int main(void)
{
    //.....
	int a[1] = {1};
	int b[2] = {1,2};
	int c[3] = {1,2,3};
	int d[5] = {1,2,3,4,6};
	int distance = 0;

	if( ListIsArithmeticSequence(a,1,&distance) )
	{
		printf("a中元素是等差数列,diatance=%d\n",distance);
	}

	if(ListIsArithmeticSequence(b,2,&distance))
	{
		printf("b中元素是等差数列,diatance=%d\n",distance);
	}

	if(ListIsArithmeticSequence(c,3,&distance))
	{
		printf("c中元素是等差数列,diatance=%d\n",distance);
	}

	if(ListIsArithmeticSequence(d,5,&distance))
	{
		printf("d中元素是等差数列,diatance=%d\n",distance);
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
int ListIsArithmeticSequence(int *L,int len,int *distance)
{
	int i;

	if(len <= 1)
	{
		return 0;
	}
	else if(len == 2)
	{
		*distance = L[1] - L[0];
		return 1;
	}
	else
	{
		for(i = 2; i < len; i++)
		{
			if( L[i] - L[i-1] != L[i-1] - L[i-2] )
			{
				return 0;
			}
		}
		*distance = L[1] - L[0];

		return 1;		
	}
}
