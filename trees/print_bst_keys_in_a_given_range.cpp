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

node*buildBST(node*root, int d){

	if(root == NULL){
		node*n = new node(d);
		return n;
	}

	if(d > root->data){
		root->right = buildBST(root->right,d);
	}
	else if(d < root->data){
		root->left = buildBST(root->left ,d );
	}
	return root;	
}


void preorder(node*root){

	if(root == NULL){
		return;
	}

	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}

void print_within_range(node*root,int a,int b){

	if(root == NULL){
		return ;
	}
	print_within_range(root->left,a,b);
	if(root->data >= a && root->data <= b){
		cout<<root->data<<" ";
	}
	print_within_range(root->right,a,b);
	return ;
}


int main(){

	int t;
	cin>>t;

	while(t>0){

		int n;
		cin>>n;
		int arr[n];

		for(int i=0;i<n;i++){
			cin>>arr[i];
		}

		
		int a,b;
		cin>>a>>b;

		node*root = new node(arr[0]);

		for(int i=0;i<n;i++){
			root = buildBST(root,arr[i]);
		}


		cout<<"# Preorder : ";
		preorder(root);
		cout<<endl;
		cout<<"# Nodes within range are : ";
		print_within_range(root,a,b);
		cout<<endl;
		t--;
	}
	return 0;
}