#include <bits/stdc++.h>
using namespace std;

int primes[]={1,2,3,5,7,11,13,17,19,23,29};
long long dp[2005][2005]={0};
int n,tw;
typedef pair<long long,int> p;
vector <p> c;
vector <long long> v;

int main(){
	
    cin>>n>>tw;
    int l,m;
    c.push_back(make_pair(0,0));
    
    for(int i=1;i<=n;i++){
    	cin>>l>>m;
    	c.push_back(make_pair(l,m));
    }
    sort(c.begin(),c.end());
   
   	for(int i=0;i<=n;i++){
   		for(int j=0;j<=tw;j++){
   			if(i==0 || j==0)
   				dp[i][j]=0;
   			else if(j<c[i].second)
   				dp[i][j]=dp[i-1][j];
   			else
   				dp[i][j]=max(dp[i-1][j],(c[i].first+dp[i-1][j-c[i].second]));
   		}
   	}
   	
   	int x=n,y=tw;
   	while(x>0 && y>0){
   		if(dp[x][y]!=dp[x-1][y]){
   			v.push_back(c[x].first);
   			y=y-c[x].second;
   		}
   		x=x-1;
   	}
   	
   	for(int i=0;i<v.size();i++){
   		cout<<v[i]<<endl;
   	}
   	
   	int j=10;
   	sort(v.begin(),v.end());
   	long long ans=0;
   	for(int i=v.size()-1;i>=0;i--){
   		ans+=(v[i]*primes[j]);
   		j--;
   		if(j<0) 
   			j=0;
   	}
   	cout<<ans<<endl;
    return 0;
}
