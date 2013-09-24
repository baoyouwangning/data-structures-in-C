#include <stdlib.h>
#include <stdio.h>
#include "DynaSeqList.h"

int main()
{
	//test
	SqList *aList = NULL;
	char choice;
	ElemType i;
	ElemType e;
	ElemType refresh = 5;
	ElemType (*fp)(ElemType, ElemType);
	void (*fq)(ElemType); 
	
	aList = (SqList *)malloc(sizeof(SqList));
	aList -> elem = NULL;

	while(1)
	{
		if(!(refresh % 5))
		{
			printf("************************************************************************\n");
			printf("线性表，顺序表操作\n");
			printf("I:初始化顺序表\n");
			printf("D:销毁顺序表\n");
			printf("T:判断顺序表是否为空\n");
			printf("L:得到顺序表的长度\n");
			printf("G:得到顺序表的第i个元素\n");
			printf("E:得到顺序表指定元素的位置\n");
			printf("H:得到顺序表指定元素的前驱\n");
			printf("J:得到顺序表指定元素的后继\n");
			printf("F:遍历顺序表\n");
			printf("C:清空顺序表\n");
			printf("K:在顺序表的指定位置插入结点，插入位置i表示在第i个元素之前插入\n");
			printf("M:删除顺序表的第i个结点\n");
			printf("Q:退出程序\n");
			printf("************************************************************************\n");
		}
		
		fflush(stdin);
		printf("请选择操作：");
		scanf("%c",&choice);
		refresh++;

		switch(choice)
		{
		case 'I':
			//bool InitList(SqList *L);
			InitList(aList);
		
			break;
		case 'D':
			//void DestroyList(SqList *L);
			DestroyList(aList);	
			break;
		case 'T':
			//bool ListEmpty(SqList L);
			ListEmpty(*aList);

			break;
		case 'L':
			//int  ListLength(SqList L);
			ListLength(*aList);

			break;
		case 'G':
			printf("请输入要获得第几个元素：");
			scanf("%d",&i);
			fflush(stdin);

			//bool GetElem(SqList L, int i, ElemType *e);
			if(GetElem(*aList,i,&e))
			{
				printf("第%d个元素=%d\n",i,e);
				system("pause");
			}
			break;
		case 'E':
			fp = &compare;

			printf("请输入要查找元素的值：");
			scanf("%d",&e);
			fflush(stdin);

			//int  LocateElem(SqList L, ElemType e, int (*fp)(ElemType, ElemType)); 
			if( i = LocateElem(*aList,e,fp))
			{
				printf("表中第一个与元素%d相等的元素的位序为：%d\n",e,i);
				system("pause");
			}
			break;
		case 'H':
			printf("请输入要获得其前驱的元素：");
			scanf("%d",&i);
			fflush(stdin);

			//bool PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
			if(PriorElem(*aList,i,&e))
			{
				printf("表中第一个与元素%d相等的元素的前驱为：%d\n",i,e);
				system("pause");
			}

			break;
		case 'J':
			printf("请输入要获得其后继的元素：");
			scanf("%d",&i);
			fflush(stdin);

			//bool NextElem(SqList L, ElemType cur_e, ElemType *nxt_e);
			if(NextElem(*aList,i,&e))
			{
				printf("表中第一个与元素%d相等的元素的后继为：%d\n",i,e);
				system("pause");
			}

			break;
		case 'F':
			fq = &visit;

			//void ListTraverse(SqList L, void (*fp)(ElemType));
			ListTraverse(*aList,fq);
		
			break;
		case 'C':
			//void ClearList(SqList *L);
			ClearList(aList);

			break;
		case 'K':
			printf("请输入要插入的插入位置：");
			scanf("%d",&i);
			printf("请输入要插入的元素：");
			scanf("%d",&e);
			fflush(stdin);

			//bool ListInsert(SqList *L, int i, ElemType e);
			ListInsert(aList,i,e);

			break;
		case 'M':
			printf("请输入要删除节点的位序：");
			scanf("%d",&i);
			fflush(stdin);

			//bool ListDelete(SqList *L, int i, ElemType *e);
			if(ListDelete(aList,i,&e))
			{
				printf("删除的第%d个节点的值为：%d",i,e);
			}

			break;
		case 'Q':	
			return 0;
		}
	}
	
	system("pause");
	return 0;
}