#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define pb push_back
#define S second
#define F first
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    ll n,q;
    cin>>n>>q;

    ll a[n];
    vvi indxs(n+1);
    for(ll i=0; i<n; i++){
        cin>>a[i];
        indxs[a[i]].pb(i);
    }
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    for(ll i=0; i<q; i++){
        ll l, r;
        ll ans = 1;
        cin>>l>>r;
        l--;
        r--;
        ll d = r-l+1;
        for(ll i=0; i<50; i++){
            ll ind = uniform_int_distribution<ll>(l,r)(rng);
            ll val = a[ind];
            ll curr = upper_bound(indxs[val].begin(),indxs[val].end(),r)-lower_bound(indxs[val].begin(),indxs[val].end(),l);
            ans = max(ans, 2*curr - d);
        }
        cout<<ans<<endl;
    }


    return 0;
}
