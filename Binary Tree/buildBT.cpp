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

//Print Binary Tree Preorder
void printBTpre(node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	printBTpre(root->left);
	printBTpre(root->right);
}

//Print Binary Tree Inorder
void printBTin(node* root){
	if(root==NULL){
		return;
	}
	printBTin(root->left);
	cout<<root->data<<" ";
	printBTin(root->right);
}

//Print Binary Tree Postorder
void printBTpost(node* root){
	if(root==NULL){
		return;
	}
	printBTpost(root->left);
	printBTpost(root->right);
	cout<<root->data<<" ";
}

//Height of Binary Tree - O(n)
int height(node* root){
	if(root==NULL){
		return 0;
	}

	int h_ls = height(root->left);  //height of left sub tree
	int h_rs = height(root->right); // height of right sub tree
	return max(h_ls,h_rs) + 1;
}

// Print Kth level
void printKthlevel(node* root,int k){
	if(root==NULL){
		return;
	}
	if(k==1){
		cout<<root->data<<" ";
		return;
	}
	printKthlevel(root->left,k-1);
	printKthlevel(root->right,k-1);

}

//Print binary tree Level order - Print all Level - O(n^2)
void printAllLevel(node* root){
	int h = height(root);

	for(int i=1;i<=h;i++){
		printKthlevel(root,i);
		cout<<endl;
	}
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

//Count number of nodes
int count(node* root){
	if(root==NULL){
		return 0;
	}

	return 1 + count(root->left) + count(root->right);
}

//Sum of all nodes
int sum(node* root){
	if(root==NULL){
		return 0;
	}

	return root->data + sum(root->left) + sum(root->right);
}

//Diameter of a Binary tree - O(n^2)
int diameter(node* root){
	if(root==NULL){
		return 0;
	}

	int d1 = height(root->left) + height(root->right); //dia pass through root
	int d2 = diameter(root->left); //dia lies in left sub tree
	int d3 = diameter(root->right); //dia lies in the right sub tree

	return max(d1,max(d2,d3));
}

//Diameter of Tree - FASTER WAY - O(n)
// use Bottom up approach  - post order treversal
// keep record of height and dia of each node from bottom to top
class Pair{
public:
	int height;
	int diameter;	
};

Pair diameterFast(node* root){
	Pair p;
	if(root==NULL){
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = diameterFast(root->left);
	Pair right = diameterFast(root->right);

	p.height = max(left.height,right.height) + 1; 
	p.diameter = max(left.height+right.height,max(left.diameter,right.diameter));

	return p;
}

//Replace data of nodes with the sum of its children
int replaceSum(node* root){
	if(root==NULL){
		return 0;
	}

	if(root->left == NULL && root->right == NULL){
		return root->data;
	}

	int leftsum = replaceSum(root->left);
	int rightsum = replaceSum(root->right);

	int temp = root->data;
	root->data = leftsum + rightsum;

	return temp+root->data; // return to the parent
}


//8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main(){
	node* root = buildBT();

	cout<<"Pre Order"<<endl;
	printBTpre(root);

	cout<<endl<<"In Order"<<endl;
	printBTin(root);

	cout<<endl<<"Post Order"<<endl;
	printBTpost(root);

	cout<<endl<<"Height"<<endl;
	cout<<height(root);

	cout<<endl<<"Kth Level"<<endl;
	printKthlevel(root,2);

	cout<<endl<<"Level Order"<<endl;
	printAllLevel(root);

	cout<<endl<<"Level (BFS) Order"<<endl;
	bfs(root);

	cout<<endl<<"Number of Node"<<endl;
	cout<<count(root);

	cout<<endl<<"Sum of all Nodes"<<endl;
	cout<<sum(root);

	cout<<endl<<"Diameter of the Binary Tree"<<endl;
	cout<<diameter(root);

	cout<<endl<<"Diameter FAST of the Binary Tree"<<endl;
	Pair p = diameterFast(root);
	cout<<p.diameter;

	cout<<endl<<"Binary Tree after replacing nodes with the sum of their child nodes"<<endl;
	replaceSum(root);
	bfs(root);


	return 0;
}