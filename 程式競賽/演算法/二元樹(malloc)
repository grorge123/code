#include<bits/stdc++.h>
using namespace std;
struct tree {
    int data=0;
    tree *l=0,*r=0;
};
void addt(tree **head,tree **ptr,int a){
    if(*head==0){
        tree *now = (tree *)malloc(sizeof(tree));
        *head=now;
        (*head)->data=a;
        (*head)->l=NULL;
        (*head)->r=NULL;
    }else{
        if((*ptr)->data>a){
            if((*ptr)->l!=0){
                addt(head,&(*ptr)->l,a);
            }else{
                tree *now = (tree *)malloc(sizeof(tree));
                (*ptr)->l=now;
                (*ptr)->l->data=a;
                (*ptr)->l->l=NULL;
                (*ptr)->l->r=NULL;
            }
        }else if((*ptr)->data<a){
            if((*ptr)->r!=0){
                addt(head,&(*ptr)->r,a);
            }else{
                tree *now = (tree *)malloc(sizeof(tree));
                (*ptr)->r=now;
                (*ptr)->r->data=a;
                (*ptr)->r->l=NULL;
                (*ptr)->r->r=NULL;
            }
        }
    }
}
void print(tree *ptr){
    if(ptr->l!=0){
        print(ptr->l);
    }
    if(ptr->r!=0){
        print(ptr->r);
    }
    cout << ptr->data<<endl;
}
int main(){
    int n;
    tree *ptr=NULL,*head=NULL;
    cin >> n;
    for(int i=0;i<n;i++){
        int a;
        cin >> a;
        addt(&head,&head,a);
    }
    print(head);
}
