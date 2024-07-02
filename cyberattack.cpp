#include <iostream>
#include <vector>
using namespace std;

vector<int> getNumPoints(vector<int> &layers, vector<int> &energy, long long k)
{
    int n = layers.size();
    vector<int> points(n, 0);
    int range = -1;
    vector<int> prefixSum(n, 0);

    // Calculate prefix sums for layers
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            prefixSum[i] = layers[i];
        }
        else
        {
            prefixSum[i] = prefixSum[i - 1] + layers[i];
        }
    }

    for (int start = 0; start < n; ++start)
    {
        int ans = 0;
        if (range >= start)
        {
            ans = (range - start + 1);
        }

        long long remainingEnergy = k;
        if (start > 0)
        {
            int val = 0;
            if (range >= start)
            {
                if (start != 0)
                {
                    val = prefixSum[range] - prefixSum[start - 1];
                }
                else
                {
                    val = prefixSum[range];
                }
            }
            remainingEnergy -= (val);
        }

        int check = 0;
        while (range + 1 < n && remainingEnergy >= layers[range + 1])
        {
            if (remainingEnergy-layers[range+1] >= energy[range + 1])
            {
                ans++;
            }
            else
            {
                break;
            }
            check++;
            range++;
            remainingEnergy -= layers[range];
        }
        if (check == 0)
            range++;

        points[start] = ans;
        // cout << start << " " << range << " " << ans << endl;
    }

    return points;
}

int main()
{
    int n = 3;
    vector<int> layers = {5, 8, 1};
    vector<int> energy = {4, 2, 1};
    long long k = 10;

    // int n = 4;
    // vector<int> layers = {2, 3, 4, 5};
    // vector<int> energy = {1, 2, 3, 4};
    // long long k = 15;
    vector<int> result = getNumPoints(layers, energy, k);

    for (int points : result)
    {
        cout << points << " ";
    }
    cout << endl;

    return 0;
}
