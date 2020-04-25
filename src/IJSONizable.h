#ifndef CPP_COFFEE_SYSTEM_IJSONIZABLE_H
#define CPP_COFFEE_SYSTEM_IJSONIZABLE_H

#include "json.hpp"

using json = nlohmann::json;

class IJSONizable {
    public:
        virtual ~IJSONizable() = default;
        virtual json toJSON() = 0;
};

#endif //CPP_COFFEE_SYSTEM_IJSONIZABLE_H
