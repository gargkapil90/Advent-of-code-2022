#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main(){
    ifstream file;
    file.open("rockPaperScissors2.txt");

    // A, X= Rock 1
    // B, Y = Paper 2
    // C, Z = Scissor 3
    // loss = 0, draw = 3, win = 6
    // win = X C, Y A, Z B
    // x = loss, y = draw, z = win
    map<char, int> points;
    points.insert({'X', 1});
    points.insert({'Y', 2});
    points.insert({'Z', 3});

      map<char, char> draw;
    draw.insert({'A', 'X'});
    draw.insert({'B', 'Y'});
    draw.insert({'C', 'Z'});

      map<char, int> win;
    win.insert({'A', 'Y'});
    win.insert({'B', 'Z'});
    win.insert({'C', 'X'});

      map<char, int> loss;
    loss.insert({'A', 'Z'});
    loss.insert({'B', 'X'});
    loss.insert({'C', 'Y'});
    long totalScore = 0;

    string line;
    while(!file.eof()){
        getline(file, line);
        char opponent = line[0];
        char mine = line[2];
        
        if(mine == 'X'){//loss
           totalScore += points[loss[opponent]];
        }
        else if(mine == 'Y'){ // Draw
            totalScore += (points[draw[opponent]] + 3);
        }else{//win
            totalScore += (points[win[opponent]] + 6);
        }        
    }
    cout<<totalScore<<endl;    
    return 0;
}