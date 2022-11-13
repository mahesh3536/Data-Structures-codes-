#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int> rank,parent,size;
    public: 
    DisjointSet(int n){
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1);
        for(int i = 0;i<=n;i++){
            parent[i]=i;
            size[i]= 1;
        }
    }
    int findUPar(int node){
        if(node == parent[node]) {
            return node;
        }
        return parent[node]=findUPar(parent[node]);
    }
    void unionByRank(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u == ulp_v) return;
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
    
};
class graph{
   public:
   int nodes;
   graph(int n){
    this->nodes = n;
   }
   unordered_map<int,list<vector<int>>> adj;
   void print();
   void addEdge(int , int ,int ,bool);
   void shortest_path(int);
   void prim_algorithm(int);
   void Kruskal_algorithm();
};
int main(){
   graph g (7);
   cout << "Enter edges : ";
   int m ;
   cin>>m;
   for(int i = 0;i<m;i++){
    int u,v,weight;
    cin >> u >> v >> weight ;
    g.addEdge(u,v,weight,0);
   }
   g.print();

   cout << endl;
   g.prim_algorithm(1);
    cout << endl;
   g.Kruskal_algorithm();
}

void graph :: print() {
    for (auto i : adj)
        {
            cout << i.first<< "->";
            for(auto j : i.second){
                cout << "{" << j[0] << "," << j[1] << "}" << " ";
            }
            cout << endl;
        }
}

void graph :: addEdge(int u,int v,int weight,bool direction){
    adj[u].push_back({v,weight});
    if(direction==0){
        adj[v].push_back({u,weight});
    }
}

void graph :: shortest_path(int S){
    vector<int> dist(nodes+1,1e9);
    set<pair<int,int>> s;
    dist[S]=0;
    s.insert({0,S});
    while(!s.empty()){
        auto it = *(s.begin());
        int dis = it.first ;
        int node = it.second;
        s.erase(it);
        for(auto j : adj[node]){
             int adjdist = j[1];
             int adjnode = j[0];
             if(dis + adjdist < dist[adjnode]){
                if(dist[adjnode]!=1e9){
                    s.erase({dist[adjnode],adjnode});
                }
                dist[adjnode] = dis + adjdist;
                s.insert({dis+adjdist,adjnode});
             }
        }
    }


    for(int i = 0;i<=nodes;i++){
        if(dist[i]==1e9) cout << -1 << " ";
        else cout << dist[i] << " ";
    }
}
void graph :: prim_algorithm(int S){
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int>>> pq;
    vector<int> vis(this->nodes ,0);
    unordered_map<int,list<vector<int>>> adj1;
    pq.push({0,S});
    int minWt = 0;
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if(vis[node]==1) continue;
        int mini = INT_MAX;
        minWt+=wt;
        for(auto it : adj[node]){
            if(it[1]==wt){
               mini = min(mini,it[0]);
            }
        }
        if(mini!=INT_MAX)
        {adj1[node].push_back({mini,wt});
        adj1[mini].push_back({node,wt});}
        vis[node] = 1;
        for(auto it : adj[node]){
            int adjnode = it[0];
            int adjwt = it[1];
            if(!vis[adjnode]){
                pq.push({adjwt,adjnode});
            }
        }
    }
   cout << "Weight of minimum spannig tree is : " << minWt << endl;
   for (auto i : adj1)
        {
            cout << i.first<< "->";
            for(auto j : i.second){
                cout << "{" << j[0] << "," << j[1] << "}" << " ";
            }
            cout << endl;
        }
   cout << endl;
} 
void graph :: Kruskal_algorithm(){
    vector<pair<int,pair<int,int>>> edges;
    unordered_map<int,list<vector<int>>> adj1;
    for(int i = 1 ; i<=this->nodes;i++){
        for(auto it : adj[i]){
            int adjNode = it[0];
            int wt = it[1];
            int node = i;
            edges.push_back({wt,{node,adjNode}});
        }
    }
    sort(edges.begin(),edges.end());
    DisjointSet ds(this->nodes);
    int minWt = 0;
    for(auto it : edges){
        int weight = it.first ;
        int u = it.second.first ;
        int v = it.second.second;
        if(ds.findUPar(u) != ds.findUPar(v)){
             adj1[u].push_back({v,weight});
             adj1[v].push_back({u,weight});
             minWt+=weight;
             ds.unionBySize(u,v);
        }
    }
    cout << "Weight of minimum spannig tree is : " << minWt << endl;
    //printing minimum spanning tree 
    for (auto i : adj1)
        {
            cout << i.first<< "->";
            for(auto j : i.second){
                cout << "{" << j[0] << "," << j[1] << "}" << " ";
            }
            cout << endl;
        }
   cout << endl;
}