#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int a[] = {1,2,3,4,5};
    int n = sizeof(a)/sizeof(int);

    //Search --> Find(arr,arr+,key)
    int key;
    cin>>key;

    auto it = find(a,a+n,key); // it will return the address of the key element
    int index = it - a; // to get the index we can just sub the address by base address 

    if(index==n)
    {
        cout<<"Key is not found"<<endl;
    }
    else
    {
        cout<<"Key is found  "<<a[index]<<endl;
    }

    // Search in an sorted array Binary Search is better as it has nlogn complexcity
    int sarr[] = {2,4,6,8,8,8,9,10};
    int sn = sizeof(sarr)/sizeof(int);

    bool present = binary_search(sarr,sarr+sn,key); //returns true or false

    if(present)
    {
        cout<<"Key is present in Sorted Array"<<endl;
    }
    else
    {
        cout<<"Key is not present in Sorted Array"<<endl;
    }
    

    //Two more things
    // To get the index 
    // we have two func -> lower_bound(a,a+n,key) and upper_bound(a,a+n,key)
    // they work in logn time

    auto itl = lower_bound(sarr,sarr+sn,8); // returns the address of the first occurnace of a value >= KEY
    cout<<"Lower bound index of key '8' "<<(itl-sarr)<<endl; // index

    auto itu = upper_bound(sarr,sarr+sn,8); // returns the address of the first occurnace of a value > KEY
    cout<<"Upper bound index of key '8' "<<(itu-sarr)<<endl; //index

    //Frequncy of any elemet in an sorted array can be find out by ( UB-LB )
    int UB = itu-sarr;
    int LB = itl-sarr;

    cout<<"Frequncy of key '8 ' is "<<UB-LB<<endl;


    // Rotate a conatiner --> rotate(start index , rotate about , end index)
    int arr[] = {1,2,3,4,5};
    int narr = sizeof(arr)/sizeof(int);

    rotate(arr,arr+3,arr+n);

    for(int i=0;i<narr;i++)
    {
        cout<<arr[i]<<" ";
    }

    cout<<endl;
    //Next Permutaion --> next_permutation(arr,arr+n) It will dive the next lexiographic bigger number
    vector<int> v{1,2,3};

    next_permutation(v.begin(),v.end());

    for(int x:v)
    {
        cout<<x<<" ";
    }
    cout<<endl;
    //Pair
    pair<int,string> p = make_pair(100,"Audi");
    cout<<p.first<<" "<<p.second;
    
    return 0;
}