// { Driver Code Starts
// Program to find minimum number of platforms
// required on a railway station
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    
    static bool customsort(const pair<int,char>&a, const pair<int,char>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
    
    int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	vector<pair<int,char>>res;
    	for(int i=0;i<n;i++){
    	    res.push_back({arr[i],'a'});
    	    res.push_back({dep[i],'d'});
    	}
    	int result =1,plat =0;
    	sort(res.begin(),res.end(),customsort);
    	for(auto u:res){
    	    if(u.second=='a')plat++;
    	    else plat--;
    	    result = max(result, plat);
    	}
    	return result;
    }
};


// { Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}  // } Driver Code Ends