#ifndef MILITARY_H
#define MILITARY_H

class Military {
private:
    int soldierCount;
    double morale;

public:
    Military();
    void recruitSoldiers();          // Attempts to recruit soldiers
    int getSoldierCount() const;     // Returns the total number of soldiers
    void trainSoldiers(int count);   // Trains a specified number of soldiers
    double getMorale() const;        // Returns the morale of the military
};

#endif // MILITARY_H