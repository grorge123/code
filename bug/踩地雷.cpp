#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<queue>
using namespace std;
struct smap{
    int ty;
    int num;
};
struct df{
    int x;
    int y;
};
int flagint=0;
smap ma[1000][1000]={};
int end=0;
void randf(int n,int m,int a){
    int i;
    unsigned seed;
    seed = (unsigned)time(NULL); // ���o�ɶ��ǦC
    srand(seed);
    for(i=0; i<a;i++){
        int x=rand()%n;
        int y=rand()%m;
//        cout << "x"<<x<<"y"<<y;
        if(ma[x][y].num!=-1)
            ma[x][y].num=-1;
        else
            i--;
    }
}
void tprint(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num!=-1)
                cout << ma[i][q].num;
            else
                cout << "*";
        }
        cout << endl;
    }
}
void print(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].ty==0)
                cout << "-";
            else if(ma[i][q].ty==1)
                cout << "^";
            else if(ma[i][q].ty==3)
                cout << "?";
            else
                cout << ma[i][q].num;
        }
        cout << endl;
    }
}
void gprint(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num!=-1){
                if(ma[i][q].ty==0)
                    cout << "-";
                else if(ma[i][q].ty==1)
                    cout << "^";
                else if(ma[i][q].ty==2)
                    cout << ma[i][q].num;
                else if(ma[i][q].ty==3)
                    cout << "?";
            }else{
                cout << "*";
            }
        }
        cout << endl;
    }
}
void write(int n,int m){
    int fin[8][2]={{1,0},{1,1},{0,1},{-1,1},{0,-1},{-1,-1},{-1,0},{1,-1}};
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num!=-1){
                ma[i][q].num=0;
                for(int s=0;s<8;s++){
                    if(ma[i+fin[s][0]][q+fin[s][1]].num==-1)
                    ma[i][q].num++;
                }
            }
        }
    }
}
void whilt(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            ma[i][q].ty=0;
        }
    }
}
void bfs(int x,int y,int n,int m){
    queue<df> q;
    ma[x][y].ty=2;
    int fin[8][2]={{1,0},{1,1},{0,1},{-1,1},{0,-1},{-1,-1},{-1,0},{1,-1}};
    df now;
    now.x=x;
    now.y=y;
    q.push(now);
    while(q.empty()==0){
//        cout << "�i�Jdfs";
        df will;
        will=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            if(will.x+fin[i][0]>=0&&will.x+fin[i][0]!=n&&will.y+fin[i][1]>=0&&will.y+fin[i][1]!=m&&ma[will.x+fin[i][0]][will.y+fin[i][1]].num==0&&ma[will.x+fin[i][0]][will.y+fin[i][1]].ty==0){
                ma[will.x+fin[i][0]][will.y+fin[i][1]].ty=2;
                now.x=will.x+fin[i][0];
                now.y=will.y+fin[i][1];
//                cout << now.x<<" "<<now.y<<endl;
                q.push(now);
            }else if(will.x+fin[i][0]>=0&&will.x+fin[i][0]!=n&&will.y+fin[i][1]>=0&&will.y+fin[i][1]!=m){
                ma[will.x+fin[i][0]][will.y+fin[i][1]].ty=2;
            }
        }
    }
}
void flag (int x,int y,int a){
    if(flagint<=a){
        if(ma[x][y].ty==0){
            ma[x][y].ty=1;
            flagint++;
            return;
        }
    }else{
        cout << "�X�l���ഡ�W�L�a�p"<<endl;
        return;
    }
    if(ma[x][y].ty==1){
        ma[x][y].ty=3;
        return;
    }
    if(ma[x][y].ty==3){
        ma[x][y].ty=0;
        flagint--;
        return;
    }
}
void doit(int x,int y,int z,int n,int m,int a){
    if(z==3){
        tprint(n,m);
        return;
    }else if(z==2){
        flag(x,y,a);
    }else if(z==1){
        if(ma[x][y].num==-1){
            cout << "gameover"<<endl;
            end=1;
            gprint(n,m);
            return;
        }else if(ma[x][y].num==0){
            bfs(x,y,n,m);
        }else{
            ma[x][y].ty=2;
        }
    }else{
    cout << "�L�����O";
    return;
    }
}
void referee(int n,int m){
    for(int i=0;i<n;i++){
        for(int q=0;q<m;q++){
            if(ma[i][q].num==-1&&ma[i][q].ty!=1)
                return;
        }
    }
    cout << "�AĹ�F"<<endl;
    end=1;
    return;
}
int main(){
    int n,m,a=1e9;
    cout << "�ФJ���e:";
    cin >> n>>m;
    while(a>n*m/2){
        cout << "�п�J�a�p�ƶq:";
        cin >>a ;
        if(a>n*m/2)
            cout << "�a�p�ƻݤp������e��2";
    }
    cout << "�C����l��"<<endl;
    randf(n,m,a);
    write(n,m);
    while(end==0){
        print(n,m);
        int x,y,z;
        cout << "�п�Jxy�y�ЩM����ʧ@1�O���X2�O��U�h";
        cin >>x>>y>>z;
        x--;y--;
        if(ma[x][y].ty!=2)
            if(x<0||y<0||x>n||y>m)
                cout << "�W�X�d��"<<endl;
            else
                doit(x,y,z,n,m,a);
        else
            cout << "����w�}�o";
        if(flagint==a)
            referee(n,m);
    }
//    tprint(n,m);
}
