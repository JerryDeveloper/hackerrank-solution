#include <iostream>
#include <string>

using namespace std;

/* input

1 2
3
3.1233
abcde
fgh ijklmn opqr
xyz zzz
1
n

*/

/* output

123
3.1233
abcde
fgh
 ijklmn opqr
xyz zzz
1
n

*/

int main()
{
    // int
    int a, b, c;
    cin >> a >> b;
    cin >> c;
   
    // double
    double d;
    cin >> d;
   
    cout << a << b << c << endl;
    cout << d << endl;
   
    // string
    string e, f;
    cin >> e;
    cin >> f;
    
    cout << e << endl;
    cout << f << endl;
    
    // read line
    string g;
    getline(cin, g);
    cout << g << endl;
    
    string h;
    getline(cin, h);
    cout << h << endl;
    
    // read boolean
    bool i;
    cin >> i;
    cout << i << endl;
    
    // read char
    char j;
    cin >> j;
    cout << j << endl;
    
    return 0;
}