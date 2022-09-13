//Doubly Linked List 

#include<iostream>
using namespace std;

struct node
{
	int data;
	struct node * next;
	struct node * prev;
};

typedef struct node NODE;
typedef struct node * PNODE;

class DoublyLL
{
	private:
			int iCnt;
			PNODE Head;

	public:

		DoublyLL();

		~DoublyLL();

		void insertFirst(int iNo);

		void insertLast(int iNo);

		void insertAtPos(int iNo,int iPos);

		void deleteFirst();

		void deleteLast();

		void deleteAtPos(int iPos);

		void display();

		int count();
};

DoublyLL::DoublyLL()
{
	iCnt=0;
	Head=NULL;
}

DoublyLL::~DoublyLL()
{
	delete Head;
}


void DoublyLL::insertFirst(int iNo)
{
	PNODE newn=NULL;

	newn=new NODE;

	if(newn==NULL)
	{

		cout<<"Unable to Allowcate Memory!!!\n";
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{

		Head->prev=newn;
		newn->next=Head;
		Head=newn;
	}
	iCnt++;

}

void DoublyLL::insertLast(int iNo)
{
	PNODE newn=NULL;

	newn=new NODE;

	if(newn==NULL)
	{

		cout<<"Unable to Allowcate Memory!!!\n";
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		int iCnt=0;
		PNODE Temp=NULL;
		Temp=Head;

		while(Temp->next!=NULL)
		{	
			iCnt++;
			Temp=Temp->next;
		}

		Temp->next=newn;
		newn->prev=Temp;
	}
	iCnt++;

}

void DoublyLL:: insertAtPos(int iNo,int iPos)
{
	int iSize=iCnt;

	if((iPos<1)||iPos>(iSize+1))
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

		if(newn==NULL)
		{

			cout<<"Unable to Allowcate Memory!!!\n";
		}

		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;

		if(Head==NULL)
		{
			Head=newn;
		}

		Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		newn->next=Temp->next;
		Temp->next->prev=newn;
		Temp->next=newn;
		newn->prev=Temp;

		iCnt++;
	}

}

void DoublyLL::deleteFirst()
{
	if(Head==NULL)
	{
		cout<<"Linked List is Empty\n";
		return;
	}
	else if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
	
		Head=Head->next;

		delete Head->prev;
		Head->prev=NULL;
	}

	iCnt--;
}

void DoublyLL::deleteLast()
{
	if(Head==NULL)
	{
		cout<<"Linked List is Empty\n";
	}
	else if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		PNODE Temp = Head;

		while(Temp->next->next!=NULL)
		{
			Temp=Temp->next;
		}

		delete Temp->next;
		Temp->next=NULL;
	}

	iCnt--;
}

void DoublyLL::deleteAtPos(int iPos)
{
	int iSize=iCnt;


	if(iPos<1 || iPos>iSize)
	{
		cout<<"Invalid Position\n";
		return;
	}

	if(Head==NULL)
	{
		cout<<"Linked List is Empty\n";
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
		PNODE Temp=Head;
		PNODE TempDel=NULL;
		
		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		TempDel=Temp->next;
		Temp->next=TempDel->next;
		TempDel->next->prev=Temp;
		delete TempDel;

		iCnt--;
	}
}

void DoublyLL::display()
{
	PNODE Temp=Head;

	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->data<<"|<=>";
		Temp=Temp->next;
	}	
	cout<<"NULL\n";
}

int DoublyLL::count()
{
	return iCnt;
}