#include"Stronghold.h"
#include <iostream>
using namespace std;

Economy::Economy() : goldReserve(1000.0), taxRate(10.0) {}

void Economy::adjustTaxRate(double rate) {
    if (rate < 0.0 || rate > 1.0) {
        cout << "Invalid tax rate. Must be between 0.0 and 1.0\n";
        return;
    }

    taxRate = rate;
    if (rate > 0.7) {
        inflationRate -= 0.5;
    }
    else if (rate < 0.3) {
        inflationRate += 0.5;
    }
    else {
        inflationRate += 0.1;
    }

    inflationRate = max(0.0, min(inflationRate, 20.0));

    cout << "Tax rate set to " << taxRate * 100 << "%.\n";
    cout << "Inflation adjusted to " << inflationRate << "%.\n";
}


void Economy::update(Kingdom& kingdom) {
    double income = kingdom.getPopulation().getTotalPopulation() * taxRate * 0.1;
    goldReserve += income;
}
void Economy::adjustInflation(double a) {
    inflationRate = a;
}
void Economy::tradeResources() {


    goldReserve += 500.0;
}
void Economy::fundPublicServices() {
    goldReserve -= 200.0;
}
double Economy::getInflation() const {
    return inflationRate;
}

double Economy::getGoldReserve() const {
    return goldReserve;
}

double Economy::getTaxRate() const {
    return taxRate;
}