//Singly Linear Linked List

#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node* PNODE;
typedef struct node** PPNODE;

void insertFirst(PPNODE Head,int iNo)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory...");
	}

	newn->data=iNo;
	newn->next=NULL;

	if((*Head)==NULL)
	{
		(*Head)=newn;
	}
	else
	{
		newn->next=(*Head);
		(*Head)=newn;
	}
}

void insertLast(PPNODE Head,int iNo)
{
	PNODE newn=NULL;

	newn=(PNODE)malloc(sizeof(NODE));

	if(newn==NULL)
	{
		printf("Unable to Allowcate Memory...");
	}

	newn->data=iNo;
	newn->next=NULL;

	if((*Head)==NULL)
	{
		(*Head)=newn;
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


void insertAtPos(PPNODE Head,int iNo,int iPos)
{
	int iSize=0;

	PNODE newn=NULL;
	PNODE Temp=NULL;

	iSize=count(*Head);	

	if(iPos<1||iPos>(iSize+1))
	{
		printf("Invalid Position:\n");
		return;
	}

	if(iPos==1)
	{
		insertFirst(Head,iNo);
	}
	else if(iPos==(iSize+1))
	{
		insertLast(Head,iNo);
	}
	else
	{
		Temp=*Head;
		newn=(PNODE)malloc(sizeof(NODE));

		if(newn==NULL)
		{
			printf("Memory Not Allowcate\n");
		}

		newn->data=iNo;
		newn->next=NULL;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}
		newn->next=Temp->next;
		Temp->next=newn;

	}

}

void deleteFirst(PPNODE Head)
{
	if(*Head==NULL)
	{
		printf("Linked List is Empty!!!\n");
		return;
	}
	else if((*Head)->next==NULL)
	{
		free(*Head);
		*Head=NULL;
	}
	else
	{
		PNODE Temp=*Head;

		*Head=Temp->next;
		free(Temp);
	}
	

}

void deleteLast(PPNODE Head)
{
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
		PNODE Temp=*Head;

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
	PNODE DeleteTemp=NULL;

	iSize=count(*Head);

	if(iPos<1||iPos>(iSize))
	{
		printf("Invalid Position:");
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

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		DeleteTemp=Temp->next;
		Temp->next=Temp->next->next;
		free(DeleteTemp);

	}

}

void display(PNODE Head)
{
	while((Head)!=NULL)
	{
		printf("|%d|->",Head->data);
		Head=Head->next;
	}
	printf("NULL\n");
}


int count(PNODE Head)
{
	int iCnt=0;

	while((Head)!=NULL)
	{
		iCnt++;
		Head=Head->next;
	}
	return iCnt;
}

