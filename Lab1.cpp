#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    double price;
    int quantity;

    Book() = default;

    Book(int id, const string& title, const string& author, double price, int quantity)
        : id(id), title(title), author(author), price(price), quantity(quantity) {}

    string to_string() const {
        return std::to_string(id) + "," + title + "," + author + "," + std::to_string(price) + "," + std::to_string(quantity);
    }

    static Book from_string(const string& str) {
        stringstream ss(str);
        string item;
        int id, quantity;
        string title, author;
        double price;

        getline(ss, item, ',');
        id = stoi(item);
        getline(ss, title, ',');
        getline(ss, author, ',');
        getline(ss, item, ',');
        price = stod(item);
        getline(ss, item);
        quantity = stoi(item);

        return Book(id, title, author, price, quantity);
    }
};

void addBook() {
    ofstream file("books.txt", ios::app);
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    int id, quantity;
    string title, author;
    double price;

    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore(); 
    cout << "Enter Title: ";
    getline(cin, title);
    cout << "Enter Author: ";
    getline(cin, author);
    cout << "Enter Price: ";
    cin >> price;
    cout << "Enter Quantity: ";
    cin >> quantity;

    Book book(id, title, author, price, quantity);
    file << book.to_string() << endl;
    file.close();
    cout << "Book added successfully!" << endl;
}

void showBooks() {
    ifstream file("books.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    cout << "Book Records:\n";
    while (getline(file, line)) {
        Book book = Book::from_string(line);
        cout << "ID: " << book.id 
             << ", Title: " << book.title 
             << ", Author: " << book.author 
             << ", Price: " << book.price 
             << ", Quantity: " << book.quantity << endl;
    }
    file.close();
}

void checkAvailability() {
    int id;
    cout << "Enter Book ID to check availability: ";
    cin >> id;

    ifstream file("books.txt");
    if (!file) {
        cerr << "Error opening file!" << endl;
        return;
    }

    string line;
    bool found = false;
    while (getline(file, line)) {
        Book book = Book::from_string(line);
        if (book.id == id) {
            found = true;
            cout << "Book is available: " << book.title << ", Quantity: " << book.quantity << endl;
            break;
        }
    }

    if (!found) {
        cout << "Book not found!" << endl;
    }

    file.close();
}

void modifyBook() {
    int id;
    cout << "Enter Book ID to modify: ";
    cin >> id;

    ifstream file("books.txt");
    vector<Book> books;
    string line;
    bool found = false;

    while (getline(file, line)) {
        Book book = Book::from_string(line);
        if (book.id == id) {
            found = true;
            cout << "Modifying Book - Current Details:\n"
                 << "Title: " << book.title << "\nAuthor: " << book.author 
                 << "\nPrice: " << book.price << "\nQuantity: " << book.quantity << endl;

            string title, author;
            double price;
            int quantity;

            cout << "Enter new Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter new Author: ";
            getline(cin, author);
            cout << "Enter new Price: ";
            cin >> price;
            cout << "Enter new Quantity: ";
            cin >> quantity;

            books.push_back(Book(id, title, author, price, quantity));
        } else {
            books.push_back(book);
        }
    }

    file.close();

    if (!found) {
        cout << "Book not found!" << endl;
        return;
    }

    ofstream outFile("books.txt");
    for (const auto& b : books) {
        outFile << b.to_string() << endl;
    }
    outFile.close();
    cout << "Book modified successfully!" << endl;
}

void deleteBook() {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    ifstream file("books.txt");
    vector<Book> books;
    string line;
    bool found = false;

    while (getline(file, line)) {
        Book book = Book::from_string(line);
        if (book.id != id) {
            books.push_back(book);
        } else {
            found = true;
        }
    }

    file.close();

    if (!found) {
        cout << "Book not found!" << endl;
        return;
    }

    ofstream outFile("books.txt");
    for (const auto& b : books) {
        outFile << b.to_string() << endl;
    }
    outFile.close();
    cout << "Book deleted successfully!" << endl;
}

int main() {
    int choice;

    do {
        cout << "\nBookshop Management System\n";
        cout << "1. Add Book Records\n";
        cout << "2. Show Book Records\n";
        cout << "3. Check Availability\n";
        cout << "4. Modify Book Records\n";
        cout << "5. Delete Book Records\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addBook(); break;
            case 2: showBooks(); break;
            case 3: checkAvailability(); break;
            case 4: modifyBook(); break;
            case 5: deleteBook(); break;
            case 6: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice! Please try again." << endl; break;
        }
    } while (choice != 6);

    return 0;
}
