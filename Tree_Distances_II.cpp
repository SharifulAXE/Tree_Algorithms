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
 
const int N = 2e5 + 5;

vector<int> g[N];
long long sub[N], dist[N];
int n;

// it is an approach to calculate each node 
// tree dp + reconstructing dp


void dfs1(int u, int p, int depth) {
    sub[u] = 1;
    dist[1] += depth;

    for (int v : g[u]) {
        if (v == p) continue;
        dfs1(v, u, depth + 1);
        sub[u] += sub[v];
    }
}

void dfs2(int u, int p) {
    for (int v : g[u]) {
        if (v == p) continue;

        dist[v] = dist[u] + (n - sub[v])-sub[v];
        dfs2(v, u);
    }
}

 

void solve() {

    // Code Here


    cin >> n;
    for (int i = 1; i < n; i++) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dfs1(1, 0, 0);
    dfs2(1, 0);

    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << "\n";


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int tc = 1;
   //// cin >> tc;
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