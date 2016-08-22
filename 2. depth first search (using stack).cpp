#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll visited[100005];
ll dist[100005];
ll c=-1;

int bfs(ll x,vector<ll> adj[]){
	dist[x]=0;
	queue<ll> q;
	q.push(x);
	while(!q.empty()){
		ll u=q.front();
		q.pop();
		if(visited[u]==1)
			continue;
		visited[u]=1;
		for(ll i=0;i<adj[u].size();i++){
			if(visited[adj[u][i]]==0){
				dist[adj[u][i]]=dist[u]+1;
				q.push(adj[u][i]);
			}
		}
	}
}

int main(){
    ll t,n,q,x,y;
    scanf("%lld",&t);
    while(t--){
    	memset(visited,0,sizeof(visited));
    	memset(dist,-1,sizeof(dist));
    	scanf("%lld",&n);
    	vector<ll> adj[n+1];
    	for(ll i=1;i<=n;i++){
    		scanf("%lld",&x);
    		adj[x].push_back(i);
    	}
    	scanf("%lld",&q);
    	bfs(0,adj);
    	while(q--){
    		scanf("%lld %lld",&x,&y);
    		printf("%lld\n",max(c,dist[x]-dist[y]-1));
    	}
    }
    return 0;
}
