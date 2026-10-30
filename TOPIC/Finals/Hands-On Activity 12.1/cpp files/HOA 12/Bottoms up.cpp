#include <iostream>
#include <algorithm>


int getMinSteps ( int n ){
    int* dp = new int[n+1];
    int i;
    dp[1] = 0; // trivial case
    for( i = 2 ; i <= n ; i ++ ){
        dp[i] = 1 + dp[i-1];
        if(i%2==0) dp[i] = std::min( dp[i] , 1+ dp[i/2] );
        if(i%3==0) dp[i] = std::min( dp[i] , 1+ dp[i/3] );
    }
    int retVal = dp[n];
    delete[] dp;
    return retVal;
}


int main(){
    std::cout << getMinSteps(10) << '\n';
    return 0;
}
