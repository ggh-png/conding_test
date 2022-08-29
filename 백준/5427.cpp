#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// map
int n, m;
int map[1004][1004];
int Jvisited[1004][1004];
int Fvisited[1004][1004];
// joy
int dy[] = {-1, 0, 1, 0};
int dx[] = {0, 1, 0, -1};

// x, y
int x, y, jx, jy, fx, fy;
// q 
queue<pair<int, int>> fq;
queue<pair<int, int>> jq;
vector<string> v;
int main()
{
    int num;
    cin >> num;
    for(int k=0; k < num; k++)
    {
        
        cin >> m >> n;
        // map 이진화 
        for(int i=0; i < n; i++)
        {
            string str;
            cin >> str;
            for(int j=0; j < m; j++)
            {
                char tmp = str[j];
                if(tmp == '#')
                    map[i][j] = 1;
                else if(tmp == '.')
                    map[i][j] = 0;
                else if(tmp == '@')
                {
                    jy = i;
                    jx = j;
                }
                else
                {
                    fq.push({i, j});
                    Fvisited[i][j] = 1;
                }
            }
        }
        
        jq.push({jy, jx});
        Jvisited[jy][jx] = 1;

        // 최단거리 
        while (fq.size())
        {
            fx = fq.front().second;
            fy = fq.front().first;
            fq.pop();

            for(int i=0; i < 4; i++)
            {
                int ny = fy + dy[i];
                int nx = fx + dx[i];
                
                if(ny < 0 || nx < 0|| ny >= n || nx >= m)
                    continue;
                // 벽일 경우, 이미 방문 했을 경우 
                if(map[ny][nx] || Fvisited[ny][nx])
                    continue;
                Fvisited[ny][nx] = Fvisited[fy][fx] + 1;
                fq.push({ny, nx});
            }
        }

        while(jq.size())
        {
            y = jq.front().first;
            x = jq.front().second;
            jq.pop();

            for(int i=0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];
                
                if(ny < 0 || nx < 0|| ny >= n || nx >= m)
                    continue;    
                // 벽일 경우, 이미 방문 했을 경우 
                if(map[ny][nx] || Jvisited[ny][nx])
                    continue;
                Jvisited[ny][nx] = Jvisited[y][x] + 1;
                jq.push({ny, nx});
            }
        }
        // 불을 피해가는 최단거리 값
        for(int i=0; i < n; i++)
            for(int j=0; j < m; j++)
            if(Jvisited[i][j] >= Fvisited[i][j] && Fvisited[i][j])
                    Jvisited[i][j] = 0;    

        long long min = 9999999999;
        for(int i=0; i < n; i++)
        {
            if(i == 0 || i == n-1)
            {
                for(int j=0; j < m; j++)
                    if(min > Jvisited[i][j] && Jvisited[i][j])
                        min = Jvisited[i][j];
            }
            else
            {
                if(min > Jvisited[i][0] && Jvisited[i][0])
                    min = Jvisited[i][0];
                else if(min > Jvisited[i][m-1] && Jvisited[i][m-1])
                    min = Jvisited[i][m-1];
            }
        }

        // map 출력
        // cout << "---------------" << endl;
        // for(int i=0; i < n; i++)
        // {
        //     for(int j=0; j < m; j++)
        //     {
        //        cout << Jvisited[i][j] << " ";
        //     }   
        //     cout << endl;
        // }
        // 출구가 존재하면
        if(min != 9999999999)
            v.push_back(to_string(min));
        else
            v.push_back("IMPOSSIBLE");
        for(int i=0; i < n+4; i++)
            for(int j=0; j < m+4; j++)
            {
                Fvisited[i][j] = 0;
                Jvisited[i][j] = 0;
                map[i][j] = 0;
            }
        // 초기화      
        while(jq.size())
            jq.pop();
        while(fq.size())
        fq.pop();
        
    }
    for(auto &el : v)
        cout << el << endl;


    return 0;
}