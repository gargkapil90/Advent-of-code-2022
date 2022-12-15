#include<iostream>
#include<fstream>
#include<set>
#include<vector>
using namespace std;

vector<vector<char>> draw(6, vector<char>(40, '?'));
int registerX = 1;
int cycle = 0;
int signalStrength = 0;
set<int> cycles = {20, 60, 100, 140, 180, 220};

void handle_tick(){
    draw[(cycle-1)/40][(cycle-1)%40] = abs(registerX - ((cycle -1)%40)) <= 1 ? '#' : ' ';
    if(cycles.find(cycle) != cycles.end()){
        signalStrength += cycle*registerX;
    }
}

int main(){
    fstream file;
    file.open("signalStrength.txt");
    string line;    
    
    while(!file.eof()){
        getline(file, line);
        int space = line.find(" ");
        string instruction = line.substr(0,4);
        int value = space != -1 ? stoi(line.substr(5)) : 0;
        if(instruction == "noop"){
            cycle++;
            handle_tick();                      
        }else{
            cycle++;
            handle_tick();
            cycle++;
            handle_tick();
            registerX += value;
        }
    }
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 40; j++){
            cout<<draw[i][j];
        }
        cout<<endl;
    }
    return 0;
}