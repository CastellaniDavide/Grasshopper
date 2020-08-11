/*
 * This template is valid both in C and in C++,
 * so you can expand it with code from both languages.
 */

#include <bits/stdc++.h>

using namespace std;

// constraints
#define MAXN 100000
#define MAXM 1000000

// input data
int N, M, i,j;
vector<vector<int> > graph;
int A[MAXM], B[MAXM];

int main()
{
    ios_base::sync_with_stdio(false);
//  uncomment the following lines if you want to read/write from files
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin>>N>>M;
    graph.resize(N);

    for(i=0; i<M; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }



    int sol=1;
    bool visited[N];
    bool intermedio[N];

    for(i=0; i<N; i++)
    {
        visited[i]=false;
        intermedio[i]=false;
    }

    queue<int> q;

    q.push(0);
    visited[0] = true;

    while (!q.empty())
    {

        int f = q.front();
        q.pop();

        for (auto &u : graph[f])
        {
            if(!intermedio[u])
            {
                intermedio[u]=true;
                for(auto &v : graph[u])
                {
                    if (!visited[v])
                    {

                        q.push(v);
                        visited[v] = true;
                        sol++;
                    }
                }
            }
        }
    }

    /*
    // insert your code here
    for(i=0; i<N; i++)
    {
       for(j=0; j<graph[i].size(); j++)
       {
           cout<<graph[i][j]<<endl;
       }
    }*/

    cout<<sol<<endl;
    //printf("%d\n", 42); // change 42 with actual answer
    return 0;
}
