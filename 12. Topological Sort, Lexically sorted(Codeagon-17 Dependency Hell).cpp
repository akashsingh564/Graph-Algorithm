#include <bits/stdc++.h>
using namespace std;

int n;
int visit [100005];
int degree [100005];
vector <int> adj[100005];
vector <int> dependecy[100005];
vector <int> topo_sorted;
set <int> pq;
set <int> prog;

int reset(){
	memset(visit,0,sizeof(visit));
	memset(degree,0,sizeof(degree));
	for(int i=0;i<100005;i++){
		adj[i].clear();
		dependecy[i].clear();
	}
	pq.clear();
	prog.clear();
	topo_sorted.clear();
	return 0;
}

int dfs(vector <int> dependecy[], int x){
	prog.insert(x);
	visit[x]=1;
	for(int i=0;i<dependecy[x].size();i++)
		if(!visit[dependecy[x][i]])
			dfs(dependecy, dependecy[x][i]);
	return 0;
}

int topo_sort(){
	for(int i=1;i<=n;i++)
			if(!degree[i])
				pq.insert(i);

	while(!pq.empty()){
		int top=*pq.begin();
		topo_sorted.push_back(top);
		pq.erase(top);
		for(int i=0;i<adj[top].size();i++){
			degree[adj[top][i]]--;
			if(!degree[adj[top][i]])
				pq.insert(adj[top][i]);
		}
	}
	return 0;
}

int main(){
	int t,q,d,x;
	cin>>t;
	while(t--){
		reset();
		cin>>n>>q;
		for(int i=1;i<=n;i++){
			cin>>d;
			for(int j=0;j<d;j++){
				cin>>x;
				dependecy[i].push_back(x);
				adj[x].push_back(i);
				degree[i]++;
			}
		}
		for(int i=0;i<q;i++){
			cin>>x;
			dfs(dependecy ,x);
		}
		topo_sort();
		vector <int> ans;
		for(int i=0;i<n;i++)
			if(prog.find(topo_sorted[i])!=prog.end())
				ans.push_back(topo_sorted[i]);
		cout<<ans.size()<<endl;
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}
