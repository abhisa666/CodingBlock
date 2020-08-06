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

//We are using bottom up apporach - post order traversal
//O(n)
// A tree is a HEIGHT BALANCE TREE if for every node |h1-h2|<=1
// so we keep track of height and the balance status for every nodes from bottom to top
class HBpair{
public:
    int height;
    bool balance;
};

HBpair isHeightBalance(node* root){
    HBpair p;
    if(root==NULL){
        p.height = 0;
        p.balance = true;
        return p;
    }

    HBpair left = isHeightBalance(root->left);
    HBpair right = isHeightBalance(root->right);

    p.height = max(left.height,right.height) + 1;

    if(abs(left.height-right.height) <= 1 && left.balance && right.balance){
        p.balance = true;
    }
    else{
        p.balance = false;
    }

    return p;

}





//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main()
{   
    node* root = buildBT();

    if(isHeightBalance(root).balance){
        cout<<"Height balace tree";
    }else{
        cout<<"Not a Height balance tree";
    }
    
    return 0;
}