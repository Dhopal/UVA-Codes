#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define rep(i, a, b) for(int i = a; i < b; ++i)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vpii;

bool seen[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};
bool ok(int x, int y){
  if(x<0 or y<0 or x>=2000 or y>=2000 or seen[x][y])return false;
  return true;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
while(1){
  int P;
  cin>>P;
  if(P==0)break;
  vpii A;
  for(int i=0;i<P;i++){
    int x,y;
    cin>>x>>y;
    A.pb(mp(x,y));
  }
  int Q;
  cin>>Q;
  set<pii> B;
  for(int i=0;i<Q;i++){
    int x,y;
    cin>>x>>y;
    B.insert(mp(x,y));
  }
  for(int i=0;i<N;i++)
  for(int j=0;j<N;j++)
  seen[i][j]=false;
  
  queue<piii> q;
  for(int i=0;i<A.size();i++){
    int x=A[i].F;
    int y=A[i].S;
    q.push(mp(0,mp(x,y)));
    seen[x][y]=1;
  }
  int ans=0;
  while(!q.empty()){
    piii front=q.front();
    q.pop();
    int x=front.S.F;
    int y=front.S.S;
    int t=front.F;
    if(B.find(mp(x,y))!=B.end()){
      ans=t;
      break;
    }
    for(int i=0;i<4;i++){
      int nx=x+dx[i];
      int ny=y+dy[i];
      if(ok(nx,ny)){
        q.push(mp(t+1,mp(nx,ny)));
        seen[nx][ny]=1;
      }
    }
  }
  cout << ans << '\n';
}
return 0;
}