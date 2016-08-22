#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ff first
#define ss second
ll visited[100001];
//ll parent[100001][100001];
ll dist[100001][100001];
typedef pair<ll,ll> p;
ll n,src;

ll dij(ll x, vector<p> adj[]){
	for(ll i=1;i<=n;i++){
		dist[src][i]=-1;
		//parent[src][i]=-1;
		visited[i]=0;
	priority_queue<p> q;
	}
	dist[src][x]=10000007;
	//parent[src][x]=0;
	q.push(make_pair(10000007,x));
	
	while(!q.empty()){
		p top=q.top();
		q.pop();
		ll u=top.ss;
		if(visited[u]==1)
			continue;
		visited[u]=1;
		dist[src][u]=top.ff;
		
		for(ll i=0;i<adj[u].size();i++){
			ll node=adj[u][i].ss;
			ll wt=min(dist[src][u],adj[u][i].ff);
			if(visited[node]==0 && wt>=dist[src][node]){
				//parent[src][node]=u;
				dist[src][node]=wt;
				q.push(make_pair(wt,node));
			}
		}
	}
	return 0;
}

int main(){
    ll e,x,y,w,q,dest,pass;
    
    	scanf("%lld %lld",&n,&e);
    	vector<p> adj[n+1];
    	for(int i=0;i<e;i++){
    		scanf("%lld %lld %lld",&x,&y,&w);
    		adj[x].push_back(make_pair(w,y));
    		adj[y].push_back(make_pair(w,x));
    	}
    	cin>>q;
    	while(q--){
    		scanf("%lld %lld %lld",&src,&dest,&pass);
    		if(pass==0 || src==dest){
    			printf("0\n");
    			continue;
    		}
    		dij(src,adj);
    		if(dist[src][dest]==1){
    			printf("-1\n");
    			continue;
    		}
    		ll ans=pass/(dist[src][dest]-1);
    		if(pass%(dist[src][dest]-1)!=0)
    			ans+=1;
    		printf("%lld\n",ans);
    	}
    return 0;
}
