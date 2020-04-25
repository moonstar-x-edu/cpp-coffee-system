#include "CoffeeDirector.h"

// TODO: Implement how extras are added to the coffee.

CoffeeDirector::CoffeeDirector() {

}

Coffee CoffeeDirector::makeEspresso() {
    this->builder.reset();

    this->builder.setName("Espresso");
    this->builder.setBeans(Bitter);
    this->builder.setSize(Small);
    this->builder.setBasePrice(3);

    return this->builder.getResult();
}

Coffee CoffeeDirector::makeLatte() {
    this->builder.reset();

    this->builder.setName("Latte");
    this->builder.setBeans(Arabic);
    this->builder.setSize(Medium);
    this->builder.setBasePrice(3.5);

    return this->builder.getResult();
}

Coffee CoffeeDirector::makeMocha() {
    this->builder.reset();

    this->builder.setName("Mocha");
    this->builder.setBeans(Colombian);
    this->builder.setSize(Large);
    this->builder.setBasePrice(2.8);

    return this->builder.getResult();
}

Coffee CoffeeDirector::makeCapuccino() {
    this->builder.reset();

    this->builder.setName("Capuccino");
    this->builder.setBeans(Arabic);
    this->builder.setSize(ExtraLarge);
    this->builder.setBasePrice(2.25);

    return this->builder.getResult();
}
