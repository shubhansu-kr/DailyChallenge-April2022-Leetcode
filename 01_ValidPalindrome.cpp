// https://leetcode.com/problems/valid-palindrome-ii/

// Given a string s, return true if the s can be palindrome after
// deleting at most one character from it.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool validPalindrome(string s)
    {
        int flag = 1;
        int n = s.size();
        for (int i = 0; i <= n / 2; i++)
        {
            if (flag)
            {
                if (s[i] != s[n - i - 1])
                {
                    i--;
                    flag = 0;
                    n--;
                    continue;
                }
            }
            else
            {
                if (s[i] != s[n - i - 1])
                {
                    return false;
                }
            }
        }
        return true;
    }
};

int main()
{

    return 0;
}