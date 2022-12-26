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
        list.last=list.first;
        list.first->next=list.last;
        list.first->prev=list.last;
        list.last=list.first;
    }
    else{
        TListItem* newItem = new TListItem;
        newItem->value=val;
        newItem->next=list.first;
        newItem->prev=list.last;
        list.last->next=newItem;
        list.last=list.last->next;
        list.first->prev=list.last;
    }
}

void printList(TList list){
    TListItem* tmp=list.first;
    int count=0;
    while(tmp!=list.first || count==0){
        cout<<tmp->value<<" ";
        tmp=tmp->next;
        if(tmp==list.last) count++;
    }
}

void deleteElement(TList& list, int k){
    TListItem* tmp=list.last;
    for(int i=0; i<k; i++){
        tmp=tmp->prev;
    }
    if(tmp==list.first){
        list.first=tmp->next;
    }
    if(tmp==list.last){
        list.last=tmp->prev;
    }
    tmp->prev->next=tmp->next;
    tmp->next->prev=tmp->prev;
    delete tmp;
    
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
    cout<<"Кільцевий список: ";
    printList(R);
    cout<<endl<<"Введіть номер елемента з кінця який потрібно видалити: ";
    int k;
    cin>>k;
    deleteElement(R, k);
    printList(R);
    return 0;
}



