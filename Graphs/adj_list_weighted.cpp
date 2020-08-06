#include<iostream>
#include<unordered_map> //Hash map
#include<list>
#include<cstring>
using namespace std;

class Graph{
    
    // Hash map of key - String, value - list<pair<String,int>>
    unordered_map< string, list<pair<string,int> > > l; 

    public:

    void addEdge(string x,string y,bool bi,int wt){
        l[x].push_back(make_pair(y,wt));
        if(bi) l[y].push_back(make_pair(x,wt));

    }

    void printAdjList(){
        //Iterate over the pair(key,value) of map
        for(auto p:l){
            string city = p.first;//key
            list<pair<string,int>> nbrs = p.second;
            
            cout<<city<<" -> ";
            for(auto nbr : nbrs){
                string dest=nbr.first;
                int dis=nbr.second;
                cout<<"("<<dest<<","<<dis<<"), ";
            }
            cout<<endl;
        }
    }
};

int main(){

    Graph g;
    g.addEdge("A","B",true,20);
    g.addEdge("B","D",true,40);
    g.addEdge("A","C",true,10);
    g.addEdge("A","D",false,50);
    g.addEdge("C","D",true,30);



    g.printAdjList();

    return 0;
}