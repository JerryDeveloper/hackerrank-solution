#include <bits/stdc++.h>

using namespace std;

int gemstones(vector <string> arr){
    map<char, set<int>> counter;
    for(int i = 0; i < arr.size(); ++i)
    {
        string curStone = arr[i];
        for(int j = 0; j < curStone.size(); ++j)
            counter[curStone[j]].insert(i);
    }
    
    int res = 0;
    for(auto c : counter)
        if(c.second.size() == arr.size())
            ++res;
    
    return res;
}

int main() {
    int n;
    cin >> n;
    vector<string> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++){
       cin >> arr[arr_i];
    }
    int result = gemstones(arr);
    cout << result << endl;
    return 0;
}
