#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <set>

using namespace std;

class Solution
{
public:
    int robotSim(vector<int> &commands, vector<vector<int>> &obstacles)
    {
        int x = 0;
        int y = 0;
        unordered_map<string, int> mp;

        for (auto it : obstacles)
        {
            string key = to_string(it[0]) + "+" + to_string(it[1]);
            mp[key]++;
        }
        vector<vector<int>> dire = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        // N E S W
        int res = 0;
        int d = 0;
        for (auto it : commands)
        {
            if (it == -1)
            {
                d = (d + 1) % 4;
            }
            else if (it == -2)
                d = (d - 1) % 4;
            else
            {

                for (int i = 0; i < it; i++)
                {
                    int dx = x + dire[d][0];
                    int dy = y + dire[d][1];
                    string key = to_string(dx) + "+" + to_string(dy);
                    if (mp.find(key) != mp.end())
                        break;
                    x = dx;
                    y = dy;
                    res = max(res, x * x + y * y);
                }
            }
        }
        return res;
    }
};
