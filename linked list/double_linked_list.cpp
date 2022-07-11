#include<iostream>
using namespace std;

template<class T>
class node{
public:
      T data;
      node* next;
      node* prev;
};

template<class T>
class double_list{
public:
      node<T> *head,*tail;
      double_list()
      {
          head = NULL;
          tail = NULL;
      }

      void insert(T val)
      {
        node<T> *temp = new node<T>;
        if(head==NULL)
        {
           head = tail = temp;
           temp->data = val;
           temp->next=NULL;
           temp->prev=NULL;
        }
        else
        {
            tail->next=temp;
            temp->data = val;
            temp->next=NULL;
            temp->prev=tail;
            tail = temp;
        }
      }
     void print();

     void remove(int pos)
     {
        node<T> *n,*p;
        n=p=head;
        for(int i=1;i<pos-1;i++)
        {
            n=n->next;
            p=p->next;
        }
        n=n->next;
        p->next=n->next;
        n->next->prev=p;
        delete n;
     }

     void addatstart(T val)
     {
        node<T>* temp = new node<T>;
        temp->data = val;
        temp->next = head;
        head->prev = temp;
        head = temp;
     }

     void addatpos(int pos,T val)
     {
        if(pos==1)
        {
           addatstart(val);
        }
        else{
            node<T> *temp = new node<T>;
            temp->data = val;
            node<T>* n;
            n=head;
            for(int i=1;i<pos-1;i++)
            {
              n=n->next;
            }
            temp->next=n->next;
            n->next=temp;
            temp->prev=n;
        }
     }

     void reverse()
     {
        node<T> *cur,*p;
		p=NULL;
        cur=head;
		while(cur!=NULL)
		{
			cur->prev=cur->next;
			cur->next=p;
			p=cur;
			cur=cur->prev;
		}
		head=p;
     }
};

template<class T>
void double_list<T>::print()
{
   node<T>* n;
   n=head;
   while(n!=NULL)
   {
       cout<<n->data<<"\t";
       n=n->next;
   }
   cout<<endl;
}

int main()
{
    double_list<int> l;
    l.insert(1);
    l.insert(3);
    l.insert(5);
    l.insert(9);
    l.insert(2);
    l.remove(2);
    l.addatstart(8);
    l.addatpos(3,7);
    l.print();
    l.reverse();
    l.print();
    return 0;
}