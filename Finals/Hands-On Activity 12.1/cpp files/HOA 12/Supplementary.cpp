#include <iostream>
#include <vector>

//matrix size 4x4
//definition of variables
#define M 4
#define N 4

//Top-down recursion (matrix, m, n, cost)
int Paths(int matrix[M][N], int m, int n, int cost) {
    //Base case 1
    //define out of bounds as program termination
    if (m < 0 || n < 0 || cost < 0) {
        return 0;
    }

    //Base Case 2 
    //define starting cell as (0,0)
    if (m == 0 && n == 0) {
        return (cost == matrix[0][0]) ? 1 : 0;
    }

    //count paths by moving up (m-1, n) and left (m, n-1)
    int remainingCost = cost - matrix[m][n];
    return Paths(matrix, m - 1, n, remainingCost) + 
           Paths(matrix, m, n - 1, remainingCost);
}

int main() {
    //4x4 matrix definition
    int matrix[M][N] = {
        { 4, 7, 1, 6 },
        { 6, 7, 3, 9 },
        { 3, 8, 1, 2 },
        { 7, 1, 7, 3 }
    };
    //target cost initialization
    int cost = 25;
    int alt_cost = 26;

    //Start from destination cell (M-1, N-1)
    int totalPaths = Paths(matrix, M - 1, N - 1, cost);
    int totalPathsAlt = Paths(matrix, M - 1, N - 1, alt_cost);

    std::cout << "The total number of paths with cost " << cost 
              << " is " << totalPaths << std::endl;

    std::cout << "The total number of paths with cost " << alt_cost 
              << " is " << totalPathsAlt << std::endl;
              
    return 0;
}