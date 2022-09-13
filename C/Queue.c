//QUEUE DATA STRUCTURE

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

}NODE,*PNODE,**PPNODE;

void enquque(PPNODE Head,int iNo)
{
	PNODE newn=NULL;
	PNODE Temp=NULL;
	newn=malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable To Allowcate Memory\n");
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
		PNODE Temp=*Head;

		while(Temp->next!=NULL)
		{
			Temp=Temp->next;
		}

		Temp->next=newn;

	}
}

void dequeue(PPNODE Head)
{

	PNODE Temp=NULL;

	if(*Head==NULL)
	{
		printf("Queue is Empty!!!\n");
		return;
	}
	else
	{
		Temp=*Head;

		*Head=Temp->next;
		free(Temp);		
	}
}

void display(PNODE Head)
{
	PNODE Temp=Head;

	if(Head==NULL)
	{
		printf("Queue is Empty\n");
		return;
	}
	else
	{
		while(Temp!=NULL)
		{
			printf(" %d ",Temp->data);
			Temp=Temp->next;
		}
		printf("\n");
	}

	

}

int count(PNODE Head)
{
	PNODE Temp=Head;
	int iCount=0;

	if(Head==NULL)
	{
		printf("Queue is Empty\n");
		return -1;
	}

	while(Temp!=NULL)
	{
		iCount++;
		Temp=Temp->next;
	}

	return iCount;


}

