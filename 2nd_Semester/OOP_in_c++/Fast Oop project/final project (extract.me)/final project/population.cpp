#include "Stronghold.h"

Population::Population() {
    groups[PEASANT] = { PEASANT, 150, 50.0 };
    groups[MERCHANT] = { MERCHANT, 200, 60.0 };
    groups[NOBLE] = { NOBLE, 100, 80.0 };
    groups[SOLDIER] = { SOLDIER, 200, 40.0 };
    groups[CIVILAN] = { CIVILAN, 700, 70.0 };

    growthRate = 0.05;
    health = 75.0;
}

void Population::update(Kingdom& kingdom) {
    for (int i = 0; i < SOCIAL_CLASS_COUNT; i++) {
        groups[i].count += (groups[i].count * growthRate);
    }
}

int Population::getTotalPopulation() const {
    int total = 0;
    for (int i = 0; i < SOCIAL_CLASS_COUNT; i++) {
        total += groups[i].count;
    }
    return total;
}

void Population::adjustHappiness(SocialClass type, double delta) {
    happiness[type] += delta;
    happiness[type] = max(0.0, min(happiness[type], 100.0));
}


void Population::addPopulation(SocialClass sClass, int count) {
    if (sClass >= 0 && sClass < SOCIAL_CLASS_COUNT) {
        groups[sClass].count += count;
    }
}

bool Population::removePopulation(SocialClass sClass, int count) {
    if (sClass >= 0 && sClass < SOCIAL_CLASS_COUNT && groups[sClass].count >= count) {
        groups[sClass].count -= count;
        return true;
    }
    return false;
}

int Population::getCount(SocialClass sClass) const {
    if (sClass >= 0 && sClass < SOCIAL_CLASS_COUNT) {
        return groups[sClass].count;
    }
    return 0;
}

double Population::getHappiness(SocialClass sClass) const {
    if (sClass >= 0 && sClass < SOCIAL_CLASS_COUNT) {
        return groups[sClass].happiness;
    }
    return 0;
}

double Population::getOverallHappiness() const {
    double totalHappiness = 0;
    for (int i = 0; i < SOCIAL_CLASS_COUNT; i++) {
        totalHappiness += groups[i].happiness;
    }
    return totalHappiness / SOCIAL_CLASS_COUNT;
}

void Population::affectHealth(double amount) {
    health += amount;
}