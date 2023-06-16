#include <bits/stdc++.h>
#define ll long long
#define endl '\n'
#define S second
#define F first
#define pb push_back
#define mp make_pair
#define yes cout<<"YES\n";
#define no cout<<"NO\n";
using namespace std;
typedef vector<ll> vi;
typedef vector<vector<ll>> vvi;
typedef pair<ll,ll> pll;
typedef vector<pll> vpll;

vi t;
ll fn;

void init (ll nn)
{
	fn = nn;
	t.assign (fn, 0);
}

ll sum (ll r)
{
	ll result = 0;
	for (; r >= 0; r = (r & (r+1)) - 1)
		result += t[r];
	return result;
}

void inc (ll i, ll delta)
{
	for (; i < fn; i = (i | (i+1)))
		t[i] += delta;
}

ll sum (ll l, ll r)
{
	return sum (r) - sum (l-1);
}

ll inversions_number(vi& vec){
	init(vec.size());
	ll ans = 0;
	for(ll i=0; i<vec.size(); i++){
		ans += sum(vec[i], vec.size()-1);
		inc(vec[i], 1);
	}
	return ans;
}

ll getans(string& s, string& b){
	map<char, queue<ll>> m;
	for(ll i=0; b[i]; i++){
		m[b[i]].push(i);
	}

	vi a(s.size());
	for(ll i=0; s[i]; i++){
		a[i] = m[s[i]].front();
		m[s[i]].pop();
	}

	return(inversions_number(a));
}


int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	ll tt;
	cin>>tt;
	while(tt--){
		string s;
		cin>>s;
		map<char, ll> cnt;

		for(ll i=0; s[i]; i++){
			cnt[s[i]]++;
		}

		string anot = "ANOT";
		ll ans = -1;
		string ct;
		do{
			string tmp = "";
			for(ll i=0; i<4; i++){
				for(ll j=0; j<cnt[anot[i]]; j++){
					tmp += anot[i];
				}
			}

			ll gt = getans(s, tmp);
			if(gt > ans){
				ans = gt;
				ct = tmp;
			}
		} while(next_permutation(anot.begin(), anot.end()));

		cout<<ct<<endl;

	}


    return 0;
}
