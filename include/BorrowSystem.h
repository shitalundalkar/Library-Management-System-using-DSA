#ifndef BORROWSYSTEM_H
#define BORROWSYSTEM_H

#include <unordered_map>
#include <queue>
#include <vector>
#include "Library.h"

void borrowBook(Library& lib, int bookId, int userId);
void returnBook(Library& lib, int bookId, int userId);

#endif
