#include<iostream>
using namespace std;

template <class T>
class node{
	public:	
	T data;
	node* next;
};

template <class T>
class singly_linked_list:public node<T>{
public:
    node<T> *head,*tail;	
	singly_linked_list()
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
		   temp->next=NULL;
		}
		else
		{
			tail->next = temp;
			temp->data = val;
			temp->next = NULL;
			tail = temp;
		}
	}
	
	void add_at_start(T val);
	void add_at_pos(T val,int pos);
	
	int count_node()
	{
		int n;
		node<T> *tmp;
		tmp=head;
		while(tmp!=NULL)
		{
			n++;
			tmp=tmp->next;
		}
		return n;
	}
	
	void reverse_list()
	{
		node<T> *cur,*nxt,*prev;
		prev=NULL;
		cur=nxt=head;
		while(nxt!=0)
		{
			nxt=nxt->next;
			cur->next=prev;
			prev=cur;
			cur=nxt;
		}
		head=prev;
	}
	
	void peek(int pos)
	{
       node<T> *n;
	   n = head;
	   for(int i=1;i<pos;i++)
	   { 
         n = n->next;
	   }
	   cout<<n->data<<endl;
	}

    void Delete(int pos)
	{
		node<T> *p,*n;
	    n=p=head;
		for(int i=1;i<pos-1;i++)
		{
			p=p->next;
			n=n->next;
		}
		n=n->next;
		p->next = n->next;
		delete n;
	}

	void print()
	{
		node<T> *temp;
		temp = head;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp = temp->next;
		}
	}
	
};

template <class T>
void singly_linked_list<T>::add_at_start(T val){
	node<T> *temp = new node<T>;
	temp->data=val;
	temp->next=head;
	head=temp;
}

template <class T>
void singly_linked_list<T>::add_at_pos(T val, int pos){
	node<T> *temp = new node<T>;
	temp->data=val;	
	if(pos==1)
	{
		node<T> *temp = new node<T>;
	    temp->data=val;
	    temp->next=head;
	    head=temp;
	}
	
	node<T> *n;
	n=head;
	for(int i=1;i<pos-1;i++)
	{
		n=n->next;
	}
	temp->next=n->next;
	n->next=temp;
}

int main() {
	singly_linked_list<char> L;
	L.add('h');
	L.add('e');
	L.add('l');
	L.add('l');
	L.add('o'); 
	L.add_at_start('O');
	L.add_at_pos('d',4);
	//cout<<L.count_node()<<endl;
	L.reverse_list();
	L.Delete(4);
	L.print();
	L.peek(1);
	return 0;   
}
