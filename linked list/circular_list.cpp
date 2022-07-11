#include<iostream>
using namespace std;

template <class T>
class node{
	public:	
	T data;
	node* next;
};

template <class T>
class circular_linked_list:public node<T>{
public:
    node<T> *head,*tail;	
	circular_linked_list()
	{
	   head = NULL;
	   tail = NULL;
	}
	void add(T val)
	{
		node<T> *temp = new node<T>;
		if(head==NULL)
		{
		   head=tail=temp;
		   temp->data=val;
		   temp->next=head;
		}
		else
		{
			tail->next=temp;
			temp->data=val;
			temp->next=head;
			tail=temp;
		}
	}
	
	void add_at_start(T val);
	void add_at_pos(T val,int pos);
	
	int count_node()
	{
		int n=0;
		node<T> *c;
		c=head;
		while(c->next!=head)
		{
			n++;
			c=c->next;
		}
		n++;
		return n;
	}
	
	void peek(T val)
	{
      node<T> *n;
	  int pos=1;
	  n=head;
	  while(n->data!=val)
	  {
		pos++;
		n=n->next;
	  }
     cout<<"desired element is at "<<pos<<endl;
	}

    void Delete(int pos)
	{
		node<T> *n,*p;
		n=p=head;
		for(int i=1;i<pos-1;i++)
		{
			n=n->next;
		}
		n=n->next;
		p->next=n->next;
		delete n;
	}

	void print()
	{
		node<T> *temp;
		temp = head;
		while(temp->next!=head)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
		cout<<temp->data<<endl;
	}
	
};

template <class T>
void circular_linked_list<T>::add_at_start(T val)
{
    node<T> *temp = new node<T>;
	node<T> *p;
	p=head;
	temp->data=val;
	temp->next=head;
	while(p->next!=head)
	{
		p=p->next;
	}
	p->next=temp;
	head=temp;
}

template <class T>
void circular_linked_list<T>::add_at_pos(T val, int pos)
{
    if(pos==1)
	{
		add_at_start(val);
	}
	else
	{ 
		node<T> *temp = new node<T>;
		node<T> *n;
		n=head;
		temp->data=val;
		for(int i=1;i<pos-1;i++)
		{
			n=n->next;
		}
		temp->next=n->next;
		n->next=temp;
	}
}

int main() {
	circular_linked_list<int> cl;
	cl.add(1);
	cl.add(2);
	cl.add(4);
	cl.add(5);
	cl.print();
	cout<<cl.count_node()<<endl;
	cl.peek(2);
	cl.add_at_pos(9,1);
	cl.print();
	return 0;   
}