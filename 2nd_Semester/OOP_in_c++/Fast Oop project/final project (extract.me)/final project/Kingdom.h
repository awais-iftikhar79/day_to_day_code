#ifndef KINGDOM_H
#define KINGDOM_H

#include "Military.h"
#include "Population.h"
#include "Economy.h"
#include "ResourceManager.h"

class Kingdom {
private:
    Military military;
    Population population;
    Economy economy;
    ResourceManager resourceManager;

public:
    Kingdom();
    Military& getMilitary();
    Population& getPopulation();
    Economy& getEconomy();
    ResourceManager& getResourceManager();

    void update();            // Updates the kingdom's state for the next turn
    void handleEvents();      // Handles random events
    void checkFinancialHealth(); // Checks the financial health of the kingdom
};

#endif // KINGDOM_H