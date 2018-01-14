#include <bits/stdc++.h>
using namespace std;
#define N 505  // fault in probem constraints
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

class cell{
public:
  int north;
  int south;
  int east;
  int west;
};
//0=none 1=door 2=wall

class node
{
public:
  int x,y,t;
};

cell g[N][N];
//int seen[N][N];
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int dis[N][N];

bool ok(int x, int y){
  if(x<0 or y<0 or x>=N or y>=N )return false;
  return true;
}

void add(int x, int y, int a, int b, int c, int d){
  if(a)g[x][y].north=a;
  if(b)g[x][y].south=b;
  if(c)g[x][y].east=c;
  if(d)g[x][y].west=d;
}

void blank(){
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      g[i][j].north=0; g[i][j].south=0; g[i][j].east=0; g[i][j].west=0; // why add() not used think
      //seen[i][j]=0;
      dis[i][j]=MOD;
    }
  }
}

int door,wall;


int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  freopen("o.txt","w",stdout);
vi res;
while(1){
  cin>>wall>>door;
  if(wall==-1)break;
  blank();
  for(int i=0;i<wall;i++){
    int x,y,d,l;
    cin>>x>>y>>d>>l;
    if(d==0){
      for(int i=x;i<x+l;i++){
        int nx=i;
        int ny1=y-1;
        int ny2=y;
        add(nx,ny1,2,0,0,0);//g[nx][ny1](2,0,0,0);
        add(nx,ny2,0,2,0,0);//g[nx][ny2](0,2,0,0);
      }
    }
    else{
      for(int i=y;i<y+l;i++){
        int nx1=x-1;
        int nx2=x;
        int ny=i;
        add(nx1,ny,0,0,2,0);//g[nx1][ny1](0,0,2,0);
        add(nx2,ny,0,0,0,2);//g[nx2][ny](0,0,2,0);
      }
    }
  }


   for(int i=0;i<door;i++){
    int x,y,d,l;
    cin>>x>>y>>d;
    l=1;
    if(d==0){
      for(int i=x;i<x+l;i++){
        int nx=i;
        int ny1=y-1;
        int ny2=y;
        add(nx,ny1,1,0,0,0);//g[nx][ny1](2,0,0,0);
        add(nx,ny2,0,1,0,0);//g[nx][ny2](0,2,0,0);
      }
    }
    else{
      for(int i=y;i<y+l;i++){
        int nx1=x-1;
        int nx2=x;
        int ny=i;
        add(nx1,ny,0,0,1,0);//g[nx1][ny1](0,0,2,0);
        add(nx2,ny,0,0,0,1);//g[nx2][ny](0,0,2,0);
      }
    }
  }
//   for(int i=1;i<=3;i++){
//     for(int j=1;j<=3;j++){
// printf("%d %d : %d %d %d %d      ",i,j,g[i][j].north,g[i][j].south,g[i][j].east,g[i][j].west);
//     }
//     cout<<endl;
//   }
  double d1,d2;
  cin>>d1>>d2;
  int f1,f2;
  f1=d1,f2=d2;
 
 
  
  priority_queue<piii, vector<piii>, greater<piii > > q;

  q.push(mp(0,mp(0,0)));
  dis[0][0]=0;
  int ans = -1;
  //bool reach = false;

  while(!q.empty()){
    piii f=q.top();
    q.pop();

    int x1=f.S.F;
    int y1=f.S.S;
    int t1=f.F;

    if(dis[x1][y1] < t1)continue;

    piii o;
    //move top
    int x2=x1;
    int y2=y1+1;
    int t2=t1;
    if(ok(x2,y2) and g[x1][y1].north!=2){
     if(g[x1][y1].north == 1)t2++;
     if(t2 < dis[x2][y2]){
          o=mp(t2,mp(x2,y2));//o.x=x2;o.y=y2;o.t=t2;
          q.push(o);
        //  seen[x2][y2]=1;
          dis[x2][y2]=t2;
        }
    }

    //move down
    x2=x1;
    y2=y1-1;
    t2=t1;
    if(ok(x2,y2) and g[x1][y1].south!=2){
      if(g[x1][y1].south == 1)t2++;
     if(t2 < dis[x2][y2]){
          o=mp(t2,mp(x2,y2));//o.x=x2;o.y=y2;o.t=t2;
          q.push(o);
         // seen[x2][y2]=1;
          dis[x2][y2]=t2;
        }
    }
    // move right
    x2=x1+1;
    y2=y1;
    t2=t1;
    if(ok(x2,y2) and g[x1][y1].east!=2){
      if(g[x1][y1].east == 1)t2++;
      if(t2 < dis[x2][y2]){
          o=mp(t2,mp(x2,y2));//o.x=x2;o.y=y2;o.t=t2;
          q.push(o);
          //seen[x2][y2]=1;
          dis[x2][y2]=t2;
        }
    }
    //move left
    x2=x1-1;
    y2=y1;
    t2=t1;
    if(ok(x2,y2) and g[x1][y1].west!=2){
      if(g[x1][y1].west == 1)t2++;
      if(t2 < dis[x2][y2]){
          o=mp(t2,mp(x2,y2));//o.x=x2;o.y=y2;o.t=t2;
          q.push(o);
          //seen[x2][y2]=1;
          dis[x2][y2]=t2;
        }
    }
  }
  if(f1>=N or f2>=N){
  	res.pb(dis[N-2][N-2]); continue;  //TRICKY
  }
  if(dis[f1][f2] < MOD)ans=dis[f1][f2];
  res.pb(ans);
}
for(int i=0;i<res.size();i++){
	 cout<<res[i]<<"\n";
}
return 0;
}