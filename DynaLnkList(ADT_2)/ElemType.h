/***
*ElemType.h - ElemTypeµÄ¶¨Òå
*
****/

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

#endif /* ELEMTYPE_H */