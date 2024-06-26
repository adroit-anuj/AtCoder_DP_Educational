// Idea:-
//   * Just do dfs at every node, and store the maximum depth of every node in an array, name it as DP;
//   * The maximum value has to be stored only.
//   * Output the maximum value from the DP array;

// ====================================================================================================================
// Code:-  (C++)

#include<bits/stdc++.h>
#define int long long int

vector<int> graph[100009];                 //graph initialised
vector<int> visited(100009,0);            //Visited array initialised
vector<int>DP(100009,0);


void input(int n, int e){
    for(int i=0;i<e;i++){
        int v1,v2;cin>>v1>>v2;
        graph[v1].push_back(v2);          //Since the graph is directed;
    }
}


void dfs(int root){

    for(int child:graph[root]){
        if(!visited[child]){
            visited[child]=1;
            dfs(child);
        }
        DP[root] = max(DP[root],1+DP[child]);  //Just give it a moment, and think what does it do?   [ Ans=> https://textsaver.flap.tv/lists/6j2k ]
    }
}


void func(){
    int n,e;cin>>n>>e;
    input(n,e);
    for(int i=1;i<=n;i++){
        if(!visited[i])dfs(i);        //Running the modified DFS for every node, so that we can save the MAX depth of every node in DP;
    }
    int ans = 0;
    for(int ele:DP)ans = max(ele,ans);
    cout<<ans;
}




int32_t main(){
    func();
    return 0;
}
