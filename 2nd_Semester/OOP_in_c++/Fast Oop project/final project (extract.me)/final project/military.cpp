#include "Stronghold.h"
#include<iostream>
Military::Military() {
    soldierCount = 100;
    morale = 50.0;
    foodRequired = 0.0;
    payRequired = 0.0;
    corruptionLevel = 0.0;
}
void Military::recruitSoldiers() {
    int randomRecruits = rand() % 21 + 10;
    soldierCount += randomRecruits;
    cout << randomRecruits << " soldiers were recruited in this attempt.\n";
}
void Military::trainSoldiers(int count) {
    if (count <= 0) {
        cout << "Cannot train zero or negative soldiers!\n";
        return;
    }
    if (count > soldierCount) {
        cout << "Not enough soldiers available to train!\n";
        return;
    }
    morale = min(1.0, morale + (count * 0.01));
    cout << count << " soldiers completed basic training.\n";
    cout << "Morale improved to " << (morale * 100) << "%\n";
}
void Military::update(Kingdom& kingdom) {
    manageMorale();
    if (foodRequired > 0) {
        foodRequired -= 1.0;
        if (foodRequired < 0.0) foodRequired = 0.0;
    }
    if (payRequired > 0) {
        paySoldiers();
    }
}
void Military::paySoldiers() {
    if (payRequired > 0) {
        payRequired = 0.0;
        morale += 10.0;
        decreaseCorruption(5.0);
        if (morale > 100.0) morale = 100.0;
    }
    else {
        morale -= 5.0;
        increaseCorruption(5.0);
        if (morale < 0.0) morale = 0.0;
    }
}
void Military::manageMorale() {
    if (foodRequired > 0) {
        morale -= 5.0;
        increaseCorruption(2.0);
        if (morale < 0.0) morale = 0.0;
    }
    if (isCorrupted()) {
        morale -= corruptionLevel * 0.1;
        if (morale < 0.0) morale = 0.0;
    }
}

int  Military::getSoldierCount() const {
    return soldierCount;
}

double Military::getMorale() const {
    return morale;
}