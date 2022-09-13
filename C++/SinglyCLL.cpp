//Singly Circular Linked List

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyCircularLL
{
	private:

		PNODE Head;
		PNODE Tail;
		int CountNode;

	public:

			SinglyCircularLL();

			~SinglyCircularLL();

			void insertFirst(int iNo);

			void insertLast(int iNo);

			void insertAtPos(int iNo,int iPos);

			void deleteFirst();

			void deleteLast();

			void deleteAtPos(int iPos);

			void display();

			int count();
};

SinglyCircularLL::SinglyCircularLL()
{
	Head=NULL;
	Tail=NULL;
	CountNode=0;
}

SinglyCircularLL::~SinglyCircularLL()
{
	delete Head;
}

void SinglyCircularLL::insertFirst(int iNo)
{
	PNODE newn=NULL;

	newn=new NODE;

	newn->data=iNo;
	newn->next=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}

	Tail->next=Head;

	CountNode++;
}

void SinglyCircularLL::insertLast(int iNo)
{
	PNODE newn=NULL;

	newn=new NODE;

	newn->data=iNo;
	newn->next=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->next=newn;
		Tail=newn;
	}

	Tail->next=Head;
	CountNode++;
}

void SinglyCircularLL:: insertAtPos(int iNo,int iPos)
{
	int iSize=CountNode;

	if(iPos<1||iPos>iSize+1)
	{
		cout<<"Invalid Position\n";
		return;
	}	
	else if(iPos==1)
	{
		insertFirst(iNo);
	}
	else if(iPos==iSize+1)
	{
		insertLast(iNo);
	}
	else
	{
		PNODE newn=NULL;
		PNODE Temp=NULL;

		newn=new NODE;

		newn->data=iNo;
		newn->next=NULL;

		Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		newn->next=Temp->next;
		Temp->next=newn;
	}

			
}

void SinglyCircularLL::deleteFirst()
{

	if(Head == NULL && Tail ==  NULL)      
    {
    	cout<<"Linked List is Empty\n";
        return;
    }
    else if(Head == Tail)      
    {
       	delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else   
    {
 
        Head = Head -> next;
        delete Tail->next;

        Tail->next = Head;
    }
	CountNode--;
}


void SinglyCircularLL:: deleteLast()
{

	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty\n";
		return;
	}
	else if(Head==Tail)
	{
		delete Tail;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		PNODE Temp=Head;

		while(Temp->next!=Tail)
		{
			Temp=Temp->next;
		}
		Temp->next=Head;
		delete Tail;
		Tail=Temp;
			
	}
	CountNode--;
}

void SinglyCircularLL::deleteAtPos(int iPos)
{
	int iSize=CountNode;

	if(iPos<1||iPos>iSize)
	{
		cout<<"Invalid Position\n";
		return;
	}
	else if(iPos==1)
	{
		deleteFirst();
	}
	else if(iPos==iSize)
	{
		deleteLast();
	}
	else
	{
		PNODE Temp=NULL;
		PNODE DeleteTemp=NULL;

		Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		DeleteTemp=Temp->next;

		Temp->next=DeleteTemp->next;
		delete DeleteTemp;

		CountNode--;
	}
}

void SinglyCircularLL::display()
{
	PNODE Temp=NULL;

	Temp=Head;

	if(Head==NULL)
	{
		return;
	}

	while(Temp!=Tail)
	{
		cout<<"|"<<Temp->data<<"|->";
		Temp=Temp->next;
	}

	cout<<"|"<<Temp->data<<"|->";
	cout<<"NULL\n";
}

int SinglyCircularLL::count()
{
	return CountNode;
}
