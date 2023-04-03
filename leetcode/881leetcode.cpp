class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        sort(people.begin(),people.end());
        int res=0;
        int start=0,end=n-1;
        while(start<=end){
            if(people[start]+people[end]<=limit)
            {
                start++;
                end--;
            }
            else
                end--;
            res++;
        }
        return res;
    }
};
