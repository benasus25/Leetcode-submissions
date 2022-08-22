class Solution {
public:
	bool isPowerOfFour(int n) {
		if(n <= 0){
			return false;
		}
		if(n & (n - 1)){
			return false;
		}
		return !(n & (0xAAAAAAAA));
	}
};