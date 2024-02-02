#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>

// Создание структуры персонажа
struct Character {
    static int nextId;
    int id; 
    enum class CharacterClass {
        Warrior,
        Archer,
        Mage
    } characterClass;
    float meleeAttack;
    float rangedAttack;

    // Автоматическое присвоение id
    Character(CharacterClass characterClass, float meleeAttack, float rangedAttack)
        : id(nextId++), characterClass(characterClass), meleeAttack(meleeAttack), rangedAttack(rangedAttack) {}
};
int Character::nextId = 1;

// Функция для поиска самого сильного персонажа
int strongestCharacter(const std::vector<Character>& characters) {
    auto it = std::max_element(characters.begin(), characters.end(), [](const Character& a, const Character& b) {
        return (a.meleeAttack + a.rangedAttack) < (b.meleeAttack + b.rangedAttack);
    });

    return (it != characters.end()) ? it->id : -1;
}

// Функция для поиска самого сильного персонажа в каждом классе
std::vector<int> strongestCharacterInEachClass(const std::vector<Character>& characters) {
    std::vector<int> strongestIds(3, -1); // Initialize with -1 for Warrior, Archer, and Mage
    std::vector<float> maxStrengths(3, 0.0f); // Initialize max strengths for each class

    for (const auto& character : characters) {
        int classIndex = static_cast<int>(character.characterClass);
        float totalStrength = character.meleeAttack + character.rangedAttack;

        if (totalStrength > maxStrengths[classIndex]) {
            maxStrengths[classIndex] = totalStrength;
            strongestIds[classIndex] = character.id;
        }
    }

    return strongestIds;
}

// Main function
int main()
{
    std::vector<Character> characters;
    std::string input;
    int classInput;
    float meleeAttack, rangedAttack;

    std::cout << "Enter character details. Type 'end' to finish input." << std::endl;
    while (true)
    {
        std::cout << "Enter character class [0=Warrior, 1=Archer, 2=Mage]: ";
        std::cin >> input;
        if (input == "end") break;

        // Проверка ввода
        try
        {
            classInput = std::stoi(input);
        }
        catch (const std::invalid_argument&)
        {
            std::cerr << "Invalid input. Please enter a number for the character class." << std::endl;
            continue;
        }

        if (classInput < 0 || classInput > 2)
        {
            std::cerr << "Invalid class input. Please enter 0 for Warrior, 1 for Archer, or 2 for Mage." << std::endl;
            continue;
        }

        std::cout << "Enter melee attack strength: ";
        if (!(std::cin >> meleeAttack))
        {
            std::cerr << "Invalid input. Please enter a valid number for melee attack strength." << std::endl;
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the line
            continue;
        }

        std::cout << "Enter ranged attack strength: ";
        if (!(std::cin >> rangedAttack))
        {
            std::cerr << "Invalid input. Please enter a valid number for ranged attack strength." << std::endl;
            std::cin.clear(); // Clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the rest of the line
            continue;
        }

        characters.emplace_back(static_cast<Character::CharacterClass>(classInput), meleeAttack, rangedAttack);
    }

    // Поиск самого сильного персонажа
    int strongestId = strongestCharacter(characters);
    if (strongestId != -1)
    {
        std::cout << "The strongest character is: " << strongestId << std::endl;
    }
    else
    {
        std::cout << "No characters recorded." << std::endl;
    }

    // Поиск самого сильного персонажа в каждом классе
    std::vector<int> strongestIds = strongestCharacterInEachClass(characters);
    std::cout << "The strongest character in each class is: Warrior: " << strongestIds[0] << ", Archer: " <<
        strongestIds[1] << ", Mage: " << strongestIds[2] << std::endl;

    return 0;
}
