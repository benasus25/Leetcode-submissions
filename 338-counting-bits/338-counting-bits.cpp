class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num);
        res.push_back(0);  // for num=0
        if(num==0) return res;
        for(int i=1;i<=num;i++){
            res[i]=res[i/2]+i%2;
        }
        return res;
    }
};