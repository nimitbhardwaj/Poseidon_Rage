#include <iostream>
#include <vector>
using namespace std;
vector<pair<int,int> > arr[300000];
    
void merge(vector<pair<int,int> > &a,vector<pair<int,int> > &b,vector<pair<int,int> > &c,int len)
{
    int i=0,j=0;
    a.push_back(b[i++]);
    while(i<b.size()-1)
    {  
        if(b[i].second>=len) 
            a.push_back(b[i]);
        i++;
    }
    if(b.size()>1)
        a.push_back(b[i++]);
    
    j=0;
    if(b[b.size()-1].first==c[0].first)
        a[a.size()-1].second+=c[j++].second;
    else
        a.push_back(c[j++]);
    while(j<c.size()-1)
    {
        if(c[j].second>=len)
            a.push_back(c[j]);
        j++;
    }
    if(c.size()>1)
        a.push_back(c[j]);
}
    
void make_tree(int *st,int low,int up,int loc=1)
{   
    pair<int,int> temp;
    if(low==up)
    {
        temp.first=st[low];
        temp.second=1;
        arr[loc].push_back(temp);
        return;
    }
    make_tree(st,low,(low+up)/2,2*loc);
    make_tree(st,(low+up)/2+1,up,2*loc+1);
        
    merge(arr[loc],arr[2*loc],arr[2*loc+1],(up-low+1)/2);
}

vector<pair<int,int> >* query(int left,int right,int low,int up,int k,int l=1)
{   
    vector<pair<int,int> > *temp;
    if(left==low&&right==up)
    {
        return &arr[l];
    }
    if(right<=(low+up)/2)
        return query(left,right,low,(low+up)/2,k,2*l);
    if(left>(low+up)/2)
        return query(left,right,(low+up)/2+1,up,k,2*l+1);
    else
    {
        temp = new vector<pair<int,int> >;
        
        vector<pair<int,int> > &a=*temp;
        vector<pair<int,int> > &b=*(query(left,(low+up)/2,low,(low+up)/2,k,2*l));
        vector<pair<int,int> > &c=*(query((low+up)/2+1,right,(low+up)/2+1,up,k,2*l+1));
        
        merge(a,b,c,k);
        return &a;
    }
}


int main()
{
	long long int m,n,l,r,k,i,j,ans;
	vector<pair<int,int>  > *a;
	cin >> n >> m;
	int array[n+1];
	
	for(i=1;i<=n;i++)
        cin >> array[i];

    make_tree(array,1,n);

    for(i=0;i<m;i++)
	{
		cin >> l >> r >> k;
		ans=-1;
		a=query(l,r,1,n,k);
		for(j=0;j<a->size();j++)
		{
		    if(a->at(j).second>=k) 
	        {
	            ans=a->at(j).first;
	            break;
	        }  
	    }
	    cout << ans << endl;
	}
	return 0;  
}
