#include "Client.h"

Client::Client() {

}

int Client::displayMenu() {
    int option;

    do {
        cout << endl;
        cout << "--- Coffee System v0.1 ---" << endl;
        cout << "1. Create a new transaction." << endl;
        cout << "2. Display last transaction." << endl;
        cout << "3. Display all transactions." << endl;
        cout << "4. Exit" << endl;
        option = safeIntCin();

        if (option < 1 || option > 4) {
            cout << "Invalid option!" << endl;
        }
    } while (option < 1 || option > 4);
    cout << endl;

    return option;
}

void Client::doDisplayTransaction(json transactionObj) {
    // TODO: Implement actual transaction display.
    cout << "Name: " << transactionObj["name"] << "\t id: " << transactionObj["id"] << endl;
}

void Client::handleMenu() {
    while (true) {
        int option = this->displayMenu();

        switch (option) {
            case 1: {
                this->createTransaction();
                break;
            }
            case 2: {
                this->displayLastTransaction();
                break;
            }
            case 3: {
                this->displayAllTransactions();
                break;
            }
            case 4: {
                cout << "Thank you for your patronage!" << endl;
                return;
            }
            default: {
                throw "Invalid Client Option!";
            }
        }
    }
}

void Client::createTransaction() {
    // TODO: Implement transaction creation.
    Transaction transaction;
}

void Client::displayLastTransaction() {
    json transactions = this->db.getTransactions();

    if (transactions.empty()) {
        cout << "There's no transactions to show! :(" << endl;
        return;
    }

    cout << "This this is the last transaction made:" << endl;
    doDisplayTransaction(transactions[0]);
}

void Client::displayAllTransactions() {
    json transactions = this->db.getTransactions();

    if (transactions.empty()) {
        cout << "There's no transactions to show! :(" << endl;
        return;
    }

    cout << "Here's a list of all the previous transactions:" << endl;
    for (json::iterator it = transactions.begin(); it != transactions.end(); ++it) {
        doDisplayTransaction(*it);
    }
}

void Client::init() {
    this->handleMenu();
}
