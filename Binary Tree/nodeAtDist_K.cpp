#include<iostream>
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

//Given a target node and value K
// List all nodes which are at dist K from the Target node

//All the nodes at dist K from the Target node will be at 2 kinds of positions
//1. Subtree rooted at the target
//2. Subtree of any ancester of the target

//1. Recursivly go K steps down in the left and right sub tree

//2. For any node - if target is L-1 dist away in the Left sub tree
//   the node at K-L-1 dist away from the node in the right sub tree is answer

//2. For any node - if target is R-1 dist away in the Right sub tree
//   the node at K-R-1 dist away from the node in the left sub tree is answer

int nodeatDistK(node* root,node* target,int k){
    if(root==NULL){
        return -1;
    }
    else if(root==target){  
        perculateDown(root,k);
        return 1;
    }
    else{
        int l = nodeatDistK(root->left,target,k);
        int r = nodeatDistK(root->right,target,k);

        if(l!=1){
            if(l==k){
                
            }
        }
    }
}


int main()
{
    
    return 0;
}