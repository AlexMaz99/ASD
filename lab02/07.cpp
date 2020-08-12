#include <iostream>
#include <cmath>

using namespace std;

struct node {
    int w;
    node *next;
};

node* scal (node *&first, node *&second)
{
    if (first==NULL) return second;
    if (second==NULL) return first;
    node *f=new node;
    f->next=first;
    first=f;
    node *s=new node;
    s->next=second;
    second=s;

    while (f->next!=NULL && s->next!=NULL)
    {
        if (f->next->w < s->next->w) f=f->next;
        else
        {
            node*tmp=s->next;
            s->next=tmp->next;
            tmp->next=f->next;
            f->next=tmp;
            f=f->next;
        }
    }
    if (f->next==NULL)
    {
        f->next=s->next;
        s->next=NULL;
    }
    f=first;
    s=second;
    first=first->next;
    delete f;
    delete s;
    return first;
}

void insert_last (node *&first, int n) //dodawanie elementu na koniec listy
{
    node *p=new node;
    p->w=n;
    p->next=NULL;
    if (first==NULL) first=p;
    else
    {
        node *r=first;
        while (r->next!=NULL)
        {
            r=r->next;
        }
	r->next=p;
    }
}




int main ()
{

    node *first=new node;
    first=NULL;
    node*second=new node;
    second=NULL;

    insert_last (first,1);
    insert_last (first,2);
    insert_last (first,8);
    insert_last (first,12);


    insert_last (second,3);
    insert_last (second,4);
    insert_last (second,7);
    insert_last (second,15);

   first=scal(first, second);


    while (first!=NULL)
    {
        cout<<first->w<<" ";
        first=first->next;
    }

    return 0;

}