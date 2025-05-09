#include "Stronghold.h"
#include <iostream>

using namespace std;

Event::Event() : type(FAMINE), description("Unknown Event"), impact(0) {}

Event::Event(EventType t, const string& desc, int imp)
    : type(t), description(desc), impact(imp) {
}

void Event::triggerEvent() {
    cout << "Event Triggered: " << description << endl;
    switch (type) {
    case PLAGUE:
        cout << "A plague has struck the kingdom!" << endl;
        break;
    case FAMINE:
        cout << "A famine has hit the land!" << endl;
        break;
    case REBELLION:
        cout << "A rebellion is brewing among the peasants!" << endl;
        break;
    case DISCOVERY_OF_GOLD:
        cout << "Gold has been discovered in the mines!" << endl;
        break;
    case NATURAL_DISASTER:
        cout << "A natural disaster has occurred!" << endl;
        break;
    default:
        cout << "Unknown event type!" << endl;
        break;
    }
}
EventType Event::getType() const {
    return type;
}

string Event::getDescription() const {
    return description;
}

int Event::getImpact() const {
    return impact;
}

void Event::update(Kingdom& kingdom) {
    if (kingdom.getPopulation().getOverallHappiness() < 50) {
        impact += 10;
    }
    if (impact > 50) {
        triggerEvent();
    }
}