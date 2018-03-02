#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define bloop(i,n,j) for(int (i)=(j);(i)<(n);(i)++)
#define bloop1(i,n,j) for(int (i)=(j);(i)<=(n);(i)++)
#define sloop(i,n,j) for(int (i)=n;(i)>(j);(i)--)
#define sloop1(i,n,j) for(int (i)=n;(i)>=(j);(i)--)
#define pb push_back
#define F first
#define S second
#define LL long long int
#define be(a) a.begin
#define itr iterator
#define p_q priority_queue
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
#define D double
#define MS0(x) memset((x),0,sizeof((x)))
#define MS1(x) memset((x),-1,sizeof((x)))
#define RI(x) x=rit()
#define RII(a,b) a=rit(),b=rit()
#define RIII(a,b,c) a=rit(),b=rit(),c=rit()
const int INF = 0x7f7f7f7f;
inline LL rit(){
    LL f=0,key=1;
    char c;
    do{
        c=getchar();
        if(c=='-') key=-1;
    }while(c<'0' || c>'9');
    do{
        f=f*10+c-'0';
        c=getchar();
    }while(c>='0' && c<='9');
    return f*key;
}
char s[1000][1000];
struct xy{
    int x,y;
};
struct an{
    char n;
    int data;
};
bool check(xy *now,int h,int l){
    for(int i=1;i<=h;i++){
        for(int q=1;q<=l;q++){
            if(s[i][q]>='a'&&s[i][q]<='z'){
                now->x=i;
                now->y=q;
                return true;
            }
        }
    }
    return false;
}
bool cmd(an a,an b){
    if(a.data!=b.data){
        return a.data>b.data;
    }
    return a.n<b.n;
}
int main(){
    int n,n2;
    cin >> n;
    n2=n;
    while(n--){
        int l,h;
        memset(s,0,sizeof(s));
        queue<xy> qu;
        vector<an> ans2;
        map<char,int> ans;
        cin >> h>>l;
        for(int i=1;i<=h;i++){
            for(int q=1;q<=l;q++){
                cin >> s[i][q];
            }
        }
        xy now;
        while(check(&now,h,l)){
            int all=0;
            char word=s[now.x][now.y];
            qu.push(now);
            while(!qu.empty()){
                int d[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
                xy now=qu.front();
                qu.pop();
//                cout <<now.x<<" "<<now.y<<" "<<s[now.x][now.y]<<endl;
                if(s[now.x][now.y]<'a'||s[now.x][now.y]>'z')continue;
//                system("pause");
                for(int i=0;i<4;i++){
                    if(s[now.x+d[i][0]][now.y+d[i][1]]==s[now.x][now.y]){
                        all++;
                        xy will;
                        will.x=now.x+d[i][0];
                        will.y=now.y+d[i][1];
                        qu.push(will);
                    }
                }
                s[now.x][now.y]='1';
            }
            if(ans.find(word)!=ans.end()){
                ans[word]++;
            }else{
                ans.insert(pair<char,int>(word,1));
            }
        }
        for(map<char,int>::iterator it=ans.begin();it!=ans.end();it++){
            an a;
            a.n=it->F;
            a.data=it->S;
            ans2.push_back(a);
        }
        sort(ans2.begin(),ans2.end(),cmd);
        cout << "World #"<<n2-n<<endl;
        for(vector<an>::iterator it=ans2.begin();it!=ans2.end();it++){
            cout <<it->n<<": "<<it->data<<endl;
        }
    }
}
