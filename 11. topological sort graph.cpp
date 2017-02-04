#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int visit[20005];
stack <ll> s[20005];
ll y,c;

int dfs(vector <ll> adj[], ll x){
    visit[x]=1;
    for(ll i=0;i<adj[x].size();i++){
        if(!visit[adj[x][i]]){
            s[y].push(adj[x][i]);
            c++;
        }
    }
    for(ll i=0;i<adj[x].size();i++){
        if(!visit[adj[x][i]])
            dfs(adj, adj[x][i]);
    }
    return 0;
}

int main() {
    long long q,n,m,x,i,j,d;
    cin>>q;
    while(q--){
    	c=0;
        memset(visit,0,sizeof(visit));
        cin>>n>>m;
        vector <ll> adj[n+1];
        for(i=1;i<=n;i++){
            cin>>d;
            while(d--){
                cin>>x;
                adj[i].push_back(x);
            }
            sort(adj[i].rbegin(),adj[i].rend());
        }
        for(y=0;y<m;y++){ 
            cin>>x;
            if(!visit[x]){
                s[y].push(x);
                c++;
            }
            dfs(adj, x);
        }
        cout<<c<<endl;

        vector < pair<ll,stack<ll> > > ans;
        for(i=0;i<m;i++){
            ans.push_back(make_pair(s[i].top(),s[i]));
        }
        sort(ans.begin(), ans.end());
        /*for(i=0;i<m;i++){
            ll key=ans[i];
            for (j=0;j<m;j++){
                if(!s[j].empty() && s[j].top()==key){
                    while(!s[j].empty()){
                        cout<<s[j].top()<<" ";
                        s[j].pop();
                    }
                }
            }
        }*/
        for(i=0;i<m;i++){
        	while(!ans[i].second.empty()){
        		cout<<ans[i].second.top()<<" ";
                ans[i].second.pop();
        	}
        }
    }
    return 0;
}