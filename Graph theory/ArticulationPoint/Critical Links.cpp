# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e4;

int n;
vector<int> v[N];
int seen[N];
int fup[N], tin[N];
int  timer;
set<pair<int,int> > bridge;

void dfs(int u, int p){
    seen[u] = 1;
    fup[u] = tin[u] = timer++;
    
    for(int i = 0; i < v[u].size(); i++){
        int to = v[u][i];
        if(to == p)continue;
        if(seen[to]) fup[u] = min(fup[u], tin[to]);
        else{
            dfs(to, u);
            fup[u] = min(fup[u], fup[to]);
            if(tin[u] < fup[to]){
                vector<int> k; k.push_back(u); k.push_back(to);
                sort(k.begin(), k.end());
                bridge.insert(make_pair(k[0],k[1]));
            }
            
        }
    }
   
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

while(cin >> n){                 //cout << n << endl;
  for(int i = 0; i <= n; i++)v[i].clear();
    for(int i = 0; i < n; i++){
        int x, y; cin >> x;                        //cout<<x<<" ";      
        string s; cin >> s;
        int cnt = 0;
        for(int j = 1; j < (s.size()-1); j++)
            cnt = 10 * cnt + (s[j] - '0');                  
        for(int j = 0; j < cnt; j++){
            cin >> y;                                     //cout << y <<" ";
            v[x].push_back(y);
            v[y].push_back(x);
        }                                             //cout<<endl;
    }                                              
    memset(seen, 0, sizeof seen);
    memset(fup, 0, sizeof fup);
    memset(tin, 0, sizeof tin);
    timer = 0;
    bridge.clear();
    for(int i = 0; i < n; i++)
    if(seen[i] == 0) dfs(i,-1);
  
    cout << bridge.size() << " critical links\n";
    for(auto p : bridge) cout << p.first << " - " << p.second << '\n'; cout << '\n';
}
return 0;
}