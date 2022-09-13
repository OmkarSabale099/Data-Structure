//STACK DATA STRUCTURE

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;

};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE; 

void push(PPNODE Head,int iNo)
{
	PNODE newn=NULL;

	newn=(struct node *)malloc(sizeof(NODE));
	
	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory\n");
		return;
	}

	newn->data=iNo;
	newn->next=NULL;

	if(*Head==NULL)
	{
		*Head=newn;
	}
	else
	{
		newn->next=*Head;
		*Head=newn;
	}
	
}

int pop(PPNODE Head)
{
	int iNo=0;

	if(*Head==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}

	iNo=(*Head)->data;

	if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		PNODE Temp=*Head;

		*Head=(*Head)->next;
		free(Temp);

	}
	return iNo;
}

int peek(PNODE Head)
{
	if(Head==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	else
	{
		return Head->data;
	}
	
}


void display(PNODE Head)
{
	PNODE Temp=Head;

	while(Temp!=NULL)
	{
		printf("| %d ",Temp->data);
		Temp=Temp->next;
	}
	printf("\n");
}

int count(PNODE Head)
{
	int iCnt=0;

	if(Head==NULL)
	{
		printf("Stack is Empty\n");
		return -1;
	}
	else
	{
		while(Head!=NULL)
		{
			iCnt++;
			Head=Head->next;
		}
		return iCnt;
	}
	
}
