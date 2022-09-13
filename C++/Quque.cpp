// Queue Data Structure

#include<iostream>
using namespace std;

typedef struct node
{
	int Data;
	struct node *Next;
	
}NODE,*PNODE;

class Quque
{

private:

			PNODE Head;
			int NodeCount;
public:
			Quque();

			~Quque();

			void enqueue(int iNo);

			int dequeue();

			void dispaly();

			int count();
	
};

Quque::Quque()
{
	Head=NULL;
	NodeCount=0;
}

Quque::~Quque()
{
	delete Head;
}

void Quque::enqueue(int iNo)
{
	PNODE newn=NULL;
	PNODE Temp=NULL;

	newn=new NODE;

	if(newn==NULL)
	{
		return;
	}

	newn->Data=iNo;
	newn->Next=NULL;

	if(Head==NULL)
	{
		Head=newn;
	}
	else
	{
		Temp=Head;

		while(Temp->Next!=NULL)
		{
			Temp=Temp->Next;
		}

		Temp->Next=newn;
	}

	NodeCount++;
}

int Quque::dequeue()
{
	int iNo=0;

	if(Head==NULL)
	{
		cout<<"Quque is Empty!!!\n";
		return -1;
	}

	iNo=Head->Data;


	if(Head->Next==NULL)
	{
		delete Head;
		Head=NULL;
	}
	else
	{
		PNODE Temp=Head;

		Head=Head->Next;
		delete Temp;
	}

	NodeCount--;
	return iNo;
}

void Quque::dispaly()
{
	if(Head==NULL)
	{
		return;
	}
	else
	{
		PNODE Temp=Head;

		while(Temp!=NULL)
		{
			cout<<Temp->Data<<" ";
			Temp=Temp->Next;
		}
		cout<<"\n";
	}
}

int Quque::count()
{
	return NodeCount;
}
