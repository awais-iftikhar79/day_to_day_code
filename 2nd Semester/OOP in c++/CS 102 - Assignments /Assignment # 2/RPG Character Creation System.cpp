#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

class Character
{
protected:
    string name;
    int level;
    int health_points;

public:
    friend void battle(Character &obj1, Character &obj2);
    Character(string n, int l) : name(n), level(l), health_points(100) {}
    void display()
    {
        cout << "Name : " << name << endl;
        cout << "Level : " << level << endl;
        cout << "Health Points :" << health_points << endl;
    }
    int attack()
    {
        return rand() % 10 + 5;
    }
    void get_damage(int damage)
    {
        health_points -= damage;
    }
    bool is_alive()
    {
        return health_points > 0;
    }
    string get_name()
    {
        return name;
    }
    int get_health()
    {
        return health_points;
    }
};
class Warrior : public Character
{
protected:
    int strength;
    int armor;

public:
    Warrior(string n, int l, int s, int ar) : Character(n, l)
    {
        strength = s;
        armor = ar;
    }
    int attack()
    {
        return rand() % strength + 10;
    }
    void get_damage(int damage)
    {
        int reduced_damage = damage - (armor + level / 2);
        if (reduced_damage < 0)
        {
            reduced_damage = 0;
        }
        health_points -= reduced_damage;
    }
};

class Mage : public Character
{
protected:
    int intelligence;
    int mana;

public:
    Mage(string n, int l, int i, int m) : Character(n, l)
    {
        intelligence = i;
        mana = m;
    }
    int attack()
    {
        if (mana >= 10)
        {
            mana -= 10;
            return rand() % intelligence + (mana / 4) + level * 2;
        }
        else
        {
            return rand() % 5 + 3;
        }
    }
    void get_damage(int damage)
    {
        if (mana >= 15)
        {
            damage /= 2;
            cout << damage << " is absorbed by magical shield " << endl;
        }
        health_points -= damage;
        if (health_points < 0)
        {
            health_points = 0;
        }
    }
};

class Rogue : public Character
{
protected:
    int agility;
    int evasion;

public:
    Rogue(string n, int l, int agi, int eva) : Character(n, l)
    {
        agility = agi;
        evasion = eva;
    }
    int attack()
    {
        return rand() % agility + 5;
    }
    void get_damage(int damage)
    {
        int chance = rand() % 100;
        if (chance < evasion + level)
        {
            cout << name << " doged the attack" << endl;
        }
        else
        {
            health_points -= damage;
            if (health_points < 0)
            {
                health_points = 0;
            }
        }
    }
};
void battle(Character &ch1, Character &ch2)
{
    cout << "------ BATTLE BEGINS ------" << endl
         << endl;
    cout << "-- PLAYER 1 DETAILS --" << endl;
    ch1.display();
    cout << endl;
    cout << "-- PLAYER 2 DETAILS --" << endl;
    ch2.display();
    int round = 1;
    while (ch1.is_alive() && ch2.is_alive())
    {
        cout << "------ ROUND # " << round << " --------" << endl
             << endl;

        int damage1 = ch1.attack();
        cout << ch1.get_name() << " attacks for " << damage1 << " damage!" << endl;
        ch2.get_damage(damage1);

        if (ch2.is_alive())
        {
            int damage2 = ch2.attack();
            cout << ch2.get_name() << " attacks for " << damage2 << " damage!" << endl
                 << endl;
            ch1.get_damage(damage2);
        }

        cout << "------ STATUS AFTER ROUND " << round << " ------ " << endl
             << endl;

        if (ch1.get_health() < 0)
        {
            ch1.health_points = 0;
        }
        if (ch2.get_health() < 0)
        {
            ch2.health_points = 0;
        }

        ch1.display();
        cout << endl;
        ch2.display();
        cout << endl;
        round++;
    }
    if (ch1.is_alive())
    {
        cout << ch1.get_name() << " Wins the battle !" << endl;
    }
    else
    {
        cout << ch2.get_name() << " Wins the battle!" << endl;
    }
}

int main()
{
    srand(time(0));

    Warrior w("Awais", 2, 50, 60);
    Rogue r("Huni Bhai", 3, 60, 70);
    Mage m("Ahmad khalid", 4, 80, 20);

    battle(m, r);

    return 0;
}