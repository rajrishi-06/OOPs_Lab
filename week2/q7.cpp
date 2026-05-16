#include <iostream>
#include <vector>
using namespace std;

class Member;
class LibraryBook {
private:
    int bookID;
    string title, author;
public:
    LibraryBook(int id, string t, string a) : bookID(id), title(t), author(a) {}
    friend void displayBorrowDetails(const LibraryBook&, const Member&);
};

class Member {
private:
    string memberName;
    int memberID;
    vector<LibraryBook> borrowedBooks;
public:
    Member(string name, int id) : memberName(name), memberID(id) {}
    void borrowBook(const LibraryBook& book) {
        borrowedBooks.push_back(book);
    }
    friend void displayBorrowDetails(const LibraryBook&, const Member&);
};

void displayBorrowDetails(const LibraryBook& book, const Member& member) {
    cout << member.memberName << " (ID: " << member.memberID << ") borrowed " 
         << book.title << " by " << book.author << " (Book ID: " << book.bookID << ")\n";
}

int main() {
    LibraryBook book1(101, "C++ Programming", "Bjarne Stroustrup");
    LibraryBook book2(102, "Data Structures", "Mark Weiss");

    Member member("Alice", 1);
    member.borrowBook(book1);
    member.borrowBook(book2);

    displayBorrowDetails(book1, member);
    displayBorrowDetails(book2, member);

    return 0;
}