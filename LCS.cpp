// The Idea:
//   1. Consider two strings:- 
//         "adroitanuj" and "adroitanuj". Pretty simmple, right? Since both are same, the answer is 10;
//   2. Consider these two strings now:-
//         "adroitanuj" and "xxxadroitanuj". Again pretty simmple, right? You remove the substring "xxx" from the second string, you get the result same as 1.
//   3. Consider these two strings now:-
//         "adroitanuj" and "xaxdxrxoxixtxaxnxuxj".
//         So, just ignore the "x" character. You get the same result as 1.
//   4. So, every time the first character of both string are same, you increment the counter by 1, and remove both the characters.
//   5. If they are not same, eith remove the first character from first string, or from the second string, or from both. Who knows which path would 
//      give you the maximum value? Let that be done by recursion. You should not worry about it.
//   6. Just worry about stroing the pre-calculated value;
//   7. DP[i][j], the i represents that you are at i-th index of first string and j represents that you are at j-th index;
//   8. Answer will be at bottom right corner cell;
//   9. To fnd the string, do backtracking.
//       -if dp[i-1][j]==dp[i][j+1] then add the character.Then i-- and j--;
//       - else follow the maximum of these two and check if s1[i]==s2[j] or not.
//       - Do these steps until you hit dp[0][0];
      
// -----------------------------------------------------------------------------------------------------------------------------------------------------------------
// Code:   (C++)

#include<bits/stdc++.h>
using namespace std;
#define int long long int
#define intr(n) int n;cin>>n;
#define str(n) string n;cin>>n;
#define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];


int dp(string s1, string s2,int n,int m, vector<vector<int> >&vec){
    if(n<=0 || m<=0){
        vec[n][m]=0;
        return vec[n][m];
    }
    if(vec[n][m]!=-1)return vec[n][m];

    if(s1[0]==s2[0]){
        vec[n][m] = 1 + dp(s1.substr(1),s2.substr(1),n-1,m-1,vec);
        return vec[n][m];
    }
    else{
        int a = dp(s1.substr(1),s2.substr(1),n-1,m-1,vec);
        int b = dp(s1,s2.substr(1),n,m-1,vec);
        int c = dp(s1.substr(1),s2,n-1,m,vec);
        int maxm = max(a,max(b,c));
        vec[n][m]=maxm;
        return vec[n][m];
    }
}




void thaala(){
    str(s1);str(s2);
    s1="@"+s1;
    s2="!"+s2;
    int n=s1.length(),m=s2.length();
    vector<vector<int> >vec(n+1);
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            vec[i].push_back(-1);
        }
    }
    dp(s1,s2,n,m,vec);

    string s="";
    int i=n,j=m;
    while(i>0 && j>0){
        if(s1[i]==s2[j]){s+=s1[i];i--;j--;}
        else{
            if(vec[i-1][j]>vec[i][j-1])i--;
            else j--;
        }
    }
    reverse(s.begin(),s.end());
    cout<<s;


}


int32_t main(){ 
    int TC=1;while(TC--){thaala();}
}
