inline int mul(int a,int b){
    return (a*b)%mod7;
}
inline int add(int a,int b){
    return (a+b)%mod7;
}
void mat_mul(int ans[3][3],int a[3][3],int b[3][3]){
    int c[3][3];
    MS0(c);
    REP(i,3) REP(j,3) REP(k,3)
        c[i][j] = add(c[i][j],mul(a[i][k],b[k][j]));

    REP(i,3) REP(j,3)
        ans[i][j] = c[i][j];
}
void mat_mul2(int ans[3],int a[3],int b[3][3]){
    int c[3];
    MS0(c);
    REP(i,3) REP(j,3)
        c[i] = add(c[i],mul(a[j],b[i][j]));
    REP(i,3) ans[i] = c[i];
}
int mei[32][3][3];
void init(){
    mei[0][0][1] = mei[0][1][2] = mei[0][2][0] = mei[0][2][1] = mei[0][2][2] = 1;
    REP1(i,1,32){
        mat_mul(mei[i],mei[i-1],mei[i-1]);
    }
}
int n;
int a[3];
void read(){
    n = rit()-1;
    a[0] = a[1] = a[2] = 1;
}
void solve(){
    int i=0;
    while(n){
        if(n%2) mat_mul2(a,a,mei[i]);
        n>>=1;
        i++;
    }
    cout<<a[0]<<endl;
}