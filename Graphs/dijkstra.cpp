#include<iostream>
#include<map> //Hash map
#include<list>
#include<climits>
#include<set>
#include<cstring>

using namespace std;

template<typename T>

class Graph{

map<T,list<pair<T,int>>> m;

public:

    void addEdge(T x,T y,int dis,bool bi=true){
        m[x].push_back(make_pair(y,dis));
        if(bi) m[y].push_back(make_pair(x,dis));
    }

    void printAdjList(){
        //Iterate over the pair(key,value) of map
        for(auto p:m){
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

    void dijsktraSSSP(T src){
        map<T,int> dist; //map to store key-city and there val-dist from src
        
        //set all dist to infinity
        for(auto p:m){
            dist[p.first]=INT_MAX;
        }

        //Make a set to find out the node with the minimun distance 
        set<pair<int,T>> s; // pair of (dis,city) sorted array
        //sorting of set is based on the first of the pair

        dist[src]=0;
        s.insert(make_pair(0,src)); //put the pair of dis,city of the src

        // while set is not empty
        while(!s.empty()){
            
            //get the pair at the front of the set
            //since the set is sorted we get the pair with minimum dis from src
            //That is we want - the city with the minimum distance
            auto set_p = *(s.begin()); //begin() returns a address of the first element of the set
            T node = set_p.second; //get the node from the pair as eg.- (8,delhi)
            int nodeDist = set_p.first; //get the distance

            //once we get the node and dist we can erase the pair
            s.erase(s.begin()); //pop out the first element of the set

            //Iterate over the nbrs/children of the current node
            for(auto nbrPair:m[node]){
              //  parentDist  + edge        <  child/nbr Dist 
                if(nodeDist + nbrPair.second < dist[nbrPair.first]){
                    // we have to update the dist
                    // updation of a element in set is not possible
                    // we have to remove the old pair and add the new pair
                    T dest = nbrPair.first;
                    auto f = s.find(make_pair(dist[dest],dest));
                    if(f!=s.end()){//it means we find the node
                        s.erase(f);
                    } 
                    //insert the new pair
                    dist[dest] = nodeDist + nbrPair.second;
                    s.insert(make_pair(dist[dest],dest));
                }
            }    


        }

        //print the distance to every node
        for(auto i : dist){
            cout<<"Distace of "<<i.first<<" from "<<src<<" is "<<i.second<<endl;
        }

    }


};


int main(){

    Graph<string> india;

    india.addEdge("Amritsar","Delhi",1);
    india.addEdge("Amritsar","Jaipur",4);
    india.addEdge("Jaipur","Delhi",2);
    india.addEdge("Jaipur","Mumbai",8);
    india.addEdge("Bhopal","Agra",2);
    india.addEdge("Mumbai","Bhopal",3);
    india.addEdge("Agra","Delhi",1);

    india.printAdjList();
    cout<<endl;
    india.dijsktraSSSP("Amritsar");

    return 0;
}