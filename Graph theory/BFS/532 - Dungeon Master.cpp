#include <bits/stdc++.h>
using namespace std;
#define N 35
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;

int l , r, c;
char dungeon[N][N][N];
bool seen[N][N][N];

class node{
public:
  int _l;
  int _r;
  int _c;
  int _t;
  node(int x, int y, int z, int d){
    _l = x; _r = y; _c = z; _t = d;
  }
};

bool ok(int x, int y, int z){
  if(x < 0 or y < 0 or z < 0 or x >= l or y >= r or z >= c or seen[x][y][z] or dungeon[x][y][z]=='#')
    return false;
  return true;
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
while(1){
  cin >> l >> r >> c; 
  if(l + r + c == 0)break;
  int sl, sr, sc, el, er, ec;
  for(int lev = 0; lev < l; lev++){
    for(int row = 0; row < r; row++){
      for(int col = 0; col < c; col++){
        char ch;
        cin >> ch; //cout<<ch;
        dungeon[lev][row][col] = ch;
        if(ch == 'S'){
          sl = lev, sr = row, sc = col;
        }
        if(ch == 'E'){
          el = lev, er = row, ec = col;
        }
      }//cout<<'\n';
    }//cout<<'\n';
  }
 for(int i = 0; i < N; i++){
  for(int j = 0; j < N; j++){
    for(int k = 0; k < N; k++){
      seen[i][j][k] = false;
    }
  }
 }

 int ans = -1;
 queue<node> q;
 node start(sl,sr,sc,0);
 
 q.push(start);
 seen[sl][sr][sc] = true;

 while(!q.empty()){
  node p = q.front();
  q.pop();
  if(p._l == el and ( p._r == er and p._c == ec)){
    ans = p._t; break;
  }
  for(int i = -1; i <= 1; i++){
    for(int j = -1; j <= 1; j++){
      for(int k = -1; k <= 1; k++){
        if(abs(i)+abs(j)+abs(k) != 1)continue;
        int a = p._l + i;
        int b = p._r + j;
        int c = p._c + k;
        if(ok(a,b,c)){
          node n(a,b,c,p._t+1);
          q.push(n);
          seen[a][b][c]=true;
        }
      }
    }
  }
 }
 if(ans == -1){
 printf("Trapped!\n"); continue;
 }
 printf("Escaped in %d minute(s).\n", ans);
}
return 0;
}