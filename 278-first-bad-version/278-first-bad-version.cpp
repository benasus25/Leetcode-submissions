// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    int i =0,r=n;
    while(i<r){
        int mid = i+(r-i)/2;
        if(isBadVersion(mid))r= mid;
        else i = mid+1;
    }
    return r;
    }
};