#include <bits/stdc++.h>
using namespace std;

int c[100005];
int visit[100005];

int dfs(vector<int> adj[], int x, int col){
	int z=1;
	if(c[x]!=col)
		return 0;
	visit[x]=1;
	for(int i=0;i<adj[x].size();i++)
		if(!visit[adj[x][i]])
			z=dfs(adj, adj[x][i], col);
	return z;
}

int main(){
	int n,x,y;
	cin>>n;
	vector <int> adj[n+1];
	memset (c,0,sizeof(c));
	for(int i=0;i<n-1;i++){
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for(int i=0;i<n;i++)
		cin>>c[i+1];
	for(int i=1;i<=n;i++){
		memset (visit,0,sizeof(visit));
		visit[i]=1;
		x=1;
		for(int j=0;j<adj[i].size() && x==1;j++)
			x=dfs(adj, adj[i][j], c[adj[i][j]]);
		if(x==1){
			cout<<"YES"<<endl;
			cout<<i<<endl;
			return 1;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}

