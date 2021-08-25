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


node* build(string s){

	if(s == "true"){
		int d;
		cin>>d;
		node*root = new node(d);
		string l;
		cin>>l;
		if(l == "true"){
			root->left = build(l);
		}
		string k;
		cin>>k;
		if(k == "true"){
			root->right = build(k);
		}
		return root;
	}
	return NULL;
}

int height(node*root){

	if(root == NULL){
		return 0;
	}

	int ls = height(root->left);
	int rs = height(root->right);

	return max(ls,rs)+1;
}

void printAtlevelK(node*root,int k){

	if(root == NULL){
		return ;
	}

	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	printAtlevelK(root->left,k-1);
	printAtlevelK(root->right,k-1);
}

void printAtlevelK1(node*root,int k){

	if(root == NULL){
		return ;
	}

	if(k == 0){
		cout<<root->data<<" ";
		return;
	}
	printAtlevelK(root->right,k-1);
	printAtlevelK(root->left,k-1);
}

void zigag(node*root){
	int h= height(root);
	for(int i=0;i<h;i++){
		if(i%2 == 0){
			printAtlevelK(root,i);
		}
		else{
			printAtlevelK1(root,i);
		}
	}
}


int main(){

	node*root = build("true");
	zigag(root);
	cout<<endl;
	return 0;
}