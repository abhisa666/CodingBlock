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

    void bfs(T src){
        map<T,bool> visited; //visited map - T[src] = true to make it visited
        queue<T> q;

        q.push(src);
        visited[src]=true;

        while(!q.empty()){
            T node = q.front();
            q.pop();
            cout<<node<<", ";

            // push the nbrs in the queue of the node just poped
            for(auto nbr:l[node]){
                if(!visited[nbr]){
                    q.push(nbr);
                    //Mark the pushed nbr as visited
                    visited[nbr]=true;
                }
            }
        }
    }


};


int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,8);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(1,11);
    g.addEdge(3,4);
    g.addEdge(3,12);
    g.addEdge(4,5);

    g.bfs(0);


    return 0;
}