#include <iostream>
#include <string>

using namespace std;

class Pokemon {
    public:
    Pokemon(int n, string name, string type, int hp);
    void attacked(int damage);
    int getHp() const;
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

class Pikachu:Skill
{

};

int main(){
    const Pokemon p1(0, "hello", "hello", 12);
    cout << p1.getHp() << endl;
    return 0;
}

Pokemon::Pokemon(int n, string name, string type, int hp): n(n), name(name),type(type), hp(hp) {}

void Pokemon::attacked(const int damage){
    hp -= damage;
}

int Pokemon::getHp() const{
    return hp;
}

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



