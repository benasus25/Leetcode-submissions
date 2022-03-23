class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
    vector<vector<int>>graph(n,vector<int>());
    vector<int>inorder(n,0);
    for(int i=0;i<prerequisites.size();i++){
        graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
        inorder[prerequisites[i][0]]++;
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(!inorder[i])q.push(i);
    }
    int cnt=0;
    while(!q.empty()){
        int num = q.front();
        for(auto u:graph[num]){
            inorder[u]--;
            if(inorder[u]==0)q.push(u);
        }
        cnt++;
        q.pop();
    }
    if(cnt==n)return true;
        return false;
    }
};