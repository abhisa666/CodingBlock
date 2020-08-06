#include<iostream>
#include<queue>
using namespace std;

class node{
public:
	int data;
	node* left;
	node* right;

	node(int d){
		data=d;
		left=NULL;
		right=NULL;
	}
};

//BFS - Level order with O(n) with help of queue
void bfs(node* root){
	queue<node*> q; // elements of the queue holds the address of the nodes
	
	q.push(root);
	q.push(NULL);

	while(!q.empty()){

		//pick the node at the front
		node* n = q.front();
		if(n==NULL){
			cout<<endl;
			q.pop();
			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{

			//Print the data of the front node element
			cout<<n->data<<" ";

			//Push its children into the queue if exist
			if(n->left)
				q.push(n->left);

			if(n->right)	
				q.push(n->right);
			//pop out the first element as it has been printed and its work is done
			q.pop();

		}
		
	}
}

node* createTreefromTraversals(int* in,int* pre,int s,int e){
    static int i = 0; //we dont want to backtrack it to i=0 for recursion calls
    if(s>e){
        return NULL;
    }

    node* root = new node(pre[i]);
    //find the index of data element in the IN_orer array
    int index=-1;
    for(int j=s;j<=e;j++){
        if(in[j]==pre[i]){
            index = j;
            break;
        }
    }

    i++;
    //Recursivly build left and right sub trees- left of the index is the left subtree of the root
    //and right of the index in the IN order aray is the right subtree of the root
    root->left = createTreefromTraversals(in,pre,s,index-1);
    root->right = createTreefromTraversals(in,pre,index+1,e);

    return root;
}

int main()
{
    int in[]={3,2,8,4,1,6,7,5};
    int n = sizeof(in)/sizeof(int);
    int pre[]={1,2,3,4,8,5,6,7};

    node* root = createTreefromTraversals(in,pre,0,n-1);
    bfs(root);
    
    return 0;
}