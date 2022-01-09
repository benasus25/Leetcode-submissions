class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int i = 0,j =0;
    vector<int>res;
    while(i<m&&j<n){
        if(nums1[i]>=nums2[j]){
            res.push_back(nums2[j]);
            j++;
        }
        else{
            res.push_back(nums1[i]);
            i++;
        }
    }
    while(i<m){
        res.push_back(nums1[i]);
        i++;
    }
    while(j<n){
        res.push_back(nums2[j]);
        j++;
    }
    for(int i =0;i<n+m;i++){
        nums1[i]= res[i];
    }
    }
};