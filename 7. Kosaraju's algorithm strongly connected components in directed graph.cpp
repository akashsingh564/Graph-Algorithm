#include <bits/stdc++.h>
using namespace std;

int visited[10001]={0};
stack <int> s;

int fill_stack(int x,vector<int> adj[]){
	visited[x]=1;
	for(int i=0;i<adj[x].size();i++){
		if(visited[adj[x][i]]==0)
			fill_stack((adj[x][i]),adj);
	}
	s.push(x);
}

int dfs(int x,vector<int> adj[]){
	visited[x]=1;
	cout<<x<<" ";
	for(int i=0;i<adj[x].size();i++)
		if(visited[adj[x][i]]==0)
			dfs((adj[x][i]),adj);
}


int main(){
    int n,e,x,y;
    cin>>n>>e;
    
    for(int i=0;i<=n;i++)
	    visited[i]=0;
    
    vector <int> adj1[n+1];
    vector <int> adj2[n+1];
    for(int i=0;i<e;i++){
    	cin>>x>>y;
    	adj1[x].push_back(y);
    	adj2[y].push_back(x);
    }
    
    for(int i=1;i<=n;i++)
    	if(visited[i]==0)
    		fill_stack(i,adj1);

    for(int i=0;i<=n;i++)
	    visited[i]=0;
	    
	while(!s.empty()){
		int j=s.top();
		s.pop();
		if(visited[j]==0){
			dfs(j,adj2);
			cout<<endl;
		}
	}
    return 0;
}
