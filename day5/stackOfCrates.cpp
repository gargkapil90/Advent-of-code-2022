#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include <stack>
using namespace std;
int main(){
    fstream file;
    file.open("stackOfCrates.txt");
    string line;
    string ans = "";
    bool stackInput = true;
    vector<stack<char>> v;
    while(stackInput){
        getline(file, line);
        if(line.length() != 0){
            stack<char> s;
            int n = line.length();
            for(int i = 0; i < n; i++){
                s.push(line[i]);
            }
            v.push_back(s);
        }else{
            stackInput = false;
        }    
       
    }

    while(!file.eof())
    {
        getline(file, line);
        stringstream s_stream(line);
        vector<string> temp;
        while(s_stream.good()){
            string substr;
            getline(s_stream, substr, ' ');
            temp.push_back(substr);
        }
        int moveFromIndex = stoi(temp[3]) - 1;      
        int moveToIndex = stoi(temp[5]) - 1;
        int numbeOfMovements = stoi(temp[1]);
        for(int i = 1; i <= numbeOfMovements; i++){
            char top = v[moveFromIndex].top();
            v[moveFromIndex].pop();
            v[moveToIndex].push(top);
        }
    }
    int size = v.size();
    for(int i = 0; i < size; i++){
        ans += v[i].top();
    }
    cout<<ans<<endl;
    
    
    return 0;
}