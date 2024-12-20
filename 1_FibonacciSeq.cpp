#include<iostream>
#include<vector>

using namespace std;

int recursiveFunction(int n, vector<int> &dp){
    if (dp[n]!=-1) {
        // Step 3: check if answer is already present in dp array or not
        // if present return from dp array only
        return dp[n];
    } else {
        // if not present,
        // Step 2: Store and return answers from DP array
        dp[n] = recursiveFunction(n-1, dp) + recursiveFunction(n-2, dp);
        return dp[n];
    }
}

void RecursionMemoization(int n){
    // Step 1: Create DP array
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    dp[1] = 1;
    cout<<recursiveFunction(n, dp)<<endl;
}

void TabulationMehtod(int n){
    // Create dp array
    vector<int> dp(n, -1);
    // fill the initial data into dp array
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < n+1; i++){
        dp[i] = dp[i-1] + dp[i-2];
    } 
    cout<<dp[n]<<endl;
}

void TabulationSpaceOptimized(int n){
    int last = 1;
    int second_last = 0;
    for (int i = 2; i < n+1; i++){
        int temp = last + second_last;
        second_last = last;
        last = temp;
    }
    cout<<last<<endl;
}

int main(){
    // USING TOP->DOWN approach i.e using recursion + memoization 
    RecursionMemoization(8);
    // USING BOTTOM->UP approach i.e using tabulation method
    TabulationMehtod(9);
    // SPACE OPTIMIZATION: don't need complete array, only n-1 and n-2 is required to form n
    TabulationSpaceOptimized(8);
}