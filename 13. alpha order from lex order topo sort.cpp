#include <bits/stdc++.h>
using namespace std;

int visit[35];
int instack[35];
string s[105];
vector <int> adj[26];
vector <int> ans;
int flag;

int dfs(int x){
	visit[x]=1;
	instack[x]=1;
	for(int i=0;i<adj[x].size();i++){
		if(instack[adj[x][i]]){
			flag=1;
			return 0;
		}

		if(!visit[adj[x][i]])
			dfs(adj[x][i]);
	}
	instack[x]=0;
	ans.push_back(x);
	return 0;
}

int topo_sort(){
	for(int i=0;i<26;i++)
		if(!visit[i])
			dfs(i);
	return 0;
}

int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>s[i];
	for(int i=1;i<n;i++){
		for(int j=0; s[i][j] && s[i-1][j]; j++){
			if(s[i-1][j]==s[i][j]){
				if(j==(s[i].size()-1)){
					if(s[i-1].size() > s[i].size()){
						cout<<"Impossible"<<endl;
						return 0;
					}
				}
				continue;
			}
			else{
				adj[s[i-1][j]-'a'].push_back(s[i][j]-'a');
				break;
			}
		}
	}
	topo_sort();
	if(!flag){
		for(int i=ans.size()-1;i>=0;i--)
			cout<<char(ans[i]+'a');
		cout<<endl;
	}
	else
		cout<<"Impossible"<<endl;
	return 0;
}