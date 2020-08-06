// Cycle detaction in a undirected graph by DSU
#include<iostream>
#include<vector>
using namespace std;

class dsu{
    vector<int> parent;
    int total_component;
public:

    void init(int v){
        parent.resize(v);
        // sz.resize(v);
        for(int i=0;i<v;i++) parent[i] = i;
        // for(int i=0;i<v;i++) sz[i] = 1;
        total_component=v;
    }

    int get_superparent(int x){
        if(x==parent[x]) return x;
        else return parent[x] = get_superparent(parent[x]); //path compression
    }

    void unite(int x,int y){
        int superparent_x = get_superparent(x);
        int superparent_y = get_superparent(y);
        if(superparent_x!=superparent_y){
            parent[superparent_x] = superparent_y;
            // sz[superparent_y] += sz[superparent_x];
            // sz[superparent_x] = 0;
            total_component--;
        }
    }

};

int main(){
    
    // we start building a graph simulation by dsu
    // we can be able to detect a cycle while making edges
    // a and b make a edge if they are in difrent components
    // if they are found in the same component there is a cycle

    dsu G;
    bool cycle=false;
    int n; // number of vertex
    cin>>n;

    G.init(n);

    int e; //number of edges
    cin>>e;

    //form the edges
    for(int i=0;i<e;i++){
        int x,y;
        cin>>x>>y;
        x--;
        y--;
        if(G.get_superparent(x)!=G.get_superparent(y)){
            // x and y are in diffrent components
            G.unite(x,y);
        }
        else{
            //in same component
            //there was a path from x to y hence a cycle detected
            cycle=true;
            // cout<<"This edge will give a cycle";
        }
    }

    if(cycle) cout<<"The graph has Cycle";
    else cout<<"No cycle is detected";


    return 0;

}

