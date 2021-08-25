#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	int data;
	Node*left;
	Node*right;

	Node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

Node* build_tree(){

	int d;
	cin>>d;
	int l, r;
	queue<Node*> q;
	Node*root = new Node(d);
	q.push(root);

	while(!q.empty()){

		Node*f = q.front();
		q.pop();
		cin>>l>>r;
		if(l != -1){
			f->left = new Node(l);
			q.push(f->left);
		}
		if(r != -1){
			f->right = new Node(r);
			q.push(f->right);
		}
	}
	return root;
}



void verticalOrder(Node* root, int d, map<int,vector<int>> &m){

	if(root == NULL){
		return ;
	}

	m[d].push_back(root->data);
	verticalOrder(root->left,d-1,m);
	verticalOrder(root->right,d+1,m);
	return ;
}

int main(){

	int k ;
	cin>>k;
	
	Node*root = build_tree();
	map<int, vector<int>> m;


	int d = 0;
	verticalOrder(root,d,m);

	for(auto p : m){
		for(int x : p.second){
			cout<<x<<" ";
		}
		cout<<endl;
	}

	return 0;
}
