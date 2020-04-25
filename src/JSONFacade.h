#ifndef CPP_COFFEE_SYSTEM_JSONFACADE_H
#define CPP_COFFEE_SYSTEM_JSONFACADE_H

#include <string>
#include <fstream>
#include <iomanip>
#include "json.hpp"

using namespace std;
using json = nlohmann::json;

class JSONFacade {
    private:
        string filename;
        json readFromFile();
        void writeToFile(json j);
        void createFile();
        bool fileExists();

    public:
        JSONFacade();
        JSONFacade(string filename);

        json getTransactions();
        void createTransaction();
};

#endif //CPP_COFFEE_SYSTEM_JSONFACADE_H
