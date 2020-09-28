//
// Created by lenovo on 2020/9/28.
//
#include <stdio.h>
#define MAX_STACK_SIZE 50
#include <iostream>
using namespace std;
typedef int elemtype;
typedef struct Stack{
    elemtype data[MAX_STACK_SIZE];
    int top;
}*sqstack;

sqstack init(){
    sqstack stack = (sqstack) malloc(sizeof(Stack));
    if(stack==NULL)
        return NULL;
    stack->top = -1;
    return stack;
}

bool Push(sqstack stack,elemtype e){
    if(stack->top==MAX_STACK_SIZE-1)
        return false;
    stack->top++;
    stack->data[stack->top] = e;
    return true;
}
elemtype Pop(sqstack stack){
    if(stack->top>=0){
        stack->top--;
        return stack->data[stack->top+1];
    } else{
        cout<<"stack is empty"<<endl;
        return -1;
    }
}


int main(){
    sqstack test_stack;
    test_stack = init();
    for(int i = 0; i<4;i++){
        Push(test_stack,i);
    }
    for (int j = 0; j < 4; ++j) {
        cout<<Pop(test_stack)<<endl;
    }
}

