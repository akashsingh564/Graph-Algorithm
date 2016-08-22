#include <bits/stdc++.h>
#include <map>
using namespace std;

const int INF=999;
int dist[100][100];
int path[100][100];

int floydwarshall(int u){
	
	for(int k=0;k<u;k++)
		for(int i=0;i<u;i++)
			for(int j=0;j<u;j++)
				if(dist[i][j]>dist[i][k]+dist[k][j]){
					dist[i][j]=dist[i][k]+dist[k][j];
					path[i][j]=path[j][k];
				}
				
	return 0;
}


int main(){
	int u,v,w,q;
    string s,s1,s2;
    map <int,string> station;
    cin>>u>>v;
    for(int i=0;i<u;i++){
    	cin>>s;
    	station[i]=s;
    }
    
    for(int i=0;i<u;i++)
    	for(int j=0;j<u;j++){
    		dist[i][j]=INF;
    		path[i][j]=INF;
		if(i==j) dist[i][j]=0;
    	}
    
    for(int i=0;i<v;i++){
    	cin>>s1>>s2>>w;
    	int x,y;
    	for (map<int,string>::iterator it=station.begin();it!=station.end();++it){
			if (it->second==s1)
				x=it->first;
			if (it->second==s2)
				y=it->first;
		}
		dist[x][y]=dist[y][x]=w;
		path[x][y]=x;
		path[y][x]=y;
    }
    
    floydwarshall(u);
	
	/************* if dist[i][i]!=0 then graph has negative edge cycle *************/
    
   /* for(int i=0;i<u;i++){
    	for(int j=0;j<u;j++){
    		cout<<dist[i][j]<<"\t";
    	}
    	cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<u;i++){
    	for(int j=0;j<u;j++){
    		cout<<path[i][j]<<"\t";
    	}
    	cout<<endl;
    }*/
    
    cin>>q;
    while(q--){
    	cin>>s1>>s2;
    	int x,y;
    	for (map<int,string>::iterator it=station.begin();it!=station.end();++it){
			if (it->second==s1)
				x=it->first;
			if (it->second==s2)
				y=it->first;
		}
		cout<<dist[x][y]<<endl;
    }
    return 0;
}
