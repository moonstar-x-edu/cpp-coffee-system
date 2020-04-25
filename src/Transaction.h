#ifndef CPP_COFFEE_SYSTEM_TRANSACTION_H
#define CPP_COFFEE_SYSTEM_TRANSACTION_H

#include <iostream>
#include <vector>
#include <ctime>
#include <map>
#include <string>
#include "CoffeeDirector.h"
#include "ShopClient.h"
#include "IJSONizable.h"

using namespace std;

using CoffeeExtras = map<string, bool>;

class Transaction : public IJSONizable {
    private:
        ShopClient* client;
        vector<Coffee> items;
        double amount;
        time_t timestamp;

        CoffeeDirector director;

        void createClient();
        static bool requestFor(string extra);
        CoffeeExtras requestCoffeeDetails();

    public:
        Transaction();

        void displayMenu();
        void handleMenu();
        void displayItems();
        void addItem();
        void removeItem();
        void completeTransaction();
        void dismissTransaction();

        json toJSON() override;
};

#endif //CPP_COFFEE_SYSTEM_TRANSACTION_H
