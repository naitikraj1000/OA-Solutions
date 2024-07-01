//Sprinkler 
//Prefix Problem


#include "bits/stdc++.h"

using namespace std;
const int mod=1e9+9;
#define ll long long int

ll fastpow(ll a ,ll b){
    ll res=1;
    while(b){
       if(b&1) res=(res*a)%mod;
       a=(a*a)%mod;
       b/=2;
    }
    return res;
}

const ll p=31;
const ll k=fastpow(p,mod-2);
 
void solve(ll TC)
{

    ll n;
    cin >> n;

    string s;
    cin >> s;

    vector<ll> great(n + 1), equal(n + 1), less(n + 1, 0);

    vector<ll> pre(n + 1), pt(n + 1), inv(n + 1);

    pt[0] = 1;
    inv[0] = 1;
    pre[0] = 0;

    for (ll i = 1; i <= n; i++)
    {
        pre[i] = (pre[i - 1] + (s[i - 1] - 'a' + 1) * pt[i - 1]) % mod;
        pt[i] = (pt[i - 1] * p) % mod;
        inv[i] = (inv[i - 1] * k) % mod;
    }

    for (ll i = 2; i <= n; i++)
    {

        if (s[i - 1] > s[0])
        {
            great[1]++; // start contributing from length 1 to atmost n-i+1
            great[n - i + 2]--;
        }
        else if (s[i - 1] < s[0])
        {
            less[1]++; // start contributing from length 1 to atmost n-i+1
            less[n - i + 2]--;
        }
        else
        {

            equal[1]++;

            ll low = i, high = n;

            ll ind = i;

            while (low <= high)
            { // fiding the index upto which it is equal to prefix
                ll m = (low+high)/2;
                ll hash1 = pre[m - i + 1];
                ll hash2 = (((pre[m] - pre[i - 1] + mod) % mod) * inv[i]) % mod;
                if (hash1 == hash2)
                {
                    ind = m;
                    low = m + 1;
                }
                else
                    high = m - 1;
            }
            //
            equal[ind - i + 2]--; /// now from length 1 to ind-i+1 it will contribute in equal

            if (ind + 1 <= n)
            {
                if (s[ind] > s[0])
                {
                    great[ind + 1 - i + 1]++; // after that it will contribute in gretaer upto the max length we can get upto n index
                    great[n - ind + 1]--;
                }
                else
                {
                    less[ind + 1 - i + 1]++;
                    less[n - ind + 1]--;
                }
            }
        }
    }

    for (ll i = 1; i < n; i++)
    {
        great[i] += great[i - 1];
        less[i] += less[i - 1];
        equal[i] += equal[i - 1];
        cout << great[i] << " " << equal[i] << " " << less[i] << endl;
    }
}

int main()
{
    ll Tc = 1;
    // cin>>Tc;

    solve(Tc);

    return 0;
}
