#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
	private:

			PNODE Head;
			int iCnt;

	public:

			SinglyLL();

			~SinglyLL();
			
			void inserFirst(int iNo);

			void inserLast(int iNo);

			void inserAtPos(int iNo,int iPos);

			void deleteFirst();

			void deleteLast();

			void deleteAtPos(int iPos);

			void display();

			int count();
};


SinglyLL::SinglyLL()
{
	Head=NULL;
	iCnt=0;
}

SinglyLL::~SinglyLL()
{
	delete Head;
}


void SinglyLL:: inserFirst(int iNo)
{

	PNODE newn=NULL;

	newn=new NODE;

	newn->data=iNo;
	newn->next=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}
	iCnt++;

}


void SinglyLL:: inserLast(int iNo)
{

	PNODE newn=NULL;

	newn=new NODE;

	newn->data=iNo;
	newn->next=NULL;

	
	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		PNODE temp=Head;

		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=newn;
	}
	
	iCnt++;

}


void SinglyLL:: inserAtPos(int iNo,int iPos)
{
	PNODE temp=NULL;
	PNODE newn=NULL;


	newn=new NODE;

	newn->data=iNo;
	newn->next=NULL;


	if(iPos<1||iPos>iCnt+1)
	{
		cout<<"Invalid Position:\n";
		return;
	}
	else if(iPos==1)
	{
		inserFirst(iNo);
	}
	else if(iPos==iCnt+1)
	{
		inserLast(iNo);
	}
	else
	{
		temp=Head;

		for (int i = 1; i < iPos-1; i++)
		{	
			temp=temp->next;
		}

		newn->next=temp->next;
		temp->next=newn;
		iCnt++;
	}

}


void SinglyLL:: deleteFirst()
{
	if(Head==NULL)
	{
		return;
	}
	else if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		PNODE temp=Head;

		Head=temp->next;
		free(temp);
	}

	iCnt--;
	
}


void SinglyLL:: deleteLast()
{

	if(Head==NULL)
	{
		return;
	}
	else if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		PNODE temp=Head;

		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}

		free(temp->next);
		temp->next=NULL;	
	}

	iCnt--;
}


void SinglyLL:: deleteAtPos(int iPos)
{
	PNODE temp=NULL;
	PNODE delTemp=NULL;

	if(iPos<1||iPos>iCnt)
	{
		cout<<"Invalid Position\n";
	}
	else if(iPos==1)
	{
		deleteFirst();
	}
	else if(iPos==iCnt)
	{
		deleteLast();
	}
	else
	{
		temp=Head;


		for (int i = 1; i < iPos-1; i++)
		{
			temp=temp->next;
		}

		delTemp=temp->next;

		temp->next=temp->next->next;
		delete delTemp;
		iCnt--;
	}
}

void SinglyLL:: display()
{
	PNODE temp = Head;

    while(temp != NULL)
    {
        cout<<"|"<<temp->data<<"|-> ";
        temp = temp -> next;
    }
    cout<<"NULL";
    cout<<endl;
}


int SinglyLL:: count()
{
	return iCnt;
}

