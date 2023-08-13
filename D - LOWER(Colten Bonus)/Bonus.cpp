#include<iostream>
#include<vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    int N, Q;
    char c;
    string S;
    int finalChangeIndex, finalChangePos;
    unordered_map<int, int> record;

    cin >> N >> S >> Q;

    int C[Q][3];

    for(int i = 0; i < Q; i++)
    {
        cin >> C[i][0] >> C[i][1] >> c;

        if(C[i][0] != 1)
        {
            finalChangeIndex = C[i][0];
            finalChangePos = i;
        }
        else
        {
            record[C[i][1] - 1] = i;
            S[C[i][1] - 1] = c;
        }
    }

    for(int i = 0; i < N; i++)
    {
        if(record[i] < finalChangePos)
        {
            if(finalChangeIndex == 2)
            {
                if(S[i] >= 'A' && S[i] <= 'Z')
                {
                    S[i] += 32;
                }
            }
            else if(finalChangeIndex == 3)
            {
                if(S[i] >= 'a' && S[i] <= 'z')
                {
                    S[i] -= 32;
                }
            }
        }
    }

    cout << S;
}