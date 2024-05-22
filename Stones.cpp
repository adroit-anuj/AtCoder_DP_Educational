//Ohhhh Tooodles!!!!

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

/*
        Pt_2_B_Noted?
*/


void thaala(){
    intr(N);intr(K);
    vector<int>vec(N);for(int i=0;i<N;i++)cin>>vec[i];
    int dp[100001]={0};
    for(int i=0;i<=K;i++){
        for(int ele : vec){
            if(i>=ele && dp[i-ele]==0){
                dp[i]=1;
                break;
            }
            else continue;
        }
    }
    (dp[K]==0)?cout<<"Second":cout<<"First";
      
}


int32_t main(){ 
    int TC=1;while(TC--){thaala();}
}
