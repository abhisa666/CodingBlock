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

node* buildBalanceBTfromArray(int* a,int s,int e){
    if(s>e){
        return NULL;
    }

    int mid = (s+e)/2;
    node* root = new node(a[mid]);
    root->left = buildBalanceBTfromArray(a,s,mid-1);
    root->right = buildBalanceBTfromArray(a,mid+1,e);

    return root;

}

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

int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(int);

    node* root = buildBalanceBTfromArray(arr,0,n-1);
    bfs(root);
    
    return 0;
}