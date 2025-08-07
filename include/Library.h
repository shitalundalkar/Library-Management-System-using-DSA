#ifndef LIBRARY_H
#define LIBRARY_H

#include "Book.h"

class Library {
private:
    Book* head;

public:
    Library();
    void addBook(int id, string title, string author, string genre);
    void removeBook(int id);
    void displayBooks();
    Book* findBook(int id);
    Book* getHead();
};

#endif
