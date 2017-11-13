#include <bits/stdc++.h>

using namespace std;

// use dynamic programming, https://en.wikipedia.org/wiki/Longest_common_subsequence_problem

int commonChild(string s1, string s2){
    
    // a better way to 0-initialize: array = new int[M][N]();
    
    const int s1Len = s1.size() + 1;
    const int s2Len = s2.size() + 1;
    int **count = new int*[s1Len];
    for(int i = 0; i < s1Len; ++i)
        count[i] = new int[s2Len];
    
    for(int i = 0; i < s1.size() + 1; ++i)
    {
        count[i][0] = 0;
    }
    
    for(int j = 0; j < s2.size() + 1; ++j)
    {
        count[0][j] = 0;
    }
    
    for(int i = 1; i < s1.size() + 1; ++i)
    {
        for(int j = 1; j < s2.size() + 1; ++j)
        {
            if(s1[i - 1] == s2[j - 1])
                count[i][j] = count[i - 1][j - 1] + 1;
            else
                count[i][j] = max(count[i - 1][j], count[i][j - 1]);
        }
    }
    
    int res = count[s1.size()][s2.size()];
    delete [] count;
    
    return res;
}

int main() {
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int result = commonChild(s1, s2);
    cout << result << endl;
    return 0;
}
