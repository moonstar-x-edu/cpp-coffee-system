#include "Transaction.h"

Transaction::Transaction() {
    this->createClient();
}

void Transaction::createClient() {
    string clientName;
    long clientPhone;
    long clientID;
    string clientAddress;

    cout << "Insert client's name: ";
    cin >> clientName;
    cout << "Insert client's phone number: ";
    cin >> clientPhone;
    cout << "Insert client's ID; ";
    cin >> clientID;
    cout << "Insert client's home address: ";
    cin >> clientAddress;

    this->client = new ShopClient(clientName, clientPhone, clientID, clientAddress);
}

bool Transaction::requestFor(string extra) {
    char response;

    do {
        cout << "With " << extra << "? (y/n) ";
        cin >> response;

        if (response != 'y' && response != 'n') {
            cout << "Invalid answer. Please enter 'y' or 'n'." << endl;
        }
    } while (response != 'y' && response != 'n');

    return response == 'y';
}

CoffeeExtras Transaction::requestCoffeeDetails() {
    CoffeeExtras extras;

    extras["sugar"] = this->requestFor("sugar");
    extras["cocoa"] = this->requestFor("cocoa");
    extras["cinnamon"] = this->requestFor("cinnamon");
    extras["milk"] = this->requestFor("milk");
    extras["cream"] = this->requestFor("cream");

    return extras;
}

void Transaction::displayMenu() {
    // TODO: Implement menu.
}

void Transaction::handleMenu() {
    //TODO: Implement menu handle.
}

void Transaction::displayItems() {
    cout << "Current items in cart:" << endl;
    for (unsigned long i = 0; i < this->items.size(); i++) {
        cout << this->items[i].toString() << endl;
    }
    cout << endl;
}

void Transaction::addItem() {
    // TODO: Implement create coffee.
}

void Transaction::removeItem() {
    // TODO: Implement remove item.
}

void Transaction::completeTransaction() {
    // TODO: Implement transaction complete.
}

void Transaction::dismissTransaction() {
    // TODO: Implement transaction dismiss.
}

json Transaction::toJSON() {
    json j;
    json jsonItems;
    for (unsigned long i = 0; i < this->items.size(); i++) {
        jsonItems.push_back(this->items[i].toJSON());
    }

    j["client"] = this->client->toJSON();
    j["items"] = jsonItems;
    j["amount"] = amount;
    j["date"] = asctime(localtime(&this->timestamp));

    return j;
}
