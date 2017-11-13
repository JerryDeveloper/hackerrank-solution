#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    
    set<int> allScores;
    
    if(s.size() > 0)
    {
        int lastPtr = 0;
        allScores.insert(s[lastPtr] - 'a' + 1);
        for(int i = 1; i < s.size(); ++i)
        {
            if(s[i] == s[lastPtr])
                allScores.insert((s[lastPtr] - 'a' + 1) * (i - lastPtr + 1));
            else
            {
                lastPtr = i;
                allScores.insert(s[lastPtr] - 'a' + 1);
            }
        }
    }
        
    
    int n;
    cin >> n;
    for(int a0 = 0; a0 < n; a0++){
        int x;
        cin >> x;
        
        if(allScores.find(x) != allScores.end())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    
    return 0;
}
