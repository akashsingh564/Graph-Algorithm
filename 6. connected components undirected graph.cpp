#include <bits/stdc++.h>
using namespace std;

int visited[10001]={0};

int dfs(int x,vector<int> adj[]){
	cout<<x<< " ";
	visited[x]=1;
	for(int i=0;i<adj[x].size();i++){
		if(visited[adj[x][i]]==0)
			dfs((adj[x][i]),adj);
	}
}


int main(){
    int n,e,x,y;
    cin>>n>>e;
    vector <int> adj[n+1];
    for(int i=0;i<e;i++){
    	cin>>x>>y;
    	adj[x].push_back(y);
    	adj[y].push_back(x);
    }
    
    int i=1;
    while(i<=n){
    	if(visited[i]==0){
    		dfs(i,adj);
    		cout<<endl;
    		i=1;
    	}
    	i++;
    }
    return 0;
}
