class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        for(int i=0;i<nums1.size();i++){
            nums1[i] = abs(nums1[i] - nums2[i]);
        }
        int M = *max_element(nums1.begin(),nums1.end()), k = k1+k2;
        vector<int>diff(M+1);
        for(int i=0;i<nums1.size();i++){
            diff[nums1[i]]++;
        }
        for(int i=M;i>0;i--){
            if(k<=0)break;
            if(diff[i]>0){
                int temp = min(k,diff[i]);
                diff[i] -= temp;
                diff[i-1] += temp;
                k-=temp;
            }
        }
        long long answer = 0;
        for(long long i=0;i<=M;i++){
            answer += (long long)(diff[i])*i*i;    
        }
        return answer;
    }
};