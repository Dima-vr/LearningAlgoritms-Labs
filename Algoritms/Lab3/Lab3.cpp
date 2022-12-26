#include <iostream>
#include <cmath>
using namespace std;


//translation from decimal(10) number system to binary(0 or 1) 
struct TQueueItem
{
    int value;
    TQueueItem *next;
};

struct TQueue
{ 
    TQueueItem *head;
    TQueueItem *tail;
};

TQueue initQueue()
{ 
    TQueue q; 
    q.head=NULL;
    q.tail=NULL;
    return q;
}

int isEmpty(const TQueue&q)
{
return q.head == NULL;
}

void enQueue(TQueue &q, int value)
{ 
    if(isEmpty(q))
    {
        q.head = new TQueueItem();
        q.head->value=value;
        q.head->next=NULL;
        q.tail=q.head;
    }else
    { 
        q.tail->next = new TQueueItem();
        q.tail->next->value = value;
        q.tail->next->next = NULL;
        q.tail = q.tail->next;
    }
}

int deQueue (TQueue &q)
{ 
    if(isEmpty(q))
        return 0;
    else
    { 
        int result = q.head->value;
        TQueueItem *item=q.head;
        q.head=q.head->next;
        delete item;
        if(q.head==NULL) q.tail=q.head;
        return result;
    }
}

// int isEmpty(NodeOut int* stack){
//     return stack==NULL;
// }
int countEl(TQueueItem* q, int count){
    if(q == NULL)
        return count;
    else
    { 
        count++;
        return countEl(q->next, count);
    }
}


int main( )
{
    TQueue q;
    q=initQueue();
    int x,n;
    cout<<"Введіть кількість елементів: ";
    cin>>n;
    for(int i=0;i<n;i++){
        x=-1;
        while(x!=0 && x!=1){
            //cout<<"Введіть "<<i+1<<"-й елемент: ";
            cin >> x;
        }
        enQueue (q,x);
    }
    int count = countEl(q.head, 0);
    int result=0;
    while(!isEmpty(q)){
        result+=deQueue(q)*pow(2,count-1);
        count--;
    }
    cout<<endl<<result;
    
    return 0;
}

