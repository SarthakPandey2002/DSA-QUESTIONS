class Solution {
public:
    string removeStars(string s) {
        int n=s.size();
        int j=0;
        vector<char>temp(n);
        for(int i=0;i<n;i++){
            if(j!=0 && s[i]=='*')
                j--;
            else{
                temp[j]=s[i];
                j++;
            }
        }
        string ans="";
        for(int i=0;i<j;i++)
            ans+=temp[i];
        return ans;
    }
};
