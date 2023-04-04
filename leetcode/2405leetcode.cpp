class Solution {
public:
    int partitionString(string s) {
        int n=s.size();
        int res=1;
        unordered_set<char>st;
        for(int i=0;i<n;i++){
            char x=s[i];
            if(st.find(x)==st.end())
                st.insert(x);
            else{
                st.clear();
                st.insert(x);
                res++;
            }
        }
        return res;
    }
};
