/*
948. Bag of Tokens
Question Link -->>
948. Bag of Tokens

*/
#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int bagOfTokensScore(vector<int> &tokens, int power)
    {
        sort(tokens.begin(), tokens.end());

        int maxsc = 0, sc = 0, i = 0, j = tokens.size() - 1;

        while (i <= j)
        {
            if (power >= tokens[i])
            {
                power -= tokens[i++];

                maxsc = max(maxsc, ++sc);
            }
            else if (sc > 0)
            {
                power += tokens[j--];
                sc--;
            }
            else
            {
                break;
            }
        }
        return maxsc;
    }
};