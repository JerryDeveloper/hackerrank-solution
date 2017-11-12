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
int main() {
    string s;
    getline(cin, s);
    
    set<char> allLetters;
    
    for(int i = 0; i < s.size(); ++i)
    {
        char curChar = s[i];
        if(curChar <= 'z' && curChar >= 'a')
            allLetters.insert(curChar);
        else if(curChar <= 'Z' && curChar >= 'A')
            allLetters.insert(tolower(curChar));
    }

    if(allLetters.size() == 26)
        cout << "pangram" << endl;
    else
        cout << "not pangram" << endl;
    
    return 0;
}
