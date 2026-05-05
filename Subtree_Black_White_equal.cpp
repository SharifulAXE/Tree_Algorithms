/*
In The Name Of Allah

From Dust I Have Come I Will be Dust

Author: Md. Shariful Islam Sijan
*/

#include <bits/stdc++.h>
using namespace std;
#define nl "\n"
#define int long long
#define yes cout << "YES" << nl;
#define no cout << "NO" << nl;
#define vi vector<int>
#define ip(x) for(auto &it : x) cin >> it
#define all(x) x.begin(),x.end()

// function are here
const int N=1e5+7;

int ans=0;

vector<pair<int,int>>cnt(N);

void dfs(int node , int parent, vector< int >adj[],string &s){

    // loop for each just find callig dfs

    if(s[node-1]=='B'){
        cnt[node]={0,1};
    }else{
        cnt[node]={1,0};
    }

    for(auto child:adj[node]){

        if(parent==child) continue;

        dfs(child,node,adj,s);
        cnt[node].first+=cnt[child].first;
        cnt[node].second+=cnt[child].second;
        

       

    }

}

void solve() {

    // Code Here
    int n; cin >> n ;
    vi a(n-1);

    ip(a);

    string s ; cin >> s;

    vector< int >adj[n+2];

    for(int i=0; i<n-1; i++){

        adj[a[i]].push_back(i+2);
        adj[i+2].push_back(a[i]);

    }


    dfs(1,0,adj,s);

    for(int i=1; i<=n; i++){
        if(cnt[i].first==cnt[i].second) ans++;
    }
    

    cout<<ans<<nl;
    ans=0;



}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
    cin >> tc;
    while(tc--){
        solve();
    }
}

/**
░█████╗░░░░░░░░░░░░░░░
██╔══██╗░░██╗░░░░██╗░░
██║░░╚═╝██████╗██████╗
██║░░██╗╚═██╔═╝╚═██╔═╝
╚█████╔╝░░╚═╝░░░░╚═╝░░
░╚════╝░░░░░░░░░░░░░░░
**/