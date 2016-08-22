#include <bits/stdc++.h>
using namespace std;

const int MAX=100001;
typedef pair<int,int> p;
long long dist[MAX]={MAX};
int visited [MAX]={0};
int parent[MAX]={-1};
int n;

long long dijkstra(int x, vector<p> adj[]){
	
	for(int i=1;i<=n;i++){
    	visited[i]=0;
    	dist[i]=1000000009;
    	parent[i]=-1;
	}
	
	priority_queue <p ,vector<p> ,greater<p>> q;
	q.push(make_pair(0,x));
	parent[x]=x;
	dist[x]=0;
	
	while(!q.empty()){
		p top=q.top();
		q.pop();
		if(visited[top.second]==1)
			continue;
		
		int u=top.second;
		visited[u]=1;
		dist[u]=top.first;
		//cout<<"picked "<<u<<" wighing "<<top.first<<endl;
		
		for(int i=0;i<adj[u].size();i++){
			int y=adj[u][i].second;
			if(visited[y]==0 && (dist[y]>(adj[u][i].first + dist[u]))){  /**** if already existing in que. is at shorter dis. or from current node is it shorter****/
				parent[y]=u;
				dist[y]=adj[u][i].first+dist[u];
				q.push(make_pair(dist[y],y));
				//cout<<"pushed "<<y<<" weigt "<<dist[y]<<endl;
			}
		}
	}
	return 0;
}

int main(){
	int t,e,x,y,s,d,v;
	long long w;
	cin>>t;
	while(t--){
		cin>>n>>e;
	    vector <p> adj1[n+1];
	    vector <p> adj2[n+1];
	    for(int i=0;i<e;i++){
	    	cin>>x>>y>>w;
	    	adj1[x].push_back(make_pair(w,y));
	    	adj1[y].push_back(make_pair(w,x));
	    	adj2[x].push_back(make_pair(w,y));
	    	adj2[y].push_back(make_pair(w,x));
	    }
	    cin>>s>>v>>d;
	    
	    dijkstra(s,adj1);
	    
	    if(parent[v]==-1){
	    	cout<<"No Train Found."<<endl;
	    	continue;
	    }
	    
	    vector<int> path1;
	    
	    int t=v;
	    while(t!=s){
	    	t=parent[t];
	    	path1.push_back(t);
	    }
	    long long cost=dist[v];
	    
	    dijkstra(v,adj2);
	    
	    if(parent[d]==-1){
	    	cout<<"No Train Found."<<endl;
	    	continue;
	    }
	    
	    vector<int> path;
	    t=d;
	    path.push_back(d);
	    while(t!=v){
	    	t=parent[t];
	    	path.push_back(t);
	    }
	    
	    cost+=dist[d];
    	cout<<cost<<endl;
	    for(int i=path1.size()-1;i>=0;i--)
    		cout<<path1[i]<<" ";
	    for(int i=path.size()-1;i>=0;i--)
    		cout<<path[i]<<" ";
    	cout<<endl;
	}

    return 0;
}
