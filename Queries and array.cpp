// Google Question
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using lld = long double;

#ifndef ONLINE_JUDGE
#include "debugalgo.h"
#else
#define debug(x)
#endif

const ll mod = 1e9 + 7;

//https://www.thejoboverflow.com/p/p1386/

/*
Use binary search to get the maximum possible minimum value mn.Then whatever number a[i], is greater than mn
and also greater than b[i]. You can use (a[i]-b[i]) to increase a[j] if a[j]<mn at a cost of c[i].
To choose minimum c[i] you can use priority_queue
make a priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> and push {c[i],a[i]-b[i]}
*/


bool feasible(ll mid, vector<ll>&a, vector<ll>&b)
{
	ll avl = 0;
	int n = a.size();
	for (int i = 0; i < n; i++)
	{
		if (a[i] > mid)
		{
			avl += a[i] - max(b[i], mid);
		}
		if (a[i] < mid)
		{
			avl -= (mid - a[i]);
		}
	}

	if (avl < 0) return 0;
	return 1;
}

ll getmin(vector<ll>&a, vector<ll>&b, ll avg)
{

	ll l = 0;
	ll r = avg;

	ll ans = 0;

	while (l <= r)
	{
		ll mid = l + (r - l) / 2;

		if (feasible(mid, a, b))
		{
			ans = mid;
			l = mid + 1;
		}
		else r = mid - 1;
	}

	return ans;
}
void solve()
{
	int n;
	cin >> n;

	vector<ll> a(n), b(n), c(n);

	ll avg = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];

		avg += a[i];
	}

	avg /= n;

	for (int i = 0; i < n; i++) cin >> b[i];
	for (int i = 0; i < n; i++) cin >> c[i];


	ll mn = getmin(a, b, avg);

	debug(mn);


	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>pq;


	for (int i = 0; i < n; i++)
	{
		if (a[i] > mn && a[i] > b[i])
		{
			pq.push({c[i], a[i] - max(mn, b[i])});
		}
	}


	ll ans = 0;

	for (int i = 0; i < n; i++)
	{
		while (a[i] < mn)
		{
			auto x = pq.top();
			pq.pop();

			if (x.second >= mn - a[i])
			{
				ans += (x.first * (mn - a[i])) % mod;
				ans %= mod;
				x.second -= (mn - a[i]);
				a[i] = mn;

				if (x.second)
					pq.push({x.first, x.second});

			}
			else
			{
				ans += (x.first * x.second) % mod;
				ans %= mod;
				a[i] += x.second;
			}
		}
	}

	cout << mn << " " << ans << "\n";

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifndef ONLINE_JUDGE
	freopen("error.txt", "w", stderr);
#endif

	int tt = 1;
	cin >> tt;
	while (tt--)
	{
		solve();
	}
}
