// Check if a Undirected Graph has a Cycle or not using DFS
// Cycle - more than one way to visit a node
#include<iostream>
#include<list>
#include<queue>
using namespace std;

// Nodes or vertex is Integer
class Graph{
    int V;
    //array of lists of size V
    list<int> *l;\
    public:

    Graph(int v){
        this->V=v;
        l = new list<int>[V];
    }

    void addEdge(int x,int y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    bool cycle_helper(int node,bool *visited,int parent){

        //visit a node
        visited[node]=true;

        for(auto nbr:l[node]){
            if(!visited[nbr]){
                parent=node;
                bool cycle_mila = cycle_helper(nbr,visited,parent);
                if(cycle_mila){
                    return true;
                }
            }
            //nbr is visisted and the nbr is not the parent
            else if(nbr!=parent){
                return true;
            }
        }

        //leaves the node
        return false;
    }

    bool is_cycle(){
        bool *visited = new bool[V];

        //no node is visited 
        for(int i=0;i<V;i++){
            visited[i] = false;
        }
        int node=0;
        int parent = -1;
        return cycle_helper(node,visited,parent);

    }
};

int main(){

    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    //g.addEdge(4,0);
    
    if(g.is_cycle()){
        cout<<"This Graph has a cycle";
    }
    else{
        cout<<"This Graph does not has a cycle";
    }

    return 0;
}