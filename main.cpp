//بسم الله الرحمن الرحيم

#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int,int> pii;
typedef pair<double, double> pdd;
typedef pair<ll, ll> pll;
typedef vector<pii> vii;
typedef vector<pll> vll;
typedef double dl;
//using u128 = __uint128_t;
#define el << '\n'
#define PI 3.141592653589793238
#define _test_ int _ ; cin >> _ ; while(_--)
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)
ll gcd ( ll  a, ll b ) { return __gcd ( a, b ) ; }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ) ; }
int dx[]={0,0,+1,-1,+1,-1,-1,+1} ;
int dy[]={+1,-1,0,0,+1,-1,+1,-1} ;
///   ***   ---   |||__________LET'S BEGIN (-_^)________|||   ---   ***   ///

const ll infLL = 1e15 ;
const int inf = 1e9 ;
const int mod = 1e6+3 ;
const int mx = 1e5+123 ;
ll n , ans[mx],m;
vll adj[mx];

void dijkstra(ll source )
{
    for(int i=1;i<=n;i++) ans[i]=infLL;  // initialization
    ans[source]=0;


    priority_queue<pll>q;

    q.push({0,source});  // pushing source in queue

    while( !q.empty() )
    {
        ll cost= -1 * q.top().first ;
        ll node= q.top().second ;
        q.pop();
        if(ans[node]<cost) continue;  // not checking the route which is already bigger //

        for(auto i:adj[node])
        {
            ll adj_cost=i.second;
            ll adj_node=i.first;
            if( cost+adj_cost<ans[adj_node] )  // relaxation //
            {
                ans[adj_node]=cost+adj_cost;
                q.push({-ans[adj_node],adj_node});
            }
        }
    }
}

void _case_( )
{
    cin >> n >> m ;
    while(m--)
    {
        ll u,v,w;
        cin >> u >> v >> w ;
        adj[u].push_back({v,w});
        //adj[v].push_back({u,w});
    }
    dijkstra(1);
    for(int i=1;i<=n;i++)
        cout << ans[i] << ' ' ;
}

int main( )
{
    optimize( );
    //_test_
        _case_( ) ;
}

///////////* ________ *  N A Y E M  * ________ *///////////