    #include<vector>
    #include<iostream>
    using namespace std;
     
    int main()
    {
    	int t=4;
    	cin>>t;
    	while(t--)
    	{
    		int m,n,i,j,k;
    		long long int mm , sum , df ,dff;
    		cin >> n >> m;
    		vector<long long int> marr(m),narr(n);
    		long long int arr[m][n];
    		for(i=0;i<n;i++)//big array narr
    		{
    		    cin >> narr[i];
    		}
    		for(i=0;i<m;i++)//small array marr
    		{
    		    cin >> marr[i];
    		}
    		
    		for(i=0;i<m;i++)//fill 2d rray with sums of that rnges
    		{
    		    sum=0;
    		    for(j=0;j<marr[i];j++)
    		    {
    		        sum+=narr[j];
    		    } 
    		    arr[i][0]=sum;
    		    for(j=0;j<n-marr[i];j++)
    		    {
    		        sum+=narr[j+marr[i]];
    		        sum-=narr[j];
    		        arr[i][j+1]=sum;
    		    }
    		}
    		
    		for(i=m-2;i>=0;i--)//for all m//turns
    		{   
    		    dff=0;
    		    for(j=0;j<n-marr[i]+1;j++)//for a particular turns all possibilities
    		    {   
    		        df=0;
    		        if(dff==arr[i+1][j] || j==0)//biggest element in frst position so remove it and add last one 
    		        {
        		        for(k=j+1;k<j+marr[i]-marr[i+1];k++)//find the largest in range
        		        {   
        		            df= (df > arr[i+1][k] ? df : arr[i+1][k] ) ;		              
        		        }
    		        }
    		        else//compare previous biggest with lant one
    		        {
    		            df=(dff > arr[i+1][j+marr[i]-marr[i+1]-1] ? dff : arr[i+1][j+marr[i]-marr[i+1]-1]);
    		//            cout<<df<<".";
    		        }   
    		        arr[i][j]=arr[i][j]-df;
    		        dff=df;
    	//	        cout<<","<<arr[i][j]<<" ";
    		    }
    	//	    cout<<endl;
    		}
    		
    		df=0;
    		for(i=0;i<n-marr[0]+1;i++)
    		{
    		    df= (df > arr[0][i] ? df : arr[0][i]);
    		}
    		cout<<df<<endl;
    	}
    	return 0;
    } 
