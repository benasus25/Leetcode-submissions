class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int,int>> req;
        for(int i = 0;i<arr.size();i++){
            req.push_back(make_pair(arr[i],i));
        }
        sort(req.begin(), req.end());
        int num = 1;
        vector<int>res(arr.size(), num);
        for(int i=1;i<req.size();i++){
            if(req[i].first>req[i-1].first){
                num++;
            }
            res[req[i].second]=num;
        }
        return res;
    }
};