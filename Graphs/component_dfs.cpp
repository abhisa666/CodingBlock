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

    void dfs(){
        map<T,bool> visited;
        //Mark all the nodes as not visited in the beginning
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }

        //Iterate over all the vertices and init a dfs call
        int cnt=0;
        for(auto p:l){
            T node = p.first;
            if(!visited[node]){
                cout<<"Component "<<cnt<<" --> ";
                dfs_helper(node,visited);
                cout<<endl;
                cnt++;
            }
        } 
        
    }


};


int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(0,3);
    g.addEdge(0,4);

    g.addEdge(5,6);
    g.addEdge(6,7);

    g.addEdge(8,8);
 
    g.dfs();


    return 0;
}