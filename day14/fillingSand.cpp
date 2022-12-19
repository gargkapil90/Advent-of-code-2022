#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>

using namespace std;
typedef pair<int, int> pairs;
set<pairs> filled;
int max_y = INT_MIN;

bool settle_a_sand()
{
    int x = 500, y = 0;
    while (y <= max_y)
    {
        pair temp = make_pair(x, y + 1);
        if (filled.find(temp) == filled.end())
        {
            y += 1;
            continue;
        }
        temp = make_pair(x - 1, y + 1);
        if (filled.find(temp) == filled.end())
        {
            x -= 1;
            y += 1;
            continue;
        }
        temp = make_pair(x + 1, y + 1);
        if (filled.find(temp) == filled.end())
        {
            x += 1;
            y += 1;
            continue;
        }
        temp = make_pair(x, y);
        filled.insert(temp);
        return true;
    }
    return false;
};

int main()
{
    fstream file;
    file.open("fillingSand.txt");
    string line;

    while (!file.eof())
    {
        getline(file, line);
        stringstream s_stream(line);
        string delimiter_char = " -> ";
        size_t pos = 0;

        vector<string> temp;
        string substr;
        while ((pos = line.find(delimiter_char)) != std::string::npos)
        {
            substr = line.substr(0, pos);
            temp.push_back(substr);
            line.erase(0, pos + delimiter_char.length());
        }
        temp.push_back(line);

        vector<pair<int, int>> coordinates;
        int t = temp.size();
        for (int i = 0; i < t; i++)
        {
            int index = temp[i].find(",");
            int x = stoi(temp[i].substr(0, index));
            int y = stoi(temp[i].substr(index + 1));
            coordinates.push_back({x, y});
        }

        int cor = coordinates.size();
        for (int i = 1; i < cor; i++)
        {
            int cx = coordinates[i].first;
            int cy = coordinates[i].second;
            int px = coordinates[i - 1].first;
            int py = coordinates[i - 1].second;

            if (cx != px)
            {
                for (int j = min(cx, px); j <= max(cx, px); j++)
                {
                    pair x = make_pair(j, cy);
                    filled.insert(x);
                }
            }

            if (cy != py)
            {
                for (int j = min(cy, py); j <= max(cy, py); j++)
                {
                    pair x = make_pair(cx, j);
                    filled.insert(x);
                }
            }
        }
    }

    int f = filled.size();
    for (auto s : filled)
    {
        if (max_y < s.second)
        {
            max_y = s.second;
        }
    }

    int ans = 0;

    while (true)
    {
        bool settled = settle_a_sand();
        if (!settled)
            break;
        ans++;
    }
    cout << ans << endl;

    return 0;
}