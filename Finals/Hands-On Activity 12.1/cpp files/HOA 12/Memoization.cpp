#include <iostream>
#include <algorithm>

 // we will initialize the elements to -1 ( -1 means, not solved it yet )
int getMinSteps(int n,int memo[]){
    if ( n == 1 ){
    std::cout << "Best Case Found\n";
    return 0; // base case
}
    if( memo[n] != -1 ){ // we have solved it already :)
    std::cout << "Case Already Solved\n";
    return memo[n];
}
    int r = 1 + getMinSteps( n - 1, memo ); // '-1' step . 'r' will contain the optimal answer finally
    if( n%2 == 0 ) r = std::min( r , 1 + getMinSteps( n / 2, memo )) ; // '/2' step
    if( n%3 == 0 ) r = std::min( r , 1 + getMinSteps( n / 3, memo )) ; // '/3' step
    memo[n] = r ; // save the result. If you forget this step, then it's the same as plain recursion.
    return r;
}

int main() {
    int n = 10;
    int memo[100];
    std::fill(memo, memo + 100, -1);

    getMinSteps(n, memo);
    return 0;
}