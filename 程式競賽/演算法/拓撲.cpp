#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,ar[105][105]={},arp[105][105]={0};
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int q=1;q<=n;q++){
            cin >> ar[i][q];
        }
    }
    for(int i=1;i<=n;i++){
        arp[i][1]=ar[i][1];
    }
    for(int i=1;i<=n;i++){
        for(int q=2;q<=n;q++){
            arp[i][q]=arp[i][q-1]+ar[i][q];
        }
    }
//    for(int i=0;i<n;i++){
//        cout << arp[i][n-1]<<endl;
//    }
    int ma=-1e9;
    for(int i=0;i<n;i++){
        for(int q=i+1;q<=n;q++){
            int all=arp[1][q]-arp[1][i];
            for(int d=2;d<=n;d++){
//                if(all<(all+arp[d][q]-arp[d][i])&&all<arp[d][q]-arp[d][i])
//                    all+=(arp[d][q]-arp[d][i]);
//                else
//                    all=arp[d][q]-arp[d][i];
                all = max( arp[d][q] - arp[d][i] , all + arp[d][q] - arp[d][i] );
                if(all>ma)
                    ma=all;
            }
        }
    }
    cout << ma<<endl;
}
