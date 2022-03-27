    bool comparator(vector<int>&a,vector<int> &b){
        return a[0]-a[1]>b[0]-b[1];
    }

class Solution {
public:
    

    
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans =0;
        sort(costs.begin(),costs.end(),comparator); 
        for(int i=0;i<costs.size()/2;i++){
            ans+=costs[i][1]+costs[i+costs.size()/2][0];
        }
    return ans;
    }
};