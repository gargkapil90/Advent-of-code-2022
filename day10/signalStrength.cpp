#include<iostream>
#include<fstream>
#include<set>
using namespace std;

void calcualteStrength(int cycle, set<int> cycles, int registerX, int &strength){
    if(cycles.find(cycle) != cycles.end()){
        strength += cycle*registerX;
    }
}

int main(){
    fstream file;
    file.open("signalStrength.txt");
    string line;
    int registerX = 1;
    int cycle = 0;
    int signalStrength = 0;
    set<int> cycles = {20, 60, 100, 140, 180, 220};
    while(!file.eof()){
        getline(file, line);
        int space = line.find(" ");
        string instruction = line.substr(0,4);
        int value = space != -1 ? stoi(line.substr(5)) : 0;
        if(instruction == "noop"){
            cycle++;
            calcualteStrength(cycle, cycles, registerX, signalStrength);                      
        }else{
            cycle++;
            calcualteStrength(cycle, cycles, registerX, signalStrength);
            cycle++;
            calcualteStrength(cycle, cycles, registerX, signalStrength);
            registerX += value;
        }
    }
    cout<<"Signal Strength: "<<signalStrength<<endl;
    return 0;
}