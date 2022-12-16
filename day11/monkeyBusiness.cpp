#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Monkey
{
public:
    vector<int> items;
    string operation;
    string operationValue;
    int divideBy;
    vector<int> monkeyNumber;
    int inspectCount = 0;
    void throwItem(Monkey m, int item)
    {
        m.items.push_back(item);
    }
};
int main()
{
    fstream file;
    file.open("monkeyBusiness.txt");
    string line;
    vector<Monkey> monkeys;
    int monkeyIndex = -1;
    while (!file.eof())
    {
        getline(file, line);
        stringstream s_stream(line);
        // cout << line << endl;
        vector<string> temp;
        while (s_stream.good())
        {
            string substr;
            getline(s_stream, substr, ' ');
            temp.push_back(substr);
        }

        if (temp[0] == "Monkey")
        {
            Monkey m;
            monkeyIndex++;
            // cout<<"Money : "<<monkeyIndex<<endl;
            
            monkeys.push_back(m);
            // cout<<"InspectCount : "<<++monkeys[monkeyIndex].inspectCount<<endl;;
            while (!file.eof())
            {
                getline(file, line);
                // cout << line << endl;
                // cout<<line.length()<<endl;
                if (line.length() == 0)
                    break;
                stringstream s_stream1(line);
                vector<string> temp1;
                while (s_stream1.good())
                {
                    string substr1;
                    getline(s_stream1, substr1, ' ');
                    temp1.push_back(substr1);
                    // cout << substr1 << ",";
                }                

                if (temp1[2] == "Starting")
                {
                    // cout<<"Items: ";
                    for (int i = 4; i < temp1.size(); i++)
                    {
                        // cout<<stoi(temp1[i])<<" ";
                        monkeys[monkeyIndex].items.push_back(stoi(temp1[i]));
                    }
                    // cout<<endl;
                }
                else if (temp1[2] == "Operation:")
                {
                    // cout<<"Operation: "<<temp1[6]<<" "<<temp1[7]<<endl;
                    monkeys[monkeyIndex].operation = temp1[6];
                    monkeys[monkeyIndex].operationValue = temp1[7];
                }
                else if (temp1[2] == "Test:"){
                    monkeys[monkeyIndex].divideBy = stoi(temp1[5]);
                }
                else
                {
                    // cout<<"Money number: "<<stoi(temp1[9])<<endl;
                    monkeys[monkeyIndex].monkeyNumber.push_back(stoi(temp1[9]));
                }
            }
        }
    }

    for (int i = 1; i <= 20; i++)
    {
        for (int m = 0; m < monkeys.size(); m++)
        {
            vector<int> items = monkeys[m].items;
            for (int j = 0; j < items.size(); j++)
            {
                monkeys[m].inspectCount++;
                
                int worryLevel = items[j];
                string op = monkeys[m].operation;
                string opVal = monkeys[m].operationValue;
                int divideBy = monkeys[m].divideBy;
                int val = (opVal == "old") ? items[j] : stoi(opVal);
                if (op == "*")
                {
                    worryLevel *= val;
                }
                else
                {
                    worryLevel += val;
                }
                worryLevel /= 3;
                if(worryLevel%divideBy == 0){
                    monkeys[monkeys[m].monkeyNumber[0]].items.push_back(worryLevel);
                }else{
                    monkeys[monkeys[m].monkeyNumber[1]].items.push_back(worryLevel);
                }
            }
            monkeys[m].items.clear();
        }
    }
    vector<int> inspects;
    for(int m = 0; m < monkeys.size(); m++){
        inspects.push_back(monkeys[m].inspectCount);
    }
    sort(inspects.begin(), inspects.end());
    int m = inspects.size();
    cout<<inspects[m-1]*inspects[m-2];
    return 0;
}