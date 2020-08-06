#include<iostream>
#include<map> //Hash map
#include<list>
#include<queue>
#include<cstring>

using namespace std;

template<typename T>

class Graph{

map<T,list<T>> l;
public:

    void addEdge(T x,T y){
        l[x].push_back(y);
        // l[y].push_back(x);
    }

    void dfs_helper(T src,map<T,bool> &visited,list<T> &ordering){
        //Recursive function that will treverse the graph

        visited[src]=true;

        //go to all nbr of that node which is not visited
        for(auto nbr:l[src]){
            if(!visited[nbr]){
                dfs_helper(nbr,visited,ordering);
            }
        }

        //Just before return back pushfront the node
        ordering.push_front(src);
        return;
    }

    void dfs(){
        map<T,bool> visited;
        list<T> ordering;

        //Mark all the nodes as not visited in the beginning
        for(auto p:l){
            T node = p.first;
            visited[node] = false;
        }

        for(auto p:l){
            T node = p.first;
            if(!visited[node]){
                dfs_helper(node,visited,ordering);
            }
        } 

        //print the order list
        for(auto node:ordering){
            cout<<node<<endl;
        }
    }


};


int main(){

    Graph<string> g;

    g.addEdge("Python","DataPreprocessing");
    g.addEdge("Python","PyTorch");
    g.addEdge("Python","ML");
    g.addEdge("DataPreprocessing","ML");
    g.addEdge("PyTorch","DL");
    g.addEdge("ML","DL");
    g.addEdge("DL","FaceRecogn");
    g.addEdge("DataSet","FaceRecogn");

 
    g.dfs();


    return 0;
}