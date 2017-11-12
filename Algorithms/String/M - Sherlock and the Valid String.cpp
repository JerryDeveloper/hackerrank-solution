#include <bits/stdc++.h>

using namespace std;

string isValid(string s){
    map<char, int> counter;
    
    for(int i = 0; i < s.size(); ++i)
    {
        ++counter[s[i]];
    }
    
    if(counter.size() <= 1)
        return "YES";
    
    vector<pair<char, int>> list(counter.begin(), counter.end());
    sort(list.begin(), list.end(), [](pair<char, int> &a, pair<char, int> &b) { return a.second < b.second; });
    
    //for(auto l : list)
    //    cout << l.first << " : " << l.second << endl;
    
    // case 1: 1, 4, 4
    // case 2: 4, 4, 5
    // case 3: 4, 4, 4
    // be careful: 1, 4, 4, 5
    
    for(int i = 1; i < list.size(); ++i)
    {
        int cur = list[i].second;
        int prev = list[i - 1].second;
        if(cur == prev || (i == list.size() - 1 && cur == prev + 1) || (i == 1 && prev == 1))
            continue;
        else
            return "NO";
    }
    
    if(list.size() > 2 && list[0].second == 1 && list[list.size() - 1].second == list[list.size() - 2].second + 1)
        return "NO";
    
    return "YES";
}

int main() {
    string s;
    cin >> s;
    string result = isValid(s);
    cout << result << endl;
    return 0;
}
