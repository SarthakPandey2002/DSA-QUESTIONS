class Solution {
public:
    
    long long bs(vector<int>& potions,int target,int s){
        long long n=potions.size();
        long long l=0,r=n-1;
        long long lr=n;
        long long c=0;
        while(l<=r){
            long long mid=l+(r-l)/2;
            long long temp=((long long)potions[mid])*((long long)target);
            if(temp>=s){
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return n-r-1;
    }
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans;
        sort(potions.begin(),potions.end());
        for(long long i=0;i<spells.size();i++){
            ans.push_back(bs(potions,spells[i],success));
        }
        return ans;
    }
};
