#include <bits/stdc++.h>

using namespace std;

int theLoveLetterMystery(string s){
    int i = 0;
    int j = s.size() - 1;
    int res = 0;
    while(i < j)
        res += abs(s[i++] - s[j--]);
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = theLoveLetterMystery(s);
        cout << result << endl;
    }
    return 0;
}
