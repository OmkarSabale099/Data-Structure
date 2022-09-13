//Doubly Linked List

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};

typedef struct node NODE;
typedef struct node *PNODE;
typedef struct node **PPNODE;

void insertFirst(PPNODE Head,int iNo)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory!!!\n");
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		(*Head)->prev=newn;
		newn->next=*Head;
		*Head=newn;
	}
}

void insertLast(PPNODE Head,int iNo)
{
	PNODE Temp=*Head;

	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory!!!\n");
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		while(Temp->next!=NULL)
		{
			Temp=Temp->next;
		}
		Temp->next=newn;
		newn->prev=Temp;
	}

}

void insertAtPos(PPNODE Head,int iNo,int iPos)
{

	int iSize=0,iCnt=0;
	PNODE newn=NULL;
	PNODE Temp=NULL;

	iSize=count(*Head);

	if(iPos<1||iPos>(iSize+1))
	{
		printf("Invalid Position:\n");
		return;
	}
	else if(iPos==1)
	{
		insertFirst(Head,iNo);
	}
	else if(iPos==iSize+1)
	{
		insertLast(Head,iNo);

	}
	else
	{
		Temp=*Head;
		newn=(PNODE)malloc(sizeof(NODE));

		if(newn==NULL)
		{
			printf("Unable to Allowcate Memory!!!\n");
		}

		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;
		for (int i = 1; i < iPos-1; i++)
		{
			Temp=Temp->next;	
		}
		newn->next=Temp->next;
		newn->next->prev=newn;
		newn->prev=Temp;
		Temp->next=newn;

	}
}

void deleteFirst(PPNODE Head)
{
	PNODE Temp=*Head;

	if(*Head==NULL)
	{
		return;
	}
	if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		*Head=Temp->next;
		Temp->prev=NULL;
		free(Temp);
	}
}


void deleteLast(PPNODE Head)
{

	PNODE Temp=*Head;

	if(*Head==NULL)
	{
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		while(Temp->next->next!=NULL)
		{
			Temp=Temp->next;
		}
		free(Temp->next);
		Temp->next=NULL;
	}
	
}

void deleteAtPos(PPNODE Head,int iPos)
{
	int iSize=0;

	PNODE Temp=NULL;
	PNODE TempDel=NULL;

	iSize=count(*Head);

	if(iPos<1||iPos>iSize)
	{
		printf("Invalid Position\n");
		return;
	}
	else if(iPos==1)
	{
		deleteFirst(Head);
	}
	else if(iPos==iSize)
	{
		deleteLast(Head);
	}
	else
	{

		Temp=*Head;


		for (int i = 1; i < iPos-1; i++)
		{
			Temp=Temp->next;
		}

		TempDel=Temp->next;

		Temp->next=TempDel->next;
		TempDel->next->prev=Temp;
		free(TempDel);
	}

}

void display(PNODE Head)
{
	while(Head!=NULL)
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
	printf("\n");
}

int count(PNODE Head)
{
	int iCnt=0;
	while(Head!=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}


