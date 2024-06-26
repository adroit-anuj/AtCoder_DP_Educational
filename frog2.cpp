// Note:
//   Please read the file "A - Frog 1". The logic remains in that file only.
//   This problem is just an extension of problem A;

// Resemblance:
//   Here, we are free to jump from atmost Kth platform to the current platform, earlier we were restricted to K=2;
//   Just run the loop from the current platform to the K-th previous platform, and return the minimum of them.

// -------------------------------------------------------------------------------------------------------------------------
// Code: (C++)

  #include<bits/stdc++.h>
  using namespace std;
  #define int long long int
  #define intr(n) int n;cin>>n;
  #define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];

  int dp[1000001]={0};

  void thaala(){

    int n,K;cin>>n>>K;
    int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
    dp[1]=abs(arr[1]-arr[0]);    
    for(int i=2;i<n;i++){
        int x=INT_MAX;
        for(int j=1;j<=K;j++){
            if(i-j<0)break;
            int x = dp[i-j]+abs(arr[i]-arr[i-j]);    //Note the similarity. Do dry run for K=2;
            x=min(k,x);
        }
        dp[i]=x;
      }
      cout<<dp[n-1];
  }  


int32_t main(){ int TC=1;while(TC--){thaala();}}
