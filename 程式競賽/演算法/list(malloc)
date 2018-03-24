#include<cstdio>
#include<bits/stdc++.h>
#include<stdlib.h>
using namespace std;
struct lis{
    int data=0;
    lis *nex=NULL;
};
lis *head[105];
bool add(int a,int b,lis **ptr){
    if(*ptr==NULL){
        lis *now=(lis *)malloc(sizeof(lis));
        *ptr=now;
        now->nex=NULL;
        now->data=b;
        return true;
    }else if((*ptr)->nex!=NULL){
        return add(a,b,&(*ptr)->nex);
    }else{
        lis *now=(lis *)malloc(sizeof(lis));
        (*ptr)->nex=now;
        now->nex=NULL;
        now->data=b;
        return true;
    }
}
bool leave_back(int a,lis **ptr){
    if(*ptr==NULL){
        return false;
    }
    if((*ptr)->nex!=NULL){
        return leave_back(a,&(*ptr)->nex);
    }else if((*ptr)->nex==NULL){
        *ptr=NULL;
        return true;
    }
}
bool leave_front(int a,lis **ptr){
    if(*ptr==NULL){
        return false;
    }
    (*ptr)=(*ptr)->nex;
    return true;
}
bool join(int a,int b,lis **ptr){
    if(*ptr==NULL){
        (*ptr)=head[a];
        head[a]=NULL;
    }else if((*ptr)->nex==NULL){
        (*ptr)->nex=head[a];
        head[a]=NULL;
    }else if((*ptr)->nex!=NULL){
        return join(a,b,&(*ptr)->nex);
    }
}
void print(lis *ptr){
    if(ptr==NULL){
        printf(" empty");
    }else if(ptr->nex!=NULL){
        printf(" %d",ptr->data);
        return print(ptr->nex);
    }else{
        printf(" %d",ptr->data);
        return;
    }
}
int cosize(lis *ptr){
    if(ptr==NULL){
        return 0;
    }else if(ptr->nex!=NULL){
        return cosize(ptr->nex)+1;
    }else{
        return 1;
    }
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    while(m--){
        string cmd;
        cin >> cmd;
        if(cmd=="ADD"){
            int a,b;
            scanf("%d %d",&a,&b);
            add(a,b,&head[a]);
        }else if(cmd=="LEAVE"){
            int a;
            scanf("%d",&a);
            if(!leave_front(a,&head[a])){
                printf("queue %d is empty!\n",a);
            }
        }else if(cmd=="JOIN"){
            int a,b;
            scanf("%d %d",&a,&b);
            join(a,b,&head[b]);
        }else if(cmd=="SIZE"){
            int a;
            cin >> a;
            cout << cosize(head[a])<<endl;
        }else if(cmd=="PRINT"){
            int a;
            cin >> a;
            print(head[a]);
            cout <<endl;
        }
//        cout << cosize(head[1]);
    }
    for(int i=1;i<=n;i++){
        printf("queue %d:",i);
        print(head[i]);
        printf("\n");
    }

}
