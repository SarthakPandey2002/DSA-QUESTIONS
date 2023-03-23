Number of Operations to Make Network Connected

class Solution {
public:
    
    void dfs(vector<bool>&visited,unordered_map<int,vector<int>>&mp,int u){
        visited[u]=true;
        for(auto x:mp[u]){
            if(!visited[x])
            dfs(visited,mp,x);    
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& c) {
        vector<bool>visited(n,false);
        unordered_map<int,vector<int>>mp;
        int e=c.size();
        if(e<n-1)
            return -1;
        for(auto x:c){
            int a=x[0];
            int b=x[1];
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        int res=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(visited,mp,i);
                res++;
            }
        }
        return res-1;
    }
};
