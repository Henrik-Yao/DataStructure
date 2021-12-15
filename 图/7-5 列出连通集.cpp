#include<bits/stdc++.h>
using namespace std;
 
bool g[12][12]; 
bool vd[12]; 
 
void dfs(int u, int n){
    if (!vd[u]){
        vd[u] = true;
        cout << u << " ";
        for (int v = 0; v < n; v++)
            if (g[u][v] && !vd[v])
                dfs(v, n); 
    }
}
 
void bfs(int u, int n){
    queue<int> q;
    vd[u] = true;
    q.push(u);
    while (!q.empty()){
        u = q.front();
        q.pop();
        cout << u << " ";
        for (int v = 0; v < n; v++){
            if (g[u][v] && !vd[v]){
                q.push(v);
                vd[v] = true;
            }
        } 
    }
}
 
int main() {
    int n, e;
    int a, b;
    memset(g, 0, sizeof(g));
    memset(vd, 0, sizeof(vd));
    
    cin >> n >> e;
    for (int i = 0; i < e; i++){
        cin >> a >> b;
        g[a][b] = g[b][a] = true;
    }
    
    for (int i = 0; i < n; i++){ 
        if (!vd[i]){
            cout << "{ ";
            dfs(i, n);
            cout << "}" << endl;
        }
    }
    
    memset(vd, 0, sizeof(vd)); 
    for (int i = 0; i < n; i++){
        if (!vd[i]){
            cout << "{ ";
            bfs(i, n);
            cout << "}" << endl;
        }
    }
    
    return 0;
}
