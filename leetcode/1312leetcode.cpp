class Solution {
public:
    
    int lcs(string a,string b){
        int n=a.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][n];
    }
    
    int minInsertions(string s) {
        string a=s;
        reverse(s.begin(),s.end());
        return s.size()-lcs(s,a);
    }
};
