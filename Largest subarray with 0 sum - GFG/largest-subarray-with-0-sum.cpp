// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        // You)r code here
    map<int, int> p;
    int sum = 0; // Initialize the sum of elements
    int len = 0; // Initialize result

    for (int i = 0; i < n; i++)
    {
        // Add current element to sum
        sum += A[i];
        if(A[i] == 0 and len == 0)
            len = 1;
        if(sum == 0)
            len = i + 1;

        // Look for this sum in Hash table
        if (p.find(sum) != p.end())
        {
            // If this sum is seen before, then update max_len
            len = max(len, i - p[sum]);
        }
        else
        {
            // Else insert this sum with index in hash table
            p[sum] = i;
        }
    }
    return len;
    }
};


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}


  // } Driver Code Ends