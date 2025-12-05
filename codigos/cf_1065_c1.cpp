#include<bits/stdc++.h>

using namespace std;

void solve(){
    int n; cin>>n;
    vector<int> a(n);
    vector<int> b(n);

    int score = 0;

    for(int &x:a){
        cin>>x;
        score^=x;
    }
    for(int &x:b){
        cin>>x;
        score^=x;
    }

    if(!score){
        cout<<"Tie"; return ;
    }

    int i,x=0;

    for(i=n-1;i>=0;i--){
        if(a[i]^b[i]){
            x=i;
            break;
        }
    }

    cout<<(x%2!=0?"Mai":"Ajisai");


}

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int t; cin>>t;
    while(t--){
        solve();
        if(t>0)cout<<'\n';
    }

    return 0;
}