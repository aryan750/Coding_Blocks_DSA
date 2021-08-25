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

	node* buildtree(string s){

		if(s == "true"){
			int d;
			cin>>d;
			node*root = new node(d);
			string l;
			cin>>l;
			if(l == "true"){
				root->left = buildtree(l);
			}
			string r;
			cin>>r;
			if(r == "true"){
				root->right = buildtree(r);
			}
			return root;
		}
		return NULL;
	}

	class hbpair{
		public:
			int diff;
			bool bal;
	};

	hbpair is_balanced(node*root){

		hbpair p;

		if(root == NULL){
			p.diff = 0;
			p.bal = true;
			return p;
		}


		hbpair left = is_balanced(root->left);
		hbpair right = is_balanced(root->right);
		p.diff = max(left.diff,right.diff) + 1;
		if(abs(left.diff - right.diff) <= 1 && left.bal && right.bal){
			p.bal = true;
		}
		else{
			p.bal = false;
		}
		return p;
	}


	int main(){

		node*root = buildtree("true");
		if(is_balanced(root).bal){
			cout<<"true";
		}
		else{
			cout<<"false";
		}
		cout<<endl;



		return 0;
	}