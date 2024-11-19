#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class Skill {
public:
    Skill(string name, string skillType, int damage, int maxTry);
    string getName();
    string getSkillType();
    int getDamage() const;
    int getMaxTry() const;
    int getRemaining() const;
private:
    string name;
    string skillType;
    int damage;
    int maxTry;
    int remaining;
};

class Pokemon {
    public:
    Pokemon();
    Pokemon(int n, string name, string type, int hp, Skill skill0, Skill skill1, Skill skill2, Skill skill3);
    void attacked(int damage);
    int getHp() const;
    string getName() const;
    string getLastSkill() const;
    string getType() const;
    Skill skills[4];

    private: 
    int n{};
    string name;
    string type;
    int hp{};
    string lastSkill = "-";
};

class BattlePage
{
public:
    BattlePage(Pokemon pokemon1, Pokemon pokemon2);
    void printState();
    void useSkill(int skillId);
private:
    Pokemon pokemon1;
    Pokemon pokemon2;
    int turn = 0;
};

Pokemon setPokemon(int n);

string getFixedSizeString(string text, int size);

// Main 함수
int main(){
    int firstPokemon, secondPokemon;

    cout << "Choose a Pokemon(0~4): ";
    cin >> firstPokemon;
    cout << "Choose another Pokemon(0~4): ";
    cin >> secondPokemon;

    if(firstPokemon == secondPokemon)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        exit(1);
    }

    Pokemon pokemon1 = setPokemon(firstPokemon);
    Pokemon pokemon2 = setPokemon(secondPokemon);

    BattlePage battlePage(pokemon1, pokemon2);
    battlePage.printState();

    while(true)
    {
        int skill;
        cout << "Choose a skill(0~3): ";
        cin >> skill;
    }

    return 0;
}

// Skill 클래스 정의
Skill::Skill(string name, string skillType, int damage, int maxTry):name(name), skillType(skillType), damage(damage), maxTry(maxTry)
{
    remaining = maxTry;
}


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

int Skill::getRemaining() const
{
    return remaining;
}

// Pokemon 생성자 선언
Pokemon::Pokemon(): skills{Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0)}{}

Pokemon::Pokemon(int n, string name, string type, int hp, Skill skill0, Skill skill1, Skill skill2, Skill skill3): n(n), name(name),type(type), hp(hp), skills{skill0, skill1, skill2, skill3} {}


void Pokemon::attacked(const int damage){
    hp -= damage;
}

int Pokemon::getHp() const{
    return hp;
}

string Pokemon::getName() const
{
    return  name;
}

string Pokemon::getLastSkill() const
{
    return lastSkill;
}

string Pokemon::getType() const
{
    return type;
}


Pokemon setPokemon(const int n)
{
    switch(n)
    {
    case 0:
        return {0,"Pikachu", "Electric", 35, Skill("Tackle", "Normal", 4, 5), Skill("Glass Knot", "Glass", 8,5), Skill("Thunderbolt", "Electric", 10, 5), Skill("Megabolt", "Electric", 15, 3)};
    case 1:
        return {0,"Dratini", "Water", 41, Skill("Wrap", "Normal", 4, 10), Skill("Aqua Tail", "Water", 3,5), Skill("Water Pulse", "Water", 13, 2), Skill("Hyper Beam", "Normal", 20, 1)};
    case 2:
        return {0,"Eevee", "Normal", 55, Skill("Tackle", "Normal", 4, 5), Skill("Sand Attack", "Ground", 8,3), Skill("Bite", "Normal", 12, 3), Skill("Rain Dance", "Water", 15, 1)};
    case 3:
        return {0,"Charmander", "Fire", 39, Skill("Tackle", "Normal", 4, 5), Skill("Flamethrower", "Fire", 11,5), Skill("Dig", "Ground", 7, 5), Skill("Heat Wave", "Fire", 14, 5)};
    case 4:
        return {0,"Palkia", "Water", 90, Skill("Hydro Pump", "Water", 12, 10), Skill("Earth Power", "Ground", 15,10), Skill("Surf", "Water", 13, 10), Skill("Spatial Rend", "Normal", 30, 10)};
    default:
        return {};
    }

}

// BattlePage 클래스 정의
BattlePage::BattlePage(Pokemon pokemon1, Pokemon pokemon2):pokemon1(pokemon1), pokemon2(pokemon2){}

void BattlePage::printState()
{
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" <<endl;
    cout << "+------------------------------+------------------------------+" << endl;
    string name1 = pokemon1.getName();
    string name2 = pokemon2.getName();
    if(turn %2 == 0)
    {
        name1 += " (*)";
    }else
    {
        name2 += " (*)";
    }
    cout << "| " << getFixedSizeString(name1, 29) << "| "<< getFixedSizeString(name2, 29) << "|" <<  endl;
    cout << "| Type: "<< getFixedSizeString(pokemon1.getType(), 23) <<"| Type: "<< getFixedSizeString(pokemon2.getType(), 23) << "|" <<endl;
    cout << "| HP: "<< getFixedSizeString(to_string(pokemon1.getHp()), 25) <<"| HP: "<< getFixedSizeString(to_string(pokemon2.getHp()), 25) << "|" << endl;
    cout << "+------------------------------+------------------------------+" << endl;
    cout << "| Latest Skill: " << getFixedSizeString(pokemon1.getLastSkill(), 15) <<"| Latest Skill: "<< getFixedSizeString(pokemon2.getLastSkill(), 15) << "|"<< endl;
    cout << "|                              |                              |" << endl;
    cout << "+------------------------------+------------------------------+" << endl;

    for(int i=0; i<4; i++)
    {
        cout << "| (" << i << ") " << getFixedSizeString(pokemon1.skills[i].getName(), 25) << "| (0) " << getFixedSizeString(pokemon2.skills[i].getName(), 25) << "|" << endl;
        cout << "|     - Type: "<< getFixedSizeString(pokemon1.skills[i].getSkillType(),17) << "|     - Type: " << getFixedSizeString(pokemon2.skills[i].getSkillType(),17) << "|" << endl;
        cout << "|     - Damage: "<< getFixedSizeString(to_string(pokemon1.skills[i].getDamage()),15) << "|     - Damage: " << getFixedSizeString(to_string(pokemon2.skills[i].getDamage()),15) << "|" << endl;
        string count1, count2;
        count1 = to_string(pokemon1.skills[i].getRemaining());
        count1 += "(";
        count1 += to_string(pokemon1.skills[i].getMaxTry());
        count1 += ")";
        count2 = to_string(pokemon2.skills[i].getRemaining());
        count2 += "(";
        count2 += to_string(pokemon2.skills[i].getMaxTry());
        count2 += ")";
        cout << "|     - Count: "<< getFixedSizeString(count1,16) << "|     - Count: " << getFixedSizeString(count2,16) << "|" << endl;
    }
    cout << "+------------------------------+------------------------------+"<< endl;
}

void BattlePage::useSkill(int skillId)
{
    if(turn %2 == 0)
    {
        int damage = pokemon1.skills[skillId].getDamage();

    }
}


string getFixedSizeString(string text, int size)
{
    int textSize = text.length();
    int spaceLength = size - textSize;
    for(int i=0; i< spaceLength; i++)
    {
        text += " ";
    }
    return text;
}
