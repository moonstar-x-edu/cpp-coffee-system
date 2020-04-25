#ifndef CPP_COFFEE_SYSTEM_CLIENT_H
#define CPP_COFFEE_SYSTEM_CLIENT_H

#include <iostream>
#include "JSONFacade.h"
#include "Transaction.h"

using namespace std;

class Client {
    private:
        JSONFacade db;
        static void doDisplayTransaction(json transactionObj);

    public:
        Client();

        static int displayMenu();
        void init();
        void handleMenu();
        void createTransaction();
        void displayLastTransaction();
        void displayAllTransactions();
};

#endif //CPP_COFFEE_SYSTEM_CLIENT_H
