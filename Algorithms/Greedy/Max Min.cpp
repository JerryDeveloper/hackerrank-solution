#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int N, K, unfairness = INT_MAX;
    cin >> N >> K;
    int list[N];
    for (int i=0; i<N; i++)
        cin >> list[i];
    
    /** Write the solution code here. Compute the result, store in  the variable unfairness --
    and output it**/
    
    // 1. sort the array
    sort(list, list + N);
    
    // 2. traverse through the array
    for(int i = 0; i < N - K + 1; ++i)
    {
        int temp = list[i + K - 1] - list[i];
        if(temp < unfairness)
            unfairness = temp;
    }
    
    cout << unfairness << "\n";
    return 0;
}

