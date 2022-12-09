#include<iostream>
#include<fstream>
#include<map>
using namespace std;

int main(){
    ifstream file;
    file.open("rockPaperScissors.txt");

    // A, X= Rock 1
    // B, Y = Paper 2
    // C, Z = Scissor 3
    // loss = 0, draw = 3, win = 6
    // win = X C, Y A, Z B
    map<char, int> points;
    points.insert({'X', 1});
    points.insert({'Y', 2});
    points.insert({'Z', 3});
    long totalScore = 0;

    string line;
    while(!file.eof()){
        getline(file, line);
        char opponent = line[0];
        char mine = line[2];
        //draw
        if((opponent == 'A' && mine == 'X') || (opponent == 'B' && mine == 'Y') || (opponent == 'C' && mine == 'Z')){
            totalScore += (points[mine] + 3);
        }
        //win
        else if((mine == 'X' && opponent == 'C') || (opponent == 'A' && mine == 'Y') || (opponent == 'B' && mine == 'Z')){
            totalScore += (points[mine] + 6);
        }
        else{
            totalScore += points[mine];
        }
    }
    cout<<totalScore<<endl;    
    return 0;
}