#include <bits/stdc++.h>

using namespace std;

// 1. to solve duplicate, coins in solutions must be in ascending order

map<tuple<long, vector<long>::iterator, vector<long>::iterator>, long> calc_res;

long getWays(long n, vector<long>::iterator begin, vector<long>::iterator end){
    
    if(begin >= end)
        return 0;
    
    auto map_key = make_tuple(n, begin, end);
    
    if(calc_res.find(map_key) != calc_res.end())
        return calc_res[make_tuple(n, begin, end)];
    
    long cur_res = 0L;
    
    for(auto i = begin; i != end; ++i)
    {
        //cout << "step = " << n << ", coin = " << *i << endl;
        if(n - *i < 0)
            break;
        else if(n - *i == 0)
            cur_res += 1;
        else if(calc_res.find(make_tuple(n - *i, i, end)) != calc_res.end())
            cur_res += calc_res[make_tuple(n - *i, i, end)];
        else
        {
            long tmp = getWays(n - *i, i, end);
            cur_res += tmp;
        }
    }
    
    calc_res[map_key] = cur_res;
    
    return cur_res;
}

int main() {
    int n;
    int m;
    cin >> n >> m;
    vector<long> c(m);
    for(int c_i = 0; c_i < m; c_i++){
       cin >> c[c_i];
    }
    
    sort(c.begin(), c.end());
    
    // Print the number of ways of making change for 'n' units using coins having the values given by 'c'
    long ways = getWays(n, c.begin(), c.end());
    
    cout << ways << endl;
    
    return 0;
}
