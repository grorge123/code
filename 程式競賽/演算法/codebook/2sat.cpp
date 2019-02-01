

void dfs(int p){
    mk[p] = 1;
    SREP(i,v[p]){
        if(!mk[i]) dfs(i);
    }
    finish[r++] = p;
}
void dfs2(int p){
    mk[p] = 1;
    scc[p] = nscc;
    SREP(i,rv[p]){
        if(!mk[i]) dfs2(i);
    }
}
void do_scc(){
    MS0(mk);
    REP(i,n){
        if(!mk[i]) dfs(1);
    }
    MS0(mk);
    RREP(i,r){
        if(!mk[i]){
            dfs2(finish[i]);
            nscc++;
        }
    }
}

main(){
    cin>>a>>b;
    add_edge(not(a),b); //v && rv
    add_edge(not(b),a);
    do_scc();
    REP(i,n) if(scc[a] == scc[not(a)]) // no solution
    REP(i,2*n){
        if(!smk[scc[finish[i]]]){
            smk[scc[finish[i]]] = 1;
            smk[scc[not(finish[i])]] = 2;
        }
    }
    REP(i,n){
        if(smk[scc[i]] == 1) cout<<i<<endl;
        else cout<<"not "<<i<<endl;
    }

}