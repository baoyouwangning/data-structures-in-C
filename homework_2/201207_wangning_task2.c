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
		printf("�ڴ濪��ʧ��");
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

	for(i = 0; i < cLen; i++)
	{
		*pa++ = *pc++;
	}

	*aLen = cLen;

	free(c);
	return 1;
} 
