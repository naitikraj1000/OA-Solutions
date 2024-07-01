//Sprinkler Kevin's Soln
//Author Naitik Raj

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll dp[215][215];
ll DP[215][215];

ll get_idx_continious_substring(string &prefix, string &s, int idx)
{

    ll cnt = 0;
    int verify = 1;
    while (cnt != prefix.size())
    {
        if (idx + cnt >= s.size())
        {
            verify = 0;
            break;
        }
        if (prefix[cnt] != s[idx + cnt])
        {
            verify = 0;
        }
        cnt++;
    }

    if (verify == 0)
    {
        return 0;
    }
    else
    {
        return cnt + get_idx_continious_substring(prefix, s, idx + cnt);
    }
}

ll func(ll idx, ll j, string &s)
{

    if (idx == j)
    {
        return 1;
    }
    if (idx > j)
    {
        return 0 * 1ll;
    }
    if (dp[idx][j] != -1)
    {
        return dp[idx][j];
    }

    ll ans = 1ll * (s.size() - idx);
    string prefix;
    for (ll i = idx; i < j; i++)
    {
        prefix.push_back(s[i]);
        ll sz = prefix.size();
        ll cnt = DP[idx][i];
        ll len = i - idx + 1;
        ll total_size = j - idx + 1;
        ll q = total_size / len;
        ll nxt_idx = min(idx + cnt, idx + len * q);
        // cout << idx << " " << prefix << " " << nxt_idx << endl;
        ans = min(ans, min((nxt_idx - idx), 3ll + func(idx, idx + sz - 1, s)) + func(nxt_idx, j, s));
    }

    return dp[idx][j] = ans;
}

int main()
{

    string s;
    cin >> s;
    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < 215; i++)
    {
        for (int j = 0; j < 215; j++)
        {
            DP[i][j] = 0;
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        string prefix;
        for (int j = i; j < s.size(); j++)
        {
            prefix.push_back(s[j]);
            DP[i][j] = get_idx_continious_substring(prefix, s, i);
            // cout<<i<<" "<<j<<" "<<prefix<<" "<<DP[i][j]<<endl;
        }
    }

    cout << func(0, s.size() - 1, s) << endl;
}

// string a="kjdnvdfvkddvjb"
