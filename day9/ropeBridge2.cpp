#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include<vector>
using namespace std;

bool isTouching(int *head, int *tail)
{
    if (abs(head[0] - tail[0]) <= 1 && abs(head[1] - tail[1]) <= 1)
        return true;
    return false;
}
void move(int *head, int *tail)
{   
    if (!isTouching(head, tail))
    {
        int tailX = head[0] == tail[0] ? 0 : (head[0] - tail[0]) / abs(head[0] - tail[0]);
        int tailY = head[1] == tail[1] ? 0 : (head[1] - tail[1]) / abs(head[1] - tail[1]);
        tail[0] += tailX;
        tail[1] += tailY;
    }
}

int main()
{
    fstream file;
    file.open("ropeBridge.txt");
    string line;
    int right[] = {0, 1};
    int left[] = {0, -1};
    int up[] = {-1, 0};
    int down[] = {1, 0};

    int head[] = {0, 0};
    // vector<vector<int, int>> tail;
    // for(int i = 1; i <= 10; i++){
    //     tail.push_back({0, 0});
    // }
    int tail[9][2] = {{0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}, {0, 0}};

    set<pair<int, int>> s;
    s.insert(make_pair(tail[8][0], tail[8][1]));
    while (!file.eof())
    {
        getline(file, line);
        char dir = line[0];
        int steps = stoi(line.substr(2));
        for (int i = 1; i <= steps; i++)
        {
            if (dir == 'R')
            {      
                head[0] += right[0];
                head[1] += right[1];
                int head1[2] = {head[0], head[1]};
                for(int i = 0; i < 9; i++){
                    move(head1, tail[i]);
                    head1[0] = tail[i][0];
                    head1[1] = tail[i][1];
                }
                
            }
            else if (dir == 'L')
            {
                head[0] += left[0];
                head[1] += left[1];
                int head1[2] = {head[0], head[1]};
                for(int i = 0; i < 9; i++){
                    move(head1, tail[i]);
                    head1[0] = tail[i][0];
                    head1[1] = tail[i][1];
                }
            }
            else if (dir == 'U')
            {
                head[0] += up[0];
                head[1] += up[1];
                int head1[2] = {head[0], head[1]};
                for(int i = 0; i < 9; i++){
                    move(head1, tail[i]);
                    head1[0] = tail[i][0];
                    head1[1] = tail[i][1];
                }
            }
            else if (dir == 'D')
            {
                head[0] += down[0];
                head[1] += down[1];
                int head1[2] = {head[0], head[1]};
                for(int i = 0; i < 9; i++){
                    move(head1, tail[i]);
                    head1[0] = tail[i][0];
                    head1[1] = tail[i][1];
                }
            }
            s.insert(make_pair(tail[8][0], tail[8][1]));
        }
    }
    cout << s.size() << endl;
    return 0;
}