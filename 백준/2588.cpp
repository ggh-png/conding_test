#include<iostream> 
#include<string>
#include<vector>
#include<math.h>

using namespace std;


int main()
{
    string a, b; // 숫자 입력 
    vector<int> temp;
    int tmp;
    int answer=0;
    cin >> a >> b;
    for(int i=0; i <= b.size(); i++)
    {
        tmp = stoi(a) * (int)(b[b.size() - i]-48);
        temp.push_back(tmp);
    }
    for(int i=1; i < temp.size(); i++)
    {
        cout << temp[i] << endl;
        temp[i] *= pow(10, (i-1));
    }
    for(int i=1; i < temp.size(); i++)
        answer += temp[i];
    cout << answer << endl;  
}