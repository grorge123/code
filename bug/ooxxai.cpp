#include<bits/stdc++.h>
using namespace std;
char g[4][4] ;
int l[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},
                {1,4,7},{2,5,8},{0,4,8},{2,4,6}} ;
char end=0;
void desscript(void){
    cout <<"�C������:"<<endl;
    cout <<"�ѽL�Ҧ�"<<endl;
    cout <<"��b��y�a�b��x"<<endl;
    cout <<"��Jxy�b�y��"<<endl;
    cout <<"�p�G��J1 2"<<endl;
    cout <<".O."<<endl<<"..."<<endl<<"..."<<endl;
}
void print(void){
    cout << endl;
    for(int i=0;i<3;i++){
        for(int q=0;q<3;q++){
            cout << g[i][q];
        }
        cout << endl;
    }
}
void other(void){
    cout << "�п�Jx,y�y��:";
    int x,y,result=0;
    cin >> x>>y;
    x--;
    y--;
    if(x>=0&&x<3&&y>=0&&y<3){
        if(g[x][y]=='.'){
            g[x][y]='O';
            return;
        }
        cout <<"�Фŭ��ƤU"<<endl;
        result=1;
    }
    if(result==0)
        cout << "�榡���~";
    other();
}
void com(void){
    for(int i=0;i<8;i++){
        int result=0;
        for(int q=0;q<3;q++){
            int x=l[i][q]/3,y=l[i][q]%3;
            if(g[x][y]=='X'){
                result++;
            }
            if(result==2){
                for(int s=0;s<3;s++){
                    int x=l[i][s]/3,y=l[i][s]%3;
                    if(g[x][y]=='O')break;
                    if(g[x][y]=='.'){
                        g[x][y]='X';
                        return;
                    }
                }
            }
        }
    }
    for(int i=0;i<8;i++){
        int result=0;
        for(int q=0;q<3;q++){
            int x=l[i][q]/3,y=l[i][q]%3;
            if(g[x][y]=='O'){
                result++;
            }
            if(result==2){
                for(int s=0;s<3;s++){
                    int x=l[i][s]/3,y=l[i][s]%3;
                    if(g[x][y]=='X')break;
                    if(g[x][y]=='.'){
                        g[x][y]='X';
                        return;
                    }
                }
            }
        }
    }
    int ran=1;
    srand(time(NULL));
    int a=(rand()%9);
    while(ran){
        int x=a/3,y=a%3;
        if(g[x][y]=='.'){
            g[x][y]='X';
            ran=0;
            return;
        }
        a++;
        a%9;
    }
}
void referee(void){
    for(int i=0;i<8;i++){
        int result=0;
        for(int q=0;q<3;q++){
            int x=l[i][q]/3,y=l[i][q]%3;
            if(g[x][y]=='X'){
                result++;
            }
        if(result==3){
            end='N';
            printf("�A��F");
            return;
        }
//        printf("�A��F����");
        }
    }
//    cout << endl;
    for(int i=0;i<8;i++){
        int result=0;
        for(int q=0;q<3;q++){
            int x=l[i][q]/3,y=l[i][q]%3;
            if(g[x][y]=='O'){
                result++;
            }
        if(result==3){
            end='N';
            printf("�AĹ�F\n");
            return;
        }
//            printf("�AĹ�F����");
        }
    }
//    cout <<endl;
    int result=0;
    for(int i=0;i<3;i++){
        for(int q=0;q<3;q++){
            if(g[i][q]=='.'){
                result++;
            }
//            printf("�������%d",result);
        }
    }
//    cout << endl;
    if(result==0){
        printf("����");
        end='N';
        return;
    }
}
int main(){
    cout << "�ѽL��l��......"<<endl;
    for(int i=0;i<3;i++){
        for(int q=0;q<3;q++){
            g[i][q]='.';
        }
    }
    print();
    cout << "��l�Ƨ���";
    desscript();
    cout <<"�}�l�Ы���Jy:";
    cin >> end;
    int change=0;
    cout<< "��ܧ�u1�N�����2�N����u:";
    cin>>change;
    system("cls");
    if(change==2){
        com();
        print();
//        system("pause");
//        system("cls");
    }
    while(end=='y'){
        other();
        print();
//        system("pause");
//        system("cls");
        referee();
        if(end=='N')break;
        com();
//        cout <<"�i�J��X�Ҧ�"<<endl;
        print();
//        system("pause");
//        cout << "�i�J�f�d�Ҧ�"<<endl;
        referee();
    }
    cout << "�C������";
    system("pause");
    return 0;

}
