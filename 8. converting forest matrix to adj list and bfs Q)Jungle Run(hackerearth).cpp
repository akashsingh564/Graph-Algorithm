#include <bits/stdc++.h>
using namespace std;

int parent[100001];
int dist[100001];
int color[100001];
int n;

int bfs(int x,vector<int> adj[]){
	for(int i=1;i<=n*n;i++){
		parent[i]=-1;
		dist[i]=-1;
		color[i]=0;
	}
	
	queue<int> q;
	
	parent[x]=0;
	dist[x]=0;
	color[x]=1;
	
	q.push(x);
	
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=0;i<adj[u].size();i++){
			int y=adj[u][i];
			if(color[y]==0){
				dist[y]=dist[u]+1;
				parent[y]=u;
				color[y]=1;
				q.push(y);
			}
		}
		color[u]=2;
	}
	return 0;
}



int main(){
    int src,dest;
    cin>>n;
    char a[n+1][n+1];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		cin>>a[i][j];
    		if(a[i][j]=='S'){
    			src=(i*n)+j+1;
    			a[i][j]='P';
    		}
    		if(a[i][j]=='E'){
    			dest=(i*n)+j+1;
    			a[i][j]='P';
    		}
    	}
    }
    for(int i=0;i<n+1;i++){
    	a[n][i]='T';
    	a[i][n]='T';
    }
    vector <int> adj[((n*n)+1)];
    
    /*cout<<"src "<<src<<" dest "<<dest<<endl<<endl;
    for(int i=0;i<n+1;i++){
    	for(int j=0;j<n+1;j++){
    		cout<<a[i][j]<<" "<<(i*n)+j+1<<"\t";
    	}
    	cout<<endl;
    }
    cout<<endl;*/
    
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(a[i][j]=='P' && a[i][j+1]=='P'){
    			adj[((i*n)+j+1)].push_back((i*n)+j+1+1);
    			adj[((i*n)+j+1+1)].push_back((i*n)+j+1);
    		}
    		if(a[i][j]=='P' && a[i+1][j]=='P'){
    			adj[((i*n)+j+1)].push_back(((i+1)*n)+j+1);
    			adj[(((i+1)*n)+j+1)].push_back(((i*n)+j+1));
    		}
    	}
    }
    
    /*for(int i=1;i<=(n*n);i++){
    	cout<<i<<"\t";
    	for(int j=0;j<adj[i].size();j++)
    		cout<<adj[i][j]<<" ";
    	cout<<endl;
    }*/
    
    bfs(src,adj);
    cout<<dist[dest]<<endl;
    return 0;
}
