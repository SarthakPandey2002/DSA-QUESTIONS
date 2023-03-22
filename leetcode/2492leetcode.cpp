Minimum Score of a Path Between Two Cities

You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where 
roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. 
  The cities graph is not necessarily connected.

The score of a path between two cities is defined as the minimum distance of a road in this path.

Return the minimum possible score of a path between cities 1 and n.

Note:

A path is a sequence of roads between two cities.
It is allowed for a path to contain the same road multiple times, and you can visit 
cities 1 and n multiple times along the path.
The test cases are generated such that there is at least one path between 1 and n.
  
  
class Solution {
public:
    int res=INT_MAX;
    
  void dfs(vector<bool>&visited,unordered_map<int,vector<pair<int,int>>>&adj,int x){
      visited[x]=true;
            for(auto &p:adj[x]){
                int a=p.first;
                int d=p.second;
                res=min(res,d);
                if(!visited[a])
                    dfs(visited,adj,a);
            }
    }
    
    int minScore(int n, vector<vector<int>>& roads) {
        int r=roads.size();
        vector<bool>visited(n,false);
        unordered_map<int,vector<pair<int,int>>>adj;
        for(int i=0;i<r;i++){
            int a=roads[i][0];
            int b=roads[i][1];
            int c=roads[i][2];
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
        dfs(visited,adj,1);
        return res;
    }
};
