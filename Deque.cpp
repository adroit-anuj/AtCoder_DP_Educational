//Ohhhh Tooodles!!!!

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

/*
        Pt_2_B_Noted?
        3 degrees hai. L,R and the player;
        Impartial game, because a state can be a winning or a losing state;
        Depends upon the elements, player's turn, L and R;
*/

int dp[3001][3001][2];

// filling dp wrt X value;

void thaala(){
    array(arr,n);
    
    for(int i=0;i<n;i++)
        dp[i][i][0]=arr[i],dp[i][i][1]=0;

    for(int r_l=1;r_l<=n-1;r_l++){
        for(int l=0;l+r_l<n;l++){
            int r = r_l+l;
            dp[l][r][0] = max(dp[l+1][r][1]+arr[l],dp[l][r-1][1]+arr[r]);
            dp[l][r][1] = min(dp[l+1][r][0],dp[l][r-1][0]);
        }
    }



    int sum = 0;for(int ele:arr)sum+=ele;
    cout<<2*dp[0][n-1][0]-sum<<endl;



}


int32_t main(){ 
    int TC=1;while(TC--){thaala();}
}
