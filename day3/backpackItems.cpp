#include<iostream>
#include<fstream>
#include<map>

using namespace std;
int main(){
    fstream file;
    file.open("backpackItems.txt");
    string line;
    string priority = "";
    int ans = 0;
    while (!file.eof())
    {
        getline(file, line);
        int n = line.length();
        int mid = n/2;
        map<char, int> item;
        for(int i = 0; i < mid; i++){
            item[line[i]]++;
        }
        for(int i = mid; i < n; i++){
            if(item.count(line[i])){
                priority += line[i];
                break;
            }
        }
        
    }

    for(int i = 0; i < priority.length(); i++){
        if(priority[i] >= 'a' && priority[i] <= 'z'){
            ans += (priority[i] - 96);
        }else{
            ans += (priority[i] - 38);
        }
    }
    cout<<ans<<endl;
    return 0;
}