#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    
    int n, k;
    cin >> n >> k;
    vector<int> cities(n);
    for(int i = 0; i < n; ++i)
        cin >> cities[i];
    
    // logic here
    int last_on = -k;
    int earliest_loc = -1;
    int counter = 0;
    
    for(int i = 0; i < n; ++i)
    {
        // check current city exceed limit
        if(i - last_on > 2 * k - 1)
        {
            
            //cout << i << " " << last_on << " " << earliest_loc << endl;
            
            if(earliest_loc != -1 && earliest_loc - last_on <= 2 * k - 1)
            {
                // switch on
                ++counter;
                last_on = earliest_loc;
                
                earliest_loc = i;
                while(earliest_loc < n && cities[earliest_loc] == 0) ++earliest_loc; // find next city with tower
                i = earliest_loc - 1; // update latest location to current earlest_loc
            }
            else {
                // fail to find such a location
                counter = -1;
                break;
            }
        }
        else // can push limit further
            if(cities[i] == 1)
            {
                //cout << i << endl;
                earliest_loc = i;
            }
    }
    
    //cout << counter << endl;
    
    // last earliest_loc
    if(counter != -1 && earliest_loc != -1 && earliest_loc != n && n - 1 - earliest_loc < k)
        ++counter;
    
    cout << counter << endl;
    
    return 0;
}
