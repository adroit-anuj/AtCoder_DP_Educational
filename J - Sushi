//Ohhhh Tooodles!!!!

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define fast_io 
#define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

/*
        Pt_2_B_Noted?
*/
double dp[300][300][300]={0};


double func(int one, int two, int three, int n){
    if(one<0 || two<0 || three<0)return 0;
    if(one==0 && two==0 && three==0)return 0;
    if(dp[one][two][three]!=0)return dp[one][two][three];

    dp[one][two][three] = (n+one*func(one-1,two,three,n)*1.0+two*func(one+1,two-1,three,n)*1.0+three*func(one,two+1,three-1,n)*1.0)/(one+two+three); 
    return dp[one][two][three];
}



void thaala(){
    
    vector<int>vec(4,0);
    array(arr,n);
    for(int i=0;i<n;i++)vec[arr[i]]++;
    cout<<setprecision(15)<<func(vec[1],vec[2],vec[3],n);




}


int32_t main(){
    int TC=1;while(TC--){thaala();}
}
