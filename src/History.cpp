#include "History.h"
#include <iostream>
using namespace std;

unordered_map<int, stack<string>> userHistory;

void addToHistory(int userId, const string& bookTitle) {
    userHistory[userId].push(bookTitle);
}

void showHistory(int userId) {
    if (userHistory[userId].empty()) {
        cout << "No history found.\n";
        return;
    }

    stack<string> temp = userHistory[userId];
    while (!temp.empty()) {
        cout << temp.top() << endl;
        temp.pop();
    }
}
