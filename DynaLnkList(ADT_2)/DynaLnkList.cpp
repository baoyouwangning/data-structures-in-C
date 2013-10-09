/***
*DynaLnkList.cpp - 动态链表，即顺序表的动态链式存储实现
*
*
*题目：实验2-2 线性表的动态链式存储实现
*
*	
****/

/******************************************************************************
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
		  2.
		  else if('R' == choice)
		{
			//void ClearList(LinkList L);
			ClearList(aHead);
			aHead = NULL;

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}




*********************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <assert.h>
#include "DynaLnkList.h"

/*------------------------------------------------------------
操作目的：	初始化链表
初始条件：	无
操作结果：	构造一个空的线性表
函数参数：
		LinkList *L	待初始化的线性表
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool InitList(LinkList *L)
{
	*L = (LinkList)malloc(sizeof(LNode));//*L = (LNode *)malloc(sizeof(LNode));
	if(!(*L))
	{
		printf("头结点内存开辟失败！程序退出！\n");
		return FALSE;
	}
	(*L) -> next = NULL;

	printf("初始化链表成功！^_^\n");
	return TRUE;
}

/*------------------------------------------------------------
操作目的：	销毁链表
初始条件：	线性表L已存在
操作结果：	销毁线性表L
函数参数：
		LinkList *L	待销毁的线性表
返回值：
		无
------------------------------------------------------------*/
void DestroyList(LinkList *L)
{
	LinkList p;

	if(!(*L))
	{
		printf("链表未初始化！\n");
		return;
	}
	else 
	{	
		while((*L)->next)
		{
			p = (*L)->next;
			free(*L);
			*L = p;
		}
		free(*L);
		*L = NULL;

		printf("销毁链表成功！^_^\n");
		return;
	}
}

/*------------------------------------------------------------
操作目的：	判断链表是否为空
初始条件：	线性表L已存在
操作结果：	若L为空表，则返回true，否则返回false
函数参数：
		LinkList L	待判断的线性表
返回值：
		bool		是否为空
------------------------------------------------------------*/
bool ListEmpty(LinkList L)
{
	if(!L)
	{
		printf("链表未初始化！链表为空！\n");
		return FALSE;
	}
	else if(!(L->next))
	{
		printf("链表只用头结点！链表为空！\n");
		return FALSE;
	}
	else
	{
		printf("链表不为空！");
		return TRUE;
	}
}

/*------------------------------------------------------------
操作目的：	得到链表的长度
初始条件：	线性表L已存在
操作结果：	返回L中数据元素的个数
函数参数：
		LinkList L	线性表L
返回值：
		int			数据元素的个数
------------------------------------------------------------*/
int ListLength(LinkList L)
{
	ElemType length = 0;

	if(!L)
	{
		printf("链表未初始化！\n");
		return FALSE;
	}
	else if(!(L->next))
	{
		printf("链表只用头结点！数据元素为空！\n");
		return FALSE;
	}
	else 
	{
		while(L = L -> next)
		{
			length++;
		}
		printf("链表的数据元素的个数（长度）为%d\n",length);
		return length;
	}
}

/*------------------------------------------------------------
操作目的：	得到链表的第i个元素
初始条件：	线性表L已存在，1<=i<=ListLength(L)
操作结果：	用e返回L中第i个数据元素的值
函数参数：
		LinkList L	线性表L
		int i		数据元素的位置
		ElemType *e	第i个数据元素的值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool GetElem(LinkList L, int i, ElemType *e)
{	
	fflush(stdin);
	LinkList p;
	ElemType j;

	if(!L)
	{
		printf("链表未初始化！\n");
		return FALSE;
	}
	else 
	{
		p = L -> next;
		j = 1;
		while( p && j < i)
		{
			p = p -> next;
			j++;
		}
		if(!p || j > i)
		{
			printf("查找位置不存在！\n");
			return ERROR;
		}
		*e = p -> data;
		printf("第i=%d的数据元素的值为：%d\n",i,*e);
		return OK;
	}
}

/*------------------------------------------------------------
操作目的：	得到链表指定元素的位置
初始条件：	线性表L已存在
操作结果：	返回L中第一个与e满足关系compare()的数据元素的位序。
			若这样的元素不存在则返回0。
函数参数：
		LinkList L	线性表L
		ElemType e	数据元素e
		int (*fp)()	用于比较相等的函数指针
返回值：
		int			与e满足关系compare()的数据元素的位序
------------------------------------------------------------*/
int LocateElem(LinkList L, ElemType e, int (*fp)(ElemType, ElemType))
{	
	fflush(stdin);
	fp = &compare;
	LinkList p;
	ElemType i = 0;

	if(!L)
	{
		printf("链表未初始化！\n");
		return FALSE;
	}
	else 
	{	
		p = L -> next;
		while( p && (*fp)(p->data,e))
		{
			p = p -> next;
			i++;
		}
		if(!p)
		{
			printf("查找位置不存在！\n");
			return ERROR;
		}
		printf("第一个与相等的数据元素的位序：%d\n",i);
		return i;
	}
}

/*------------------------------------------------------------
操作目的：	得到链表指定元素的前驱
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是第一个，则用pre_e返回
			它的前驱，否则操作失败，pre_e无定义
函数参数：
		LinkList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *pre_e	前驱数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e)
{
	fflush(stdin);
	LinkList p;
	ElemType (*fpc)(ElemType, ElemType) =  &compare;

	if(!L)
	{
		printf("链表未初始化！\n");
		return FALSE;
	}
	else 
	{
		p = L;
		while( p->next && (*fpc)(cur_e,p->next->data) )
		{
			p = p -> next;
		}	
		if(!(p->next))
		{
			printf("当前链表中没有您指定的元素%d\n",cur_e);
			return FALSE;
		}
		else if( p == L)
		{
			printf("第一个与您指定的元素相等的为第一个元素，故其无前驱！\n");
			return FALSE;
		}
		else
		{	
			*pre_e = p -> data;
			printf("指定元素%d的前驱%d\n",cur_e,*pre_e);
			return OK;
		}
	}
}

/*------------------------------------------------------------
操作目的：	得到链表指定元素的后继
初始条件：	线性表L已存在
操作结果：	若cur_e是L的数据元素，且不是最后一个，则用nxt_e返
			回它的后继，否则操作失败，nxt_e无定义
函数参数：
		LinkList L		线性表L
		ElemType cur_e	数据元素cur_e
		ElemType *nxt_e	后继数据元素
返回值：
		bool			操作是否成功
------------------------------------------------------------*/
bool NextElem(LinkList L, ElemType cur_e, ElemType *nxt_e)
{
	fflush(stdin);
	LinkList p;
	ElemType (*fpc)(ElemType, ElemType) =  &compare;

	if(!L)
	{
		printf("链表未初始化！\n");
		return FALSE;
	}
	else 
	{
		p = L -> next;
		while( p && (*fpc)(cur_e,p->data) )
		{
			p = p -> next;
		}
		if(!p)
		{
			printf("当前链表中没有您指定的元素%d\n",cur_e);
			return FALSE;
		}
		else if(!(p->next))
		{
			printf("第一个与您指定的元素相等的为最后一个元素，故其无后继！\n");
			return FALSE;
		}
		else
		{
			*nxt_e = p -> next -> data;
			return OK;
		}
	}
}

/*------------------------------------------------------------
操作目的：	遍历链表
初始条件：	线性表L已存在
操作结果：	依次对L的每个元素调用函数fp
函数参数：
		LinkList L		线性表L
		void (*fp)()	访问每个数据元素的函数指针
返回值：
		无
------------------------------------------------------------*/
void ListTraverse(LinkList L, void (*fp)(ElemType))
{
	LinkList p;
	fp = &visit;

	if(!L)
	{
		printf("链表未初始化！\n");
		return;
	}
	else if(!(L->next))
	{
		printf("链表只用头结点！数据元素为空！\n");
		return;
	}
	else 
	{
		p = L;
		while(p = p->next )
		{
			(*fp)(p->data);
		}
	}
	return;
}
/*------------------------------------------------------------
操作目的：	清空链表
初始条件：	线性表L已存在
操作结果：	将L置为空表
函数参数：
		LinkList L	线性表L
返回值：
		无
------------------------------------------------------------*/
void ClearList(LinkList L)
{	
	LinkList p;

	if(!L)
	{
		printf("链表未初始化！无需清空\n");
		return;
	}
	else 
	{	
		while(L->next)
		{
			p = L->next;
			free(L);
			L = p;
		}
		free(L);
		L = NULL;
		printf("清空链表成功！^_^\n");
		return;
	}
}

/*------------------------------------------------------------
操作目的：	在链表的指定位置插入结点，插入位置i表示在第i个
			元素之前插入
初始条件：	线性表L已存在，1<=i<=ListLength(L) + 1
操作结果：	在L中第i个位置之前插入新的数据元素e，L的长度加1
函数参数：
		LinkList L	线性表L
		int i		插入位置
		ElemType e	待插入的数据元素
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListInsert(LinkList L, int i, ElemType e)
{
	fflush(stdin);
	LinkList p;
	LinkList s;
	int j;

	if(!L)
	{
		printf("链表未初始化！\n");
		return FALSE;
	}
	else 
	{
		p = L;
		j = 0;
		while(p && j < i-1)
		{
			p = p -> next;
			j++;
		}
		if(!(j <= i-1))
		{
			printf("i小于1,删除位置不存在!\n");
			return FALSE;
		}
		else if(!p)
		{
			printf("插入位置大于当前表长+1,删除位置不存在\n");
			return FALSE;
		}
		else
		{
			s = (LinkList)malloc(sizeof(LNode));
			s -> data = e;
			s -> next = p -> next;
			p -> next = s;

			printf("插入成功! ^_^\n");
			return OK;
		}
	}
}

/*------------------------------------------------------------
操作目的：	删除链表的第i个结点
初始条件：	线性表L已存在且非空，1<=i<=ListLength(L)
操作结果：	删除L的第i个数据元素，并用e返回其值，L的长度减1
函数参数：
		LinkList L	线性表L
		int i		删除位置
		ElemType *e	被删除的数据元素值
返回值：
		bool		操作是否成功
------------------------------------------------------------*/
bool ListDelete(LinkList L, int i, ElemType *e)
{
	fflush(stdin);
	LinkList p;
	LinkList q;
	int j;

	if(!L)
	{
		printf("链表未初始化！无需清空\n");
		return FALSE;
	}
	else 
	{
		p = L;
		j = 0;
		while(p->next && j < i-1)
		{
			p = p -> next;
			j++;
		}
		if(!(p->next) || j > i-1)
		{
			return ERROR;
		}
		q = p -> next;
		p -> next = q -> next;
		*e = q -> data;
		free(q);

		return OK;
	}	
}