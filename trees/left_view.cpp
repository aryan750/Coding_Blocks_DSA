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


node* buildtree(){

	int d;
	cin>>d;
	int l,r;
	queue<node*> q;
	node*root = new node(d);
	q.push(root);
	while(!q.empty()){

		node*f = q.front();
		q.pop();

		cin>>l>>r;
		if(l != -1){
			f->left = new node(l);	
			q.push(f->left);
		}
		if(r != -1){
			f->right = new node(r);
			q.push(f->right);
		}
	}
	return root;
}

void leftview(node*root, int &max_level, int curr_level){

	if(root == NULL){
		return ;
	}

	if(max_level < curr_level){
		cout<<root->data<<" ";
		max_level = curr_level;
	}

	leftview(root->left,max_level,curr_level+1);
	leftview(root->right,max_level,curr_level+1);
}


int main(){


	node*root = buildtree();
	int max_level = -1;
	leftview(root,max_level,0);
	cout<<endl;



	return 0;
}