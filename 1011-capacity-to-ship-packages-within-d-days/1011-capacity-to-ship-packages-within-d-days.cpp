class Solution {
public:
    
    bool helper(vector<int>num,int d, int val){
        int count=1,sum =0;
        for(int i=0;i<num.size();i++){
            if(sum+num[i]<=val)sum+=num[i];
            else{
                count++;
                sum = num[i];
                if(count>d)return false;
            }
        }
        return true;
    }    
    int shipWithinDays(vector<int>& weights, int days) {
        int high = accumulate(weights.begin(),weights.end(),0);
        int low = *max_element(weights.begin(),weights.end());
        while(low<high){
            int mid = low +(high-low)/2;
            if(!helper(weights,days,mid)){
                low = mid+1;
            }
            else{
                high =mid;
            }
        }
        return low;
    }
};