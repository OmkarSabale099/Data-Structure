//DOUBLY CIRCULAR LINKED LIST

#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
	struct node *prev;

}NODE,*PNODE,**PPNODE;

class DoublyCircularLL
{
	private:

		PNODE Head;
		PNODE Tail;
		int CountNode;

	public:

		DoublyCircularLL();

		~DoublyCircularLL();
		
		void insertFirst(int iNo);
		
		void insertLast(int iNo);
		
		void insertAtPos(int iNo,int iPos);
		
		void deleteFirst();
		
		void deleteLast();
		
		void deleteAtPos(int iNo);
		
		void display();
		
		void displayRev();
		
		int count();
};

DoublyCircularLL::DoublyCircularLL()
{
	Head=NULL;
	Tail=NULL;
	CountNode=0;
}

DoublyCircularLL::~DoublyCircularLL()
{
	delete Head;
}


void DoublyCircularLL::insertFirst(int iNo)
{
	PNODE newn=NULL;

	newn=new NODE;

	if(newn==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		newn->next=Head;
		Head->prev=newn;
		Head=newn;
	}
	Tail->next=Head;
	Head->prev=Tail;

	CountNode++;
}

void DoublyCircularLL:: insertLast(int iNo)
{
	PNODE newn=NULL;

	newn=new NODE;

	if(newn==NULL)
	{
		cout<<"Unable to Allowcate Memory!!!\n";
		return;
	}

	newn->data=iNo;
	newn->next=NULL;
	newn->prev=NULL;

	if((Head==NULL)&&(Tail==NULL))
	{
		Head=newn;
		Tail=newn;
	}
	else
	{
		Tail->next=newn;
		newn->prev=Tail;
		Tail=newn;
	}
	Tail->next=Head;
	Head->prev=Tail;

	CountNode++;

}

void DoublyCircularLL::insertAtPos(int iNo,int iPos)
{
	int iSize=count();

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

		newn=new NODE;

		if(newn==NULL)
		{
			cout<<"Unable to Allowcate Memory!!!\n";
			return;
		}

		newn->data=iNo;
		newn->next=NULL;
		newn->prev=NULL;

		PNODE Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		newn->next=Temp->next;
		Temp->next->prev=newn;
		Temp->next=newn;
		newn->prev=Temp;

		CountNode++;
	}

	Tail->next=Head;
	Head->prev=Tail;
}

void DoublyCircularLL::deleteFirst()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty!!!\n";
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Head=Head->next;
		delete(Tail->next);
		Tail->next=Head;
		Head->prev=Tail;
	}

	CountNode--;
}

void DoublyCircularLL::deleteLast()
{
	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Linked List is Empty!!!\n";
		return;
	}
	else if(Head==Tail)
	{
		delete Head;
		Head=NULL;
		Tail=NULL;
	}
	else
	{
		Tail=Tail->prev;
		delete (Head->prev);
		Tail->next=Head;
		Head->prev=Tail;
	}

	CountNode--;

}

void DoublyCircularLL::deleteAtPos(int iPos)
{
	int iSize=count();

	if(iPos<0||iPos>iSize)
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
		PNODE Temp=Head;

		for(int i=1;i<iPos-1;i++)
		{
			Temp=Temp->next;
		}

		PNODE DeleteNode=Temp->next;

		Temp->next=DeleteNode->next;
		DeleteNode->next->prev=Temp;
		delete(DeleteNode);

		CountNode--;
	}
}


void DoublyCircularLL::display()
{
	PNODE Temp=NULL;

	Temp=Head;

	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Unable to Print Linked List is Empty!!!\n";
		return;
	}
	else
	{
		while(Temp!=Tail)
		{
			cout<<"|"<<Temp->data<<"|<=>";
			Temp=Temp->next;
		}
		cout<<"|"<<Temp->data<<"|<=>";
		cout<<"\n";	
	}
	
}

void DoublyCircularLL::displayRev()
{
	PNODE Temp=NULL;

	Temp=Tail;

	if((Head==NULL)&&(Tail==NULL))
	{
		cout<<"Unable to Print Linked List is Empty!!!\n";
		return;
	}
	else
	{
		while(Temp!=Head)
		{
			cout<<"|"<<Temp->data<<"|<=>";
			Temp=Temp->prev;
		}
		cout<<"|"<<Temp->data<<"|<=>";
		cout<<"\n";
	}

	
}

int DoublyCircularLL::count()
{
	return CountNode;
}

