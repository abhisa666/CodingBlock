//Cheack if a undirected Graph is a Tree or not
// Cycle detection by BFS
// Graph wiithout a cycle is a tree
#include<iostream>
#include<list>
#include<queue>
using namespace std;

// Nodes or vertex is Integer
class Graph{
    int V;
    //array of lists of size V
    list<int> *l;
    public:

    Graph(int v){
        this->V=v;
        l = new list<int>[V];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    // Check if we are visiting a node by more than one path - it has cycle
    bool is_tree(){
        bool *visited = new bool[V];
        int *parent =  new int[V];

        queue<int> q;

        //no node is visisted initialy 
        for(int i=0;i<V;i++){
            visited[i] = false;
            parent[i] = i;
        }

        int src=0;
        q.push(src);
        visited[src]=true;

        //pop out one node from queue and visit its nbrs
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto nbr:l[node]){
                if(visited[nbr]==true && parent[node]!=nbr){
                    return false;
                }
                else if(!visited[nbr]){
                    visited[nbr]=true;
                    parent[nbr]=node;
                    q.push(nbr);
                }
               
            }
        }

        return true;
    }
};

int main(){

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(3,2);
    g.addEdge(1,2);
    // g.addEdge(0,3);

    if(g.is_tree()){
        cout<<"This Graph is a Tree";
    }
    else{
        cout<<"This Graph is not a Tree as it has a cycle";
    }

    return 0;
}