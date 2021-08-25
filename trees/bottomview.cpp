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


void bottomview(node*root){

	if(root == NULL){
		return ;
	}

	int hd = 0;
	queue<node*> q;
	map<int, int> m;  

	root->hd = hd;
	q.push(root);


	while(!q.empty()){

		node*temp = q.front();
		q.pop();

		hd = temp->hd;

		m[hd] = temp->data;

		if(temp->left != NULL){
			temp->left->hd = hd-1;
			q.push(temp->left);
		}

		if(temp->right != NULL){
			temp->right->hd = hd+1;
			q.push(temp->right);
		}
	}
	for(auto i = m.begin();i != m.end();i++){
		cout<<i->second<<" ";
	}
}



int main(){

	node*root = buildtree();

	bottomview(root);


	cout<<endl;


	return 0;
}
