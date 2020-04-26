#include "Transaction.h"

Transaction::Transaction() {
    this->createClient();
    this->handleMenu();
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

int Transaction::displayMenu() {
    int option;

    do {
        cout << endl;
        cout << "--- Transaction Menu ---" << endl;
        cout << "1. Add a new item to the cart." << endl;
        cout << "2. List current items in cart." << endl;
        cout << "3. Remove an item from the cart." << endl;
        cout << "4. Complete the transaction." << endl;
        cout << "5. Dismiss the transaction." << endl;
        cin >> option;

        if (option < 1 || option > 5) {
            cout << "Invalid option!" << endl;
        }
    } while (option < 1 || option > 5);
    cout << endl;

    return option;
}

int Transaction::displayCoffeeOptions() {
    int option;

    do {
        cout << endl;
        cout << "--- Coffee Options ---" << endl;
        cout << "1. Espresso" << endl;
        cout << "2. Latte" << endl;
        cout << "3. Mocha" << endl;
        cout << "4. Cappuccino" << endl;
        cin >> option;

        if (option < 1 || option > 4) {
            cout << "Invalid option!" << endl;
        }
    } while (option < 1 || option > 4);
    cout << endl;

    return option;
}

int Transaction::displayCoffeeSizes() {
    int option;

    do {
        cout << endl;
        cout << "--- Coffee sizes available ---" << endl;
        cout << "1. Small" << endl;
        cout << "2. Medium" << endl;
        cout << "3. Large" << endl;
        cout << "4. Extra Large" << endl;
        cin >> option;

        if (option < 1 || option > 4) {
            cout << "Invalid option!" << endl;
        }
    } while (option < 1 || option > 4);
    cout << endl;

    return option;
}

void Transaction::createClient() {
    string clientName;
    long clientPhone;
    long clientID;
    string clientAddress;

    cout << "Insert client's name: ";
    cin >> clientName;

    do {
        cout << "Insert client's phone number: ";
        cin >> clientPhone;

        if (!cin.fail()) {
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid phone number." << endl;
    } while (true);

    do {
        cout << "Insert client's ID: ";
        cin >> clientID;

        if (!cin.fail()) {
            break;
        }

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid phone number." << endl;
    } while (true);

    cout << "Insert client's home address: ";
    cin >> clientAddress;

    this->client = new ShopClient(clientName, clientPhone, clientID, clientAddress);
}

CoffeeExtras Transaction::requestCoffeeExtras() {
    CoffeeExtras extras;

    extras["sugar"] = this->requestFor("sugar");
    extras["cocoa"] = this->requestFor("cocoa");
    extras["cinnamon"] = this->requestFor("cinnamon");
    extras["milk"] = this->requestFor("milk");
    extras["cream"] = this->requestFor("cream");
    cout << endl;

    return extras;
}

Size Transaction::requestCoffeeSize() {
    while (true) {
        int option = this->displayCoffeeSizes();

        switch (option) {
            case 1:
                return Small;
            case 2:
                return Medium;
            case 3:
                return Large;
            case 4:
                return ExtraLarge;
            default:
                throw "Invalid Coffee Size!";
        }
    }
}

int Transaction::requestItemToRemove() {
    int index;

    do {
        cout << endl;
        cout << "Enter item number to remove: ";
        cin >> index;

        if (index < 1 || index > this->items.size()) {
            cout << "Invalid item number." << endl;
        }
    } while (index < 1 || index > this->items.size());
    cout << endl;

    return index;
}

void Transaction::handleMenu() {
    while (true) {
        int option = this->displayMenu();

        switch (option) {
            case 1: {
                this->addItem();
                break;
            }

            case 2: {
                this->displayItems();
                break;
            }

            case 3: {
                this->displayItems();
                this->removeItem(this->requestItemToRemove() - 1);
                break;
            }

            case 4: {
                this->completeTransaction();
                return;
            }

            case 5: {
                this->dismissTransaction();
                return;
            }

            default: {
                throw "Invalid Transaction Option!";
            }
        }
    }
}

void Transaction::addItem() {
    int option = this->displayCoffeeOptions();
    Size size = this->requestCoffeeSize();
    CoffeeExtras extras = this->requestCoffeeExtras();
    Coffee coffee;

    switch (option) {
        case 1: {
            coffee = this->director.makeEspresso(size, extras);
            break;
        }

        case 2: {
            coffee = this->director.makeLatte(size, extras);
            break;
        }

        case 3: {
            coffee = this->director.makeMocha(size, extras);
            break;
        }

        case 4: {
            coffee = this->director.makeCapuccino(size, extras);
            break;
        }

        default: {
            throw "Invalid Coffee Option!";
        }
    }

    this->items.push_back(coffee);
    cout << "Item added to cart." << endl;
}

void Transaction::displayItems() {
    cout << "Current items in cart:" << endl;
    for (unsigned long i = 0; i < this->items.size(); i++) {
        cout << i + 1 << ": " << this->items[i].toString() << endl;
    }
    cout << endl;
}

void Transaction::removeItem(int index) {
    this->items.erase(this->items.begin() + index);
    cout << "Item removed from cart." << endl;
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
