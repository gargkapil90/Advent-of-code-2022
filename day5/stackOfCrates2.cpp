#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
using namespace std;
int main(){
    fstream file;
    file.open("stackOfCrates.txt");
    string line;
    string ans = "";
    bool stackInput = true;
    vector<vector<char>> v;
    while(stackInput){
        getline(file, line);
        if(line.length() != 0){
            vector<char> s;
            int n = line.length();
            for(int i = 0; i < n; i++){
                s.push_back(line[i]);
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
        int moveFromSize = v[moveFromIndex].size();

        for(int i = moveFromSize-numbeOfMovements; i < moveFromSize; i++){
            v[moveToIndex].push_back(v[moveFromIndex][i]);
        }
        for(int i = 0; i < numbeOfMovements; i++){
            v[moveFromIndex].pop_back();
        }
        // for(int i = 1; i <= numbeOfMovements; i++){
        //     char top = v[moveFromIndex].top();
        //     v[moveFromIndex].pop();
        //     v[moveToIndex].push(top);
        // }
    }
    int size = v.size();
    for(int i = 0; i < size; i++){
        int n = v[i].size();
        ans += v[i][n-1];
    }
    cout<<ans<<endl;
    
    
    return 0;
}