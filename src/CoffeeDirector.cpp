#include "CoffeeDirector.h"

CoffeeDirector::CoffeeDirector() {

}

void CoffeeDirector::handleAddExtras(CoffeeExtras extras) {
    if (extras["sugar"]) {
        this->builder.withSugar();
    }
    if (extras["cocoa"]) {
        this->builder.withCocoa();
    }
    if (extras["cinnamon"]) {
        this->builder.withCinnamon();
    }
    if (extras["milk"]) {
        this->builder.withMilk();
    }
    if (extras["cream"]) {
        this->builder.withCream();
    }
}

Coffee CoffeeDirector::makeEspresso(Size size, CoffeeExtras extras) {
    this->builder.reset();

    this->builder.setName("Espresso");
    this->builder.setBeans(Bitter);
    this->builder.setSize(size);
    this->builder.setBasePrice(3);
    this->handleAddExtras(extras);

    return this->builder.getResult();
}

Coffee CoffeeDirector::makeLatte(Size size, CoffeeExtras extras) {
    this->builder.reset();

    this->builder.setName("Latte");
    this->builder.setBeans(Arabic);
    this->builder.setSize(size);
    this->builder.setBasePrice(3.5);
    this->handleAddExtras(extras);

    return this->builder.getResult();
}

Coffee CoffeeDirector::makeMocha(Size size, CoffeeExtras extras) {
    this->builder.reset();

    this->builder.setName("Mocha");
    this->builder.setBeans(Colombian);
    this->builder.setSize(size);
    this->builder.setBasePrice(2.8);
    this->handleAddExtras(extras);

    return this->builder.getResult();
}

Coffee CoffeeDirector::makeCapuccino(Size size, CoffeeExtras extras) {
    this->builder.reset();

    this->builder.setName("Capuccino");
    this->builder.setBeans(Arabic);
    this->builder.setSize(size);
    this->builder.setBasePrice(2.25);
    this->handleAddExtras(extras);

    return this->builder.getResult();
}
