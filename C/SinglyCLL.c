
//Singly Circular Linked List

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int Data;
	struct node *Next;
	
}NODE,*PNODE,**PPNODE;

int count(PNODE Head,PNODE Tail);

void insertFirst(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE NewNode=NULL;

	NewNode=(PNODE)malloc(sizeof(NODE));

	if(NewNode==NULL)
	{
		printf("Unable to Allowcate Memory!!!\n");
		return;
	}

	NewNode->Data=iNo;
	NewNode->Next=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=NewNode;
		*Tail=NewNode;
	}
	else
	{
		NewNode->Next=*Head;
		*Head=NewNode;
	}
	(*Tail)->Next=*Head;

}


void insertLast(PPNODE Head,PPNODE Tail,int iNo)
{
	PNODE NewNode=NULL;

	NewNode=(PNODE)malloc(sizeof(NODE));

	if(NewNode==NULL)
	{
		printf("Unable to Allowcate Memory!!!\n");
		return;
	}

	NewNode->Data=iNo;
	NewNode->Next=NULL;

	if((*Head==NULL)&&(*Tail==NULL))
	{
		*Head=NewNode;
		*Tail=NewNode;
	}
	else
	{
		(*Tail)->Next=NewNode;
		*Tail=NewNode;
	}
	(*Tail)->Next=*Head;
	
}

void insertAtPos(PPNODE Head,PPNODE Tail,int iNo,int iPos)
{
	int iSize=0;

	iSize=count(*Head,*Tail);

	if((iPos<1)||(iPos>iSize+1))
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
		PNODE NewNode=NULL;
		PNODE Temp=*Head;

		NewNode=(PNODE)malloc(sizeof(NODE));

		if(NewNode==NULL)
		{
			printf("Unable to Allowcate Memory!!!\n");
			return;
		}

		NewNode->Data=iNo;
		NewNode->Next=NULL;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		NewNode->Next=Temp->Next;
		Temp->Next=NewNode;
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
		*Head=(*Head)->Next;
		free((*Tail)->Next);
		(*Tail)->Next=*Head;
	}
}

void deleteLast(PPNODE Head,PPNODE Tail)
{
	PNODE Temp=NULL;

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
		Temp=*Head;

		while(Temp->Next!=*Tail)
		{
			Temp=Temp->Next;
		}

		free(Temp->Next);
		Temp->Next=*Head;
		*Tail=Temp;
	}
}

void deleteAtPos(PPNODE Head,PPNODE Tail,int iPos)
{
	struct node *Temp=NULL;
	struct node *DeleteTemp=NULL;

	int iSize=count(*Head,*Tail);
	
	if((iPos<1)||(iPos>iSize))
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
		Temp=*Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->Next;
		}

		DeleteTemp=Temp->Next;

		Temp->Next=DeleteTemp->Next;
		free(DeleteTemp);
	}
}

void display(PNODE Head,PNODE Tail)
{
	PNODE Temp=Head;

	if((Head==NULL)&&(Tail==NULL))
	{
		return;
	}

	while(Temp!=Tail)
	{
		printf("|%d|->",Temp->Data);
		Temp=Temp->Next;
	}
	printf("|%d|\n",Temp->Data);

}

int count(PNODE Head,PNODE Tail)
{
	int iCnt=0;

	PNODE Temp=Head;

	if((Head==NULL)&&(Tail==NULL))
	{
		return 0;
	}
	else if(Head==Tail)
	{
		return ++iCnt;
	}
	else
	{
		while(Temp!=Tail)
		{
			iCnt++;
			Temp=Temp->Next;
		}
	}

	return ++iCnt;
} 

