#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	node*left;
	node*right;

	//constuctor
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

node*formBST(int arr[], int s , int e){

	if(s > e){
		return NULL;
	}

	int mid = (s+e)/2;
	node*root = new node(arr[mid]);

	root->left = formBST(arr,s,mid-1);
	root->right = formBST(arr,mid+1,e);
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



int main(){

	int t;
	cin>>t;

	while(t>0){
		int n;
		cin>>n;
		int arr[n];

		for(int i =0;i<n;i++){
			cin>>arr[i];
		}

		node*root = formBST(arr,0,n-1);
		preorder(root);
		cout<<endl;



		t--;
	}






	return 0;
}