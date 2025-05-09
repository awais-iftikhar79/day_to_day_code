

#include <string>
#include <random>

using namespace std;

enum SocialClass
{
    PEASANT,
    MERCHANT,
    NOBLE,
    SOLDIER,
    CIVILAN,
    SOCIAL_CLASS_COUNT
};
enum ResourceType
{
    FOOD,
    WOOD,
    STONE,
    IRON,
    GOLD,
    RESOURCE_TYPE_COUNT
};
enum EventType {
    PLAGUE,
    FAMINE,
    REBELLION,
    DISCOVERY_OF_GOLD,
    NATURAL_DISASTER,
    TAX_EVASION_SCANDAL,
    MERCHANTS_STRIKE,
    DRAGON_SIGHTING,
    COMEDY_FESTIVAL,
    ASTRONOMICAL_EVENT,
    EVENT_TYPE_COUNT
};


struct SocialGroup
{
    SocialClass socialClass;
    int count;
    double happiness;
};

class Kingdom;


class Corruption
{
protected:
    double corruptionLevel;

public:
    Corruption();
    Corruption(double initialCorruption);
    void update(Kingdom& kingdom);
    void increaseCorruption(double amount);
    void decreaseCorruption(double amount);
    double getCorruptionLevel() const;
    bool isCorrupted() const;
};

class Bank : public Corruption {
private:
    double loanAmount;
    double interestRate;
    double treasuryBalance;
    bool fraudDetected;

public:
    Bank();
    Bank(double loan, double interest, double balance);
    void setLoanAmount(double a);
    void update(Kingdom& kingdom);
    void issueLoan(double a);
    void repayLoan(double a);
    void auditTreasury();
    void detectFraud();
    void applyInterest();
    void deductGold(double amount);
};


class Economy {
private:
    double taxRate;
    double inflationRate;
    double goldReserve;

public:
    Economy();
    void update(Kingdom& kingdom);
    void adjustTaxRate(double a);
    void adjustInflation(double a);
    void tradeResources();
    void fundPublicServices();
    double getTaxRate() const;
    double getInflation() const;
    double getGoldReserve() const;
};

class Event
{
private:
    EventType type;
    string description;
    int impact;

public:
    Event();
    Event(EventType t, const string& desc, int imp);
    void update(Kingdom& kingdom);
    void triggerEvent();
    EventType getType() const;
    string getDescription() const;
    int getImpact() const;
};

class EventManager
{
private:
    Event events[10];
    int eventCount;

public:
    EventManager();
    void update(Kingdom& kingdom);
    void generateRandomEvent();
    Event getLatestEvent() const;
    void applyEvent(Event& event);
    void handleEvent(Kingdom& kingdom, Event& event);
};


class Leadership
{
private:
    string leaderName;
    int leadershipStyle;
    double popularity;

public:
    Leadership();
    Leadership(const string& name);
    void update(Kingdom& kingdom);
    void holdElection(Kingdom& kingdom);
    void initiateCoup(Kingdom& kingdom);
    void changeLeader(const string& newName, int style);
    void affectPopularity(double a);
    string getLeaderName() const;
    int getLeadershipStyle() const;
    int getLeadershipLevel() const;
    double getPopularity() const;
};


class Military : public Corruption
{
private:
    int soldierCount;
    double morale;
    double foodRequired;
    double payRequired;
    int trainedSoldiers;
public:
    Military();
    void update(Kingdom& kingdom);
    void recruitSoldiers();
    void paySoldiers();
    void trainSoldiers(int count);
    void manageMorale();
    int getSoldierCount() const;
    double getMorale() const;
};


class Population
{
private:
    SocialGroup groups[SOCIAL_CLASS_COUNT];
    double growthRate;
    double happiness[SOCIAL_CLASS_COUNT];
    double health;

public:
    Population();
    void update(Kingdom& kingdom);
    void adjustHappiness(SocialClass type, double delta);
    void addPopulation(SocialClass sClass, int count);
    bool removePopulation(SocialClass sClass, int count);
    int getCount(SocialClass sClass) const;
    double getHappiness(SocialClass sClass) const;
    double getOverallHappiness() const;
    int getTotalPopulation() const;
    void affectHealth(double amount);
};


class Resource
{
private:
    ResourceType type;
    double amount;

public:
    Resource();
    Resource(ResourceType type, double a);
    void update(Kingdom& kingdom);
    void gather(double a);
    void consume(double a);
    void trade(double a);
    ResourceType getType() const;
    double getAmount() const;
    void setAmount(double amt);
};

class ResourceManager
{
private:
    Resource resources[RESOURCE_TYPE_COUNT];

public:
    ResourceManager();
    void update(Kingdom& kingdom);
    void gather(ResourceType type, int a);
    void consume(ResourceType type, int a);
    void trade(ResourceType fromType, ResourceType toType, int a);
    int get(ResourceType type) const;
};



class Kingdom
{
public:
    Population population;
    Leadership leadership;
    Economy economy;
    Bank bank;
    Military military;
    ResourceManager resourceManager;
    EventManager eventManager;
    Corruption corruption;

    Kingdom();
    void update();
    void checkFinancialHealth();
    void handleEvents();
    Population& getPopulation();
    Leadership& getLeadership();
    Economy& getEconomy();
    Bank& getBank();
    Military& getMilitary();
    ResourceManager& getResourceManager();
    EventManager& getEventManager();
    Corruption& getCorruption();
};
