/*
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

enum class CharacterClass { Warlock, Warrior };

class GameCharacter {
public:
    std::string name;
    int health;
    CharacterClass characterClass;
    int power;

    GameCharacter(std::string n, int h, CharacterClass c, int p) 
        : name(n), health(h), characterClass(c), power(p) {}

    void takeDamage(int damage)
    {
        if (characterClass == CharacterClass::Warlock) {
            if (damage > 2 * power) {
                if (rand() % 2 == 0) { // 50% шанс на избежание урона
                    return;
                }
                else
                {
                    if (characterClass == CharacterClass::Warlock) {
                        if (damage % 2 == 0) { // Двойной урон парного числа
                            damage *= 2;
                            return;
                        }
                        health -= damage;
                    }
                }
            
                health -= damage;
            } else if (characterClass == CharacterClass::Warrior) {
                if (damage % 2 == 0) { // Урон не наноситься, если урон парного числа
                    return;
                } else {
                    damage *= 3; // Тройной урон, если урон не парного числа
                    if (health <= 0.3 * originalHealth()) {
                        damage = std::max(0, damage - power); // Уменьшение урона на силу, если здоровье меньше 30%
                    }
                }
                health -= damage;
            }

            health = std::max(0, health); // Невозможно получить отрицательное здоровье
        }
    }

private:
    int originalHealth() {
        return 100; // НАчальное здоровье
    }
};

GameCharacter createCharacter() {
    std::string name;
    int health;
    int classChoice;
    int power;

    while (true) {
        std::cout << "Enter character name: ";
        std::getline(std::cin, name);
        if (name.empty()) {
            std::cout << "Invalid name, please try again.\n";
            continue;
        }

        std::cout << "Enter health value (integer): ";
        if (!(std::cin >> health)) {
            std::cout << "Invalid health, please try again.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Choose class (1 for Mage, 2 for Warrior): ";
        if (!(std::cin >> classChoice) || (classChoice != 1 && classChoice != 2)) {
            std::cout << "Invalid class choice, please try again.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        std::cout << "Enter power value (integer): ";
        if (!(std::cin >> power)) {
            std::cout << "Invalid power, please try again.\n";
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        break; 
    }

    CharacterClass characterClass = classChoice == 1 ? CharacterClass::Warlock : CharacterClass::Warrior;

    return GameCharacter(name, health, characterClass, power);
}



int main() {
    srand(time(NULL)); // Для генерации случайных чисел

    GameCharacter character = createCharacter();

    while (character.health > 0) {
        int damage;
        std::cout << "Damage dealed by enemy: ";
        std::cin >> damage;

        character.takeDamage(damage);

        std::cout << "Current Health: " << character.health << "\n";
        if (character.health <= 0) {
            std::cout << character.name << " Killed by enemy.\n";
        }
    }

    return 0;
}
*/
