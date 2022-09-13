//DOUBLY CIRCULAR LINKED LIST

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;

}NODE,*PNODE,**PPNODE;

int count(PNODE Head,PNODE Tail);	

void insertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory!!!\n");
		return;
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		newn->next=*Head;
		(*Head)->prev=newn;
		*Head=newn;
	}
	(*Tail)->next=*Head;
	(*Head)->prev=*Tail;
}

void insertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory!!!\n");
		return;
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=newn;
		*Tail=newn;
	}
	else
	{
		(*Tail)->next=newn;
		newn->prev=*Tail;
		*Tail=newn;

	}
	(*Tail)->next=*Head;
	(*Head)->prev=*Tail;

}

void insertAtPos(PPNODE Head,PPNODE Tail,int iPos,int iNo)
{
	int iSize=0;

	iSize=count(*Head,*Tail);

	if(iPos<1||iPos>iSize+1)
	{
		printf("Invalid Position\n");
		return;
	}
	else if(iPos==1)
	{
		insertFirst(Head,Tail,iNo);
	}
	else if(iPos==iSize+1)
	{
		insertLast(Head,Tail,iNo);
	}
	else
	{
		PNODE newn=NULL;

		newn=(PNODE)malloc(sizeof(NODE));

		if(newn==NULL)
		{
			printf("Unable to Allowcate Memory!!!\n");
			return;
		}

		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;

		PNODE Temp=*Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}
		newn->next=Temp->next;
		Temp->next->prev=newn;
		newn->prev=Temp;
		Temp->next=newn;
	}
}



void deleteFirst(PPNODE Head,PPNODE Tail)
{
	if((*Head==NULL)&&(*Tail==NULL))
	{
		printf("Linked List is Empty!!!\n");
		return;
	}
	else if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		*Head=(*Head)->next;	// *Head=Tail->next->next;
		free((*Tail)->next);
		(*Tail)->next=*Head;
		(*Head)->prev=*Tail;
	}

}


void deleteLast(PPNODE Head,PPNODE Tail)
{
	if((*Head==NULL)&&(*Tail==NULL))
	{
		printf("Linked List is Empty\n");
		return;
	}
	else if(*Head==*Tail)
	{
		free(*Head);
		*Head=NULL;
		*Tail=NULL;
	}
	else
	{
		(*Head)->prev=(*Tail)->prev;
		(*Tail)->prev->next=*Head;

		free(*Tail);
		*Tail=(*Head)->prev;

		(*Tail)->next=*Head;
		(*Head)->prev=*Tail;
	}
}


void deleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
	int iSize=count(*Head,*Tail);
	PNODE Temp=NULL;
	PNODE NodeDelete=NULL;

	if(iPos<1||iPos>iSize)
	{
		printf("Invalid Position\n");
		return;
	}
	else if(iPos==1)
	{
		deleteFirst(Head,Tail);
	}
	else if(iPos==iSize)
	{
		deleteLast(Head,Tail);
	}
	else
	{	
		PNODE Temp=*Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		NodeDelete=Temp->next;

		Temp->next=NodeDelete->next;
		NodeDelete->next->prev=Temp;

		free(NodeDelete);
	}
}


void display(PNODE Head,PNODE Tail)
{
	PNODE Temp=Head;
	
	if((Head==NULL)&&(Tail==NULL))
	{
		printf("Unable to Print...Linked List is Empty!!!\n");
		return;
	}
	
	do
	{
		printf("|%d|<=>",Temp->data);
		Temp=Temp->next;	

	} while (Temp!=Head);
	printf("\n");
}

//for Reverse Travelser

void displayRev(PNODE Head,PNODE Tail)
{

	PNODE Temp=Tail;

	if((Head==NULL)&&(Tail==NULL))
	{
		printf("Unable to Print...Linked List is Empty!!!\n");
		return;
	}

	while(Temp!=Head)	
	{
		printf("|%d|<=>",Temp->data);
		Temp=Temp->prev;
	}
	printf("|%d|<=>",Temp->data);
	printf("\n");
}

int count(PNODE Head,PNODE Tail)
{	
	PNODE Temp=Tail;
	int iCnt=0;

	if(Tail==NULL)
	{
		return iCnt;
	}
	else if(Head==Tail)
	{
		return ++iCnt;
	}
	else
	{
		while(Temp!=Head)
		{	
			iCnt++;
			Temp=Temp->prev;
		}
		return ++iCnt;
	}
}


