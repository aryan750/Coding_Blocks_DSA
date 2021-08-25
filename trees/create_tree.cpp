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

// int search(int *in , int s, int e, int v){

// 	for(int i =s;i<=e;i++){
// 		if(in[i]  == v){
// 			return i;
// 		}
// 	}
// 	return 0;
// }


node*create(int *in, int *pre, int s, int e){

	static int i = 0;
	if(s > e){
		return NULL;
	}

	node *root = new node(pre[i]);
	int index = -1;
	for(int j =s;j<=e;j++){
		if(in[j]  == pre[i]){
			index = j;
			break;
		}
	}
	++i;

	root->left = create(in ,pre, s,index-1);
	root->right = create(in, pre, index+1,e);
	return root;
}

void inorder(node*root){

	if(root == NULL){
		return;
	}

	if(root->left == NULL){
		cout<<"END => ";
	}
	else
		cout<<root->left->data<<" => ";

	cout<<root->data;
	if(root->right == NULL){
		cout<<" <= END"<<endl;
	}
	else{
		cout<<" <= "<<root->right->data<<endl;
	}
	inorder(root->left);
	inorder(root->right);
}


int main(){

	int n;
	cin>>n;
	int pre[n];

	for(int i =0;i<n;i++){
		cin>>pre[i];
	}

	int m;
	cin>>m;
	int in[m];

	for(int i =0;i<m;i++){
		cin>>in[i];
	}

	node*root = create(in, pre,0,n-1);
	
	inorder(root);

	return 0;
}