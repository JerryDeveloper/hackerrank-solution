#include <bits/stdc++.h>

using namespace std;

string richieRich(const string s, int n, int k){
    
    // step 1: change all non-symmetric pairs to symmetric, use the larger digit
    int i = 0;
    int j = s.size() - 1;
    set<int> mismatches;
    string res = s;
    
    while(i < j)
    {
        if(s[i] != s[j])
        {
            if(k <= 0)
                return "-1";
            else
            {
                char replaceChar = max(s[i], s[j]);

                // replace the mismatch slot the larger char
                res[i] = replaceChar;
                res[j] = replaceChar;

                --k;
                mismatches.insert(i);
            }
        }
            
        ++i;
        --j;
    }
    
    // step 2: if we have extra k, traverse again to see if we can make some pairs to '9'
    i = 0;
    j = s.size() - 1;
    
    while(i < j && k > 0)
    {
        if(res[i] != '9')
        {
            if(mismatches.find(i) != mismatches.end())
            {
                // apply one additional change
                res[i] = '9';
                res[j] = '9';
                --k;
            }
            else
            {
                // need to apply two additional changes
                if(k > 1)
                {
                    res[i] = '9';
                    res[j] = '9';
                    k -= 2;
                }
            }
        }
        
        ++i;
        --j;
    }
    
    // if the string is odd, change the middle one if still have capacity
    if(k >= 1 && n % 2 != 0)
        res[n / 2] = '9';
    
    return res;
}

int main() {
    int n;
    cin >> n;
    int k;
    cin >> k;
    string s;
    cin >> s;
    string result = richieRich(s, n, k);
    cout << result << endl;
    return 0;
}
