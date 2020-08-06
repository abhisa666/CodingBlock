#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

string extraxtStringAtKey(string str,int key)
{
    char *s = strtok( (char*)str.c_str() , " "); //strtok takes in a char array, but we have string so we have to convert it to a char array extarcting the underline char array of the string
    while(key>1)
    {
        s = strtok(NULL," ");
        key--;
    }

    return (string)s;
}

int convertIntoInt(string s)
{
    int ans=0;
    int p=1;

    for(int i=s.length()-1;i>=0;i--)
    {
        ans+=( (s[i]-'0') * p );
        p=p*10;
    }

    return ans;
}

bool numCompare(pair<string,string> s1, pair<string,string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return convertIntoInt(key1) < convertIntoInt(key2) ;
    
}

bool lexiCompare(pair<string,string> s1, pair<string,string> s2)
{
    string key1 = s1.second;
    string key2 = s2.second;

    return key1 < key2 ;
    
}


int main()
{
    int n;
    cin>>n;
    cin.get();

    string a[100];
    for(int i=0;i<n;i++)
    {
        getline(cin,a[i]);
    }

    int key;
    cin>>key;

    string reversal,ordering;
    cin>>reversal;
    cin>>ordering;

    //Create a array of pairs(string,string)
    pair<string,string> strpair[100];  //{ (string,string) , (string,string) .....}

    // Fill the pair array with first as the original string and second as the key string to compare
    for(int i=0;i<n;i++)
    {
        strpair[i].first = a[i];
        strpair[i].second = extraxtStringAtKey(a[i],key);
    }

    //sorting

    if(ordering=="numeric")
    {
        sort(strpair,strpair+n,numCompare);
    }
    else
    {
        sort(strpair,strpair+n,lexiCompare);
    }

    //Reversal
    if(reversal=="true")
    {
        for(int i=0;i<n/2;i++)
        {
            swap(strpair[i] , strpair[n-i-1]);
        }
    }

    //output
    for(int i=0;i<n;i++)
    {
        cout<<strpair[i].first<<endl;
    }
    






    return 0;
}