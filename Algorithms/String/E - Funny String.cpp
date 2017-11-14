#include <bits/stdc++.h>

using namespace std;

string funnyString(string s){
    bool isFunny = true;
    for(int i = 0, j = s.size() - 2; i < s.size() - 1 && j >= 0; ++i, --j)
    {
        if(abs(s[i + 1] - s[i]) != abs(s[j + 1] - s[j]))
            isFunny = false;
    }
    
    return isFunny?"Funny":"Not Funny";
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        string result = funnyString(s);
        cout << result << endl;
    }
    return 0;
}
