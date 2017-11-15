#include <bits/stdc++.h>

using namespace std;

int alternatingCharacters(string s){
    if(s.size() < 1)
        return 0;
    
    char prev = s[0];
    int res = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        if(s[i] != prev)
            prev = s[i];
        else
            ++res;
    }
    
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = alternatingCharacters(s);
        cout << result << endl;
    }
    return 0;
}
