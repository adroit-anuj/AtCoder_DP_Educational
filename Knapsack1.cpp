// The Idea:
//   1. For every object, there is the value for it; 
//   2. There is a limit on your sack;
//   3. So, when you arrive at a stone, you have the choice either to pick it, or not to.
//   4. By now, you would have visualized that a certain binary number will be formed.
//   5. 1000101011... '1' represents that you have picked the stone lying on ith index. '0' represents that you haven't picked it.
//   6. The length of binary string represents the number of stone options available to you.
//   7. The DP will be of 2nd degree, because the stone weight and Capacity remaining decides the answer.
//   8. If capacity is zero, the answer will be zero only.
//   9. If number of stone is zero, the answer will be zero only.
//   10. If the stone weight is STRICTLY greater than the capacity, then we have to skip it.
//   11. Arriving at a particular stone, if you pick it and if you don't pick it, you have to store max of these two cases, which
//       gives you max points till here.
//   12. The answer is stored int [N][W] because we have all the N elements, and capacity is W.
// -----------------------------------------------------------------------------------------------------------------------------------
// Code:  (C++)

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define ar(arr,n) int arr[n];for(int i=0;i<n;i++)cin>>arr[i];

int ks(int N,int W, int* wt, int* val,vector<vector<int> >&dp){
    if(N<=0 || W<=0)return 0;
    if(dp[N][W]!=-1)return dp[N][W];

    if(wt[N-1]>W){
        dp[N][W]=ks(N-1,W,wt,val,dp);
        return dp[N][W];
    }
    else{
        dp[N][W]=max(val[N-1]+ks(N-1,W-wt[N-1],wt,val,dp),ks(N-1,W,wt,val,dp));
        return dp[N][W];
    }
}



void thaala(){

    intr(N);intr(W);
    int wt[N],val[N];for(int i=0;i<N;i++)cin>>wt[i]>>val[i];
    vector<vector<int> >dp(N+1);
    for(int i=0;i<N+1;i++){
        for(int j=0;j<W+1;j++){
            dp[i].push_back(-1);
        }
    }
    
    dp[0][0]=0;
    cout<<ks(N,W,wt,val,dp);
}

int32_t main(){ int TC=1;while(TC--){thaala();}}
