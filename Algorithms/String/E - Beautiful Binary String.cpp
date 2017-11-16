#include <bits/stdc++.h>

using namespace std;

int minSteps(int n, string B){
    // 1. each 010 need to change once.
    // 2. if two 010 share same element, i.e. pattern 01010, only need to change once.
    
    int res = 0;
    for(int i = 0; i < n - 2; ++i)
    {
        if(B[i] == '0' && B[i + 1] == '1' && B[i + 2] == '0')
        {
            ++res;
            i += 2;
        }
    }
    
    return res;
}

int main() {
    int n;
    cin >> n;
    string B;
    cin >> B;
    int result = minSteps(n, B);
    cout << result << endl;
    return 0;
}
