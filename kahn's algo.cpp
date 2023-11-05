#include<bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    unordered_map<int, list<int> > reqList;

    for(int i = 0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];

        reqList[u].push_back(v);
    }

    vector<int> indegree(v, 0);

    for(auto i : reqList) {
        for(auto j : i.second) {
            indegree[j]++;
        }
    }

    queue<int> q;

    for(int i = 0; i<v; i++) {
        if(indegree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> ans;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        ans.push_back(front);

        for(auto i : reqList[front]) {
            indegree[i]--;
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
    }
    return ans;
}

int main(){
    int v= 0;
    int e = 0;
    vector<vector<int> > edges;
    return 0;
}