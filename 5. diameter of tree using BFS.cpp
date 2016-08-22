#include <bits/stdc++.h>
using namespace std;

const int MAX=100001;
int color[MAX];
int cost[MAX];
int parent[MAX];
typedef pair <int,int> p;
int n;

int BFS(int r,vector<p> adj[]){
	
	for(int i=1;i<=n;i++){
		color[i]=0;
		cost[i]=0;
		parent[i]=-1;
	}
	
	queue <p> q;
	color[r]=1;
	cost[r]=0;
	parent[r]=0;
	q.push(make_pair(0,r));
	
	while(!q.empty()){
		int u=q.front().second;
		q.pop();
		//cout<<u<< " ";
		for(int i=0;i<adj[u].size();i++){
			p y=adj[u][i];
			if(color[y.second]==0){
				color[y.second]=1;
				cost[y.second]=cost[u]+y.first;
				parent[y.second]=u;
				q.push(y);
			}
		}
		color[u]=2;
	}
	return 0;
}

int main(){
	int t;
	cin>>t;
	while(t--){
	    int a,b,x,w,e;
	    cin>>n;
	    vector <p> adj[n+1];
	    e=n-1;
	    for(int i=1;i<=e;i++){
	    	cin>>a>>b>>w;
	    	adj[a].push_back(make_pair(w,b));
	    	adj[b].push_back(make_pair(w,a));
	    }
	    long long ans=-1,c;
	    BFS(1,adj);
	    for(int i=1;i<=n;i++)
	    	if(cost[i]>ans){
	    		ans=cost[i];
	    	 	c=i;
	    	}
	    BFS(c,adj);
	    for(int i=1;i<=n;i++)
	    	if(cost[i]>ans)
	    		ans=cost[i];
	    cout<<ans<<endl;
	}
    return 0;
}
