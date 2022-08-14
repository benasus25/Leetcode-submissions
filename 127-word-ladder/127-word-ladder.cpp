class Solution {
public:
    int ladderLength(string &beginWord, string &endWord, vector<string> &wordList){
    	unordered_set<string> s(wordList.begin(), wordList.end());

    	if(s.find(endWord) == s.end()) return 0;   // if our destination is not present in our list, return 0
    	int cnt = 0;	      // to count the number of nodes/steps needed to reach the destination word
    	queue<string> q;
    	q.push(beginWord);	  // push the starting node into queue, as we did in BFS [beginWord is our root]
    	
    	while(!q.empty()){
    		auto size = q.size();
    		cnt++;
    		while(size--){
    			auto currWord = q.front(); q.pop();
    			// find the next word which can be formed after currWord by changing it's letter(s)
    			for(int i = 0; i < currWord.size(); ++i){
    				string tmp = currWord;
    				// try to change each character, make a new word find in set
    				for(char ch = 'a'; ch <= 'z'; ++ch){
    					tmp[i] = ch;			// makin' newWord
    					// if new word is same as curr word simply ignore
    					if(tmp.compare(currWord) == 0) continue;
    					if(tmp.compare(endWord) == 0) return cnt + 1;	// found the endWord return cnt

    					// if we find the newWord is present in our map. put in the queue 
                        // as the next destination node, which will help is to reach our endWord
                        if(s.find(tmp) != s.end()){
                        	q.push(tmp);		// push the newWord or a node into queue 
                        	s.erase(tmp);		// remove that word, cuz it's taken into the queue
                        }
    				}
    			}
    		}
    	}
    	return 0;
    }
};