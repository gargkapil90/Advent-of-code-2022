#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    fstream file;
    file.open("deviceSize.txt");
    string line;
    vector<string> path;
    map<string, int> directiory;
    while(!file.eof()){
        getline(file, line);
        stringstream s_stream(line);
        vector<string> temp;
        while(s_stream.good()){
            string substr;
            getline(s_stream, substr, ' ');
            temp.push_back(substr);
        }
        if(temp[0] == "$"){
            if(temp[1] == "ls"){
                continue;
            }else if(temp[1] == "cd"){
                if(temp[2] == ".."){
                    path.pop_back();
                }else{
                    path.push_back(temp[2]);
                }
            }
        }
        else{            
            if(temp[0] == "dir"){
                continue;
            }else{
                int size = stoi(temp[0]);
                string str;
                for(int i = 0; i < path.size(); i++){
                    str = str + path[i];
                    directiory[str] += size;
                }      
            } 
        }
    }
    int ans = 0;
    for(auto dir : directiory){
        if(dir.second <= 100000)
            ans += dir.second;
    }
    cout<<ans<<endl;
    return 0;
}