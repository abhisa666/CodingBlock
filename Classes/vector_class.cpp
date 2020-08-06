#include<iostream>
using namespace std;

class vec{

    public:
   
    int *arr;
    int size;
    int max_size;

    vec()
    {
       size = 0;
       max_size = 4;
       arr = new int[max_size];
    }

    vec(int i)
    {
       size = 0;
       max_size = i;
       arr = new int[max_size];
    }
    void pushback(int x)
    {   
       if(size==max_size)
       {
           max_size= 2*max_size;
           int *newptr = arr;
           arr = new int[max_size];
           for(int i=0;i<size;i++)
           {
               arr[i]=newptr[i];
           }
           delete []newptr;
       }

       arr[size] = x;
       size++;
      
    }

    void pop_back()
    {
        size--;
    }

    int csize()
    {
      return size;
    }

    int capacity()
    {
        return max_size;
    }


};

int main()
{

    vec v;
    for(int i=0;i<10;i++)
    {
        v.pushback(i);
    }
    cout<<v.csize()<<endl;
    cout<<v.capacity()<<endl;
    
    return 0;
}