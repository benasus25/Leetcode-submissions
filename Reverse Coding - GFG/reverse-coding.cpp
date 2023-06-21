//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
  const int MOD = 1e9+7;
    int sumOfNaturals(int n) {
        // code here
        long long ans =0;
        if(n%2){
            ans = (n+1)/2;
            ans *=n;
            ans%=MOD;
        }
        else{
            ans = n/2;
            ans *= (n+1);
            ans%=MOD;
        }
        return (int)ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends