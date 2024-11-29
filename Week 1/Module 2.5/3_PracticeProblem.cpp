#include <bits/stdc++.h>
using namespace std;
vector <int> v[1005];
// bool visAr[1005];

// void numberOfConnectedNode(int N)
// {
//     queue<int> q;
//     q.push(N);
//     visAr[N] = true;
    
//     while(!q.empty())
//     {
//         int par = q.front();
//         q.pop();
        
//         for(int child : v[par])
//         {
//             if(visAr[child] == false)
//             {
//                 q.push(child);
//                 visAr[child] = true;
//             }
//         }
//     }
// }

int main()
{
    int n, e;
    cin >> n >> e;
    while(e--)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    int N;
    cin >> N;

    // memset(visAr, false, sizeof(visAr));
    // numberOfConnectedNode(N);

    cout << v[N].size() << endl;

    return 0;
}
