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

// function here 


const int N = 200005;

vector<int> adj[N];
int subtree[N];

void dfs(int node, int parent) {

    subtree[node] = 1; // nije count hocche 


    for (int child : adj[node]) {
        if (child == parent) continue;

        dfs(child, node);
        subtree[node] += subtree[child];
    }
}

void solve() {

    // Code Here

 

    int n;
    cin >> n;

    // edges input
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // root = 1 
    dfs(1, 0);

    // output subtree size
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << " -> Subtree size = " << subtree[i] << '\n';
    }
 
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