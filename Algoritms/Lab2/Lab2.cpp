#include <stdio.h>
#include <iostream>
#include <climits>
using namespace std;

template <typename T>
struct NodeOut{
    T value;
    NodeOut<T>* next;
};

template <typename T>
void init(NodeOut <T>* &stack){
    stack = NULL;
}


template <typename T>
int isEmpty(NodeOut <T>* stack){
    return stack==NULL;
}

template <typename T>
void push(NodeOut <T>*& stack,  T value){
    if(isEmpty(stack)){
        stack = new NodeOut <T>;
        stack->value=value;
        stack->next=NULL;
    }
    else{
        NodeOut <T>* tmp = stack;
        stack = new NodeOut <T>;
        stack->value = value;
        stack->next = tmp;
    }
    
}

template <typename T>
T pop(NodeOut <T>* &stack){
    if(!isEmpty(stack)){
        T tmp = stack->value;
        NodeOut <T> *item = stack->next;
        delete stack;
        stack=item;
        return tmp;
    }
    T tmp1;
    return tmp1;
}

int length(int n) {
    int l = 0;
    do {
        l++;
        n /= 10;
    } while(n);
    return l;
}

int main()
{
    NodeOut<NodeOut<int>*>* Steck_out;
    init(Steck_out);
    
    int x, n;
    printf("Введіть кількість стеків: ");
    cin >> n;
    NodeOut<int>* Steck_in[n];
    for(int i=0; i<n; i++){
        init(Steck_in[i]);
        push(Steck_out, Steck_in[i]);
        printf("Введіть 0 щоб припинити введення елементів.\n");
        do{
            printf("Введіть елемент: ");
            cin >> x;
            if(x!=0)
                push(Steck_in[i], x);
        }while(x!=0);
    }
    int max[n], count[n];
    for(int i=0; i<n; i++){
        max[i]=0;
        count[i]=0;
        while(!isEmpty(Steck_in[i])){
            count[i]++;
            int number = pop(Steck_in[i]);
            if(length(number)>=length(max[i]))
                max[i] = number;
        }
    }
    for(int i=0; i<n; i++){
        printf("max length in %d stack: %d\n", i+1, max[i]);
    }
    int maxCount=0;
    int k=-1, numberOfBiggest[n];
    for(int i=0; i<n; i++){
        if(count[i] > maxCount){
            while(numberOfBiggest[k]!=0 && k>=0){
                numberOfBiggest[k]=0;
                k--;
            }
            k=0;
            maxCount=count[i];
            numberOfBiggest[k]=i;
            
        }
        else if(count[i] == maxCount){
            k++;
            numberOfBiggest[k]=i;
        }
    }
    printf("max length of stack: %d\n", maxCount);
    for(int i=0; i<=k; i++){
        printf("number of the biggest stack %d\n", numberOfBiggest[i]);
    }
    return 0;
}

