#include <bits/stdc++.h>
using namespace std;
vector<int> a;
set<int> s;

int main(){
    int t,n;
    cin>>t;
    while(t--){
    	cin>>n;
    	a.clear();
    	s.clear();
    	int ans=0,i=0,size=1,found=0;
    	if(n==1) found=1;
    	a.push_back(n);
    	while(!found){
    		ans++;
    		int x=-1,y=-1,z=-1;
    		for(i;i<size;i++){
    			if(a[i]%3==0) x=a[i]/3;
    			if(a[i]%2==0) y=a[i]/2;
    			z=a[i]-1;
    			
    			if(x==1 || y==1 || z==1){ found=1; break;}
    			
    			if(x!=-1)
    				if(s.find(x)==s.end()){
    					a.push_back(x);
    					s.insert(x);
    				}
    			if(y!=-1)
    				if(s.find(y)==s.end()){
    					a.push_back(y);
    					s.insert(y);
    				}
    				if(s.find(z)==s.end()){
    					a.push_back(z);
    					s.insert(z);
    				}
    		}
    	
    		i=size;
    		size=a.size();
    	}
    	cout<<ans<<endl;
    	
    }
    return 0;
}
