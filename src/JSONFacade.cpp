#include "JSONFacade.h"

JSONFacade::JSONFacade() {
    this->filename = "../data/transactions.json";

    if (!this->fileExists()) {
        this->createFile();
    }
}

JSONFacade::JSONFacade(string filename) {
    this->filename = filename;

    if (!this->fileExists()) {
        this->createFile();
    }
}

json JSONFacade::readFromFile() {
    ifstream file(this->filename);
    json j;
    file >> j;
    return j;
}

void JSONFacade::writeToFile(json j) {
    ofstream file(this->filename);
    file << setw(4) << j << endl;
}

void JSONFacade::createFile() {
    ofstream file(this->filename);
    file << "[ ]" << endl;
}

bool JSONFacade::fileExists() {
    ifstream file(this->filename);
    return file.good();
}

json JSONFacade::getTransactions() {
    return this->readFromFile();
}

void JSONFacade::createTransaction(json transaction) {
    json data = this->readFromFile();
    data.insert(data.begin(), transaction);
    this->writeToFile(data);
}
