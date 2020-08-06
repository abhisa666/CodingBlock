#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v;

    cout<<v.max_size(); // return bytes

    // v.push_back(1);

    // cout<<v.size()<<endl; // shows current no of elements 
    // cout<<v.capacity()<<endl; // double its size when it gets full
    
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(8);
    // v.push_back(9);
    // v.push_back(10);

    // cout<<v.capacity()<<endl;

    // for(int i=0;i<10;i++)
    // {
    //     v.push_back(i);
    // }

    // for(int i=0;i<10;i++)
    // {
    //     cout<<v[i]<<" ";
    // }
    return 0;
}