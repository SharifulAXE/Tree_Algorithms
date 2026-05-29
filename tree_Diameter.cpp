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

const int N = 1e5 + 5;

vector<int> graph[N];
int farthestNode;
int maxDistance;

void dfs(int node, int parent, int distance) {

    // maximum leaf node distance from root node to leaf node
    if (distance > maxDistance) {
        maxDistance = distance;
        farthestNode = node;
    }

    for (auto child : graph[node]) {

        if (child == parent) continue;

        dfs(child, node, distance + 1);
    }
}

void solve() {

    // Code Here
  

    int n;
    cin >> n;

    // n-1 edges
    for (int i = 0; i < n - 1; i++) {

        int u, v;
        cin >> u >> v;

        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // 1st DFS
    maxDistance = -1;
    dfs(1, -1, 0);

    int A = farthestNode;

    // 2nd DFS
    maxDistance = -1;
    dfs(A, -1, 0);

    cout << "Tree Diameter = " << maxDistance << endl;
 
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