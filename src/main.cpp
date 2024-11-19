#include <iostream>
#include <string>

using namespace std;

class Pokemon {
    public:
    Pokemon(int n, string name, string type, int hp);
    void attacked(int damage);
    int getHp() const;
    string getName() const;
    private: 
    int n;
    string name;
    string type;
    int hp; 
};

class Skill {
    public:
    Skill(string name, string skillType, int damage, int maxTry);
    string getName();
    string getSkillType();
    int getDamage() const;
    int getMaxTry() const;
    private:
    string name;
    string skillType;
    int damage;
    int maxTry;
};

class Pikachu:public Pokemon
{
public:
    Pikachu();
    Skill tackle;
    Skill glassKnot;
    Skill thunderbolt;
    Skill megabolt;
};

class Dratini:public Pokemon
{
public:
    Dratini();
    Skill wrap;
    Skill aquaTail;
    Skill waterPulse;
    Skill hyperBeam;
};

class Eevee:public Pokemon
{
public:
    Eevee();
    Skill tackle;
    Skill sandAttack;
    Skill bite;
    Skill rainDance;
};

class Charmander:public Pokemon
{
public:
    Charmander();
    Skill tackle;
    Skill flamethrower;
    Skill dig;
    Skill heatWave;
};


// Main 함수
int main(){
    const Pikachu p1;
    cout << p1.getName() << endl;
    cout << p1.tackle.getDamage() << endl;
    return 0;
}


// Pokemon 클래스 정의
Pokemon::Pokemon(int n, string name, string type, int hp): n(n), name(name),type(type), hp(hp) {}

void Pokemon::attacked(const int damage){
    hp -= damage;
}

int Pokemon::getHp() const{
    return hp;
}

string Pokemon::getName() const
{
    return name;
}


// Skill 클래스 정의
Skill::Skill(string name, string skillType, int damage, int maxTry): name(name), skillType(skillType), damage(damage), maxTry(maxTry)
{}

string Skill::getName()
{
    return name;
}

string Skill::getSkillType()
{
    return skillType;
}

int Skill::getDamage() const
{
    return damage;
}

int Skill::getMaxTry() const
{
    return maxTry;
}

// Pikachu 클래스 정의
Pikachu::Pikachu():Pokemon(0, "Pikachu", "Electric", 35), tackle("Tackle", "Normal", 4, 5), glassKnot("GlassKnot", "Glass", 8, 5), thunderbolt("Thunderbolt", "Electric", 10, 5), megabolt("Megabolt", "Electric", 15, 3)
{}

// Dratini 클래스 정의
Dratini::Dratini():Pokemon(1, "Dratini", "Water", 41), wrap("Wrap", "Normal", 4, 10), aquaTail("Aqua Tail", "Water", 3, 5), waterPulse("Water Pulse", "Water", 13, 2), hyperBeam("Hyper Beam", "Normal", 20, 1){}

// Eevee 클래스 정의
Eevee::Eevee():Pokemon(2, "Eevee", "Normal", 55), tackle("Tackle", "Normal", 4, 5), sandAttack("Sand Attack", "Ground", 8, 3), bite("Bite", "Normal", 12, 3), rainDance("Rain Dance", "Water", 15, 1){}

// Charmander 클래스 정의
Charmander::Charmander():Pokemon(3, "Charmander", "Fire", 39), tackle("Tackle", "Normal", 4, 5), flamethrower("Flamethrower", "Fire", 11, 5), dig("Dig", "Ground", 7, 5), heatWave("Heat Wave", "Fire", 14, 5){}