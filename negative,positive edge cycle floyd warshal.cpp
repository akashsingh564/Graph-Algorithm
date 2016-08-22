#include <bits/stdc++.h>
using namespace std;

int dist[101][101];
#define INF 100005

int floyd_warshall(int u){
	for(int k=1;k<=u;k++)
		for(int i=1;i<=u;i++)
			for(int j=1;j<=u;j++){
				if(dist[i][k]==INF || dist[k][j]==INF) continue;
				if(dist[i][j]>(dist[i][k]+dist[k][j]))
					dist[i][j]=dist[i][k]+dist[k][j];
			}
	return 0;
}

int main(){
    int t,u,v,x,y,w;
    cin>>t;
    while(t--){
    	cin>>u>>v;
    	
    	for(int i=1;i<=u;i++)
    		for(int j=1;j<=u;j++)
    			dist[i][j]=INF;
    			
    	for(int i=0;i<v;i++){
    		cin>>x>>y>>w;
    		w=-w;
    		if(dist[x][y]>w){
				dist[x][y]=w;
			}
    	}
    	
    	floyd_warshall(u);
    	int flag=0;

    	for(int i=1;i<=u;i++){
    		if(dist[i][i]<0 && dist[1][i]!=INF){
    			flag=1;
    			break;
    		}
    	}
    	if(flag==0) cout<<"No"<<endl;
    	else cout<<"Yes"<<endl;
    }
    return 0;
}
