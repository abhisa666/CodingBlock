#include<iostream>
#include<map> //Hash map
#include<list>
#include<queue>

using namespace std;

template<typename T>

class Graph{

map<T,list<T>> l;
public:

    void addEdge(T x,T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool> &visited){
        //Recursive function that will treverse the graph
        cout<<src<<" ";
        visited[src]=true;
        //go to all nbr of that node which is not visited
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited);
            }
        }
    }

    void dfs(T src){
        map<T,bool> visited;
        //Mark all the nodes as not visited in the beginning
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }

        dfs_helper(src,visited);
    }


};


int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    
    g.addEdge(3,0);
    g.addEdge(4,6);
    g.addEdge(4,5);
 




    g.dfs(0);


    return 0;
}