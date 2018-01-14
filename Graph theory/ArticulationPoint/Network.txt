# include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;

int n;
vector<int> v[N];
int seen[N];
int fup[N], tin[N];
int cnt, timer;

set<int> cut_ver;
void dfs(int u, int p){ //cout<<p<<"->"<<u<<"\n";
    seen[u] = 1;
    fup[u] = tin[u] = timer++;
    int children = 0;
    for(int i = 0; i < v[u].size(); i++){
        int to = v[u][i];
        if(to == p)continue;
        if(seen[to]) fup[u] = min(fup[u], tin[to]);
        else{
            dfs(to, u);
            fup[u] = min(fup[u], fup[to]);
            if(p != -1 and tin[u] <= fup[to]){cut_ver.insert(u);}
            children++;
        }
    }
    if(p == -1 and children > 1)cut_ver.insert(u);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
while(1){
    cin >> n;  //cout<<n<<endl; //
    if(n == 0) break;
    memset(seen, 0, sizeof seen);
    memset(fup, 0, sizeof fup);
    memset(tin, 0, sizeof tin);
    
    for(int i = 0; i < N; i++) v[i].clear();
    
   string t; getline(cin,t);

    while(1){
        string s; getline(cin, s); //cout<<s<<endl;
        int x;
        istringstream is(s);
        vector<int> l;
        while(is >> x) l.push_back(x);
        x = l[0];                             //cout<<x<<" ";  //
        if(x==0)break;
        for(int i = 1; i < l.size(); i++){
            int y = l[i];  
                                                 // cout<<y<<" ";   //
            v[x].push_back(y);
            v[y].push_back(x);
        } 
                                    //       cout<<"\n";           //
    }
   /// getline(cin,t);
   // cout<<endl;
    cnt = 0; timer = 0; cut_ver.clear(); 
    dfs(1, -1);            //         cout<<"+++++++++++\n";
    cnt = cut_ver.size();
    cout << cnt << '\n';
  }
  return 0;
}