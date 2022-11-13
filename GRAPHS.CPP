#include <bits/stdc++.h>
using namespace std;

class graph
{
public:
    int nodes;
    unordered_map<int,list<int>> adj;
    graph(int n){
        this->nodes = n;
    }
    void addEdge(int u, int v, bool direction)
    {
        // direction 0 undirected
        // direction 1 undirected graph
        adj[u].push_back(v);
        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void print()
    {
        for (auto i : adj)
        {
            cout << i.first<< "->";
            for (auto j : i.second)
            {
                cout << j << " ";
            }
            cout << endl;
        }
        
    }
    void bfs(int);
    void dfs(int);
    void dfs(int,int []);
    void prim_algorithm();
};
void graph ::  bfs(int src){
     int vis[nodes] = {0};
     vis[src] = 1;
     queue<int> q;
     q.push(src);
     while(!q.empty()){
        int front = q.front();
        cout << front << " ";
        q.pop();
        for(auto it : this->adj[front]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
     }

}
void graph ::  dfs(int src){
    int vis[nodes]={0};
    dfs(src,vis);
}
void graph ::  dfs(int src,int vis[]){
    vis[src] = 1;
    cout << src << " ";
    for(auto it : this->adj[src]){
        if(!vis[it]){
            dfs(it,vis);
        }
    }
}
int main()
{   
    int n;
    cout << "Enter the number of nodes:";
    cin >> n;
    int m;
    cout << "Enter the number of edges:";
    cin >> m;
    graph g(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v, 1);
    }
    //0 1 0 2 2 0 3 3 2 3 1 2 

    g.print();
    cout << endl;
    
    g.bfs(2);
    cout << endl;
    g.dfs(2);
}