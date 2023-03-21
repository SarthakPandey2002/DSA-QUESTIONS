Number of Zero-Filled Subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long n=nums.size();
        long long res=0;
        for(long long j=0;j<n;j++){
           long long i=j;
            while(j<n && nums[j]==0){
                j++;
            }
            long long temp=((j-i)*(j-i+1))/2;
            res+=temp;
        }
        return res;
    }
};
