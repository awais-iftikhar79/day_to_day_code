#include "Stronghold.h"
#include <iostream>

using namespace std;

Kingdom::Kingdom() {
    population = Population();
    leadership = Leadership("King Arthur");
    economy = Economy();
    bank = Bank();
    military = Military();
    resourceManager = ResourceManager();
    eventManager = EventManager();
    corruption = Corruption();
}

void Kingdom::update() {
    population.update(*this);
    leadership.update(*this);
    bank.update(*this);
    military.update(*this);
    resourceManager.update(*this);
    eventManager.update(*this);
    corruption.update(*this);
}

void Kingdom::checkFinancialHealth() {

    if (economy.getGoldReserve() < 1000.0) {
        cout << "Warning: Low gold reserve!" << endl;
    }
    if (economy.getTaxRate() > 0.5) {
        cout << "Warning: High tax rate!" << endl;
    }
}

void Kingdom::handleEvents() {
    eventManager.generateRandomEvent();
    Event latestEvent = eventManager.getLatestEvent();
    eventManager.applyEvent(latestEvent);
    eventManager.handleEvent(*this, latestEvent);
}




Population& Kingdom::getPopulation() {
    return population;
}

Leadership& Kingdom::getLeadership() {
    return leadership;
}

Bank& Kingdom::getBank() {
    return bank;
}

Military& Kingdom::getMilitary() {
    return military;
}

ResourceManager& Kingdom::getResourceManager() {
    return resourceManager;
}

Economy& Kingdom::getEconomy() {
    return economy;
}

EventManager& Kingdom::getEventManager() {
    return eventManager;
}

Corruption& Kingdom::getCorruption() {
    return corruption;
}