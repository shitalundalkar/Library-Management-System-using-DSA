#include "Library.h"
#include "Trie.h"
#include "BorrowSystem.h"
#include "History.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;
    TitleTrie trie;

    lib.addBook(1, "Harry Potter", "J.K. Rowling", "Fantasy");
    trie.insert("Harry Potter");

    lib.addBook(2, "Hunger Games", "Suzanne Collins", "Dystopian");
    trie.insert("Hunger Games");

    lib.displayBooks();

    borrowBook(lib, 1, 101);
    addToHistory(101, "Harry Potter");

    returnBook(lib, 1, 101);

    cout << "\nSearch books by prefix 'Hu':\n";
    trie.searchPrefix("Hu");

    cout << "\nUser 101 History:\n";
    showHistory(101);

    return 0;
}
