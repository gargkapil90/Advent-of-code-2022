#include<iostream>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream file;
    file.open("maximumTop3Calories.txt");
    string line;    
    vector<int> calories;
    int total = 0;
    while(!file.eof()){
        getline(file, line);
        if(line.length() != 0){
            int num = stoi(line);
            total += num;
        }else{
            calories.push_back(total);
            total = 0;
        }              
    }
    calories.push_back(total);
    sort(calories.begin(), calories.end(), greater<int>());
    int n = calories.size();
    for(int i = 0; i < n; i++){
        cout<<calories[i]<<endl;
    }
    int backup = calories[0] + calories[1] + calories[2];
    cout<<backup<<endl;
    file.close();
    return 0;
}