#include <bits/stdc++.h> 
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    unordered_map<int, list<pair<int,int> > > adj;
    for(int i = 0; i<g.size(); i++) {
        int v = g[i].first.first;
        int u = g[i].first.second;
        int w = g[i].second;

        adj[v].push_back(make_pair(u,w));
        adj[u].push_back(make_pair(v,w));
    }

    vector<bool> mst(n+1);
    vector<int> key(n+1);
    vector<int> parent(n+1);

    // initialisation
    for(int i = 0; i<=n; i++) {
        key[i] = INT_MAX;
        parent[i] = -1;
        mst[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for(int i = 1; i<n; i++) {
        int mini = INT_MAX;
        int u;

        // finding min node
        for(int j = 1; j<=n; j++) {
            if(mst[j] == false && key[j] < mini) {
                u = j;
                mini = key[j];
            }
        }

        // marking it true
        mst[u] = true;

        // checking adj nodes
        for(auto j : adj[u]) {
            int v = j.first;
            int w = j.second;

            if(mst[v] == false && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    vector<pair<pair<int, int>, int>> ans;

    for(int i = 2; i<=n; i++) {
        ans.push_back(make_pair(make_pair(parent[i], i), key[i]));
    }

    return ans;


}
