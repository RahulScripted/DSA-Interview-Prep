// You are given an array of unique strings words where words[i] is six letters long. One word of words was chosen as a secret word. You are also given the helper object Master. You may call Master.guess(word) where word is a six-letter-long string, and it must be from words. Master.guess(word) returns: -1 if word is not from words, or an integer representing the number of exact matches (value and position) of your guess to the secret word.
// There is a parameter allowedGuesses for each test case where allowedGuesses is the maximum number of times you can call Master.guess(word). For each test case, you should call Master.guess with the secret word without exceeding the maximum number of allowed guesses. You will get:

//     1 - "Either you took too many guesses, or you did not find the secret word." if you called Master.guess more than allowedGuesses times or if you did not call Master.guess with the secret word, or

//     2 - "You guessed the secret word correctly." if you called Master.guess with the secret word with the number of calls to Master.guess less than or equal to allowedGuesses.






#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matchCount(const string &a, const string &b) {
        int cnt = 0;
        for (int i = 0; i < a.size(); i++) {
            if (a[i] == b[i]) cnt++;
        }
        return cnt;
    }

    void findSecretWord(vector<string>& words, Master& master) {
        unordered_set<string> candidates(words.begin(), words.end());

        while (!candidates.empty()) {
            string guessWord = *candidates.begin();
            int matched = master.guess(guessWord);

            for (auto it = candidates.begin(); it != candidates.end();) {
                if (matchCount(*it, guessWord) != matched) it = candidates.erase(it);
                else ++it;
            }

            candidates.erase(guessWord);
        }
    }
};

int main() {
    vector<string> words = {"acckzz", "ccbazz", "eiowzz", "abcczz"};
    Master master;
    Solution solution;
    solution.findSecretWord(words, master);
    return 0;
}