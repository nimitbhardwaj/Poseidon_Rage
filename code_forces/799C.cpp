#include<bits/stdc++.h>
#define ulli unsigned long long int
#define ui unsigned int
using namespace std;

bool sortfun(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}

int main()
{
	int n=1,c,d,a,b;
	cin>>n>>c>>d;
	
	char ch;
	vector<pair<int,int> > vecc;
	vector<pair<int,int> > vecd;
	for(int i = 1; i <= n ; i++){
	    cin>>a>>b>>ch;
	    if(ch=='C')
	        vecc.push_back(make_pair(a,b));
	    else
	        vecd.push_back(make_pair(a,b));
	}
	
	//sort(vecc.begin(),vecc.end(),sortfun);
	//sort(vecd.begin(),vecd.end(),sortfun);
	
	int dc=0,sc=0,dd=0,sd=0,ss=0;
	
	for(int i=0;i<vecc.size();i++){
	    for(int j=i+1;j<vecc.size();j++){
	        if(vecc[i].second+vecc[j].second <= c){
	            dc=dc>vecc[i].first+vecc[j].first ? dc : vecc[i].first+vecc[j].first ;   
	        }
	    }
	    if(vecc[i].second <= c){
	        sc=sc>vecc[i].first?sc:vecc[i].first;
	    }
	}
	
	for(int i=0;i<vecd.size();i++){
	    for(int j=i+1;j<vecd.size();j++){
	        if(vecd[i].second+vecd[j].second <= d){
	            dd=dd>vecd[i].first+vecd[j].first ? dd : vecd[i].first+vecd[j].first ;   
	        }
	    }
	    if(vecd[i].second <= d){
	        sd=sd>vecd[i].first?sd:vecd[i].first;
	    }
	}
	
	if(sd!=0 && sc!=0){
	    ss=sc+sd;
	}
	
	int ans = max(ss,max(dc,dd));
	cout<<ans<<endl;
	
	
	return 0;
}
