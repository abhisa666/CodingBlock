//Distance calculated by a Level Order traversal or BFS is the shortest for UN-WEIGHTED GRAPH
#include<iostream>
#include<map> //Hash map
#include<list>
#include<queue>
#include<climits>

using namespace std;

template<typename T>

class Graph{

map<T,list<T>> l;
public:

    void addEdge(T x,T y){
        l[x].push_back(y);
        l[y].push_back(x);
    }

    void bfs_sssp(T src){
        map<T,int> dist; //visited map - store the distance
        queue<T> q;

        //marks all dist to INT_MAX
        for(auto node_pair:l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src]=0;


        while(!q.empty()){
            T node = q.front();
            q.pop();
            // cout<<node<<", ";

            // push the nbrs in the queue of the node just poped
            for(auto nbr:l[node]){
                if(dist[nbr]==INT_MAX){
                    q.push(nbr);
                    //Mark the pushed nbr as visited and assign distance
                    dist[nbr]=dist[node]+1;
                }
            }
        }

        //print the distance to every node
        for(auto node_pair:l){
            T node = node_pair.first;
            int d = dist[node];
            cout<<"Node "<<node<<" Dist from the src "<<d<<endl;
        }
    }


};


int main(){

    Graph<int> g;
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(4,5);


    g.bfs_sssp(0);


    return 0;
}