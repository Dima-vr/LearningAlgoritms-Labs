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
        list.last=list.first;
        list.first->next=list.last;
        list.first->prev=list.last;
        list.last=list.first;
    }
    else{
        auto* newItem = new TListItem;
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

void movePrev(TListIterator &it){
    it.pointer=it.pointer->prev;
}

TListIterator getEnd(TList l){
    TListIterator tmp{};
    tmp.pointer = l.last;
    return tmp;
}

void deleteElement(TList& list, int k){
    TListIterator it = getEnd(list);
    for(int i=0; i<k; i++)
        movePrev(it);
    if(it.pointer==list.first){
        list.first=it.pointer->next;
    }
    if(it.pointer==list.last){
        list.last=it.pointer->prev;
    }
    it.pointer->prev->next=it.pointer->next;
    it.pointer->next->prev=it.pointer->prev;
    delete it.pointer;

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
    cout<<"Ring list: ";
    printList(R);
    cout<<endl<<"Enter the number of the element from the end to be deleted:";
    int k;
    cin>>k;
    deleteElement(R, k);
    printList(R);
    return 0;
}


