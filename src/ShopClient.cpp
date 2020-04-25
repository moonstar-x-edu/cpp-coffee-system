#include "ShopClient.h"

ShopClient::ShopClient(string name, long phone, long id, string address) {
    this->name = name;
    this->phone = phone;
    this->id = id;
    this->address = address;
}

string ShopClient::getName() {
    return this->name;
}

long ShopClient::getPhone() {
    return this->phone;
}

long ShopClient::getID() {
    return this->id;
}

string ShopClient::getAddress() {
    return this->address;
}

json ShopClient::toJSON() {
    json j;

    j["name"] = this->name;
    j["phone"] = this->phone;
    j["id"] = this->id;
    j["address"] = this->address;

    return j;
}
