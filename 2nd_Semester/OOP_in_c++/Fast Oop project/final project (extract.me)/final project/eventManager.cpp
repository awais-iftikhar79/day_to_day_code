#include "Stronghold.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

EventManager::EventManager() : eventCount(0) {
    srand(time(0));
}

void EventManager::generateRandomEvent() {
    if (eventCount >= 10) {
        cout << "Event queue full. Cannot generate more events.\n";
        return;
    }

    EventType type = static_cast<EventType>(rand() % EVENT_TYPE_COUNT);
    string description;
    int impact = rand() % 21 + 10;

    switch (type) {
    case PLAGUE:
        description = "A deadly plague spreads through the kingdom.";
        break;
    case FAMINE:
        description = "A famine has caused widespread hunger.";
        break;
    case REBELLION:
        description = "A rebellion rises against the ruling class.";
        break;
    case DISCOVERY_OF_GOLD:
        description = "A rich vein of gold has been discovered.";
        break;
    case NATURAL_DISASTER:
        description = "A terrible natural disaster has struck.";
        break;
    case TAX_EVASION_SCANDAL:
        description = "Nobles caught hiding wealth in offshore vaults.";
        break;
    case MERCHANTS_STRIKE:
        description = "Merchants halt trade demanding lower tariffs.";
        break;
    case DRAGON_SIGHTING:
        description = "A dragon was seen in the mountains. Panic spreads.";
        break;
    case COMEDY_FESTIVAL:
        description = "A traveling troupe hosts a comedy festival. Laughter everywhere.";
        break;
    case ASTRONOMICAL_EVENT:
        description = "A rare comet lights the sky. Peasants think it’s magic.";
        break;
    default:
        description = "An unknown event occurred.";
        break;
    }

    events[eventCount++] = Event(type, description, impact);
    cout << "New event generated: " << description << " [Impact: " << impact << "]\n";
}

void EventManager::handleEvent(Kingdom& kingdom, Event& event) {
    cout << "Handling event: " << event.getDescription() << "\n";
    switch (event.getType()) {
    case PLAGUE:
        kingdom.getPopulation().affectHealth(-0.3);
        kingdom.getResourceManager().consume(FOOD, 300);
        break;
    case FAMINE:
        kingdom.getResourceManager().consume(FOOD,
            kingdom.getResourceManager().get(FOOD) * 0.5);
        kingdom.getPopulation().adjustHappiness(PEASANT, -0.4);
        break;
    case REBELLION:
        kingdom.getMilitary().recruitSoldiers();
        kingdom.getPopulation().adjustHappiness(PEASANT, -0.3);
        kingdom.getPopulation().adjustHappiness(CIVILAN, -0.2);
        break;
    case DISCOVERY_OF_GOLD:
        kingdom.getResourceManager().gather(GOLD, 500);
        kingdom.getEconomy().adjustTaxRate(-0.05);
        break;
    case NATURAL_DISASTER:
        kingdom.getResourceManager().consume(WOOD, 200);
        kingdom.getResourceManager().consume(STONE, 100);
        kingdom.getPopulation().adjustHappiness(CIVILAN, -0.15);
        break;
    case TAX_EVASION_SCANDAL:
        kingdom.getLeadership().affectPopularity(-0.2);
        kingdom.getEconomy().adjustTaxRate(0.03);
        break;
    case MERCHANTS_STRIKE:
        kingdom.getResourceManager().consume(GOLD,
            kingdom.getResourceManager().get(GOLD) * 0.3);
        kingdom.getPopulation().adjustHappiness(MERCHANT, -0.25);
        break;

    case DRAGON_SIGHTING:
        kingdom.getMilitary().recruitSoldiers();
        kingdom.getMilitary().manageMorale();
        kingdom.getResourceManager().consume(FOOD, 100);
        break;
    case COMEDY_FESTIVAL:
        for (int i = 0; i < SOCIAL_CLASS_COUNT; i++) {
            SocialClass sc = static_cast<SocialClass>(i);
            kingdom.getPopulation().adjustHappiness(sc, 0.15);
        }
        kingdom.getResourceManager().consume(GOLD, 200);
        break;
    case ASTRONOMICAL_EVENT:
        kingdom.getLeadership().affectPopularity(0.1);
        kingdom.getPopulation().adjustHappiness(NOBLE, 0.2);
        break;
    default:
        cout << "Unknown event type.\n";
        break;
    }
}

Event EventManager::getLatestEvent() const {
    if (eventCount > 0) {
        return events[eventCount - 1];
    }
    else {
        cout << "No events available.\n";
        return Event();
    }
}
void EventManager::applyEvent(Event& event) {
    cout << "Applying event...\n";
    event.triggerEvent();

}

void EventManager::update(Kingdom& kingdom) {
    for (int i = 0; i < eventCount; ++i) {
        events[i].update(kingdom);
    }
}