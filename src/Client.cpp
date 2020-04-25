#include "Client.h"

Client::Client() {

}

void Client::init() {
    // TODO: Call menu and handle option selection.
}

void Client::displayMenu() {
    // TODO: Implement menu display.
}

void Client::createTransaction() {
    // TODO: Implement a transaction creation method.
}

void Client::displayLastTransaction() {
    json transactions = this->db.getTransactions();

    doDisplayTransaction(transactions[0]);
}

void Client::displayAllTransactions() {
    json transactions = this->db.getTransactions();

    for (json::iterator it = transactions.begin(); it != transactions.end(); ++it) {
        doDisplayTransaction(*it);
    }
}

void Client::doDisplayTransaction(json transactionObj) {
    // TODO: Implement actual transaction display.
    cout << "Name: " << transactionObj["name"] << "\t id: " << transactionObj["id"] << endl;
}
