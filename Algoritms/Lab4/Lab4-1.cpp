#include <iostream>
using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};
struct TList{
    TListItem *first, *last;
};

TList initList(){
    TList t;
    t.first=NULL;
    t.last=NULL;
    return t;
}

void addListItem(TList& list, int val){
    if(list.first==NULL){
        list.first=new TListItem;
        list.first->value=val;
        list.first->next=NULL;
        list.first->prev=NULL;
        list.last=list.first;
    }
    else{
        TListItem* newItem = new TListItem;
        newItem->value=val;
        newItem->next=NULL;
        newItem->prev=list.last;
        list.last->next=newItem;
        list.last=list.last->next;
    }
}

void printList(TList list){
    TListItem* tmp=list.first;
    while(tmp!=NULL){
        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
}

int countOfInversionAll(TList list){
    int count=0;
    TListItem* tmp1=list.first, *tmp2=list.first;
    while(tmp1!=NULL){
        tmp2=tmp1->next;
        while(tmp2!=NULL){
            if(tmp1->value>tmp2->value)
                count++;
            tmp2=tmp2->next;
            
        }
        tmp1=tmp1->next;
    }
    return count;
}

int countOfInversionBetween(TList list){
    int count=0;
    TListItem* tmp1=list.first;
    while(tmp1->next!=NULL){
        if(tmp1->value>tmp1->next->value)
            count++;
        tmp1=tmp1->next;
    }
    return count;
}

int main()
{
    TList R=initList();
    int x,n;
    cout<<"Введіть кількість чисел: ";
    cin>>n;
    cout<<"Введіть числа: ";
    for(int i=0; i<n; i++){
        cin>>x;
        addListItem(R, x);
    }
    cout<<"Список: ";
    printList(R);
    cout<<endl<<"Кількість усіх інверсій: "<<countOfInversionAll(R);
    cout<<endl<<"Кількість інверсій між сусідами: "<<countOfInversionBetween(R);
    return 0;
}




