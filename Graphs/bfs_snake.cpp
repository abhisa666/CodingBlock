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

    void addEdge(int x,int y){
        l[x].push_back(y);
    }

    int bfs_sssp(T src,T dest){
        map<T,int> dist; //visited map - store the distance
        map<T,T> parent; // to store the parent
        queue<T> q;

        //marks all dist to INT_MAX
        for(auto node_pair:l){
            T node = node_pair.first;
            dist[node] = INT_MAX;
        }

        q.push(src);
        dist[src]=0;
        parent[src] = src;

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
                    parent[nbr]=node;
                }
            }
        }

        //print the distance from source to destination node
        for(auto node_pair:l){
            T node = node_pair.first;
            int d = dist[node];
            cout<<"Node "<<node<<" Dist from the src "<<d<<endl;
        }
        cout<<endl;

        //dest to src
        T temp = dest;
        while(temp!=src){
            cout<<temp<<"<--";
            temp = parent[temp];
        }
        cout<<src<<endl;
        return dist[dest];
    }

    
};


int main(){

    int board[50]={0};
    //Ladder : 2 - 15 therefore board[2] = 13
    //snake : 20 - 6 therefore board[20] = -14
    // These are Jumps
    board[2]=13;
    board[5]=2;
    board[9]=18;
    board[18]=11;
    board[17]=-13;
    board[20]=-14;
    board[24]=-8;
    board[25]=10;
    board[32]=-2;
    board[34]=-22;

    //Add edges to the graph
    Graph<int> g;

    for(int i=0;i<37;i++){
        for(int dice=1;dice<=6;dice++){
            int j = i + dice;
            j+=board[j];

            if(j<=36){
                g.addEdge(i,j);
            }
        }
    }
    g.addEdge(36,36);

    cout<<g.bfs_sssp(0,36);

    return 0;
}