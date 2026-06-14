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
const int N = 200005;

// altime you can not declair vector 
// because it is compitation error dekhabe

int dist[N];
int dist1[N];
int dist2[N];

void dfs(int node ,int parent,int cnt,vi a[]){

    dist[node]=cnt;

    for(auto i:a[node]){

        if(i!=parent){
            dfs(i,node,cnt+1,a);
        }
    }
}


void dfs1(int node ,int parent,int cnt,vi a[]){

    dist1[node]=cnt;

    for(auto i:a[node]){

        if(i!=parent){
            dfs1(i,node,cnt+1,a);
        }
    }
}

void dfs2(int node ,int parent,int cnt,vi a[]){

    dist2[node]=cnt;

    for(auto i:a[node]){

        if(i!=parent){
            dfs2(i,node,cnt+1,a);
        }
    }
}


void solve() {

    // Code Here


    int n; cin >> n;
    vi a[n+1];

    // dist.resize(n+1,0);
    // dist1.resize(n+1,0);
    // dist2.resize(n+1,0);




    for(int i=0; i<n-1; i++){
        int u,v; cin >> u >> v; 
        a[u].push_back(v);
        a[v].push_back(u);
    }

    // first node call then calculate the 1 node to maximum distance 

    dfs(1,-1,0,a);

    // calculate the maximum distance 

    int mx_leaf_node=0;
    int mx=0;

    for(int i=1;i<=n;i++){
        if(mx<=dist[i]){
            mx=dist[i];
            mx_leaf_node=i;
        }
    }
    dfs1(mx_leaf_node,-1,0,a);

    // another max distance leaf node 

    mx=0;
    mx_leaf_node=0;

    for(int i=1;i<=n;i++){
        if(mx<=dist1[i]){
            mx=dist1[i];
            mx_leaf_node=i;
        }
    }

    dfs2(mx_leaf_node,-1,0,a);

    // calculate the each node to maximun distance another node 

    vi ans;

    for(int i=1; i<=n; i++){
        ans.push_back(max(dist1[i],dist2[i]));
    }

    for(int i=0; i<n;i++){
        cout << ans [i] << " ";
        
    }
    cout << endl;






}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
   // cin >> tc;
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