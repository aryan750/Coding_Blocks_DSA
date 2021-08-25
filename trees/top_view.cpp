#include<bits/stdc++.h>
using namespace std;

class node{
public:
	int data;
	int hd;
	node*left;
	node*right;

	node(int d){
		data = d;
		hd = INT_MAX;
		left = NULL;
		right = NULL;
	}
};


node* buildtree(){
	int d;
	cin>>d;
	queue<node*> q;
	node*root = new node(d);
	q.push(root);
	int l;
	int r;
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


void topview(node*root){

	if(root == NULL){
		return ;
	}

	int hd = 0;
	queue<node*> q;
	map<int, int> m;  

	root->hd = hd;
	q.push(root);


	while(!q.empty()){

		hd = root->hd;

		if(m.count(hd) == 0){
			m[hd] = root->data;
		}


		if(root->left != NULL){
			root->left->hd = hd-1;
			q.push(root->left);
		}

		if(root->right != NULL){
			root->right->hd = hd+1;
			q.push(root->right);
		}
		q.pop();
		root = q.front();
	}
	for(auto i = m.begin();i != m.end();i++){
		cout<<i->second<<" ";
	}
}



int main(){

	node*root = buildtree();

	topview(root);


	cout<<endl;


	return 0;
}
