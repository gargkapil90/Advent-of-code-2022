#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;

int main(){
    fstream file;
    file.open("sensorsAndBeacons.txt");
    string line;
    vector<pair<int,int>> sensors;
    vector<pair<int,int>> beacons;
    while(!file.eof()){
        getline(file, line);
        stringstream s_stream(line);
        //  cout << line << endl;
        vector<string> temp;        
        while (s_stream.good())
        {
            string substr;
            getline(s_stream, substr, ' ');
            temp.push_back(substr);
            
        }
        int sx = stoi(temp[2].substr(2));
        int sy = stoi(temp[3].substr(2));
        int bx = stoi(temp[8].substr(2));
        int by = stoi(temp[9].substr(2));
        //cout<<sx<<" "<<sy<<" "<<bx<<" "<<by<<endl;
        sensors.push_back(make_pair(sx, sy));
        beacons.push_back(make_pair(bx, by));
    }
    int n = sensors.size();
    vector<int> distance;
    for(int i = 0; i < n; i++){
        distance.push_back(abs(sensors[i].first - beacons[i].first) +  abs(sensors[i].second - beacons[i].second));
    }

    int Y = 2000000;

    vector<pair<int,int>> intervals;

    for(int i = 0; i < n; i++){
        int dx = distance[i] - abs(sensors[i].second - Y);
        if(dx <= 0)
            continue;
        intervals.push_back({sensors[i].first - dx, sensors[i].first + dx});
    }

    vector<int> allowedX;
    for(int i = 0; i < n; i++){
        if(beacons[i].second == Y)
            allowedX.push_back(beacons[i].first);
    }

    int mini = INT_MAX;
    int maxi = INT_MIN;
    for (int i = 0; i < intervals.size(); i++)
    {
        mini = min(mini, intervals[i].first);
        maxi = max(maxi, intervals[i].second);
    }
    
    int ans = 0;
    for (int i = mini; i < maxi; i++)
    {
        for(int j = 0; j < allowedX.size(); j++){
            if(i == allowedX[j])
                break;
        }

        for (int j = 0; j < intervals.size(); j++)
        {
            if(i >= intervals[j].first && i <= intervals[j].second){
                ans++;
                break;
            }
        }
        
    }
    
    cout<<ans<<endl;

    return 0;
}