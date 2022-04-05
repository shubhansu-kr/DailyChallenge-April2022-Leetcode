// https://leetcode.com/problems/reveal-cards-in-increasing-order/

// You are given an integer array deck. There is a deck of cards where
// every card has a unique integer. The integer on the ith card is deck[i].

// You can order the deck in any order you want. Initially, all the cards
// start face down (unrevealed) in one deck.

// You will do the following steps repeatedly until all cards are revealed:

// Take the top card of the deck, reveal it, and take it out of the deck.
// If there are still cards in the deck then put the next top card of the
// deck at the bottom of the deck.
// If there are still unrevealed cards, go back to step 1. Otherwise, stop.
// Return an ordering of the deck that would reveal the cards in increasing order.

// Note that the first entry in the answer is considered to be the
// top of the deck.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> deckRevealedIncreasing(vector<int> &deck)
    {
        // Ignore deck - we just need to sort the deck and place them on alternate
        // indexes

        // sort the deck first
        sort(begin(deck), end(deck));
        vector<int> res(deck.size());
        int i = 0, j;
        res.size() % 2 == 0 ? j = res.size() / 2 : j = res.size() / 2 + 1;
        for (int k = 0; k < res.size(); k++)
        {
            if (k % 2 == 0)
            {
                res[k] = deck[i];
                i++;
            }
            else
            {
                res[k] = deck[j];
                j++;
            }
        }
        return res;
    }
};

int main()
{

    return 0;
}