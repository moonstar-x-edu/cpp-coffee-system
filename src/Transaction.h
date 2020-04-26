#ifndef CPP_COFFEE_SYSTEM_TRANSACTION_H
#define CPP_COFFEE_SYSTEM_TRANSACTION_H

// TODO: remove new line from date
// TODO: price up to 2 decimal

#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <string>
#include "CoffeeDirector.h"
#include "ShopClient.h"
#include "IJSONizable.h"
#include "utils.h"

using namespace std;

class Transaction : public IJSONizable {
    private:
        ShopClient* client;
        vector<Coffee> items;
        double amount;
        time_t timestamp;

        CoffeeDirector director;
        bool successful;

        static bool requestFor(string extra);
        static int displayMenu();
        static int displayCoffeeOptions();
        static int displayCoffeeSizes();

        void createClient();
        CoffeeExtras requestCoffeeExtras();
        Size requestCoffeeSize();
        int requestItemToRemove();

        void handleMenu();
        void addItem();
        void displayItems();
        void removeItem(int index);
        void completeTransaction();
        void dismissTransaction();

    public:
        Transaction();

        bool wasSuccessful();
        json toJSON() override;
};

#endif //CPP_COFFEE_SYSTEM_TRANSACTION_H
