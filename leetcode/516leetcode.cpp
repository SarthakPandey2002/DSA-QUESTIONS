Longest Palindromic Subsequence

Given a string s, find the longest palindromic subsequence's length in s.

A subsequence is a sequence that can be derived from another 
sequence by deleting some or no elements without changing the order of the remaining elements.
  
  class Solution {
public:
    
    int lcs(string &a,string&b){
        int n=a.size();
        vector<vector<int>>t(n+1,vector<int>(n+1,0));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(a[i-1]==b[j-1])
                    t[i][j]=1+t[i-1][j-1];
                else
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
            }
        }
        return t[n][n];
    }
    
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        string a=s;
        reverse(s.begin(),s.end());
        return lcs(a,s);
    }
};
