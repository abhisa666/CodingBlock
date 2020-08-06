#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char* str,char delim)
{
    static char *input = NULL;

    // first time funtion call
    if(str!=NULL) 
    {
        input = str;
    }

    //Base case -  when the last token is reach and input become NULL
    if(input==NULL)
    {
        return NULL;
    }

    //start extracting token and store in a array
    char *output = new char[strlen(input) + 1]; // made a dynamic array so it wont delete after function terminate

    int i=0;
    for(;input[i]!='\0';i++)
    {

        if(input[i] != delim)
        {
            output[i] = input[i];
        }
        else
        {
            output[i] = '\0';
            input = input + i + 1;
            return output;
        }   


    }

    //corner case--- at the end of the string
    output[i] = '\0';
    input =NULL;
    return output; 


}

int main()
{
    char s[100] = "Today is a rainy day";

    char* ptr = mystrtok(s,' ');
    cout<<ptr<<endl;

    while(ptr!=NULL)
    {
        ptr = mystrtok(NULL,' ');
        cout<< ptr<<endl;
    }

    return 0;
}