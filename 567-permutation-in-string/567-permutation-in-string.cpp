class Solution {
public:
    bool check(string s, string r, int i, int j){
        set<char>st;
        for(int i=0;i<s.length();i++){
            st.insert(s[i]);
        }
        for(int k=i;k<=j;k++){
            st.erase(r[k]);
        }
        return st.size()==0?1:0;
    }
    
    bool checkInclusion(string s1, string s2) {
    int n =s1.length();
    int m = s2.length();
    if(n>m)return false;
    int hash =0,sum=0,i=0;
    for(;i<n;i++){
        hash += s1[i]-'a'+1;
        sum += s2[i]-'a'+1;
    }
    cout<<"Initial hash and sum is "<<hash<<" "<<sum<<endl;
    int start =0;
    while(i<=m){
        if(sum==hash){
            if(check(s1,s2,start,i))return true;
        }
        if(i==m)return false;
        sum+=s2[i]-'a'+1;
        sum-=s2[start]-'a'+1;
        cout<<start<<" "<<i<<" "<<sum<<endl;        
        start++;
        i++;
    }
    return false;
    }
};