#ifndef CPP_COFFEE_SYSTEM_CLIENT_H
#define CPP_COFFEE_SYSTEM_CLIENT_H

#include <iostream>
#include "JSONFacade.h"
#include "Transaction.h"
#include "utils.h"

using namespace std;

class Client {
    private:
        JSONFacade db;

        static int displayMenu();
        static void doDisplayTransaction(json transactionObj);

        void handleMenu();
        void createTransaction();
        void displayLastTransaction();
        void displayAllTransactions();

    public:
        Client();

        void init();
};

#endif //CPP_COFFEE_SYSTEM_CLIENT_H
