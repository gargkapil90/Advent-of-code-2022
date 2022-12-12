#include<iostream>
#include<fstream>
#include<set>
using namespace std;

int main(){
    fstream file;
    file.open("tuningTrouble.txt");
    string line;
    
    while(!file.eof()){
        getline(file, line);
        int n = line.length();
        for(int i = 0; i < n; i++){
            set<char> st;
            if(i-13 >= 0){
                for(int j = i; j >= i-13; j--){
                    st.insert(line[j]);
                }                
            }
            if(st.size() == 14){
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}