#include <bits/stdc++.h>

using namespace std;

bool isPalindrome(string s)
{
    int i = 0;
    int j = s.size() - 1;
    while(i < j)
    {
        if(s[i] != s[j])
            return false;
        ++i;
        --j;
    }
    return true;
}

int palindromeIndex(string s){
    
    // linear time
    
    int i = 0;
    int j = s.size() - 1;
    int res = -1;
    while(i < j)
    {
        if(s[i] != s[j])
        {
            bool isPa = isPalindrome(s.substr(i, j - i));
            if(isPa)
            {
                res = j;
                break;
            }
            isPa = isPalindrome(s.substr(i + 1, j - i));
            if(isPa)
            {
                res = i;
                break;
            }
            else{
                res = -1;
                break;
            }
        }
        
        ++i;
        --j;
    }
    
    return res;
}

int main() {
    int q;
    cin >> q;
    for(int a0 = 0; a0 < q; a0++){
        string s;
        cin >> s;
        int result = palindromeIndex(s);
        cout << result << endl;
    }
    return 0;
}
