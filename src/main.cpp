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
    void used();
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
    void setLastSkill(string skill);
    void setSkillResult(string result);
    string getSkillResult() const;

    private: 
    int n{};
    string name;
    string type;
    int hp{};
    string lastSkill = "-";
    string skillResult = "";
};

class BattlePage
{
public:
    BattlePage(Pokemon pokemon1, Pokemon pokemon2);
    void printState();
    void useSkill(int skillId);
    bool isEnd();
    Pokemon getWinner();
    Pokemon getLoser();
private:
    Pokemon pokeballs[2];
    int turn = 0;
};

Pokemon setPokemon(int n);

string getFixedSizeString(string text, int size);

bool isIncluded(string list[], string target);

// Main 함수
int main(){
    int firstPokemon, secondPokemon;

    cout << "Choose a Pokemon(0~4): ";
    cin >> firstPokemon;
    cout << "Choose a Pokemon(0~4): ";
    cin >> secondPokemon;

    if(firstPokemon == secondPokemon)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        exit(1);
    }

    BattlePage battlePage(setPokemon(firstPokemon), setPokemon(secondPokemon));

    while(battlePage.isEnd())
    {
        battlePage.printState();
        int skill;
        cout << "Choose a skill (0~3): ";
        cin >> skill;
        battlePage.useSkill(skill);
        cout << endl;
    }
    cout << "===============================================================" << endl;
    cout << "Match Result: " << battlePage.getWinner().getName()<<" defeats " << battlePage.getLoser().getName() << endl;
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

void Skill::used()
{
    remaining--;
}

// Pokemon 생성자 선언
Pokemon::Pokemon(): skills{Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0)}{}

Pokemon::Pokemon(int n, string name, string type, int hp, Skill skill0, Skill skill1, Skill skill2, Skill skill3): n(n), name(name),type(type), hp(hp), skills{skill0, skill1, skill2, skill3}{}

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

void Pokemon::setLastSkill(string skill)
{
    lastSkill = skill;
}

string Pokemon::getSkillResult() const
{
    return skillResult;
}


string Pokemon::getType() const
{
    return type;
}

void Pokemon::setSkillResult(string result)
{
    skillResult = result;
}



Pokemon setPokemon(const int n)
{
    switch(n)
    {
    case 0:
        return {0,"Pikachu", "Electric", 35, Skill("Tackle", "Normal", 4, 5), Skill("Grass Knot", "Grass", 8,5), Skill("Thunderbolt", "Electric", 10, 5), Skill("Megabolt", "Electric", 15, 3)};
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
BattlePage::BattlePage(Pokemon pokemon1, Pokemon pokemon2):pokeballs{pokemon1, pokemon2}{}

void BattlePage::printState()
{
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" <<endl;
    cout << "+------------------------------+------------------------------+" << endl;
    string name1 = pokeballs[0].getName();
    string name2 = pokeballs[1].getName();
    if(turn %2 == 0)
    {
        name1 += " (*)";
    }else
    {
        name2 += " (*)";
    }
    cout << "| " << getFixedSizeString(name1, 29) << "| "<< getFixedSizeString(name2, 29) << "|" <<  endl;
    cout << "| Type: "<< getFixedSizeString(pokeballs[0].getType(), 23) <<"| Type: "<< getFixedSizeString(pokeballs[1].getType(), 23) << "|" <<endl;
    cout << "| HP: "<< getFixedSizeString(to_string(pokeballs[0].getHp()), 25) <<"| HP: "<< getFixedSizeString(to_string(pokeballs[1].getHp()), 25) << "|" << endl;
    cout << "+------------------------------+------------------------------+" << endl;
    cout << "| Latest Skill: " << getFixedSizeString(pokeballs[0].getLastSkill(), 15) <<"| Latest Skill: "<< getFixedSizeString(pokeballs[1].getLastSkill(), 15) << "|"<< endl;
    cout << "| "<<getFixedSizeString(pokeballs[0].getSkillResult(),29)<<"| "<<getFixedSizeString(pokeballs[1].getSkillResult(),29)<<"|" << endl;
    cout << "+------------------------------+------------------------------+" << endl;

    for(int i=0; i<4; i++)
    {
        cout << "| (" << i << ") " << getFixedSizeString(pokeballs[0].skills[i].getName(), 25) << "| ("<< i <<") " << getFixedSizeString(pokeballs[1].skills[i].getName(), 25) << "|" << endl;
        cout << "|     - Type: "<< getFixedSizeString(pokeballs[0].skills[i].getSkillType(),17) << "|     - Type: " << getFixedSizeString(pokeballs[1].skills[i].getSkillType(),17) << "|" << endl;
        cout << "|     - Damage: "<< getFixedSizeString(to_string(pokeballs[0].skills[i].getDamage()),15) << "|     - Damage: " << getFixedSizeString(to_string(pokeballs[1].skills[i].getDamage()),15) << "|" << endl;
        string count1, count2;
        count1 = to_string(pokeballs[0].skills[i].getRemaining());
        count1 += "(";
        count1 += to_string(pokeballs[0].skills[i].getMaxTry());
        count1 += ")";
        count2 = to_string(pokeballs[1].skills[i].getRemaining());
        count2 += "(";
        count2 += to_string(pokeballs[1].skills[i].getMaxTry());
        count2 += ")";
        cout << "|     - Count: "<< getFixedSizeString(count1,16) << "|     - Count: " << getFixedSizeString(count2,16) << "|" << endl;
    }
    cout << "+------------------------------+------------------------------+"<< endl;
}

void BattlePage::useSkill(int skillId)
{
    int attacker = turn %2;
    int defender;
    if(attacker)
    {
        defender = 0;
    }else
    {
        defender = 1;
    }

    if(pokeballs[attacker].skills[skillId].getRemaining()<=0)
    {
        cout << pokeballs[attacker].getName() << " failed to perform " << pokeballs[attacker].skills[skillId].getName() <<"." << endl;
        turn ++;
        return;
    }

    string defenderType = pokeballs[defender].getType();
    string skillType = pokeballs[attacker].skills[skillId].getSkillType();
    string skillResult = "It was effective.";
    int damage = pokeballs[attacker].skills[skillId].getDamage();
    if(skillType == "Ground")
    {
        if(defenderType == "Electric" || defenderType == "Fire")
        {
            damage += 5;
            skillResult = "It was super effective.";
        }else if(defenderType == "Grass")
        {
            damage -= 3;
            skillResult="It was not very effective.";
        }
    }else if(skillType == "Electric")
    {
        if(defenderType == "Water")
        {
            damage += 5;
            skillResult = "It was super effective.";
        }else if(defenderType == "Ground" || defenderType == "Electric" || defenderType == "Grass")
        {
            damage -= 3;
            skillResult="It was not very effective.";
        }
    }else if(skillType == "Water")
    {
        if(defenderType == "Ground" || defenderType == "Fire")
        {
            damage += 5;
            skillResult = "It was super effective.";
        }else if(defenderType == "Water" || defenderType == "Grass")
        {
            damage -= 3;
            skillResult="It was not very effective.";
        }
    }else if(skillType == "Grass")
    {
        if(defenderType == "Water")
        {
            damage += 5;
            skillResult = "It was super effective.";
        }else if(defenderType == "Ground" || defenderType == "Grass" || defenderType == "Fire")
        {
            damage -= 3;
            skillResult="It was not very effective.";
        }
    }else if(skillType == "Fire")
    {
        if(defenderType == "Grass")
        {
            damage += 5;
            skillResult = "It was super effective.";
        }else if(defenderType == "Water" || defenderType == "Fire")
        {
            damage -= 3;
            skillResult="It was not very effective.";
        }
    }
    cout << pokeballs[attacker].getName() << " used " << pokeballs[attacker].skills[skillId].getName() << "." << endl;
    cout << skillResult << endl;
    pokeballs[attacker].setSkillResult(skillResult);
    pokeballs[defender].attacked(damage);
    pokeballs[attacker].skills[skillId].used();
    pokeballs[attacker].setLastSkill(pokeballs[attacker].skills[skillId].getName());

    turn ++;
}

bool BattlePage::isEnd()
{
    if(pokeballs[0].getHp() > 0 && pokeballs[1].getHp() > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

Pokemon BattlePage::getWinner()
{
    if (pokeballs[0].getHp()>0)
    {
        return pokeballs[0];
    }
    return pokeballs[1];
}

Pokemon BattlePage::getLoser()
{
    if (pokeballs[0].getHp()<=0)
    {
        return pokeballs[0];
    }
    return pokeballs[1];
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

bool isIncluded(string list[], const int size, const string& target)
{
    bool found = false;
    for(int i=0; i<size; i++)
    {
        if(list[i] == target) found = true;
    }
    return found;
}
