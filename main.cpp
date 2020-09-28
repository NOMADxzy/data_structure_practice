#include <iostream>
using namespace std;
typedef int nodetype;
typedef struct Node{
    nodetype value;
    Node *next;
}*LinkList;

LinkList InitList(){
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void insert_node(LinkList list,nodetype e){
    LinkList newNode = (LinkList)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = e;
    if(list->next==NULL)
    {
        list->next = newNode;
    } 
    else
    {
        LinkList p = list;
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = newNode;
    }
}
void show_list(LinkList list){
    if(list->next == NULL) cout<<"empty list"<<endl;
    else{
        LinkList p = list;
        while (p->next != NULL){
            p = p->next;
            cout<<p->value<<" ";
        }
        cout<<endl;
    }
}

void reverse_list(LinkList list){
    if(list->next == NULL||list->next->next==NULL) return;
    else{
        LinkList p,q,r;
        q = list->next;
        r = p = q->next;
        q->next = NULL;
        while (p != NULL){
            p = p->next;
            r->next = q;
            q = r;
            r = p;
        }
        list->next = q;
    }
}
void sort_list(LinkList list){
    LinkList p,q;
    int i,len = 0;
    q = list;
    p = list->next;
    while (q->next != NULL){
        q = q->next;
        len++;
    }
    while (len>1)
    {
        q = list;
        p = list->next;
        i = 0;
        while (p->next != NULL&&i<len-1){
            if(p->value > p->next->value)
            {
                q->next = p->next;
                p->next = p->next->next;
                q->next->next = p;
            }
            q = q->next;
            p = q->next;
            i++;
        }
        len--;
    }
}
void del_elem(LinkList list,nodetype elem){
    LinkList p = list;
    while (p->next != NULL){
        if(p->next->value == elem){
            p->next = p->next->next;
        }
        else p = p->next;
    }
}
int main() {
    LinkList test_list = InitList();
    nodetype a[] = {5,2,4,5,7,4,3,2,65,6,2,2};
    for(int i = 0;i<12;i++){
        insert_node(test_list,a[i]);
    }
    show_list(test_list);
    del_elem(test_list,5);
    show_list(test_list);
    return 0;
}
