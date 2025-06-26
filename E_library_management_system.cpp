#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    int pages;
    float price;
};

Book library[100];
int bookCount = 0;

void clearScreen() {
   
    for (int i = 0; i < 30; ++i)
        cout << endl;
}

void showBanner() {
    cout << "\n===========================================\n";
    cout << "        📚 WELCOME TO THE E-LIBRARY 📖      \n";
    cout << "===========================================\n";
}

void addBook() {
    cin.ignore();
    cout << "\nEnter Book Title: ";
    getline(cin, library[bookCount].title);
    
    cout << "Enter Author Name: ";
    getline(cin, library[bookCount].author);
    
    cout << "Enter Number of Pages: ";
    cin >> library[bookCount].pages;

    cout << "Enter Price: $";
    cin >> library[bookCount].price;

    bookCount++;
    cout << "\n✅ Book added successfully!\n";
}

void displayBooks() {
    if (bookCount == 0) {
        cout << "\n⚠️ No books in the library.\n";
        return;
    }

    cout << "\n📚 List of Books in the Library:\n";
   // cout << "-------------------------------------------\n";
    for (int i = 0; i < bookCount; ++i) {
        cout << i + 1 << ". \"" << library[i].title << "\" by " << library[i].author
             << " | Pages: " << library[i].pages << " | Price: $" << library[i].price << "\n";
    }
}

string toLower(string str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

void searchByAuthor() {
    cin.ignore();
    string searchAuthor;
    cout << "\nEnter Author Name: ";
    getline(cin, searchAuthor);

    bool found = false;
    cout << "\n🔍 Books by \"" << searchAuthor << "\":\n";
    for (int i = 0; i < bookCount; ++i) {
        if (toLower(library[i].author) == toLower(searchAuthor)) {
            cout << "- " << library[i].title << " | Pages: " << library[i].pages
                 << " | Price: $" << library[i].price << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "❌ No books found by this author.\n";
}

void searchByTitle() {
    cin.ignore();
    string searchTitle;
    cout << "\nEnter Book Title: ";
    getline(cin, searchTitle);

    bool found = false;
    for (int i = 0; i < bookCount; ++i) {
        if (toLower(library[i].title) == toLower(searchTitle)) {
            cout << "\n📘 Book Found:\n";
            cout << "- Title: " << library[i].title << "\n";
            cout << "- Author: " << library[i].author << "\n";
            cout << "- Pages: " << library[i].pages << "\n";
            cout << "- Price: $" << library[i].price << "\n";
            found = true;
            break;
        }
    }

    if (!found)
        cout << "❌ Book not found in the library.\n";
}

void countBooks() {
    cout << "\n📦 Total number of books: " << bookCount << "\n";
}

int main() {
    int choice;

    do {
        showBanner();
        cout << "\n1. 📥 Add Book\n2. 📋 Display All Books\n3. 🔍 Search by Author\n";
        cout << "4. 🔍 Search by Title\n5. 📦 Book Count\n6. 🧹 Clear Screen\n7. ❌ Exit\n";

        cout << "\nChoose an option (1-7): ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: searchByAuthor(); break;
            case 4: searchByTitle(); break;
            case 5: countBooks(); break;
            case 6: clearScreen(); break;
            case 7: cout << "\n👋 Thank you for using E-Library. Goodbye!\n"; break;
            default: cout << "\n⚠️ Invalid choice. Try again.\n";
        }

        cout << "\n-------------------------------------------\n";

    } while (choice != 7);

    return 0;
}
