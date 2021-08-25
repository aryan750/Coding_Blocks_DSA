#include<bits/stdc++.h>
using namespace std;

class Node{
public:
	char data;
	map<char, Node*> children;

	bool terminal;

	Node(char d){
		data =d;
		terminal = false;
	}
};

class trie{

public:
	Node*root;

	trie(){
		root = new Node('\0');
	}

	void insert(string w){
		Node *temp = root;

		for(int i = 0 ;w[i] != '\0';i++){
			char ch = w[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
			}
			else{
				Node *n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		
		temp->terminal = true;
	}

	bool find(string w){
		Node*temp = root;
		for(int i = 0 ; w[i] != '\0';i++){
			char ch = w[i];
			if(temp->children.count(ch)==0){
				return false;
			}
			else{
				temp = temp->children[ch];
			}
		}
		vector<string> v;
		print(w,v,temp);
		sort(v.begin(),v.end());
		for(int i= 0 ;i < v.size();i++){
			cout<<v[i]<<endl;
		}
		return true;
	}

	void print(string s, vector<string> &v, Node*temp){

		if(temp->terminal){
			v.push_back(s);
		}
		for(auto i = temp->children.begin();i != temp->children.end();i++){
			s += i->second->data;
			print(s,v,i->second);
			s.pop_back();
		}
	}

};




int main(){

	trie t;
	int n;
	cin>>n;
	string s;
	while(n > 0){
		cin>>s;
		t.insert(s);
		n--;
	}

	int q;
	cin>>q;
	
	for(int i =0 ;i<q;i++){
		cin>>s;
		bool temp = t.find(s);

		if(!temp){
			cout<<"No suggestions"<<endl;
			t.insert(s);
		}
	}
	return 0 ;
}