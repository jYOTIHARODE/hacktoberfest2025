#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book {
private:
    int bookId;
    char title[50];
    float price;

public:
    Book() {
        bookId = 0;
        strcpy(title, "No Name");
        price = 0;
    }

    void getBookData() {
        cout << "\nEnter Book ID: ";
        cin >> bookId;
        cin.ignore(); // ignore newline after number
        cout << "Enter Book Title: ";
        cin.getline(title, 50);
        cout << "Enter Book Price: ";
        cin >> price;
    }

    void showBookData() const {
        cout << "\nBook ID: " << bookId
             << "\nBook Title: " << title
             << "\nBook Price: " << price << endl;
    }

    void storeBook() {
        if (bookId == 0 && price == 0) {
            cout << "\nInvalid Book Details!";
            return;
        }
        ofstream fout("books.dat", ios::app | ios::binary);
        fout.write(reinterpret_cast<char*>(this), sizeof(*this));
        fout.close();
        cout << "\nBook added successfully!\n";
    }

    void viewAllBooks() {
        ifstream fin("books.dat", ios::in | ios::binary);
        if (!fin) {
            cout << "\nNo books found.\n";
            return;
        }
        Book b;
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            b.showBookData();
        }
        fin.close();
    }

    void searchBook(const char* searchTitle) {
        ifstream fin("books.dat", ios::in | ios::binary);
        if (!fin) {
            cout << "\nNo books found.\n";
            return;
        }
        Book b;
        bool found = false;
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            if (strcmp(b.title, searchTitle) == 0) {
                b.showBookData();
                found = true;
            }
        }
        if (!found) cout << "\nBook not found.\n";
        fin.close();
    }

    void deleteBook(const char* delTitle) {
        ifstream fin("books.dat", ios::in | ios::binary);
        ofstream fout("temp.dat", ios::out | ios::binary);
        Book b;
        bool found = false;
        while (fin.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            if (strcmp(b.title, delTitle) != 0) {
                fout.write(reinterpret_cast<char*>(&b), sizeof(b));
            } else {
                found = true;
                cout << "\nDeleting Book: " << b.title << endl;
            }
        }
        fin.close();
        fout.close();
        remove("books.dat");
        rename("temp.dat", "books.dat");
        if (!found) cout << "\nBook not found to delete.\n";
    }

    void updateBook(const char* updateTitle) {
        fstream file("books.dat", ios::in | ios::out | ios::binary);
        Book b;
        bool found = false;
        while (file.read(reinterpret_cast<char*>(&b), sizeof(b))) {
            if (strcmp(b.title, updateTitle) == 0) {
                cout << "\nOld Book Details:\n";
                b.showBookData();
                cout << "\nEnter new details:\n";
                b.getBookData();
                file.seekp(-static_cast<int>(sizeof(b)), ios::cur);
                file.write(reinterpret_cast<char*>(&b), sizeof(b));
                found = true;
                cout << "\nBook updated successfully!\n";
                break;
            }
        }
        if (!found) cout << "\nBook not found to update.\n";
        file.close();
    }
};

int main() {
    Book b;
    int choice;
    char cont = 'y';
    char bookTitle[50];

    while (cont == 'y' || cont == 'Y') {
        cout << "\n\n=== Library Management Menu ===";
        cout << "\n1. Add Book";
        cout << "\n2. View All Books";
        cout << "\n3. Search Book";
        cout << "\n4. Update Book";
        cout << "\n5. Delete Book";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                b.getBookData();
                b.storeBook();
                break;
            case 2:
                b.viewAllBooks();
                break;
            case 3:
                cout << "\nEnter Book Title to Search: ";
                cin.getline(bookTitle, 50);
                b.searchBook(bookTitle);
                break;
            case 4:
                cout << "\nEnter Book Title to Update: ";
                cin.getline(bookTitle, 50);
                b.updateBook(bookTitle);
                break;
            case 5:
                cout << "\nEnter Book Title to Delete: ";
                cin.getline(bookTitle, 50);
                b.deleteBook(bookTitle);
                break;
            case 6:
                cout << "\nThank you for using the library system!\n";
                return 0;
            default:
                cout << "\nInvalid Choice! Please try again.\n";
        }

        cout << "\nDo you want to continue? (y/n): ";
        cin >> cont;
        cin.ignore();
    }

    return 0;
}
