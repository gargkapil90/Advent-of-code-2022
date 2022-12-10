#include<iostream>
#include<fstream>
#include<map>
#include<set>
using namespace std;
int main(){
    fstream file;
    file.open("backpackItems2.txt");
    string line;
    int count = 0;
    string badge;
    map<char, int> mp;
    while(!file.eof()){
        getline(file, line); 
        int n = line.length();      
        count++;
        set<char> s;    
        for(int i = 0; i < n; i++){
            if((mp.find(line[i]) == mp.end()) || (s.find(line[i]) == s.end())){
                s.insert(line[i]);
                mp[line[i]]++;
            }
        }
            
        if(count == 3){
            count = 0;
            for(auto m : mp){
                if(m.second == 3)
                    badge += m.first;
            }
            mp.clear();
        }        
    }
    int m = badge.length();
    int ans = 0;
    for(int i = 0; i < m; i++){
        char ch = badge[i];
        if(ch >= 'a' && ch <= 'z')
            ans += (ch - 'a' + 1);
        else{
            ans += (ch - 'A' + 27);
        }
    }
    cout<<ans<<endl;
    return 0;
}