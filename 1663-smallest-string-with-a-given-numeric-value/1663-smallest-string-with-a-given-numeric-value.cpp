class Solution {
public:
    string getSmallestString(int n, int k) {
    string s = "";
    if(k<n)return s;
    for(int i=0;i<n;i++){
        s+='a';
        k--;
    }
    int j = n-1;
    while(k){
        if(k>=25){
            s[j]='z';
            j--;
            k-=25;
        }
        else{
            s[j]= k+'a';
            k=0;
        }
    }
    return s;
    }
};