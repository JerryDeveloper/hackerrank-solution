#include <bits/stdc++.h>

using namespace std;

/*
bool isAnagram(string a, string b)
{
    char rec = 0;
    for(char i : a) rec = rec ^ i;
    for(char i : b) rec = rec ^ i;
    
    return rec == 0;
}
*/

int sumPairs(int i)
{
    int prod = 0;
    while(i > 1)
        prod += (--i);
    return prod;
}

int sherlockAndAnagrams(string s)
{
    int res = 0;
    for(int len = 1; len < s.size(); ++len)
    {
        map<string, int> counter;
        for(int i = 0; i < s.size() - len + 1; ++i)
        {
            string subs = s.substr(i, len);
            sort(subs.begin(), subs.end());
            ++counter[subs];
        }
        
        for(auto p : counter)
        {
            if(p.second > 1)
            {
                res += sumPairs(p.second);
            }
        }
    }
    
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = sherlockAndAnagrams(s);
        cout << result << endl;
    }
    return 0;
}
