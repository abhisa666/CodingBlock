#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include<set>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */  
    stack<int> s; 
    set<int> set1;
    int n;
    cin>>n;
    while(n!=0){
        int query_sel;
        cin>>query_sel;
        if(query_sel==1){
            int data;
            cin>>data;
            s.push(data);
            set1.insert(data);
        }
        if(query_sel==2){
            int x=s.top();
            set1.erase(x);
            s.pop();
        }
        if(query_sel==3){
            auto it = set1.rbegin();
            for (auto itr = set1.begin(); itr != set1.end(); ++itr) 
            { 
                cout << '\t' << *itr; 
            } 
            cout<<endl;
            cout<<*it<<" at end"<<endl;
        }

        n--;
    }

    for (auto itr = set1.begin(); itr != set1.end(); ++itr) 
    { 
        cout << '\t' << *itr; 
    } 
    return 0;
}
// 10
// 1 97
// 2
// 1 20
// 2
// 1 26
// 1 20
// 2
// 3
// 1 91
// 3