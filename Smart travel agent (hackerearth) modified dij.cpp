#include <bits/stdc++.h>
using namespace std;

int parent[1000009];
int visit[1000009];
int dist[1000009];
typedef pair <int,int> p;

int dij(int x, vector<p> adj[]){
	priority_queue<p> q;
	parent[x]=x;
	dist[x]=1000009;
	q.push(make_pair(dist[x],x));
	
	while(!q.empty()){
		p top=q.top();
		q.pop();
		
		if(visit[top.second]==1)
			continue;
		
		int u=top.second;
		visit[u]=1;
		
		for(int i=0;i<adj[u].size();i++){
			int node=adj[u][i].second;
			int wt=adj[u][i].first;
			int w=min(wt,dist[u]);
			
			if(w>dist[node]){
				q.push(make_pair(w,node));
				dist[node]=w;
				parent[node]=u;
			}
		}
	}
	return 0;
}

int main(){
	int n,m,x,y,w,s,d,pass;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		dist[i]=0;
		parent[i]=-1;
		visit[i]=0;
	}
	vector<p> adj[n+1];
	while(m--){
		cin>>x>>y>>w;
		adj[x].push_back(make_pair(w,y));
		adj[y].push_back(make_pair(w,x));
	}
	
	cin>>s>>d>>pass;
	dij(s,adj);
	
	vector<int> v;
	v.push_back(d);
	int t=d;
	while(d!=s){
		d=parent[d];
		v.push_back(d);
	}
	for(int i=v.size()-1;i>=0;i--)
		cout<<v[i]<<" ";
	cout<<endl;
	
	int ans=(pass/(dist[t]-1));
	if(pass%(dist[t]-1)!=0)
		ans+=1;
	cout<<ans<<endl;	
	
}