#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

int main()
{
    int n, k;
    std::cin >> n >> k;
    std::multiset<int> mst;
    int a[n];

    for (int i = 0; i < n; i++)
    {
        int c;
        std::cin >> c;
        a[i] = c;
        // mst.insert(c);
    }

    for (int i = 0; i < k; i++)
    {
        mst.insert(a[i]);
    }


    for (int i = 0; i <= (n - k); i++)
    {
        std::cout << *mst.begin() << '\n';

        if (!mst.empty())
        {
            mst.erase(mst.find(a[i]));
            mst.insert(a[k + i]);
        }
    }
}