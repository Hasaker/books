#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ERROR 0
#define OK 1

typedef int Status;

typedef struct DualNode
{
	char data;
	struct DualNode *prior;
	struct DualNode *next;
}DualNode, *DuLinkList;   // 取两个别名


Status InintList(DuLinkList *L)
{
	DualNode *p, *q;
	int i;

	*L = (DuLinkList)malloc(sizeof(DualNode));
	if( !(*L))
	{
		return ERROR;
	}

	(*L)->next = (*L)->prior = NULL;
	p = (*L);

	for( i = 0; i < 26; i++ )
	{
		q = (DualNode *)malloc(sizeof(DualNode));
		if( !q )
		{
			return ERROR;
		}

		q->data = 'A'+i;
		q->prior = p;
		q->next = p->next;
		p->next = q;

		p = q;
	}

	p->next = (*L)->next;
	(*L)->next->prior = p;

	return OK;
}

void Carser(DuLinkList *L, int i)
{
	if( i > 0 )
	{
		do
		{
			(*L) = (*L)->next;
		}while( --i );
	}
	if( i < 0 )
	{
		do
		{
			(*L) = (*L)->next;
		}while( ++i );
	}
}

int main()
{
	DuLinkList L;
	int i, n;

	InintList(&L);

	printf("请输入一个整数：");
	scanf("%d", &n);
	printf("\n");

	double duration;
    clock_t start, finish;

    start = clock();
	Carser(&L, n);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;

	for( i = 0; i < 26; i++ )
	{
		L = L->next;
		printf("%c", L->data);
	}
	printf("\n");
	printf("Time to calculate is %f seconds.", duration);
	printf("\n");
}