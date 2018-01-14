#include <bits/stdc++.h>
using namespace std;

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
typedef vector<piii> vpiii;


#define N 10000006
#define B 32
struct node{
public:
  int nxt[2];
};

typedef struct node node;

int S=1;
int n,t;
node T[N];

int p[32];

void init(){
  S=1;
  rep(i,0,N){
    rep(j,0,2){
      T[i].nxt[j]=-1;
    }
  }
}

void add(int x){
  bitset<B> a=x;
  int cur=1;
  for(int i=B-1;i>=0;i--){
    int val=a[i];  //cout<<val;//
    if(T[cur].nxt[val]==-1)
      {T[cur].nxt[val]=++S; cur = S; }
    else cur=T[cur].nxt[val];
  }  //cout<<endl;//
}

int query(int x){
  bitset<B> ret;
  bitset<B> a=x;
  int cur=1;
  for(int i=B-1;i>=0;i--){
    int val=a[i];
    if(T[cur].nxt[!val]==-1){
      cur=T[cur].nxt[val];
    }
    else{
      cur=T[cur].nxt[!val];
      ret[i]=1;
    }
  }
  int res=0;
  for(int i=B-1;i>=0;i--)
  res+=p[i]*ret[i];
  return res;
}


int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
p[0]=1;
rep(i,1,32)p[i]=p[i-1]*2;

cin>>t;
while(t--){
  init();
  cin>>n;
  add(0);
  int pre=0, ans=0;
  rep(i,0,n){
    int x;
    cin>>x;
    pre=pre^x;
    add(pre);
    int t=query(pre);
    ans=max(ans,t);
  }
  cout<<ans<<'\n';
}
// rep(i,1,10){
//   cout<<i<<" "<<T[i].nxt[0]<<" "<<T[i].nxt[1]<<endl;
// }
return 0;
}