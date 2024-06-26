// Idea:
//   1.  The problem is fairly simple to start with 2D DP.
//   2.  Try to come up with a recursion relation, and you will we able to do it by memoization.  [ans=> https://textsaver.flap.tv/lists/6j2o ]
// ====================================================================================================
// Memoization answer (Raw)

// vector<vector<int> >DP(1e5,vector<int>(1e5,-1));


// int func(vector<string>input, int i, int j, int n, int m){

//   if(i>=n || j>=m)return 0;
//   if(vec[i][j]=='#)return DP[i][j]=0;
//   if(DP[i][j]!=-1)return DP[i][j];
//   return DP[i][j] = func(input,i-1,j,n,m) + func(input,i,j-1,n,m);


// }

// void func(){
//   DP[0][0]=1;
//   //Take input 
//   for(int i=1;i<n;i++)(input[i][0]=='#')?DP[i][0]=0:DP[i][0]=DP[i-1][0];
//   for(int j=1;i<m;j++)(input[0][j]=='#')?DP[0][j]=0:DP[0][j]=DP[0][j-1];
//   func(input,n-1,m-1,n,m);   //Since the destination is the cell(n-1,m-1);
// =======================================================================================================

// Code:-  (C++)




#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;
const int E = 1e9 + 7;

int dp[1001][1001];
int n,m;
vector <string> vec(1001);

int uptown(int n, int m){
    dp[0][0]=1;
    for(int i=1;i<n;i++){
        if(vec[i][0]=='#')dp[i][0]=0;
        else dp[i][0]=dp[i-1][0];
    }
    for(int i=1;i<m;i++){
        if(vec[0][i]=='#')dp[0][i]=0;
        else dp[0][i]=dp[0][i-1];
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(vec[i][j]=='#')dp[i][j]=0;
            else dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=E;
        }
    }
    return dp[n-1][m-1];

}



void thaala(){
    cin>>n>>m;
    
    for(int i=0;i<n;i++)cin>>vec[i];
    uptown(n,m);cout<<dp[n-1][m-1];




}


int32_t main(){ 
    int TC=1;while(TC--){thaala();}
}


