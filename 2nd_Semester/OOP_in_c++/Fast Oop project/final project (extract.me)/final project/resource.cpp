#include "Stronghold.h"
using namespace std;
Resource::Resource() : type(RESOURCE_TYPE_COUNT), amount(0) {}
Resource::Resource(ResourceType type, double amount) : type(type), amount(amount) {}
void Resource::gather(double a) {
    this->amount += a;
}
void Resource::consume(double a) {
    this->amount -= a;
}
void Resource::trade(double a) {
    this->amount -= a;
}
ResourceType Resource::getType() const {
    return this->type;
}
double Resource::getAmount() const {
    return this->amount;
}
void Resource::setAmount(double amt) {
    this->amount = amt;
}
void Resource::update(Kingdom& kingdom) {
    if (kingdom.getEconomy().getTaxRate() > 0.5) {
        amount -= 0.1 * amount;
    }
    if (kingdom.getPopulation().getOverallHappiness() < 50) {
        amount -= 0.05 * amount;
    }
}