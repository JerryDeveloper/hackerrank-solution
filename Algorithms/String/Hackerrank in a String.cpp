#include <bits/stdc++.h>

using namespace std;

int main(){
    int q;
    cin >> q;
    
    string b = "hackerrank";
    
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        
        string res = "YES";
        
        int sPtr = 0;
        int bPtr = 0;
        
        while(sPtr < s.size() && bPtr < b.size())
        {
            if(s[sPtr] != b[bPtr])
                ++sPtr;
            else
            {
                ++sPtr;
                ++bPtr;
            }
        }
        
        if(bPtr == b.size())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    
    return 0;
}
