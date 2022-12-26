#include <iostream>
using namespace std;

struct TListItem{
    int value;
    TListItem *next, *prev;
};
struct TList{
    TListItem *first, *last;
};

struct TListIterator{
    TListItem* pointer;
};

TList initList(){
    TList t{};
    t.first=nullptr;
    t.last=nullptr;
    return t;
}

void addListItem(TList& list, int val){
    if(list.first==nullptr){
        list.first=new TListItem;
        list.first->value=val;
        list.first->next=nullptr;
        list.first->prev=nullptr;
        list.last=list.first;
    }
    else{
        auto* newItem = new TListItem;
        newItem->value=val;
        newItem->next=nullptr;
        newItem->prev=list.last;
        list.last->next=newItem;
        list.last=list.last->next;
    }
}

void printList(TList list){
    TListItem* tmp=list.first;
    while(tmp!=nullptr){
        cout<<tmp->value<<" ";
        tmp=tmp->next;
    }
}

int isValid(TListIterator it){
    return it.pointer!= nullptr;
}

void moveNext(TListIterator &it){
    if(isValid(it))
        it.pointer=it.pointer->next;
}

int getValue(const TListIterator &it){
    if(isValid(it))
        return it.pointer->value;
    return 0;
}

TListIterator getBegin(TList l){
    TListIterator tmp{};
    tmp.pointer = l.first;
    return tmp;
}

int countOfInversionAll(TList list){
    int count=0;
    TListIterator it1 = getBegin(list), it2;
    while(isValid(it1)){
        it2 = it1;
        while(isValid(it2)){
            if(getValue(it1)>getValue(it2))
                count++;
            moveNext(it2);
        }
        moveNext(it1);
    }
    return count;
}



int main()
{
    TList R=initList();
    int x,n;
    cout<<"Amount of numbers:";
    cin>>n;
    cout<<"Enter the numbers:";
    for(int i=0; i<n; i++){
        cin>>x;
        addListItem(R, x);
    }
    cout<<"List: ";
    printList(R);
    cout<<endl<<"Amount of inversions: "<<countOfInversionAll(R);
    return 0;
}
