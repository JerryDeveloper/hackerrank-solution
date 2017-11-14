#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        // your code goes here
        int sLen = s.size();
        bool found = false;
        for(int i = 1; i <= sLen / 2; ++i)
        {
            string a0 = s.substr(0, i);
            long long prev = stoll(a0);
            string res = "";
            while(res.size() < sLen)
            {
                res = res + to_string(prev);
                prev = prev + 1;
            }
            if(res.compare(s) == 0)
            {
                cout << "YES " << a0 << endl;
                found = true;
                break;
            }
        }
        if(!found)
            cout << "NO" << endl;
    }
    return 0;
}
