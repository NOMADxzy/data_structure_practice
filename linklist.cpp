#include <iostream>
using namespace std;
typedef int elemtype;
typedef struct Node{
    elemtype value;
    Node *next;
}*LinkList;

LinkList InitList(){
    LinkList head = (LinkList)malloc(sizeof(Node));
    head->next = NULL;
    return head;
}

void insert_node(LinkList list,elemtype e){
    LinkList newNode = (LinkList)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = e;
    LinkList p = list;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = newNode;
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
void del_elem(LinkList list,elemtype elem){
    LinkList p = list;
    while (p->next != NULL){
        if(p->next->value == elem){
            p->next = p->next->next;
        }
        else p = p->next;
    }
}
LinkList find_lastK_node(LinkList list, int K){
    LinkList cur,pre;
    pre = cur = list;
    int count = 0;
    while (cur->next!=NULL){
        cur = cur->next;
        count++;
        if(count>=K) pre = pre->next;
    }
    if(pre==list) return NULL;
    else return pre;
}

void delete_duplicates(LinkList list){
    sort_list(list);
    LinkList p = list->next;
    while (p->next != NULL){
        if(p->value==p->next->value)
        {
            p->next = p->next->next;
        }
        else p = p->next;
    }
}

LinkList get_midnode(LinkList list){
    LinkList p,q,midnode;
    p = q = list;
    int flag = 0;
    while (p->next!=NULL){
        p = p->next;
        q = q->next;
        if(p->next==NULL){
            midnode = q;
            flag = 1;
            break;
        } else
        {
            p = p->next;
        }
    }
    if(flag == 0) midnode = q->next;
    return midnode;
}
LinkList addlist(LinkList list1,LinkList list2){
    LinkList p,q,cur;
    p = list1->next; q = list2->next;
    LinkList list3 = cur;
    while (p!=NULL&&q!=NULL){
//        LinkList node = (LinkList)malloc(sizeof(Node));
//        node->next = NULL;
        if(p->value<q->value){
            insert_node(list3,p->value);
            p = p->next;
        } else if(q->value<p->value){
            insert_node(list3,q->value);
            q = q->next;
        } else{
            insert_node(list3,p->value);
            insert_node(list3,q->value);
            p = p->next;
            q = q->next;
        }
    }
    while (p!=NULL){
        insert_node(list3,p->value);
        p = p->next;
    }
    while (q!=NULL){
        insert_node(list3,q->value);
        q = q->next;
    }
    return list3;
}
int main() {
    LinkList test_list = InitList();
    LinkList test_list2 = InitList();
    elemtype a[] = {5,2,4,5,7,4,3,2,65,6,2};
    elemtype b[] = {7,9,10,11,65};
    for(int i = 0;i<11;i++){
        insert_node(test_list,a[i]);
    }
    for(int i = 0;i<5;i++){
        insert_node(test_list2,b[i]);
    }
    sort_list(test_list);
    show_list(test_list);
    show_list(test_list2);
    show_list(addlist(test_list,test_list2));
    cout<<get_midnode(test_list)->value<<endl;
    return 0;
}
