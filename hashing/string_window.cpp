#include<bits/stdc++.h>
using namespace std;

string findMinWindow(string s, string p){

	int PL = p.size();
	int SL = s.size();

	if(PL > SL){
		return "No String";
	}

	int SF[256] = {0};
	int PF[256] = {0};

	for(int i =0;i<PL;i++){
		char ch = p[i];
		PF[ch]++;
	}

	int count= 0;
	int start = 0;
	int min_len = INT_MAX;
	int start_idx = -1;

	for(int i =0;i<SL;i++){

		char ch = s[i];
		SF[ch]++;

		if( PF[ch] >= SF[ch] && PF[ch] != 0){
			count++;
		}

		//if all the characters match
		if(count == PL){

			char temp = s[start];

			while(SF[temp] > PF[temp] || PF[temp] == 0 ){
				SF[temp]--;
				start++;
				temp= s[start];
			}

			int window_len = i - start +1;
			if(window_len < min_len){
				min_len = window_len;
				start_idx = start;
			}
		}
	}
	if(start_idx == -1){
		return "No String";
	}
	string ans = s.substr(start_idx,min_len);
	return ans;
}




int main(){

	string s;
	getline(cin,s);

	string p;
	getline(cin,p);

	cout<<findMinWindow(s,p)<<endl;




	return 0;
}