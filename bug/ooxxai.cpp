#include<bits/stdc++.h>
using namespace std;
char g[4][4] ;
int l[8][3]={{0,1,2},{3,4,5},{6,7,8},{0,3,6},
                {1,4,7},{2,5,8},{0,4,8},{2,4,6}} ;
char end=0;
void desscript(void){
    cout <<"遊戲說明:"<<endl;
    cout <<"棋盤模式"<<endl;
    cout <<"橫軸為y縱軸為x"<<endl;
    cout <<"輸入xy軸座標"<<endl;
    cout <<"如果輸入1 2"<<endl;
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
    cout << "請輸入x,y座標:";
    int x,y,result=0;
    cin >> x>>y;
    x--;
    y--;
    if(x>=0&&x<3&&y>=0&&y<3){
        if(g[x][y]=='.'){
            g[x][y]='O';
            return;
        }
        cout <<"請勿重複下"<<endl;
        result=1;
    }
    if(result==0)
        cout << "格式錯誤";
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
            printf("你輸了");
            return;
        }
//        printf("你輸了測試");
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
            printf("你贏了\n");
            return;
        }
//            printf("你贏了測試");
        }
    }
//    cout <<endl;
    int result=0;
    for(int i=0;i<3;i++){
        for(int q=0;q<3;q++){
            if(g[i][q]=='.'){
                result++;
            }
//            printf("平手測試%d",result);
        }
    }
//    cout << endl;
    if(result==0){
        printf("平手");
        end='N';
        return;
    }
}
int main(){
    cout << "棋盤初始化......"<<endl;
    for(int i=0;i<3;i++){
        for(int q=0;q<3;q++){
            g[i][q]='.';
        }
    }
    print();
    cout << "初始化完成";
    desscript();
    cout <<"開始請按輸入y:";
    cin >> end;
    int change=0;
    cout<< "選擇攻守1代表先攻2代表先守:";
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
//        cout <<"進入輸出模式"<<endl;
        print();
//        system("pause");
//        cout << "進入審查模式"<<endl;
        referee();
    }
    cout << "遊戲結束";
    system("pause");
    return 0;

}
