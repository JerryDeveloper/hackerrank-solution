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
    int n;
    cin >> n;
    
    const int board_size = n;
    typedef tuple<int, int, int> step;
    
    int res[board_size - 1][board_size - 1];
    for(int a = 0; a < board_size - 1; ++a)
        for(int b = 0; b < board_size - 1; ++b)
            res[a][b] = -1;
    
    
    for(int i = 1; i < n; ++i)
    {
        for(int j = 1; j < n; ++j)
        {
            deque<step> nodes = { make_tuple(0, 0, 0) };  // (x, y, number of moves done)
            
            bool board[board_size][board_size];
            for(int a = 0; a < board_size; ++a)
                for(int b = 0; b < board_size; ++b)
                    board[a][b] = false;
            
            /*
            cout << "----------------------" << endl;
            
            for(int a = 0; a < board_size; ++a)
            {
                for(int b = 0; b < board_size; ++b)
                {
                    cout << board[a][b] << " ";
                }
                cout << endl;
            }
            
            cout << "----------------------" << endl;
            */
            
            while(nodes.size() != 0)
            {
                step cur = nodes[0];
                nodes.pop_front();
                int cur_x = get<0>(cur);
                int cur_y = get<1>(cur);
                int prev_num = get<2>(cur);
                
                //cout << cur_x << " " << cur_y << " " << prev_num << endl;
                
                if(board[cur_x][cur_y])
                {
                    // visited
                    continue;
                }
                if(cur_x == n - 1 && cur_y == n - 1)
                {
                    res[i - 1][j - 1] = prev_num;
                    break;
                }
                
                board[cur_x][cur_y] = true;
                
                int xmoves[8] = { i, i, -i, -i, j, j, -j, -j };
                int ymoves[8] = { j, -j, j, -j, i, -i, i, -i };
                int limit = (i == j)?4:8;
                for(int k = 0; k < limit; ++k)
                {
                    int next_x = cur_x + xmoves[k];
                    int next_y = cur_y + ymoves[k];
                    //cout << "next location: " << next_x << " " << next_y << endl;
                    if(next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && !board[next_x][next_y])
                    {
                        //cout << "neighbour: " << cur_x + xmoves[k] << " " << cur_y + ymoves[k] << " " << prev_num + 1 << endl;
                        nodes.push_back( make_tuple(cur_x + xmoves[k], cur_y + ymoves[k], prev_num + 1) );
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n - 1; ++i)
    {
        for(int j = 0; j < n - 1; ++j)
            cout << res[i][j] << " ";
        cout << endl;
    }
        
    
    return 0;
}
