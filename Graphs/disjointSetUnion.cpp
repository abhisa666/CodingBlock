#include<iostream>
#include<vector>
using namespace std;

class dsu{
    vector<int> parent,sz;
    int total_component;
public:

    void init(int v){
        parent.resize(v);
        sz.resize(v);
        for(int i=0;i<v;i++) parent[i] = i;
        for(int i=0;i<v;i++) sz[i] = 1;
        total_component=v;
    }

    int get_superparent(int x){
        if(x==parent[x]) return x;
        else return parent[x] = get_superparent(parent[x]); //path compression
    }

    void unite(int x,int y){
        int superparent_x = get_superparent(x);
        int superparent_y = get_superparent(y);
        if(superparent_x!=superparent_y){
            parent[superparent_x] = superparent_y;
            sz[superparent_y] += sz[superparent_x];
            sz[superparent_x] = 0;
            total_component--;
        }
    }

};