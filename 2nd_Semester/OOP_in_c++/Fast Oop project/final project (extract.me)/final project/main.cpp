#include "Stronghold.h"
#include <iostream>
#include <limits>
#include <cstdlib>
#include <ctime>

using namespace std;


void militaryMenu(Kingdom& kingdom) {
    Military& military = kingdom.getMilitary();

    while (true) {
        cout << "\nMilitary Menu" << endl;
        cout << "1. Attempt Recruitment\n";
        cout << "2. View Soldier Count\n";
        cout << "3. Train Soldiers\n";
        cout << "4. View Morale\n";
        cout << "0. Back to Main Menu\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input\n";
            continue;
        }

        switch (choice) {
        case 1:
            military.recruitSoldiers();
            break;

        case 2:
            cout << "Total soldiers: " << military.getSoldierCount() << endl;
            break;

        case 3: {
            cout << "Available soldiers: " << military.getSoldierCount() << endl;
            cout << "Enter number to train: ";
            int num;
            cin >> num;
            military.trainSoldiers(num);
            break;
        }
        case 4:
            cout << "Current morale: " << (military.getMorale() * 100) << "%\n";
            break;

        case 0:
            return;

        default:
            cout << "Invalid choice\n";
        }

        cout << "Press Enter to continue...";
        cin.ignore();
        cin.get();
    }
}

void economyMenu(Kingdom& kingdom) {
    int choice;
    cout << "\nEconomy Menu\n";
    cout << "1. Adjust Tax Rate\n";
    cout << "2. View Tax Rate\n";
    cout << "3. View Corruption Level\n";
    cout << "4. View Inflation Rate\n";
    cout << "0. Back to Main Menu\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        double rate;
        cout << "Enter new tax rate (0.0 - 1.0): ";
        cin >> rate;
        if (rate >= 0 && rate <= 1.0)
            kingdom.getEconomy().adjustTaxRate(rate);
        else
            cout << "Invalid rate.\n";
        break;
    }
    case 2:
        cout << "Current tax rate: " << kingdom.getEconomy().getTaxRate() << endl;
        break;
    case 3:
        cout << "Current corruption level: " << kingdom.getCorruption().getCorruptionLevel() << endl;
        break;
    case 4:
        cout << "Current inflation rate: " << kingdom.getEconomy().getInflation() << endl;
        break;
    case 0: return;
    default:
        cout << "Invalid choice.\n";
    }
}

void resourceMenu(Kingdom& kingdom) {
    int choice;
    cout << "\nResource Menu\n";
    cout << "1. Gather Resources\n";
    cout << "2. View Resource Stockpile\n";
    cout << "0. Back to Main Menu\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice) {
    case 1: {
        int resChoice, amount;
        cout << "Select Resource to Gather:\n";
        cout << "0. Food  1. Wood  2. Stone  3. Iron  4. Gold\n";
        cin >> resChoice;
        cout << "Enter amount to gather: ";
        cin >> amount;
        if (resChoice >= 0 && resChoice < RESOURCE_TYPE_COUNT && amount > 0)
            kingdom.getResourceManager().gather(static_cast<ResourceType>(resChoice), amount);
        else
            cout << "Invalid input.\n";
        break;
    }
    case 2: {
        const char* resourceNames[] = { "Food", "Wood", "Stone", "Iron", "Gold" };
        cout << "Current Resource Stockpile:\n";
        for (int i = 0; i < RESOURCE_TYPE_COUNT; ++i) {
            cout << resourceNames[i] << " - Amount: "
                << kingdom.getResourceManager().get(static_cast<ResourceType>(i)) << endl;
        }
        break;
    }
    case 0: return;
    default:
        cout << "Invalid choice.\n";
    }
}

void populationMenu(Kingdom& kingdom) {
    const char* classNames[] = { "Peasants", "Merchants", "Nobles", "Soldiers", "Civilians" };
    cout << "\nPopulation Status\n";
    for (int i = 0; i < SOCIAL_CLASS_COUNT; ++i) {
        cout << classNames[i] << " - Count: " << kingdom.getPopulation().getCount(static_cast<SocialClass>(i))
            << ", Happiness: " << kingdom.getPopulation().getHappiness(static_cast<SocialClass>(i)) << endl;
    }
}

void leadershipMenu(Kingdom& kingdom) {
    Leadership& leadership = kingdom.getLeadership();
    Population& population = kingdom.getPopulation();

    auto clampPercent = [](double value) {
        return max(0.0, min(100.0, value * 100));
        };

    while (true) {
        cout << "\n=== Leadership Menu " << endl;
        cout << "1. Leader Overview\n";
        cout << "2. Hold Election\n";
        cout << "3. Initiate Coup\n";
        cout << "4. Change Leader\n";
        cout << "5. View Popularity Effects\n";
        cout << "6. Return to Main Menu\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
        case 1: {
            cout << "\n--- LEADER STATS ---\n";
            cout << "Name: " << leadership.getLeaderName() << endl;
            cout << "Style: ";
            switch (leadership.getLeadershipStyle()) {
            case 0: cout << "Benevolent"; break;
            case 1: cout << "Neutral"; break;
            case 2: cout << "Tyrannical"; break;
            default: cout << "Unknown"; break;
            }
            cout << "\nLevel: " << leadership.getLeadershipLevel() << endl;
            cout << "Popularity: " << clampPercent(leadership.getPopularity()) << "%\n";

            cout << "\nCLASS HAPPINESS:\n";
            cout << "- Peasants: " << clampPercent(population.getHappiness(PEASANT)) << "%\n";
            cout << "- Merchants: " << clampPercent(population.getHappiness(MERCHANT)) << "%\n";
            cout << "- Nobles: " << clampPercent(population.getHappiness(NOBLE)) << "%\n";
            cout << "- Soldiers: " << clampPercent(population.getHappiness(SOLDIER)) << "%\n";
            cout << "- Civilians: " << clampPercent(population.getHappiness(CIVILAN)) << "%\n";
            break;
        }

        case 2: {
            cout << "\nHolding elections...\n";
            leadership.holdElection(kingdom);

            double popChange = (rand() % 30 - 10) / 100.0;
            leadership.affectPopularity(popChange);

            cout << "New leader: " << leadership.getLeaderName() << endl;
            cout << "Popularity " << (popChange >= 0 ? "+" : "")
                << clampPercent(popChange) << "%\n";
            break;
        }

        case 3: {
            if (leadership.getPopularity() < 0.3) {
                cout << "\nInitiating coup...\n";
                leadership.initiateCoup(kingdom);

                population.adjustHappiness(SOLDIER, 0.15);
                population.adjustHappiness(PEASANT, -0.1);
                cout << "Coup successful! New leader: "
                    << leadership.getLeaderName() << endl;
            }
            else {
                cout << "\nThe people still support the current leader!\n";
                cout << "Coup attempt failed (-15% popularity).\n";
                leadership.affectPopularity(-0.15);
            }
            break;
        }

        case 4: {
            cout << "\nEnter new leader name: ";
            string newName;
            cin.ignore();
            getline(cin, newName);

            cout << "Select leadership style:\n";
            cout << "0 - Benevolent\n1 - Neutral\n2 - Tyrannical\n";
            cout << "Choice: ";
            int style;
            cin >> style;

            if (style >= 0 && style <= 2) {
                leadership.changeLeader(newName, style);
                cout << "New leader appointed: " << newName << endl;

                double popEffect = (style == 0) ? 0.1 :
                    (style == 2) ? -0.1 : 0.0;
                leadership.affectPopularity(popEffect);
            }
            else {
                cout << "Invalid style selection.\n";
            }
            break;
        }

        case 5: {
            cout << "\nPopularity Menu\n";
            cout << "Current: " << clampPercent(leadership.getPopularity()) << "%\n";
            cout << "Effects:\n";
            cout << "- Tax collection efficiency: "
                << clampPercent(leadership.getPopularity() * 0.2) << "%\n";
            cout << "- Military morale: +"
                << clampPercent(leadership.getPopularity() * 0.15) << "%\n";
            cout << "- Rebellion risk: "
                << clampPercent((1.0 - leadership.getPopularity()) * 0.5) << "%\n";
            break;
        }

        case 6:
            return;

        default:
            cout << "Invalid choice.\n";
        }

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }
}

void randomEvent(Kingdom& kingdom) {
    int eventRoll = rand() % 5;

    switch (eventRoll) {
    case 0:
        cout << "\nA bountiful harvest increases food by 200.\n";
        kingdom.getResourceManager().gather(FOOD, 200);
        break;
    case 1:
        cout << "\nA fire destroys 100 wood.\n";
        kingdom.getResourceManager().gather(WOOD, -100);
        break;
    case 2:
        cout << "\nA rival kingdom attacks. You lose 20 soldiers.\n";
        kingdom.getMilitary().recruitSoldiers();
        break;
    case 3:
        cout << "\nThe economy booms. You gain 300 gold.\n";
        kingdom.getResourceManager().gather(GOLD, 300);
        break;
    case 4:
        cout << "\nUnrest spreads. Happiness of peasants drops.\n";
        kingdom.getPopulation().adjustHappiness(PEASANT, -10);
        break;
    }
}


void displayMainMenu() {
    cout << "\nStronghold Management\n";
    cout << "1. Military\n";
    cout << "2. Economy\n";
    cout << "3. Resources\n";
    cout << "4. Population\n";
    cout << "5. Leadership\n";
    cout << "6. Next Turn\n";
    cout << "0. Exit Game\n";
    cout << "Select a category: ";
}

int main() {
    srand(time(0));

    Kingdom myKingdom;
    int mainChoice;
    int turn = 1;

    cout << "\nWelcome to Stronghold Management\n";

    while (true) {
        cout << "\nTurn " << turn << "\n";
        displayMainMenu();
        cin >> mainChoice;

        switch (mainChoice) {
        case 1: militaryMenu(myKingdom); break;
        case 2: economyMenu(myKingdom); break;
        case 3: resourceMenu(myKingdom); break;
        case 4: populationMenu(myKingdom); break;
        case 5: leadershipMenu(myKingdom); break;
        case 6:
            cout << "\nProcessing Turn " << turn << "...\n";
            myKingdom.update();
            myKingdom.handleEvents();
            randomEvent(myKingdom);
            myKingdom.checkFinancialHealth();
            ++turn;
            break;
        case 0:
            cout << "\nExiting game. Thank you for playing.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }

        system("pause");
        system("cls");
    }
    system("pause");
    return 0;
}