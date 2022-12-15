#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <set>
#include <map>
using namespace std;

bool isTouching(int *head, int *tail)
{
    if (abs(head[0] - tail[0]) <= 1 && abs(head[1] - tail[1]) <= 1)
        return true;
    return false;
}
void move(int *head, int *tail, int right[]){
    head[0] += right[0];
    head[1] += right[1];
    if(!isTouching(head, tail)){
        int tailX = head[0] == tail[0] ? 0 : (head[0] - tail[0])/abs(head[0] - tail[0]);
        int tailY = head[1] == tail[1] ? 0 : (head[1] - tail[1])/abs(head[1] - tail[1]);
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
    int tail[] = {0, 0};

    set<pair<int, int>> s;
    s.insert(make_pair(tail[0], tail[1]));
    while (!file.eof())
    {
        getline(file, line);
        char dir = line[0];
        int steps = stoi(line.substr(2));
        for(int i = 1; i <= steps; i++){
            if(dir == 'R'){
                move(head, tail, right);
            }
            else if(dir == 'L'){
                move(head, tail, left);
            }
            else if(dir == 'U'){
                move(head, tail, up);
            }
            else if(dir == 'D'){
                move(head, tail, down);
            }
            s.insert(make_pair(tail[0], tail[1]));
        }
    }
    cout<<s.size()<<endl;
    return 0;
}