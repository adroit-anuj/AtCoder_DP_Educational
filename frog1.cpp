// Suppose we have 5 platforms -> _ _ _ _ _ ;
// and, Height of each platform be given as H1,H2,H3.H4 and H5;

// Idea:
//   One may think that the minimum cost to reach the destination (i:e: the 5th platform) will be either:-
//   1. Minimum cost to reach 4th platform with the addition of |H5-H4|, OR
//   2. Minimum cost to reach 3rd platform with the addition of |H5-H3|. 
//   The minimum of above two will be our answer;
//   One may get the feel from the above observation that we are supposed to use RECURSION.(Similar thing will be done to reach 4th or 3rd platform);

// Why DP:
//   Suppose the minimum cost to reach the 3rd platform is as follows:   
//       1->2->3;
//   and, to reach the minimum cost to reach the 4th platform is as follows:  
//       1->2->4;
//   One may note that there is a REPETITION of calculation of minimum cost for the path 1->2 (i:e: |H2-H1|) in both the case written above;
//   Just remember, DP is equivalent to saying "Reusing of calculated value", and we can clearly see that there is REPETITION of calculation;
//   Although small number of calulation HERE, but think what if the size of array was 1000;
//   Hence, we shall store the calulated value, and reuse it, if needed at any point.

// ----------------------------------------------------------------------------------------------------------------------------------------------------
  // The Code: (C++)
  

  #include<bits/stdc++.h>
  using namespace std;
  #define int long long int
  #define intr(n) int n;cin>>n;
  #define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
  #define print_arr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

  int dp[1000001]={0};

  void thaala(){
    array(arr,n);
    int x,y;
    dp[1]=abs(arr[1]-arr[0]);    
    for(int i=2;i<n;i++){
        x = dp[i-1]+abs(arr[i]-arr[i-1]);
        y = dp[i-2]+abs(arr[i]-arr[i-2]);
        dp[i]=min(x,y);
    }
    cout<<dp[n-1];
  }

  int32_t main(){ 
    int TC=1;
    while(TC--){thaala();}
  }

