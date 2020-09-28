//
// Created by lenovo on 2020/9/28.
//
#include <iostream>
using namespace std;
typedef int elemtype;
typedef struct StackLinked{
    elemtype elem;
    StackLinked *next;
}*Link_stack;

Link_stack init_Link_stack(){
    Link_stack stack = (Link_stack)malloc(sizeof(StackLinked));
    stack->next = NULL;
    return stack;
}
void Push(Link_stack stack,elemtype e){
    Link_stack p = (Link_stack)malloc(sizeof(StackLinked));
    p->elem = e;
    p->next = stack->next;
    stack->next = p;
}
elemtype Pop(Link_stack *stack){
    if((*stack)->next!=NULL)
    {
        *stack = (*stack)->next;
        return (*stack)->elem;
    }

}

int size(Link_stack stack){
    int k = 0;
    Link_stack p = stack;
    while (p->next!=NULL){
        p = p->next;
        k++;
    }
    return k;
}
void show_stack(Link_stack stack){
    Link_stack p = stack;
    while (p->next!=NULL){
        p = p->next;
        cout<<p->elem<<" ";
    }
    cout<<endl;
}
void destroy(Link_stack stack){
    Link_stack cur,pre;
    cur = stack;
    while (cur!=NULL){
        pre = cur;
        cur = cur->next;
        free(pre);
    }
}
int main(){
    Link_stack mystack = init_Link_stack();
    Push(mystack,1);
    Push(mystack,2);
    Push(mystack,3);
    Push(mystack,4);
    Push(mystack,5);
    Push(mystack,6);
    Pop(&mystack);
    destroy(mystack);
    cout<<size(mystack)<<endl;
    show_stack(mystack);
}


