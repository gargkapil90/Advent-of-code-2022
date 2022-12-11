#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    fstream file;
    file.open("sectionOverlap2.txt");
    string line;
    int count = 0;
    while(!file.eof()){
        getline(file, line);
        int commaIndex  = line.find(',');
        string first = line.substr(0, commaIndex);
        string second = line.substr(commaIndex + 1);
        int pos1 = first.find('-');
        int num1Start = stoi(first.substr(0,pos1));
        int num1End = stoi(first.substr(pos1+1));

        int pos2 = second.find('-');
        int num2Start = stoi(second.substr(0,pos2));
        int num2End = stoi(second.substr(pos2+1));
        if(((num2Start >= num1Start) && (num2Start <= num1End))
            || ((num2End >= num1Start) && (num2End <= num1End))
            || ((num1Start >= num2Start) && (num1Start <= num2End))
            || ((num1End >= num2Start) && (num1End <= num2End))){
                count++;
            }
    }
    cout<<count<<endl;
    return 0;
}