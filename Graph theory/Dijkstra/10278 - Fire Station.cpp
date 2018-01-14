#include <bits/stdc++.h>
using namespace std;
#define N 505
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define F first
#define S second

#define rep(i, a, b) for(int i = a; i < b; ++i)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vpii;

int n,f;
int dis[N];
int fire[N];
vpii g[N];

int  mx;
int ans;

void dijkstra(int s){
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  pq.push(mp(0,s));
  dis[s]=0;
  while(!pq.empty()){
    pii p=pq.top();
    int u=p.S;
    int w=p.F;
    pq.pop();
    if(dis[u]<w)continue;
    for(int i=0;i<g[u].size();i++){
      pii q=g[u][i];
      int v=q.F;
      int e=q.S;
      int nw=w+e;
      if(nw < dis[v]){
        dis[v]=nw;
        pq.push(mp(nw,v));
      }
    }
  }
}

int tdis[N];
void dijkstra2(int s){
  for(int i=0;i<N;i++)
    tdis[i]=dis[i];
  priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int,int> > > pq;
  pq.push(mp(0,s));
  tdis[s]=0;
  while(!pq.empty()){
    pii p=pq.top();
    pq.pop();
    int u=p.S;
    int w=p.F;
    if(tdis[u] < w)continue;
    for(int i=0;i<g[u].size();i++){
      pii q=g[u][i];
      int v=q.F;
      int e=q.S;
      int nw=w+e;
      if(nw < tdis[v]){
        tdis[v]=nw;
        pq.push(mp(nw,v));
      }
    }
  }
  int len=0;
  for(int i=1;i<=n;i++)
    len=max(len,tdis[i]);
    //cout<<s<<" "<<len<<endl;
  if(len<mx){
    mx=len;
    ans=s;
  }
  if(len==mx and s<ans)ans=s;
}

void blank(){
  for(int i=0;i<N;i++){
    fire[i]=0;
    g[i].clear();
    dis[i]=MOD;
  }
  mx=2e9;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
int t;
cin>>t;
while(t--){
  blank();
  cin>>f>>n; //cout<<f<<" "<<n<<endl;
  ans=n;
  for(int i=0;i<f;i++){
    int x;
    cin>>x; 
    fire[x]=1;
    ans = min(ans,x);
  }
 
  string s;
  getline(cin,s);
  while(getline(cin,s)){ if(s.size()==0)break;//cout<<s<<endl;
      istringstream is(s);
      int x,y,z;
      while(is>>x>>y>>z){
        g[x].pb(mp(y,z));
        g[y].pb(mp(x,z));
      }
    }
   // cout<<endl;
 for(int i=0;i<N;i++)
  if(fire[i])
    dijkstra(i);
// for(int i=1;i<=n;i++)
//   cout<<i<<" "<<dis[i]<<endl;
  int len=0; //cout<<ans<<" "<<mx<<endl;
 for(int i=1;i<=n;i++)
  len=max(len,dis[i]);
 mx=len;
   for(int i=1;i<=n;i++)
    if(!fire[i])
      dijkstra2(i);

  cout<<ans<<"\n";
  if(t)cout<<"\n";
  
}
return 0;
}