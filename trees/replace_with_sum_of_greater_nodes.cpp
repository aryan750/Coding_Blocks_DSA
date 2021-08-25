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

node*insertAtBST(int *arr, int s, int e){

	if(s>e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);
	root->left = insertAtBST(arr,s,mid-1);
	root->right = insertAtBST(arr,mid+1,e);
	return root;
}

void replace_sum(node*root, int *sum){

	if(root == NULL){
		return ;
	}

	replace_sum(root->right,sum);
	*sum = *sum + root->data;
	root->data = *sum;
	replace_sum(root->left,sum);
}

void preorder(node*root){
	if(root ==NULL){
		return ;
	}
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
}


int main(){

	int n;
	cin>>n;
	int arr[n];

	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	node*root = insertAtBST(arr,0,n-1);

	int sum = 0;
	replace_sum(root,&sum);
	preorder(root);
	cout<<endl;
	return 0;
}