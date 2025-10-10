#include <bits/stdc++.h>
using namespace std;

// Function to find the length of the shortest transformation sequence
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    unordered_set<string> wordSet(wordList.begin(), wordList.end());
    if (wordSet.find(endWord) == wordSet.end()) return 0;

    queue<pair<string, int>> q;
    q.push({beginWord, 1});

    while (!q.empty()) {
        auto [word, level] = q.front();
        q.pop();

        if (word == endWord) return level;

        for (int i = 0; i < word.size(); i++) {
            string temp = word;
            for (char ch = 'a'; ch <= 'z'; ch++) {
                temp[i] = ch;
                if (wordSet.find(temp) != wordSet.end()) {
                    q.push({temp, level + 1});
                    wordSet.erase(temp); // avoid revisiting
                }
            }
        }
    }
    return 0;
}

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};

    cout << "Shortest Transformation Sequence Length: "
         << ladderLength(beginWord, endWord, wordList) << endl;

    return 0;
}
