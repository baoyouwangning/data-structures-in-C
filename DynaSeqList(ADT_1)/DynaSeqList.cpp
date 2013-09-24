/***
*DynaSeqList.cpp - 动态顺序表，即顺序表的动态数组实现
*
*
*题目：实验2-1 线性表的动态顺序存储实现
*
*	
****/

/***********************************************************************************************************
	Important: 
			1.	At first, please add some declarations to "ElemType.h"
				
				Make it like this:

									#ifndef ELEMTYPE_H
									#define ELEMTYPE_H

									#define TRUE 1
									#define FALSE 0
									#define OK 1
									#define ERROR 0
									#define INFEASIBLE -1
									#define OVERFLOW -2

									typedef int ElemType;

									int  compare(ElemType x, ElemType y);
									void visit(ElemType e);

									#endif
		   2. Second,you must declarated at you "main.c" like this:
				
				SqList *aList = NULL;
				aList = (SqList *)malloc(sizeof(SqList));
				aList -> elem = NULL;
		   3. 
		   	  If you want to see the entire project!

		  
		  https://github.com/baoyouwangning/data-structures-in-C/tree/master/DynaSeqList(ADT_1)


********************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaSeqList.h"

const int LIST_INIT_SIZE = 100;	// 表初始分配的最大长度
const int LISTINCREMENT  = 10;	// 分配内存的增量

/*------------------------------------------------------------
操作目的：	初始化顺序表
初始条件：	无
操作结果：	构造一个空的线性表
函数参数：
		SqList *L	待初始化的线性表
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitList(SqList *L)
{	
	if(!L) 
	{
		printf("线性表L不存在,请先定义！\n");
		//exit(OVERFLOW);
		return FALSE;
	}
	L -> elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!(L -> elem))
	{	
		printf("开辟元素内存失败！\n");
		return FALSE;
	}
	L -> length = 0;               
	L -> listsize = LIST_INIT_SIZE;  

	printf("初始化顺序表成功！\n");
	return OK;
}

/*------------------------------------------------------------
操作目的：	销毁顺序表
初始条件：	线性表L已存在
操作结果：	销毁线性表L
函数参数：
		SqList *L	待销毁的线性表
返回值：
		无
------------------------------------------------------------*/
void DestroyList(SqList *L)
{	
	if(!L) 
	{
		printf("线性表L不存在,请先定义！\n");
		//exit(OVERFLOW);
		return;
	}
	else if( !(L -> elem))
	{
		printf("顺序表未初始化！\n");
	}
	else
	{
		free(L -> elem);
		L -> elem = NULL;
		L -> length = 0;
	
		printf("销毁顺序表成功！\n");
		return;
	}
}

/*------------------------------------------------------------
操作目的：	判断顺序表是否为空
初始条件：	线性表L已存在
操作结果：	若L为空表，则返回true，否则返回false
函数参数：
		SqList L	待判断的线性表
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool ListEmpty(SqList L)
{	
	if(!L.elem) 
	{	
		printf("顺序表未初始化，顺序表为空！\n");
		return TRUE;
	}
	else if( L.length == 0)
	{
		printf("顺序表已初始化，顺序表为空！\n");
		return TRUE;
	}
	else 
	{
		printf("顺序表不为空！\n");
		return FALSE;
	}
}

/*------------------------------------------------------------
操作目的：	得到顺序表的长度
初始条件：	线性表L已存在
操作结果：	返回L中数据元素的个数
函数参数：
		SqList L	线性表L
返回值：
		int			数据元素的个数
------------------------------------------------------------*/
int ListLength(SqList L)
{	
	if(!(L.elem))
	{
		printf("顺序表没有初始化！请先初始化！\n");
		return FALSE;
	}
	printf("顺序表的长度为：%d\n",L.length);
	
	return L.length;
}

/*------------------------------------------------------------
操作目的：	得到顺序表的第i个元素
初始条件：	线性表L已存在，1<=i<=ListLength(L)
操作结果：	用e返回L中第i个数据元素的值
函数参数：
		SqList L	线性表L
		int i		数据元素的位置
		ElemType *e	第i个数据元素的值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool GetElem(SqList L, int i, ElemType *e)
{
	
	if(!(L.elem))
	{
		printf("顺序表未初始化！无法查找！\n");
		return FALSE;
	}
	else if( L.length == 0)
	{
		printf("顺序表长度为0！无法查找！\n");
		return FALSE;
	}
	else if(i >= 1 && i <= L.length)
	{	
		*e = L.elem[i-1];
		
		printf("顺序表的第%d个元素为：%d\n",i,*e);
		return OK;
	}
	else
	{
		printf("查找位置不在当前顺序表的长度之内！\n");
		return FALSE;
	}
}

/*------------------------------------------------------------
操作目的：	得到顺序表指定元素的位置
初始条件：	线性表L已存在
操作结果：	返回L中第一个与e满足关系compare()的数据元素的位序。
			若这样的元素不存在则返回0。
函数参数：
		SqList L	线性表L
		ElemType e	数据元素e
		int (*fp)()	用于比较相等的函数指针
返回值：
		int			与e满足关系compare()的数据元素的位序
------------------------------------------------------------*/
int LocateElem(SqList L, ElemType e, int (*fp)(ElemType, ElemType))
{	
	ElemType i;
	fp = &compare;

	if( !(L.elem) )
	{
		printf("查找失败！顺序表未初始化！\n");
		//exit(OVERFLOW);
		return FALSE;
	}
	else if( L.length == 0 )
	{
		printf("线性表中当前没有元素！\n");
		//exit(OVERFLOW);
		return FALSE;
	}
	else 
	{
		for(i = 0; i < L.length; i++)
		{
			if( !( (*fp)(L.elem[i],e)) )
			{	
				printf("表中第一个与元素%d相等的元素的位序为：%d\n",e,i+1);
				return i+1;
			}
		}
	}
}

/*------------------------------------------------------------
操作目的：	得到顺序表指定元素的前驱
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是第一个，则用pre_e返回
			它的前驱，否则操作失败，pre_e无定义
函数参数：
		SqList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *pre_e	前驱数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{	
	ElemType i;
	ElemType (*fp)(ElemType, ElemType);
	fp = &compare;

	if(!(L.elem))
	{
		printf("查找失败！顺序表未初始化！\n");
		return FALSE;
	}
	else if( L.length < 1 )
	{	
		printf("线性表中当前没有元素！\n");
		return FALSE;
	}
	else if( i = LocateElem(L,cur_e,fp) )
	{	
		if(i == 1) 
		{
			printf("线性表中的第一个元素没有前驱！\n");
			return FALSE;
		}
		*pre_e = L.elem[i-2];

		printf("表中第一个与元素%d相等的元素的前驱为：%d\n",cur_e,*pre_e);
		return OK;
	}
	else
	{
		return FALSE; 
	}
}

/*------------------------------------------------------------
操作目的：	得到顺序表指定元素的后继
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是最后一个，则用nxt_e返
			回它的后继，否则操作失败，nxt_e无定义
函数参数：
		SqList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *nxt_e	后继数据元素
返回值：
		bool				操作是否成功
------------------------------------------------------------*/
bool NextElem(SqList L, ElemType cur_e, ElemType *nxt_e)
{	
	ElemType i;
	ElemType (*fp)(ElemType, ElemType);
	fp = &compare;

	if(!(L.elem))
	{
		printf("查找失败！顺序表未初始化！\n");
		return FALSE;
	}
	else if(L.length < 1)
	{
		printf("线性表中没有元素！\n");
		return FALSE;
	}
	else if( i = LocateElem(L,cur_e,fp) )
	{	
		if(i == L.length) 
		{	
			printf("最后一个元素没有后继元素！\n");
			return FALSE;
		}
		*nxt_e = L.elem[i];

		printf("表中第一个与元素%d相等的元素的后继为：%d\n",cur_e,*nxt_e);
		return OK;
	}
	else 
	{
		return FALSE;
	}
	
}

/*------------------------------------------------------------
操作目的：	遍历顺序表
初始条件：	线性表L已存在
操作结果：	依次对L的每个元素调用函数fp
函数参数：
		SqList L		线性表L
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void ListTraverse(SqList L, void (*fp)(ElemType))
{
	fp = &visit;
	ElemType i;
	
	if(!(L.elem))
	{
		printf("遍历失败！顺序表未初始化！\n");
		return;
	}
	else if(L.length == 0)
	{
		printf("顺序表中没有元素！\n");
		return;
	}
	else 
	{
		for( i = 0; i < L.length; i++)
		{
			(*fp)(L.elem[i]);
		}
	}
}

/*------------------------------------------------------------
操作目的：	清空顺序表
初始条件：	线性表L已存在
操作结果：	将L置为空表
函数参数：
		SqList *L	线性表L
返回值：
		无
------------------------------------------------------------*/
void ClearList(SqList *L)
{	
	if(!L) 
	{
		printf("线性表L不存在,请先定义！\n");
		//exit(OVERFLOW);
		return;
	}
    if(!(L->elem))
	{
		printf("清空失败！顺序表没有初始化！\n");
		return;
	}
	else if( L -> length == 0)
	{
		printf("顺序表中没有元素，无需清空！\n");
	}
	else
	{
		L -> length = 0;
		printf("清空顺序表成功！\n");
	}	
}

/*------------------------------------------------------------
操作目的：	在顺序表的指定位置插入结点，插入位置i表示在第i个
			元素之前插入
初始条件：	线性表L已存在，1<=i<=ListLength(L) + 1
操作结果：	在L中第i个位置之前插入新的数据元素e，L的长度加1
函数参数：
		SqList *L	线性表L
		int i		插入位置
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListInsert(SqList *L, int i, ElemType e)
{	
	ElemType *newbase;
	ElemType *q;
	ElemType *p;

	if(!L) 
	{
		printf("线性表L不存在,请先定义！\n");
		return FALSE;
	}
	if(!(L->elem))
	{
		printf("插入失败！顺序表没有初始化！\n");
		return FALSE;
	}
	else if( i < 1 || i > L -> length+1)
	{
		printf("插入位置错误！当前表的长度为：%d\n",L->length);
		return ERROR;
	}
	else if( L -> length >= L -> listsize)
	{
		newbase = (ElemType *)realloc(L -> elem,(L -> listsize + LISTINCREMENT) * sizeof(ElemType) );
		if(!newbase)
		{	
			printf("内存开辟失败！\n");
			return FALSE;
		}
		L -> elem = newbase;
		L -> listsize += LISTINCREMENT;
	}

	q = &(L -> elem[i-1]);
	for(p = &(L->elem[L->length-1]); p >= q; p--)
	{
		*(p+1) = *p;
	}
	*q = e;
	L -> length++;

	printf("插入成功！\n");
	return OK;
}

/*------------------------------------------------------------
操作目的：	删除顺序表的第i个结点
初始条件：	线性表L已存在且非空，1<=i<=ListLength(L)
操作结果：	删除L的第i个数据元素，并用e返回其值，L的长度减1
函数参数：
		SqList *L	线性表L
		int i		删除位置
		ElemType *e	被删除的数据元素值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListDelete(SqList *L, int i, ElemType *e)
{	
	ElemType *p;
	ElemType *q;

	if(!L) 
	{
		printf("线性表L不存在,请先定义！\n");
		return FALSE;
	}
	if(!(L->elem))
	{
		printf("删除失败！顺序表没有初始化！\n");
		return FALSE;
	}
	else if(i < 1 || i > L -> length)
	{
		printf("删除位置错误！当前表的长度为：%d\n",L->length);
		return ERROR;
	}
	p = &(L -> elem[i-1]);
	*e = *p;
	q = L -> elem + L -> length - 1;
	
	for( p++; p <= q; p++)
	{
		*(p-1) = *p;
	}
	L -> length--;

	printf("删除的第%d个节点的值为：%d\n",i,*e);
	printf("第%d个节点删除成功！\n",i);
	return OK;
}