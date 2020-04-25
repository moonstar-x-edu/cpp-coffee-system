#include "Client.h"

Client::Client() {

}

void Client::init() {
    this->displayAllTransactions();
    cout << endl;
    this->displayLastTransaction();
}

void Client::displayMenu() {

}

void Client::createTransaction() {

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
    cout << "Name: " << transactionObj["name"] << "\t id: " << transactionObj["id"] << endl;
}
