#include <bits/stdc++.h>

using namespace std;

int getMinimumCost(int n, int k, vector < int > c){
    // 1. sort the price
    sort(c.begin(), c.end());
    
    // 2. all buyers should purchase from most expensive flowers in first round.
    int multiplier = 1;
    int counter = k;
    int res = 0;
    for(auto cur = c.end() - 1; cur != c.begin() - 1; --cur)
    {
        if(counter == 0)
        {
            ++multiplier;
            counter = k;
        }
        
        res += multiplier * (*cur);
        --counter;
    }
    
    return res;
}

int main() {
    int n;
    int k;
    cin >> n >> k;
    vector<int> c(n);
    for(int c_i = 0; c_i < n; c_i++){
       cin >> c[c_i];
    }
    int minimumCost = getMinimumCost(n, k, c);
    cout << minimumCost << endl;
    return 0;
}
