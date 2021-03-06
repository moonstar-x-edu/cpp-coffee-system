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
    cout << "Transaction date: " << transactionObj["date"].get<string>() << endl;
    cout << "Client: " << transactionObj["client"]["name"].get<string>() << " ID: " << transactionObj["client"]["id"] << endl;
    cout << "Phone: " << transactionObj["client"]["phone"] << " Address: " << transactionObj["client"]["address"].get<string>() << endl << endl;

    cout << "Items purchased:" << endl;
    for (auto& item : transactionObj["items"]) {
        cout << item["size"].get<string>() << " " << item["name"].get<string>() << item["extrasString"].get<string>() << " Price: $" << item["price"].get<string>() << endl;
    }
    cout << endl;

    cout << "Total: $" << transactionObj["amount"].get<string>() << endl;
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
    Transaction transaction;

    if (transaction.wasSuccessful()) {
        this->db.createTransaction(transaction.toJSON());
    }
}

void Client::displayLastTransaction() {
    json transactions = this->db.getTransactions();

    if (transactions.empty()) {
        cout << "There's no transactions to show! :(" << endl;
        return;
    }

    cout << "This this is the last transaction made:" << endl;
    doDisplayTransaction(transactions[0]);
    cout << endl;
}

void Client::displayAllTransactions() {
    json transactions = this->db.getTransactions();

    if (transactions.empty()) {
        cout << "There's no transactions to show! :(" << endl;
        return;
    }

    cout << "Here's a list of all the previous transactions:" << endl;
    for (auto& item : transactions) {
        cout << "_________________" << endl;
        doDisplayTransaction(item);
        cout << endl;
    }
}

void Client::init() {
    this->handleMenu();
}
