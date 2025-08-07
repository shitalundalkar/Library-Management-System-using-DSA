#include "Library.h"
#include <iostream>
using namespace std;

Library::Library() {
    head = nullptr;
}

void Library::addBook(int id, string title, string author, string genre) {
    Book* newBook = new Book(id, title, author, genre);
    newBook->next = head;
    head = newBook;
    cout << "Book added successfully.\n";
}

void Library::removeBook(int id) {
    Book* curr = head;
    Book* prev = nullptr;
    while (curr) {
        if (curr->id == id) {
            if (prev) prev->next = curr->next;
            else head = curr->next;
            delete curr;
            cout << "Book removed.\n";
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Book not found.\n";
}

void Library::displayBooks() {
    Book* temp = head;
    while (temp) {
        cout << temp->id << " - " << temp->title << " by " << temp->author
             << " [" << (temp->isAvailable ? "Available" : "Borrowed") << "]\n";
        temp = temp->next;
    }
}

Book* Library::findBook(int id) {
    Book* temp = head;
    while (temp) {
        if (temp->id == id) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Book* Library::getHead() {
    return head;
}
