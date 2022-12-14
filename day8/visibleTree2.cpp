#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
using namespace std;

int main(){
    fstream file;
    file.open("visibleTrees.txt");
    string line;
    vector<vector<int>> mat;
    // map<string, int> directiory;
    while(!file.eof()){
        getline(file, line);
        int n = line.length();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {        
            temp.push_back(line[i] - '0');
        }
        mat.push_back(temp);      
    }
    int count = INT_MIN;
    int row = 1;
    int col = 1;
    int rows = mat.size();
    int cols = mat[0].size();
    for(int i = row; i < rows - 1; i++){

        for(int j = col; j < cols - 1; j++){
            int num = mat[i][j];            
            int left = 0;
            int right = 0;
            int up = 0;
            int down = 0;
            //left
            for(int k = j-1; k >= 0; k--){
                if(mat[i][k] < num){
                    left++;                    
                }else{
                    left++;
                    break;
                }

            }
            //right
            for(int k = j+1; k < cols; k++){
                if(mat[i][k] < num){
                    right++;                    
                }else{
                    right++;
                    break;
                }

            }
            //up
            for(int k = i-1; k >= 0; k--){
                if(mat[k][j] < num){
                    up++;                    
                }else{
                    up++;
                    break;
                }

            }
            //down
            for(int k = i+1; k < rows; k++){
                if(mat[k][j] < num){
                    down++;                    
                }else{
                    down++;
                    break;
                }
            }
            int area = left*right*up*down;
            count = max(count, area);
            
        }
    }    
    cout<<count<<endl;
    return 0;
}