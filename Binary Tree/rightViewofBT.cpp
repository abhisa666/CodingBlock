#include<iostream>
#include<vector>
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

// Build Binary tree and return the root node
node* buildBT(){
	int d;
	cin>>d;
	if(d==-1){  // not a node 
		return NULL;
	}

	node* root = new node(d); //make a new node as root
	root->left = buildBT();
	root->right = buildBT();  //recursivly build sub tress on left and right of the root node

	return root;

}

void helper(node* root,vector<int> &v, int level){
    static int max_level = -1;
    if(root==NULL){
        return;
    }

    if(level>max_level){
        max_level = level;
        v.push_back(root->data);
    }

    helper(root->right,v,level+1);
    helper(root->left,v,level+1);

}

vector<int> rightview(node* root){
    vector<int> v;
    helper(root,v,0);
    return v;
}

//1 2 -1 5 6 -1 -1 -1 3 -1 4 -1 -1
int main()
{   
    node* root = buildBT();
    vector<int> v = rightview(root);

    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    
    
    return 0;
}