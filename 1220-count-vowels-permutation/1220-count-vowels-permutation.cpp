class Solution {
const int MOD = 1e9+7;
const unordered_map<char, vector<char>>mp{{'s',{'a','e','i','o','u'}},
                                          {'a',{'e'}},
                                          {'e',{'a','i'}},
                                          {'i',{'a','e','o','u'}},
                                          {'o',{'i','u'}},
                                          {'u',{'a'}}
                                         };
unordered_map<char,vector<int>>res;
public:
    
    int solve(int n, char prev){
        if(n==0)return 1;
        if(res[prev][n])return res[prev][n];
        for(auto c:mp.at(prev)){
            res[prev][n] = (res[prev][n] + solve(n-1,c))%MOD;
        }
        return res[prev][n];
    }
    
    int countVowelPermutation(int n) {
        res['s'] = res['a'] = res['e'] = res['i']= res['o'] = res['u'] = vector<int>(n+1);
        return solve(n,'s');
    }
};