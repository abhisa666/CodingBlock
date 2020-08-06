// Check if a Directed Graph has a Cycle or not by DFS
// Cycle - connection back to a node in the current path of the node
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
    }

    bool cycle_helper(int src,bool *visited,bool *currentPath){

        //visit a node
        visited[src]=true;
        currentPath[src]=true;

        for(auto nbr:l[src]){
            if(currentPath[nbr]){
                return true;
            }
            else if(!visited[nbr]){
                bool cycle_mila = cycle_helper(nbr,visited,currentPath);
                if(cycle_mila){
                    return true;
                }
            }
        }
        //leaves the node
        currentPath[src]=false;
        return false;
    }

    bool is_cycle(){
        bool *visited = new bool[V];
        bool*currentPath = new bool[V];

        //no node is visited 
        for(int i=0;i<V;i++){
            visited[i] = false;
            currentPath[i] = false;
        }
        int src=0;

        return cycle_helper(src,visited,currentPath);

    }
};

int main(){

    Graph g(7);
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);
    g.addEdge(1,5);
    g.addEdge(5,6);
    g.addEdge(4,2); //back edge -  node which is connected to an ansester of the given node in the same path


    if(g.is_cycle()){
        cout<<"This Graph has a cycle";
    }
    else{
        cout<<"This Graph does not has a cycle";
    }

    return 0;
}