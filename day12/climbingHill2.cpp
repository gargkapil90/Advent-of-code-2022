#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    fstream file;
    file.open("climbingHill.txt");
    string line;
    vector<vector<char>> inputs;
    
    queue<pair<int, int>> startingPoints;
    while (!file.eof())
    {
        getline(file, line);
        int n = line.length();
        vector<char> temp;
        for (int i = 0; i < n; i++)
        {
            temp.push_back(line.at(i));
        }
        inputs.push_back(temp);
    }
    int rows = inputs.size();
    int cols = inputs[0].size();

    pair<int, int> start;
    pair<int, int> end;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (inputs[i][j] == 'S' || inputs[i][j] == 'a')
            {
                startingPoints.push({i, j});
            }
            else if (inputs[i][j] == 'E')
            {
                end.first = i;
                end.second = j;
            }
        }
    }

    vector<vector<int>> elevation(rows, vector<int>(cols, 0));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (inputs[i][j] == 'S')
            {
                elevation[i][j] = 1;
            }
            else if (inputs[i][j] == 'E')
            {
                elevation[i][j] = 26;
            }
            else
            {
                elevation[i][j] = (inputs[i][j] - 'a') + 1;
            }
        }
    }

    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int ans = INT_MAX;

    while (!startingPoints.empty())
    {
        pair<int, int> frontStartingPoint = startingPoints.front();
        startingPoints.pop();

        queue<pair<pair<int, int>, int>> q;
        q.push({{frontStartingPoint.first, frontStartingPoint.second}, 0});

        vector<vector<int>> vis(rows, vector<int>(cols, 0));
        vis[frontStartingPoint.first][frontStartingPoint.second] == 1;

        while (!q.empty())
        {
            pair<pair<int, int>, int> front = q.front();
            q.pop();
            int r = front.first.first;
            int c = front.first.second;
            int d = front.second;
            if (inputs[r][c] == 'E')
            {
                ans = min(ans, d);
                break;
            }
            for (int i = 0; i < 4; i++)
            {
                pair<int, int> dir = dirs[i];
                int rr = r + dir.first;
                int cc = c + dir.second;
                if ((rr >= 0 && rr < rows) && (cc >= 0 && cc < cols) && (elevation[rr][cc] <= elevation[r][c] + 1) && vis[rr][cc] == 0)
                {
                    q.push({{rr, cc}, d + 1});
                    vis[rr][cc] = 1;
                }
            }
        }
    };

    cout << ans << endl;
    return 0;
}