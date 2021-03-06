#include<bits/stdc++.h>

using namespace std;

#define fRead(x)        freopen(x,"r",stdin)
#define fWrite(x)       freopen (x,"w",stdout)

#define ff              first
#define ss              second
#define pb              push_back
#define mk              make_pair

#define sf              scanf
#define pf              printf
#define min3(a,b,c)     min(a,min(b,c))
#define max3(a,b,c)     max(a,max(b,c))
#define min4(a,b,c,d)   min(a,min(b,min(c,d)))
#define max4(a,b,c,d)   max(a,max(b,max(c,d)))
#define SQR(a)          ((a)*(a))
#define One(x)          __builtin_popcount(x)
#define FOR(i,a,b)      for(int i=a;i<=b;i++)
#define ROF(i,a,b)      for(int i=a;i>=b;i--)
#define REP(i,b)        for(int i=0;i<b;i++)
#define foreach(v, c)   for( typeof( (c).begin()) v = (c).begin();  v != (c).end(); ++v)
#define MEM(a,x)        memset(a,x,sizeof(a))
#define ABS(x)          ((x)<0?-(x):(x))
#define FABS(x)         ((x)+eps<0?-(x):(x))

#define cases           int T;cin>>T;for(int TC=1;TC<=T;TC++)
#define precision(n)    cout<<fixed<<setprecision(n);
#define printCase(x)    cout<<"Case "<<TC<<": "<<x<<endl;
#define SIZE(v)         (int)v.size()
#define dump(x)         cerr<<"~ "<<#x<<" = "<<x<<endl

#define SORT(v)         sort(v.begin(),v.end())
#define RSORT(v)        sort(v.begin(),v.end(),greater<int>())
#define REV(v)          reverse(v.begin(),v.end())
#define Unique(v)       v.erase(unique(v.begin(),v.end()),v.end())
#define minimum(a)      *min_element(a.begin(), a.end())
#define maximum(a)      *max_element(a.begin(), a.end())
#define all(v)          v.begin(),v.end()

#define Set(N,p)        N=((N)((1LL)<<(p)))
#define Reset(N,p)      N=((N)&(~((1LL)<<(p))))
#define Check(N,p)      (!(((N)&((1LL)<<(p)))==(0)))

#define FastRead        ios_base::sync_with_stdio(0);cin.tie(nullptr)

typedef long long ll;
typedef unsigned long long ull;
typedef pair < ll, ll > pll;
typedef pair < int,int> pii;

const ll inf = 2147383647;
const double pi = 2 * acos ( 0.0 );
const double eps = 1e-9;

template<class T> inline T gcd(T a,T b) {if(a<0)return
gcd(-a,b);if(b<0)return gcd(a,-b);return (b==0)?a:gcd(b,a%b);}
template<class T> inline T lcm(T a,T b) {if(a<0)return
lcm(-a,b);if(b<0)return lcm(a,-b);return a*(b/gcd(a,b));}
template<class T> T power(T N,T P){ return (P==0)?  1: N*power(N,P-1); }

ll nck[1001][1001];
ll fact[1001];
const ll mod=1000000007;

void gen_nck() {

    nck[0][0] = 1;
    for ( int n = 1; n<=1000; n++ ) {
        nck[n][0] = 1;
        for ( int k = 1;k<=n; k++ ) {
            nck[n][k] = (nck[n-1][k]%mod + nck[n-1][k-1]%mod)%mod;
        }
    }
}
void gen_fact()
{
    fact[0]=1;
    for(int i=1;i<=1000;i++)
        fact[i]=(i*fact[i-1])%mod;

}
int main()
{
    FastRead;
    gen_nck();
    gen_fact();

    ll n,m,k,ways,sum;

    cases
    {
        cin>>n>>m>>k;
        ways=nck[m][k];
        sum=0;
        for(int i=0;i<=m-k;i++)
        {
            if(i%2==0)
            {
                sum=(sum + (nck[m-k][i]*fact[n-k-i])%mod)%mod;
            }

            else
            {
                sum=(sum - (nck[m-k][i]*fact[n-k-i])%mod)%mod;
                if(sum<0)
                    sum+=mod;
            }
        }
        ways=(ways*sum)%mod;
        printCase(ways);
    }
}
