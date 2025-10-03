#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Expense structure
struct Expense {
    string category;
    double amount;
    string note;
};

// Expense Tracker class
class ExpenseTracker {
private:
    vector<Expense> expenses;

public:
    void addExpense(string category, double amount, string note) {
        Expense e;
        e.category = category;
        e.amount = amount;
        e.note = note;
        expenses.push_back(e);
        cout << "\n✅ Expense added successfully!\n";
    }

    void viewExpenses() {
        if (expenses.empty()) {
            cout << "\nNo expenses recorded yet.\n";
            return;
        }
        cout << "\n--- All Expenses ---\n";
        cout << left << setw(15) << "Category"
             << setw(10) << "Amount"
             << setw(30) << "Note" << endl;
        cout << "-----------------------------------------------\n";
        for (auto &e : expenses) {
            cout << left << setw(15) << e.category
                 << setw(10) << e.amount
                 << setw(30) << e.note << endl;
        }
    }

    void reportByCategory() {
        if (expenses.empty()) {
            cout << "\nNo expenses recorded yet.\n";
            return;
        }
        double food = 0, travel = 0, shopping = 0, others = 0;
        for (auto &e : expenses) {
            if (e.category == "Food") food += e.amount;
            else if (e.category == "Travel") travel += e.amount;
            else if (e.category == "Shopping") shopping += e.amount;
            else others += e.amount;
        }
        cout << "\n--- Expense Report By Category ---\n";
        cout << "Food:     " << food << endl;
        cout << "Travel:   " << travel << endl;
        cout << "Shopping: " << shopping << endl;
        cout << "Others:   " << others << endl;
        cout << "---------------------------------\n";
        cout << "Total:    " << (food + travel + shopping + others) << endl;
    }
};

int main() {
    ExpenseTracker tracker;
    int choice;
    string category, note;
    double amount;

    do {
        cout << "\n====== Personal Expense Tracker ======\n";
        cout << "1. Add Expense\n";
        cout << "2. View All Expenses\n";
        cout << "3. Report by Category\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter category (Food/Travel/Shopping/Others): ";
                getline(cin, category);
                cout << "Enter amount: ";
                cin >> amount;
                cin.ignore();
                cout << "Enter note: ";
                getline(cin, note);
                tracker.addExpense(category, amount, note);
                break;

            case 2:
                tracker.viewExpenses();
                break;

            case 3:
                tracker.reportByCategory();
                break;

            case 4:
                cout << "\n💡 Exiting... Thanks for using Expense Tracker!\n";
                break;

            default:
                cout << "\n❌ Invalid choice, try again.\n";
        }
    } while (choice != 4);

    return 0;
}
