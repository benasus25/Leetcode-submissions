class Solution {
public:
    bool hasAllCodes(string s, int k) {
	int n = s.size(), size = 1 << k, count = 0, hash = 0, allOnes = ~size; 
	bool set[size]; memset(set, false, sizeof(set));
	for(int i = 0; i < n; i++){                    	    
		// below line combines all above-metioned steps for rolling hash calculation
		hash = ((hash << 1) & allOnes) | (s[i] - '0');            
		if(i >= k - 1 && !set[hash])   // first k - 1 iteration are to calculate hash of first substring of length k
			set[hash] = true, count++;
	}
	return count == size;
}
};