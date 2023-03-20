Distribute Money to Maximum Children

You are given an integer money denoting the amount of money (in dollars) that you have and another integer children denoting the number of children
that you must distribute the money to.

You have to distribute the money according to the following rules:

All money must be distributed.
Everyone must receive at least 1 dollar.
Nobody receives 4 dollars.
Return the maximum number of children who may receive exactly 8 dollars if you distribute the money according to the 
aforementioned rules. If there is no way to distribute the money, return -1.
  
  class Solution {
public:
    int distMoney(int m, int c) {
        if(c>m)
            return -1;
        m-=c;
        int res=0;
        for(int i=1;i<c;i++){
            if(m>=7){
                res+=1;
                m-=7;
            }
            else
            return res;
        }
        if(m==3){
            if(res>0)
                res--;
            else
                return 0;
        }
        if(m==7)
            res++;
        return res;
    }
};
