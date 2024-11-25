// C++에서 입력과 출력을 하기 위한 라이브러리
#include <iostream>
// string을 활용하기 위한 라이브러리
#include <string>
// 프로그램 종료를 위한 라이브러리
#include <cstdlib>

// std namespace를 사용
using namespace std;

// 포켓몬의 스킬을 정의하기 위한 Class 정의
class Skill {
public:
    // 스킬 생성자
    Skill(string name, string skillType, int damage, int maxTry);
    // 스킬 이름을 가져오기 위한 함수
    string getName() const;
    // 스킬 타입을 가져오기 위한 함수
    string getSkillType() const;
    // 스킬의 공격력을 가져오기 위한 함수
    int getDamage() const;
    // 스킬 최대 시도 횟수를 가져오기 위한 함수
    int getMaxTry() const;
    // 남은 스킬 시도 횟수를 가져오기 위한 함수
    int getRemaining() const;
    // 스킬 사용 후 시도 횟수를 1 줄이기 위한 함수
    void used();
private:
  // 스킬 이름
    string name;
    // 스킬 타입
    string skillType;
    // 스킬 공격력
    int damage;
    // 스킬 최대 시도 횟수
    int maxTry;
    // 남은 스킬 시도 횟수
    int remaining;
};
// 포켓몬을 정의하기 위한 함수
class Pokemon {
public:
    // 포켓몬 기본 생성자 (아무 값도 존재하지 않는 포켓몬을 정의)
    Pokemon();
    // 포켓몬 생성자
    Pokemon(string name, string type, int hp, Skill skill0, Skill skill1, Skill skill2, Skill skill3);
    // 포켓몬이 공격을 받을 때 공격력 만큼 포켓몬 채력을 감소시키기 위한 함수
    void attacked(int damage);
    // 포켓몬 채력을 가져오기 위한 함수
    int getHp() const;
    // 포켓몬 이름을 가져오기 위한 함수
    string getName() const;
    // 포켓몬이 시전한 마지막 스킬을 가져오기 위한 함수
    string getLastSkill() const;
    // 포켓몬 타입을 가져오기 위한 함수
    string getType() const;
    // 포켓몬 스킬을 저장하기 위한 배열
    Skill skills[4];
    // 포켓몬이 사용한 마지막 스킬을 설정하기 위한 함수
    void setLastSkill(string skill);
    // 포켓몬이 사용한 마지막 스킬의 효과를 설정하기 위한 함수
    void setSkillResult(string result);
    // 포켓몬이 사용한 마지막 스킬으리 효과를 가져오기 위한 함수
    string getSkillResult() const;
private:
    // 포켓몬의 이름
    string name;
    // 포켓몬 타입
    string type;
    // 포켓몬 채력
    int hp;
    // 포켓몬이 사용한 마지막 스킬
    string lastSkill = "-";
    // 포켓몬이 사용한 마지막 스킬의 효과
    string skillResult = "";
};
// 포켓몬이 배틀을 하는 클래스
class BattlePage
{
public:
    // 생성자 (두 개의 포켓몬 필요)
    BattlePage(Pokemon pokemon1, Pokemon pokemon2);
    // 배틀 상태 출력 함수
    void printState();
    // 스킬을 사용하는 함수 (turn 이 변화함에 따라 순서에 맞는 포켓몬이 자동으로 입력된 스킬을 사용함)
    void useSkill(int skillId);
    // 배틀이 종료되었는지 확인하는 함수
    bool isEnd() const;
    // 배틀 종료 후 승자를 가져오기 위한 함수
    Pokemon getWinner();
    // 배틀 종료 후 패자를 가져오기 위한 함수
    Pokemon getLoser();
    static void notEffective(int& damage, string& result);
    static void veryEffective(int& damage, string& result);
private:
    // 포켓몬을 저장하기 위한 배열
    Pokemon pokeballs[2];
    // 배틀 턴을 저장하는 변수
    int turn = 0;
};
// 입력한 숫자에 맞는 포켓몬을 정의 (0: Pikachu, 1: Dratini, 2: Eevee, 3: Charmander, 4: Palkia)
Pokemon setPokemon(int n);
// 텍스트를 고정된 크기를 가지는 텍스트로 전환해주는 함수 (빈 공간은 스페이스로 대체)
string getFixedSizeString(string text, int size);
// Main 함수
int main(){
    // 포켓몬 index를 저장하는 변수
    int firstPokemon, secondPokemon;
    // 첫 번째 포켓몬을 입력 받음
    cout << "Choose a Pokemon(0~4): ";
    cin >> firstPokemon;
    // 두 번째 포켓몬을 입력 받음
    cout << "Choose a Pokemon(0~4): ";
    cin >> secondPokemon;

    // 만약 두 포켓몬의 인덱스가 같다면 프로그램 종료
    if(firstPokemon == secondPokemon)
    {
        cout << "You have to choose Pokemons different from each other." << endl;
        exit(1);
    }
    // 배틀 페이지 클래스를 정의
    BattlePage battlePage(setPokemon(firstPokemon), setPokemon(secondPokemon));
    // 배틀이 종료될때 까지 루프 무한 반복
    while(battlePage.isEnd())
    {
        // 현재 상태 출력
        battlePage.printState();
        // 스킬 index를 저장하는 변수
        int skill;
        // 스킬을 입력 받음
        cout << "Choose a skill (0~3): ";
        cin >> skill;
        // 스킬 사용
        battlePage.useSkill(skill);
        cout << endl;
    }
    // 배틀 종료 후 결과 출력
    cout << "===============================================================" << endl;
    cout << "Match Result: " << battlePage.getWinner().getName()<<" defeats " << battlePage.getLoser().getName() << endl;
    return 0;
}
// Skill 생성자 정의
Skill::Skill(string name, string skillType, int damage, int maxTry):name(name), skillType(skillType), damage(damage), maxTry(maxTry)
{
    // 남은 스킬 사용 횟수는 최대 사용 횟수로 정의
    remaining = maxTry;
}
// 스킬 이름 가져오는 함수 정의
string Skill::getName() const
{
    return name;
}
// 스킬 타입을 가져오는 함수 정의
string Skill::getSkillType() const
{
    return skillType;
}
// 스킬 공격력을 가져오기 위한 함수 정의
int Skill::getDamage() const
{
    return damage;
}
// 스킬 최대 시도 횟수를 가져오는 함수
int Skill::getMaxTry() const
{
    return maxTry;
}
// 남은 스킬 최대 시도 횟수를 가져오는 함수
int Skill::getRemaining() const
{
    return remaining;
}
// 스킬을 사용 후 남은 횟수를 1 줄이는 함수 정의
void Skill::used()
{
    // 남은 횟수를 1 줄임
    remaining--;
}
// Pokemon 기본 생성자 정의 (의미 없는 값)
Pokemon::Pokemon(): skills{Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0),Skill("NULL", "NULL", 0, 0)}{}
// Pokemon 생성자
Pokemon::Pokemon(string name, string type, int hp, Skill skill0, Skill skill1, Skill skill2, Skill skill3): name(name),type(type), hp(hp), skills{skill0, skill1, skill2, skill3}{}
// 포켓몬이 공격을 받았을 때 공격력 만큼 체력을 줄이는 함수 정의
void Pokemon::attacked(const int damage){
    // 공격력 만큼 체력을 감소시킴
    hp -= damage;
}
// 포켓몬의 체력을 가져오는 함수 정의
int Pokemon::getHp() const{
    return hp;
}
// 스킬 이름을 가져오는 함수
string Pokemon::getName() const
{
    return  name;
}
// 마지막 사용한 스킬을 가져오는 함수
string Pokemon::getLastSkill() const
{
    return lastSkill;
}
// 마지막에 사용한 스킬을 설정하는 함수
void Pokemon::setLastSkill(string skill)
{
    // 마지막에 사용한 스킬에 입력 값을 대입
    lastSkill = skill;
}
// 스킬을 사용한 결과를 가져오기 위한 함수
string Pokemon::getSkillResult() const
{
    return skillResult;
}
// 포켓몬의 타입을 가져오는 함수
string Pokemon::getType() const
{
    return type;
}
// 포켓몬이 사용한 스킬의 결과를 설정하기 위한 함수
void Pokemon::setSkillResult(string result)
{
    // 스킬 사용 결과에 입력값을 대입함
    skillResult = result;
}
// index에 맞는 포켓몬을 정의하는 함수
Pokemon setPokemon(const int n)
{
    // 입력 받은 index에 맞는 포켓몬을 정의 후 반환
    switch(n)
    {
    // Pikachu 정의 후 반환
    case 0:
        return {"Pikachu", "Electric", 35, Skill("Tackle", "Normal", 4, 5), Skill("Grass Knot", "Grass", 8,5), Skill("Thunderbolt", "Electric", 10, 5), Skill("Megabolt", "Electric", 15, 3)};
    case 1:
    // Dratini 정의 후 반환
        return {"Dratini", "Water", 41, Skill("Wrap", "Normal", 4, 10), Skill("Aqua Tail", "Water", 3,5), Skill("Water Pulse", "Water", 13, 2), Skill("Hyper Beam", "Normal", 20, 1)};
    case 2:
    // Eevee 정의 후 반환
        return {"Eevee", "Normal", 55, Skill("Tackle", "Normal", 4, 5), Skill("Sand Attack", "Ground", 8,3), Skill("Bite", "Normal", 12, 3), Skill("Rain Dance", "Water", 15, 1)};
    case 3:
    // Charmander 정의 후 반환
        return {"Charmander", "Fire", 39, Skill("Tackle", "Normal", 4, 5), Skill("Flamethrower", "Fire", 11,5), Skill("Dig", "Ground", 7, 5), Skill("Heat Wave", "Fire", 14, 5)};
    case 4:
    // Palkia 정의 후 반환
        return {"Palkia", "Water", 90, Skill("Hydro Pump", "Water", 12, 10), Skill("Earth Power", "Ground", 15,10), Skill("Surf", "Water", 13, 10), Skill("Spatial Rend", "Normal", 30, 10)};
    // index가 올바르지 않을 경우 기본 값 반환
    default:
        return {};
    }
}
// BattlePage 생성자 정의
BattlePage::BattlePage(Pokemon pokemon1, Pokemon pokemon2):pokeballs{pokemon1, pokemon2}{}
// 배틀 상태를 출력하는 함수 정의
void BattlePage::printState()
{
    // 배틀 이름 출력
    cout << "+-------------------------------------------------------------+" << endl;
    cout << "| 2024-02 Object-Oriented Programming Pokemon Master          |" <<endl;
    cout << "+------------------------------+------------------------------+" << endl;
    // 포켓몬의 이름을 가져옴
    string name1 = pokeballs[0].getName();
    string name2 = pokeballs[1].getName();
    // turn에 맞게 이름 뒤에 turn 식별자를 붙여줌
    if(turn %2 == 0)
    {
        name1 += " (*)";
    }else
    {
        name2 += " (*)";
    }
    // 포켓몬 이름 출력
    cout << "| " << getFixedSizeString(name1, 29) << "| "<< getFixedSizeString(name2, 29) << "|" <<  endl;
    // 포켓몬의 타입을 출력
    cout << "| Type: "<< getFixedSizeString(pokeballs[0].getType(), 23) <<"| Type: "<< getFixedSizeString(pokeballs[1].getType(), 23) << "|" <<endl;
    // 포켓몬의 체력을 출력
    cout << "| HP: "<< getFixedSizeString(to_string(pokeballs[0].getHp()), 25) <<"| HP: "<< getFixedSizeString(to_string(pokeballs[1].getHp()), 25) << "|" << endl;
    cout << "+------------------------------+------------------------------+" << endl;
    // 포켓몬이 사용한 마지막 스킬 출력
    cout << "| Latest Skill: " << getFixedSizeString(pokeballs[0].getLastSkill(), 15) <<"| Latest Skill: "<< getFixedSizeString(pokeballs[1].getLastSkill(), 15) << "|"<< endl;
    // 스킬 사용 효과를 출력
    cout << "| "<<getFixedSizeString(pokeballs[0].getSkillResult(),29)<<"| "<<getFixedSizeString(pokeballs[1].getSkillResult(),29)<<"|" << endl;
    cout << "+------------------------------+------------------------------+" << endl;
    // 포켓몬의 스킬의 정보를 출력
    for(int i=0; i<4; i++)
    {
        // 스킬 이름을 출력
        cout << "| (" << i << ") " << getFixedSizeString(pokeballs[0].skills[i].getName(), 25) << "| ("<< i <<") " << getFixedSizeString(pokeballs[1].skills[i].getName(), 25) << "|" << endl;
        // 스킬 타입을 출력
        cout << "|     - Type: "<< getFixedSizeString(pokeballs[0].skills[i].getSkillType(),17) << "|     - Type: " << getFixedSizeString(pokeballs[1].skills[i].getSkillType(),17) << "|" << endl;
        // 스킬 공격력을 출력
        cout << "|     - Damage: "<< getFixedSizeString(to_string(pokeballs[0].skills[i].getDamage()),15) << "|     - Damage: " << getFixedSizeString(to_string(pokeballs[1].skills[i].getDamage()),15) << "|" << endl;
        // 남은 횟수와 최대 시도 횟수를 출력
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
// 스킬을 사용하기 위한 함수 정의
void BattlePage::useSkill(const int skillId)
{
    // 공격자 index
    const int attacker = turn %2;
    // 방어자 index
    const int defender = !attacker;
    // 남은 스킬 횟수가 없을 경우
    if(pokeballs[attacker].skills[skillId].getRemaining()<=0)
    {
        // 스킬 실행 불가하다는 것을 출력
        cout << pokeballs[attacker].getName() << " failed to perform " << pokeballs[attacker].skills[skillId].getName() <<"." << endl;
        // 다음 턴으로 넘어감
        turn ++;
        // 아래 코드 실행 안함
        return;
    }
    // 방어 포켓몬의 타입
    const string defenderType = pokeballs[defender].getType();
    // 공격한 스킬의 타입
    const string skillType = pokeballs[attacker].skills[skillId].getSkillType();
    // 스킬 사용 효과 저장하는 변수
    string skillResult = "It was effective.";
    // 공격력을 저장하는 변수
    int damage = pokeballs[attacker].skills[skillId].getDamage();
    // 스킬과 방어자 포켓몬의 상성에 따라 공격력을 다르게 설정
    if(skillType == "Ground")
    {
        if(defenderType == "Electric" || defenderType == "Fire")
        {
            veryEffective(damage, skillResult);
        }else if(defenderType == "Grass")
        {
            notEffective(damage, skillResult);
        }
    }else if(skillType == "Electric")
    {
        if(defenderType == "Water")
        {
            veryEffective(damage, skillResult);
        }else if(defenderType == "Ground" || defenderType == "Electric" || defenderType == "Grass")
        {
            notEffective(damage, skillResult);
        }
    }else if(skillType == "Water")
    {
        if(defenderType == "Ground" || defenderType == "Fire")
        {
          veryEffective(damage, skillResult);
        }else if(defenderType == "Water" || defenderType == "Grass")
        {
            notEffective(damage, skillResult);
        }
    }else if(skillType == "Grass")
    {
        if(defenderType == "Water")
        {
          veryEffective(damage, skillResult);
        }else if(defenderType == "Ground" || defenderType == "Grass" || defenderType == "Fire")
        {
            notEffective(damage, skillResult);
        }
    }else if(skillType == "Fire")
    {
        if(defenderType == "Grass")
        {
          veryEffective(damage, skillResult);
        }else if(defenderType == "Water" || defenderType == "Fire")
        {
            notEffective(damage, skillResult);
        }
    }
    // 스킬 사용 결과 출력
    cout << pokeballs[attacker].getName() << " used " << pokeballs[attacker].skills[skillId].getName() << "." << endl;
    cout << skillResult << endl;
    // 스킬 사용 결과 저장
    pokeballs[attacker].setSkillResult(skillResult);
    // 방어자 체력 감소
    pokeballs[defender].attacked(damage);
    // 공격자 스킬 사용 횟수 감소
    pokeballs[attacker].skills[skillId].used();
    // 마지막에 사용한 스킬 이름 저장
    pokeballs[attacker].setLastSkill(pokeballs[attacker].skills[skillId].getName());
    // 다음 turn으로 이동
    turn ++;
}
// 배틀이 끝난는지 확인하는 함수
bool BattlePage::isEnd() const
{
    // 두 포켓몬의 체력이 모두 0 초과하면 true
    if(pokeballs[0].getHp() > 0 && pokeballs[1].getHp() > 0)
    {
        return true;
    }
    return false;
}
// 배틀 종료 후 승자를 가져오는 함수
Pokemon BattlePage::getWinner()
{
    // 포켓몬 1의 체력이 0을 초과한다면 포켓몬 1이 승자
    if (pokeballs[0].getHp()>0)
    {
        return pokeballs[0];
    }
    // 아니라면 포켓몬 2가 승자
    return pokeballs[1];
}
// 배틀 종료 후 패자를 가져오는 함수
Pokemon BattlePage::getLoser()
{
    // 포켓몬 1의 체력이 0 이하라면 포켓몬 1이 패자
    if (pokeballs[0].getHp()<=0)
    {
        return pokeballs[0];
    }
    // 아니라면 포켓몬 2가 패자
    return pokeballs[1];
}
// 스킬 사용 결과가 효과적이지 않을 때
void BattlePage::notEffective(int& damage, string& result){
    // 스킬 공격력 3 감소
    damage -= 3;
    // 스킬 사용 결과 할당
    result = "It was not very effective.";
}
// 스킬 사용 결과가 매우 효과적일 때
void BattlePage::veryEffective(int& damage, string& result){
    // 스킬 공격력 5 증가
  damage += 5;
    // 스킬 사용 결과 할당
  result = "It was super effective.";
}
// 고정된 크기의 string을 얻기 위한 함수
string getFixedSizeString(string text, const int size)
{
    // 입력한 텍스트의 크기
    const int textSize = static_cast<int>(text.length());
    // 고정된 크기를 맞추기 위해 필요한 공백의 개수
    const int spaceLength = size - textSize;
    // 공백의 개수 만큼 텍스트에 공백을 추가
    for(int i=0; i< spaceLength; i++)
    {
        text += " ";
    }
    // 고정된 크기의 텍스트를 반환
    return text;
}