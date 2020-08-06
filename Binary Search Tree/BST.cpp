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

node* insertInBST(node* root,int data){
    if(root==NULL){
        return new node(data);
    }

    if(data<=root->data){
        root->left = insertInBST(root->left,data);
    }
    else{
        root->right = insertInBST(root->right,data);
    }

    return root;
}

node* buildBST(){
    int d;
    cin>>d;
    node* root = NULL;
    while(d!=-1){
        root = insertInBST(root,d);
        cin>>d;
    }

    return root;
}

//BFS - Level order print with O(n) with help of queue
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

void inorder(node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<",";
    inorder(root->right);
}

int main()
{
    node* root = buildBST();
    bfs(root);
    cout<<endl;
    inorder(root);
    return 0;
}