class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& first, vector<vector<int>>& second) {
    vector<vector<int>>res;
    int m= first.size(),n=second.size(),i=0,j=0;
    while(i<m&&j<n){
        if(first[i][0]<second[j][0]){
            if(first[i][1]<second[j][0])i++;
            else{
                res.push_back({second[j][0],min(second[j][1],first[i][1])});
                if(second[j][1]>first[i][1])i++;
                else if(second[j][1]<first[i][1])j++;
                else {
                    j++,i++;
                }
            }
        }
        else{
            if(first[i][0]>second[j][1])j++;
            else{
                res.push_back({first[i][0],min(second[j][1],first[i][1])});
                if(second[j][1]>first[i][1])i++;
                else if(second[j][1]<first[i][1])j++;
                else {
                    j++,i++;
                }
            }
        }
    }
    return res;
    }
};