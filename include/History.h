#ifndef HISTORY_H
#define HISTORY_H

#include <unordered_map>
#include <stack>
#include <string>

void addToHistory(int userId, const std::string& bookTitle);
void showHistory(int userId);

#endif
