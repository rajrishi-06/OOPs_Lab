#include <iostream>
#include <stdexcept>

class LibraryBook {
private:
    int bookID;
    int availableCopies;

public:
    LibraryBook(int id, int copies)
        : bookID(id), availableCopies(copies) {}

    void borrowBook(int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive.");
        }
        if (quantity > availableCopies) {
            throw std::out_of_range("Not enough copies available.");
        }
        availableCopies -= quantity;
        std::cout << "Successfully borrowed " << quantity 
                  << " copy(ies). Remaining: " << availableCopies << "\n";
    }

    void returnBook(int quantity) {
        if (quantity <= 0) {
            throw std::invalid_argument("Quantity must be positive.");
        }
        availableCopies += quantity;
        std::cout << "Successfully returned " << quantity 
                  << " copy(ies). Available now: " << availableCopies << "\n";
    }

    int getAvailableCopies() const {
        return availableCopies;
    }
};

int main() {
    LibraryBook book(1001, 5);
    int choice, qty;

    while (true) {
        std::cout << "\nLibrary Book ID: 1001 | Copies Available: " 
                  << book.getAvailableCopies() << "\n";
        std::cout << "1. Borrow Book\n2. Return Book\n3. Exit\nChoice: ";
        std::cin >> choice;

        if (choice == 3) break;

        std::cout << "Enter quantity: ";
        std::cin >> qty;

        try {
            if (choice == 1) {
                book.borrowBook(qty);
            } else if (choice == 2) {
                book.returnBook(qty);
            } else {
                std::cout << "Invalid choice.\n";
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error: " << e.what() << "\n";
        }
    }

    std::cout << "Goodbye!\n";
    return 0;
}
