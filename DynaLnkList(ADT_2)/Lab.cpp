#include <stdio.h>
#include <stdlib.h>
#include "DynaLnkList.h"

int main()
{
	// TODO: Place your test code here
	LinkList aHead = NULL;
	ElemType e;
	ElemType i;
	ElemType (*fpc)(ElemType, ElemType) =  &compare;
	void (*fpv)(ElemType) = &visit;
	char choice;

	while(1)
	{
		printf("       ===========================动态链表测试============================\n");
		printf("       -                  I:初始化链表                                   -\n");
		printf("       -                  D:销毁链表                                     -\n");
		printf("       -                  E:判断链表是否为空                             -\n");
		printf("       -                  L:得到链表的长度                               -\n");
		printf("       -                  G:得到链表的第i个元素                          -\n");
		printf("       -                  O:得到链表指定元素的位置                       -\n");
		printf("       -                  C:得到链表指定元素的前驱                       -\n");
		printf("       -                  N:得到链表指定元素的后继                       -\n");
		printf("       -                  T:遍历链表                                     -\n");
		printf("       -                  R:清空链表                                     -\n");
		printf("       -                  S:在链表的指定位置插入结点                     -\n");
		printf("       -                  P:删除链表的第i个结点                          -\n");
		printf("       -                  Q:退出测试                                     -\n");
		printf("       ===========================动态链表测试============================\n");
		printf("^_^请选择:");

		scanf("%c",&choice);
		fflush(stdin);

		if('I' == choice)
		{
			//bool InitList(LinkList *L);
			InitList(&aHead);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('D' == choice)
		{

			//void DestroyList(LinkList *L);
			DestroyList(&aHead);
			
			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('E' == choice)
		{
			//bool ListEmpty(LinkList L);
			ListEmpty(aHead);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('L' == choice)
		{
			//int  ListLength(LinkList L);
			ListLength(aHead);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('G' == choice)
		{
			printf("请输入要查找第几个数：");
			scanf("%d",&i);
			fflush(stdin);

			//bool GetElem(LinkList L, int i, ElemType *e);
			GetElem(aHead,i,&e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('O' == choice)
		{
			printf("请输入要查找元素的值：");
			scanf("%d",&e);

			//int  LocateElem(LinkList L, ElemType e, int (*fp)(ElemType, ElemType));
			LocateElem(aHead,e,fpc);


			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('C' == choice)
		{
			printf("请输入要查找其前驱的元素：");
			scanf("%d",&i);
			fflush(stdin);

			//bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);
			PriorElem(aHead,i,&e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('N' == choice)
		{
			printf("请输入要查找其后继的元素：");
			scanf("%d",&i);
			fflush(stdin);

			//bool NextElem(LinkList L, ElemType cur_e, ElemType *nxt_e);
			NextElem(aHead,i,&e);


			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('T' == choice)
		{
			//void ListTraverse(LinkList L, void (*fp)(ElemType));
			ListTraverse(aHead,fpv);


			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('R' == choice)
		{
			//void ClearList(LinkList L);
			ClearList(aHead);
			aHead = NULL;

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('S' == choice)
		{
			printf("请输入要插入的位置：");
			scanf("%d",&i);
			fflush(stdin);
			printf("请输入要插入的元素：");
			scanf("%d",&e);

			//bool ListInsert(LinkList L, int i, ElemType e);
			ListInsert(aHead,i,e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('P' == choice)
		{
			printf("请输入要删除的位置：");
			scanf("%d",&i);

			//bool ListDelete(LinkList L, int i, ElemType *e);
			ListDelete(aHead,i,&e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('Q' == choice)
		{
			return 0;
		}
		else 
		{
			printf("选择有误！请重新选择！\n");

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
	}	
	return 0;
}