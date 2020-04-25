#ifndef CPP_COFFEE_SYSTEM_SHOPCLIENT_H
#define CPP_COFFEE_SYSTEM_SHOPCLIENT_H

#include <string>
#include "IJSONizable.h"

using namespace std;

class ShopClient : public IJSONizable {
    private:
        string name;
        long phone;
        long id;
        string address;

    public:
        ShopClient(string name, long phone, long id, string address);

        string getName();
        long getPhone();
        long getID();
        string getAddress();

        json toJSON() override;
};

#endif //CPP_COFFEE_SYSTEM_SHOPCLIENT_H
