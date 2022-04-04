class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        if (num1 == "0" || num2 == "0") return "0";
        int n = num1.length(),m = num2.length();
        vector<int>res(n+m,0);
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                res[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                res[i+j] += res[i+j+1]/10;
                res[i+j+1] %=10;
            }
        }
        int i=0;
        while(i<res.size()&&res[i]==0)i++;
        while(i<res.size()){
            ans.push_back(res[i++]+'0');
        }
        return ans;
    }
};