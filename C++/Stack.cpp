#include<iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *next;
}NODE,*PNODE;

class Stack
{
	
private:

		PNODE Head;
		int CountNode;

public:
		Stack();

		~Stack();

		void push(int iNo);
		
		int pop();
		
		int peek();
		
		void display();
		
		int count();
};

Stack::Stack()
{
	Head=NULL;
	CountNode=0;
}

Stack::~Stack()
{
	delete Head;
}

void Stack::push(int iNo)
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

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		newn->next=Head;
		Head=newn;
	}
	CountNode++;
}

int Stack::pop()
{
	int iNo=0;

	if(Head==NULL)
	{
		cout<<"Stack is Empty!!!\n";
		return -1;
	}

	iNo=Head->data;

	if(Head->next==NULL)
	{
		delete Head;
		Head=NULL;
	}

	else
	{
		PNODE Temp=Head;

		Head=Temp->next;
		delete Temp;
	}
	CountNode--;

	return iNo;
}

int Stack::peek()
{
	if(Head==NULL)
	{
		return -1;
	}
	else
	{
		return Head->data;
	}
	
}

void Stack::display()
{
	PNODE Temp=NULL;

	Temp=Head;

	while(Temp!=NULL)
	{
		cout<<"|"<<Temp->data<<"|";
		cout<<"\n____\n";
		Temp=Temp->next;
	}
	cout<<"\n";
}

int Stack::count()
{
	return CountNode;
}
