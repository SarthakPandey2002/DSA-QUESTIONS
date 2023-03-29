Reducing Dishes

class Solution {
public:
    int t[501][501];
    int solve(vector<int>&satisfaction,int idx,int time){
        int n=satisfaction.size();
        if(idx>=n)
            return 0;
        if(t[idx][time]!=-1)
            return t[idx][time];
        int take=satisfaction[idx]*time+solve(satisfaction,idx+1,time+1);
        int notTake=solve(satisfaction,idx+1,time);
        return t[idx][time]=max(take,notTake);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        memset(t,-1,sizeof(t));
        sort(satisfaction.begin(),satisfaction.end());
        int temp=solve(satisfaction,0,1);
       return max(temp,0);
    }
};
