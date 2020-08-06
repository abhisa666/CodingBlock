//Sort the dependency of the nodes
// We will use in-degree - no of nodes the given node is depend on
#include<iostream>
#include<map> //Hash map
#include<list>
#include<queue>
#include<cstring>

using namespace std;

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
    }

    void topological_sort_bsf(){
        //indegree array
        int *indegre = new int[V];
        //init 0 indegreee to all
        for(int i=0;i<V;i++){
            indegre[i]=0;
        }
        //update indegreee by traversing edges 
        // if x->y -- indegree[y]++
        for(int i=0;i<V;i++){
            for(int nbr:l[i]){
                indegre[nbr]++;
            }
        }

        //bfs
        queue<int> q;
        //1. find nodes with indegree 0
        for(int i=0;i<V;i++){
            if(indegre[i]==0){
                q.push(i);
            }
        }

        //Start removing elements from the queue
        while(!q.empty()){
            int node = q.front();
            cout<<node<<" ";
            q.pop();
            // Iterate over the nbr of the poped node and
            //decrease its indegree
            for(auto nbr:l[node]){
                indegre[nbr]--;
                if(indegre[nbr]==0){
                    q.push(nbr);
                }
            }


        }
    }
};



int main(){

    Graph g(6);

    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(2,5);
    g.addEdge(2,3);
    g.addEdge(4,5);
    g.addEdge(3,5);

    g.topological_sort_bsf();

    return 0;
}