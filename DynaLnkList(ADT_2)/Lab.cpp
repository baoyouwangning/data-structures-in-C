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
		printf("       ===========================��̬�������============================\n");
		printf("       -                  I:��ʼ������                                   -\n");
		printf("       -                  D:��������                                     -\n");
		printf("       -                  E:�ж������Ƿ�Ϊ��                             -\n");
		printf("       -                  L:�õ�����ĳ���                               -\n");
		printf("       -                  G:�õ�����ĵ�i��Ԫ��                          -\n");
		printf("       -                  O:�õ�����ָ��Ԫ�ص�λ��                       -\n");
		printf("       -                  C:�õ�����ָ��Ԫ�ص�ǰ��                       -\n");
		printf("       -                  N:�õ�����ָ��Ԫ�صĺ��                       -\n");
		printf("       -                  T:��������                                     -\n");
		printf("       -                  R:�������                                     -\n");
		printf("       -                  S:�������ָ��λ�ò�����                     -\n");
		printf("       -                  P:ɾ������ĵ�i�����                          -\n");
		printf("       -                  Q:�˳�����                                     -\n");
		printf("       ===========================��̬�������============================\n");
		printf("^_^��ѡ��:");

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
			printf("������Ҫ���ҵڼ�������");
			scanf("%d",&i);
			fflush(stdin);

			//bool GetElem(LinkList L, int i, ElemType *e);
			GetElem(aHead,i,&e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('O' == choice)
		{
			printf("������Ҫ����Ԫ�ص�ֵ��");
			scanf("%d",&e);

			//int  LocateElem(LinkList L, ElemType e, int (*fp)(ElemType, ElemType));
			LocateElem(aHead,e,fpc);


			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('C' == choice)
		{
			printf("������Ҫ������ǰ����Ԫ�أ�");
			scanf("%d",&i);
			fflush(stdin);

			//bool PriorElem(LinkList L, ElemType cur_e, ElemType *pre_e);
			PriorElem(aHead,i,&e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('N' == choice)
		{
			printf("������Ҫ�������̵�Ԫ�أ�");
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
			printf("������Ҫ�����λ�ã�");
			scanf("%d",&i);
			fflush(stdin);
			printf("������Ҫ�����Ԫ�أ�");
			scanf("%d",&e);

			//bool ListInsert(LinkList L, int i, ElemType e);
			ListInsert(aHead,i,e);

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
		else if('P' == choice)
		{
			printf("������Ҫɾ����λ�ã�");
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
			printf("ѡ������������ѡ��\n");

			system("pause");   // only for windows
			system("cls");	 // only for windows
		}
	}	
	return 0;
}