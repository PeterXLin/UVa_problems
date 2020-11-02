#include <iostream>
using namespace std;
int main()
{
    int cases;
    cin >> cases;

    while (cases--)
    {
        string nextLine;
        getline(cin, nextLine);

        int weight[20];
        int luggageAmount = 0;
        int totalWeight = 0;

        while (cin.peek() != '\n')
        {
            cin >> weight[luggageAmount];
            totalWeight += weight[luggageAmount++];
        }

        if (totalWeight % 2)
        {
            cout << "NO" << endl;
            continue;
        }

        bool dp[totalWeight + 1] = {};
        dp[0] = true;

        for (int i = 0; i < luggageAmount; i++)
        {
            for (int j = totalWeight; j >= weight[i]; j--)
            {
                if (dp[j - weight[i]])
                {
                    dp[j] = true;
                }
            }
        }

        if (dp[totalWeight / 2])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}