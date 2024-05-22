// The Idea:
//   1. Generate a 2D matrix named as vac[R][C]. The cell vac[i][j] basically represents:-
//         (max happiness till now + happiness point of i-th activity in this cell on the j-th day).
//   2. It is clear from point 1, that 0<=R<2, since we ony have 3 different activities.
  
//   3. Consider 3 days limit and 3 types of activity, with the corresponding happiness points as follow:
//       A1  A2  A3
//       B1  B2  B3
//       C1  C2  C3
//   4. The combinations available are:
//       A1->B2->C3  (1)
//       A1->C2->B3  (2)
//       B1->A2->C3  (3)
//       B1->C2->A3  (4)
//       C1->B2->A3  (5)
//       C1->A2->B3  (6)
//   5. The maximum of all of them is our answer.
//   6. While dealing with column 1, the points remain as it is, because they are the maximum till now.
//   7. While dealing with first 2 columns now:-
//         -If A2 is done, then out answer TILL HERE will be max(A2+B1,A2+C1); // Note (3) and (6) path.
//         -If B2 is done, then out answer TILL HERE will be max(B2+A1,B2+C1); // Note (1) and (5) path.
//         -If C2 is done, then out answer TILL HERE will be max(C2+B1,C2+A1); // Note (2) and (4) path.
//   8. Now the matrix vac has these values stored-
//       A1  max(A2+B1,A2+C1)  ---
//       B1  max(B2+A1,B2+C1)  ---
//       C1  max(C2+B1,C2+A1)  ---
//   9.The third column will be filled up by similar way only. It will be maximum of other two rows, of previous day.  
//   10. Hence we form the relation vac[i][j]=max(vac[(i+1)%3][j-1],vac[(i+2)%3][j-1]);
//   11. Our answer will be stored in the last column, because it is the end of your vacation. 
//   12.It's just we have to run a final loop, to find the maximum value in that last column.

// ----------------------------------------------------------------------------------------------------------------------------------------
// Code:-  (C++)

  #include<bits/stdc++.h>
  using namespace std;
  #define int long long int
  #define intr(n) int n;cin>>n;
  #define array(arr,n) intr(n);int arr[n];for(int i=0;i<n;i++)cin>>arr[i];


  int mat[3][1000001];

  void thaala(){
    intr(N);
    for(int i=0;i<N;i++){
        int a,b,c;cin>>a>>b>>c;
        
        if(!i)mat[0][i]=a,mat[1][i]=b,mat[2][i]=c;
        else{
            mat[0][i]=a+max(mat[1][i-1],mat[2][i-1]);
            mat[1][i]=b+max(mat[0][i-1],mat[2][i-1]);
            mat[2][i]=c+max(mat[1][i-1],mat[0][i-1]);
        }
      }
      cout<<max(mat[0][N-1],max(mat[1][N-1],mat[2][N-1]));
  }


  int32_t main(){int TC=1;while(TC--){thaala();}}






