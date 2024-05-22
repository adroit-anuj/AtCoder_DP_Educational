//Ohhhh Tooodles!!!!

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define str(n) string n;cin>>n;
#define array(arr,n) intr(n);double arr[n];for(int i=0;i<n;i++)cin>>arr[i];
#define print_arr(arr,n) for(int i=0;i<n;i++)cout<<arr[i]<<" ";cout<<endl;

/*
        Pt_2_B_Noted?
*/


double coins(int n,vector<vector<double> >&vec,int i,int j, double *prob){

    if(i<0 || j<0){return 0;}
    // if(i==0)return (1-prob[j-1])*1.0*coins(n,vec,i,j-1,prob);
    if(i>j){return 0;}
    if(vec[i][j]!=-1)return vec[i][j];

    return ((coins(n,vec,i-1,j-1,prob)*prob[j-1]*1.0) + (coins(n,vec,i,j-1,prob)*(1-prob[j-1])*1.0));
    
}




void thaala(){
    array(prob,n);
    vector<vector<double> >vec(n+1,vector<double>(n+1));
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            vec[i][j]=-1*(1.0);
        }
    }vec[0][0]=1.0;

    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++){
            vec[i][j]=coins(n,vec,i,j,prob);
        }
    }
    double ans = 0;
    for(int i=(n/2)+1;i<=n;i++)
        ans += vec[i][n];
    cout<<setprecision(9)<<ans;

}


int32_t main(){ 
    int TC=1;while(TC--){thaala();}
}
