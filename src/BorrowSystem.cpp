#include "BorrowSystem.h"
#include <iostream>
using namespace std;

unordered_map<int, vector<int>> userBorrowedBooks;
unordered_map<int, queue<int>> bookWaitlist;

void borrowBook(Library& lib, int bookId, int userId) {
    Book* book = lib.findBook(bookId);
    if (!book) {
        cout << "Book not found.\n";
        return;
    }
    if (book->isAvailable) {
        book->isAvailable = false;
        userBorrowedBooks[userId].push_back(bookId);
        cout << "Book borrowed successfully.\n";
    } else {
        bookWaitlist[bookId].push(userId);
        cout << "Book unavailable. Added to waitlist.\n";
    }
}

void returnBook(Library& lib, int bookId, int userId) {
    Book* book = lib.findBook(bookId);
    if (!book) {
        cout << "Book not found.\n";
        return;
    }
    book->isAvailable = true;
    cout << "Book returned.\n";

    if (!bookWaitlist[bookId].empty()) {
        int nextUser = bookWaitlist[bookId].front();
        bookWaitlist[bookId].pop();
        userBorrowedBooks[nextUser].push_back(bookId);
        book->isAvailable = false;
        cout << "Book assigned to next user in waitlist (User " << nextUser << ").\n";
    }
}
