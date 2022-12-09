#include<iostream>
#include<fstream>
using namespace std;

int main(){
    ifstream file;
    file.open("maximumCaloriesElf.txt");
    string line;    
    int maxi = INT_MIN;
    int total = 0;
    while(!file.eof()){
        getline(file, line);
        if(line.length() != 0){
            int num = stoi(line);
            total += num;
        }else{
            if(total > maxi){
                maxi = total; 
            }
            total = 0;
        }              
    }
    if(total > maxi){
        maxi = total;
    }
    cout<<maxi<<endl;
    file.close();
    return 0;
}