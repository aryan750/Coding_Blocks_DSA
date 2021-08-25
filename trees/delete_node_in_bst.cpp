#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node*insertAtBst(node*root,int d){

	if(root == NULL){
		node* nn = new node(d);
		return nn;
	}

	if(d > root->data){
		root->right = insertAtBst(root->right , d);
	}

	else if(d < root->data){
		root->left = insertAtBst(root->left ,d);
	}
	return root;
}

node*build_bst(int *arr,node*root, int n){

	for(int i=0;i<n;i++){
		root = insertAtBst(root,arr[i]);
	}

	return root;
}


node*delete_in_nst(node*root, int data){

	if(root == NULL){
		return NULL;
	}


	if(data > root->data){
		root->right  = delete_in_nst(root->right , data);
		return root;
	}
	else if(data < root->data)
	{
		root->left = delete_in_nst(root->left, data);
		return root;
	}

	else{

		//1. no child nodes
		if(root->left == NULL && root->right == NULL){
			delete root;
			return NULL;
		}

		//2. 1 child nodes 
		if(root->left != NULL && root->right == NULL){
			node*temp = root->left;
			delete root;
			return temp;
		}

		if(root->left == NULL && root->right != NULL){
			node*temp = root->right;
			delete root;
			return temp;
		}

		//3.2 child nodes
		node*replace = root->right;
		while(replace ->left != NULL){
			replace = replace->left;
		}

		root->data = replace->data;
		root->right = delete_in_nst(root->right , replace->data);
		return root;
	}
}

void preorder(node*root){
	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int main()
{
	int t;
	cin>>t;

	while(t>0){
		
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++){
			cin>>a[i];
		}
		node* root = new node(a[0]);
		root = build_bst(a,root,n);

		int k;
		cin>>k;

		int b[k];
		for(int i=0;i<k;i++){
			cin>>b[i];
		}

		for(int i = 0;i<k;i++){
			root = delete_in_nst(root,b[i]);
		}
		preorder(root);	
		cout<<endl;
		t--;
	}




	return 0;
}