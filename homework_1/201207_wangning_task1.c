/*************************************************************************
	> Function: Find element in array
	> Author: wangning
	> Mail: 201207wangning@edu2act.org or winvalx@qq.com
	> Created Time: 2013-09-08 Sunday 11:34:50
 ************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int findElementInArray(int a[], int size,int elem);

int main(void)
{
    //.....

    return 0;
}

/***************************************************************
    函数功能：在数组中查找是否有指定元素存在
    算法思想：把待查找元素依次和数组中的每一个元素进行比较，若
             待查找元素与指定元素相等，则返回当前元素下标；
             否则，数组遍历完毕也没有找到指定元素，则返回-1.
    函数参数：int a[]    待查找元素的数组
             int size   数组中元素个数
             int elem   待查找元素值
    返回值：  若查找成功，返回待查找元素在数组中的下标；
             若查找失败，则返回-1.
    时间复杂度：O(n):其中n表示数组中元素个数
    空间复杂度：O(1);
***************************************************************/
int findElementInArray(int a[], int size,int elem)
{
    int i;
    for(i = 0; i < size; i++)
    {
        if(a[i] == elem)
        {
            return i;
        }
    }
    return -1;
}
