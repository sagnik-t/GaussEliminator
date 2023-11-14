#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
#include <numeric>
#include "overloads.h"
#include "matrix.h"
using namespace std;

int main()
{
    vector<vector<int>> a {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<vector<int>> b {{1, 2, 3}, {4, 5, 6}};
    Matrix<int> A(a);
    Matrix<int> B(b);
    A.swap(0, 2);
    Matrix<int>::print(A);
    return 0;
}