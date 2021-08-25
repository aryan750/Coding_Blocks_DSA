#include<bits/stdc++.h>
using namespace std;
int sum = 0;


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


node*build_tree(){

	int d,num;
	cin>>d;
	node*root = new node(d);
	cin>>num;
	if(num == 2){
		root->left = build_tree();
		root->right = build_tree();
	}
	else if(num == 1){
		root->left = build_tree();
	}
	return root;
}

void sumAtlevelK(node*root,int k){
	if(root == NULL){
		return;
	}
	if(k == 0){
		sum += root->data;
	}
	if(k <0){
		return ;
	}
	sumAtlevelK(root->left,k-1);
	sumAtlevelK(root->right,k-1);
}

int main(){

	node*root = build_tree();
	int k;
	cin>>k;

	sumAtlevelK(root,k);
	cout<<sum<<endl;


	return 0;
}