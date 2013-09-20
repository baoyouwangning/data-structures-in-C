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
		printf("a��Ԫ���ǵȲ�����,diatance=%d\n",distance);
	}

	if(ListIsArithmeticSequence(b,2,&distance))
	{
		printf("b��Ԫ���ǵȲ�����,diatance=%d\n",distance);
	}

	if(ListIsArithmeticSequence(c,3,&distance))
	{
		printf("c��Ԫ���ǵȲ�����,diatance=%d\n",distance);
	}

	if(ListIsArithmeticSequence(d,5,&distance))
	{
		printf("d��Ԫ���ǵȲ�����,diatance=%d\n",distance);
	}
	
	system("pause");
    return 0;
}

/***************************************************************
    �������ܣ����Ҹ������Ա��е�����Ԫ���ܷ���ɵȲ�����(����Ԫ�ؾ�Ϊ����)
    �㷨˼�룺�ж�����ĳ��� ���䳤��С��2ʱ����0��
			 ���䳤�ȵ���2ʱ���򹹳ɵȲ����У�����=��һ���ǰһ�
			 ���䳤�ȴ���2ʱ���������ж�L[i] - L[i-1] == L[i-1] - L[i-2] ��
			 ������ ���� =  L[1] - L[0];
    ����������int *L   ���������ָ��
             int len   ������Ԫ�ظ���
             int *distance   ���й���
    ����ֵ��  �����ҳɹ������distance��ֵ������1��
              ������ʧ�ܣ���ֱ�ӷ���-1.
    ʱ�临�Ӷȣ�O(n):����n��ʾ������Ԫ�ظ���
    �ռ临�Ӷȣ�O(1):û�и����ռ�
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
