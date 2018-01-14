#include <bits/stdc++.h>
using namespace std;
#define N 405
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;

int s, c;
//vi g[N];

int par[N];
piii edge[N*N];

map<string, int> id;
//map<int, string> di[N];

int find(int x){
  return x == par[x] ? x : par[x] = find(par[x]);
}
bool add(int x, int y){
  int xx = find(x), yy = find(y);
  if(xx == yy) return false;
  if(rand()&1)swap(xx, yy);
  par[xx] = yy;
  return true;
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
while(1){
  cin >> s >> c; if(s + c == 0) break;
  id.clear(); //di.clear();
  for(int i = 0; i < s; i++){
    string t; cin >> t; id[t] = i; //di[i] = t;
  }
  for(int i = 0; i < N; i++){
    par[i] = i; //g[i].clear();
  }
  
  for(int i = 0; i < c; i++){
    int w; string s1, s2; cin >> s1 >> s2; cin >> w;
    int u = id[s1], v = id[s2];
    edge[i] = mp(w, mp(u,v));
  }
  int mst = 0;
  sort(edge, edge + c);
  for(int i = 0; i < c; i++){
    int w = edge[i].F;
    int u = edge[i].S.F;
    int v = edge[i].S.S; //printf("%d %d %d\n",u,v,w);
    if(add(u,v)){ //printf("%d %d %d\n",u,v,w);
      mst += w;
    }
  }
  string home; cin >> home;
  set<int> unique;
  for(int i = 0; i < s; i++){
   unique.insert(find(i)); //cout << i << " " << par[i]<<endl;	
  }
  if(unique.size() != 1){
    cout << "Impossible\n"; continue;
  }
  cout << mst << '\n';
}
return 0;
}