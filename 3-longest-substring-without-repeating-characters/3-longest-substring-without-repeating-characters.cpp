class Solution {
public:

int max(int a, int b){
    if(a>b)return a;
    return b;
}
    
int lengthOfLongestSubstring(string s) {
    vector<int>res(256,-1);
    if(s.length()<=1)return s.length();
    int ans  =1,sol=0;
    for(int i=0;i<s.length();i++){
        sol++;
        if(res[s[i]-' ']!=-1){
            if(i-sol+1<=res[s[i]-' ']){
                sol = min(sol,i-res[s[i]-' ']);
            }
        }
        res[s[i]-' ']=i;
        cout<<sol<<endl;
        ans = max(ans,sol);
    }
    cout<<"Done"<<endl;
    return ans;
    }
};