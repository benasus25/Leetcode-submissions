class Solution {
public:
    int deleteAndEarn(vector<int>& v) {
        vector<int>a(20005,0);
        int i,m=INT_MIN,x1,x2,temp;
        for(int i=0;i<v.size();i++){
            m=max(v[i],m);
            a[v[i]]++;
        }
        
        x1=a[1];
        x2=max(a[1],a[2]*2);
        
        for(i=3;i<=m;i++){
            temp=x2;
            x2=max(x2,a[i]*i+x1);
            x1=temp;
        }
        return max(x1,x2);
        
    }
    
};