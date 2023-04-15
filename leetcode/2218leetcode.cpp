 int t[1001][2001];
    int f(int i,int k,vector<vector<int>>& piles){
        int n=piles.size();
        int m=piles[i].size();
        if(i>=n)
            return 0;
        if(t[i][k]!=-1)
            return t[i][k];
        int notTake=f(i+1,k,piles);
        int take=0;
        int sum=0;
        int a=1e4;
        if(piles[i].size()>k)
            a=k;
        else
            a=piles[i].size();
        //int a=min(piles[i].size(),k);
        for(int j=0;j<a;j++){
            sum+=piles[i][j];
            // int rem=k-(j+1);
            // if(rem<0)
            //     return 0;
            if(k-(j+1)>=0){
                if(take<sum+f(i+1,k-(j+1),piles))
                    take=sum+f(i+1,k-(j+1),piles);
            }
        }
        return t[i][k]=max(take,notTake);
    }
    
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(t,-1,sizeof(t));
        return f(0,k,piles);
    }
};
