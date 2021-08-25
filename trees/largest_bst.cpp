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


int search(int *arr, int s ,int e, int v){
	for(int i =s;i<=e;i++){
		if(arr[i] == v){
			return i;
		}	
	}
	return 0;
}

node* build_tree(int *in , int *pre, int s , int e){

	static int i = 0;
	if(s>e){
		return NULL;
	}
	
	node*root = new node(pre[i++]);

	if(s == e){
		return root;
	}

	int index = search(in ,s,e,root->data);

	root->left = build_tree(in,pre,s,index-1);
	root->right = build_tree(in,pre,index+1,e);
	return root;
}

int size(node*root){
	if(root == NULL){
		return 0;
	}
	return 1+ size(root->left)+size(root->right);
}


bool isBST(node*root, int min, int max){

	if(root == NULL){
		return true;
	}

	if(root->data < min || root->data > max){
		return false;
	}

	return isBST(root->left , min ,root->data) && isBST(root->right , root->data , max);
}

int findlarge_bst(node*root){
	if(isBST(root,INT_MIN,INT_MAX)){
		return size(root);
	}
	return max(findlarge_bst(root->left),findlarge_bst(root->right));
}

int main(){


	int n;
	cin>>n;

	int in[n];
	int pre[n];

	for(int k = 0;k<n;k++){
		cin>>pre[k];
	}

	for(int k = 0;k<n;k++){
		cin>>in[k];
	}

	node*root =	build_tree(in,pre,0,n-1);

	int ans = findlarge_bst(root);
	cout<<ans<<endl;

	return 0;
}