#include <iostream>
#include <cmath>

using namespace std;

const int N=10;

int parent (int i)
{
    return i/2;
}
int left (int i)
{
    return i*2;
}
int right (int i)
{
    return i*2+1;
}
#define size t[0]

struct kopiec {
    int t[N];
    int size;
};

void heepify (int t[N], int i)
{
    int l=left(i);
    int r=right(i);
    int max=i;
    if (l<=size && t[l]>t[max]) max=l;
    if (r<=size && t[r]>t[max]) max=r;
    if (max!=i)
    {
        swap(t[max],t[i]);
        heepify (t,max);
    }
}

void built (int t[N])
{
    for (int i=size/2; i>0; i++)
        heepify (t,i);
}

void heepsort (int t[N])
{
    built (t);
    for (int i=size; i>1; i--)
    {
        swap (t[1],t[i]);
        size--;
        heepify(t,1);
    }
}

void get_max (int k[N]);
{
    if (size==0) error;
    int res=k[1];
    k[1]=k[size];
    size--;
    heepify (k,1);
    return;
}

void put (int k[N], int el)
{
    if (size==N-1) error;
    size++;
    k[size]=el;
    i=size;
    while (i>1 && k[i]>k[parent(i)])
    {
        swap(k[i], k[parent(i)]);
        i=parent(i);
    }
}


int main ()
{


}