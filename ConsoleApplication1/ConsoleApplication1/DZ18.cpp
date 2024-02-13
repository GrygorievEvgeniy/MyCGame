#include <iostream>
#include <string>
#include <memory>
#include <vector>


class Weapon {
public:
    virtual float GetDamage() const = 0;
    virtual std::string GetName() const = 0;
    virtual ~Weapon() = default; // Виртуальный деструктор для правильной очистки
};

class Sword : public Weapon {
public:
    float GetDamage() const override { return 10.0f; }
    std::string GetName() const override { return "Sword"; }
};

class Bow : public Weapon {
public:
    float GetDamage() const override { return 8.0f; }
    std::string GetName() const override { return "Bow"; }
};

class Magic : public Weapon {
public:
    float GetDamage() const override { return 12.0f; }
    std::string GetName() const override { return "Magic"; }
};

class DamageModifier {
public:
    virtual float CalculateDamage(float Damage) const = 0;
    virtual ~DamageModifier() = default; // Виртуальный деструктор для правильной очистки
};

class AdditionDamageModifier : public DamageModifier {
    float m_value;
public: 
    AdditionDamageModifier(float value) : m_value(value) {}
    float CalculateDamage(float Damage) const override {
        return Damage + m_value;
    }
};

class MultiplicationDamageModifier : public DamageModifier {
    float m_value;
public:
    MultiplicationDamageModifier(float value) : m_value(value) {}
    float CalculateDamage(float Damage) const override {
        return Damage * m_value;
    }
};

class Character {
    std::shared_ptr<Weapon> m_weapon;
    std::vector<std::shared_ptr<DamageModifier>> m_modifiers;
public:
    void SetWeapon(const std::shared_ptr<Weapon>& weapon) {
        m_weapon = weapon;
        std::cout << "Using " << m_weapon->GetName() << ", Basic Damage: " << m_weapon->GetDamage() << std::endl;
        OutputModifiedDamage();
    }

    void AddModifier(const std::shared_ptr<DamageModifier>& modifier) {
        m_modifiers.push_back(modifier);
    }

    float GetModifiedDamage() const {
        if (!m_weapon) return 0.0f;
        float damage = m_weapon->GetDamage();
        for (const auto& modifier : m_modifiers)
            damage = modifier->CalculateDamage(damage);
        return damage;
    }

private:
    void OutputModifiedDamage() const {
        if (m_weapon) {
            std::cout << "Using " << m_weapon->GetName() << ", Modified Damage: " << GetModifiedDamage() << std::endl;
        }
    }
};

int main() {
    Character character;
    auto bow = std::make_shared<Bow>();
    auto magic = std::make_shared<Magic>();
    auto sword = std::make_shared<Sword>();

    // Модификаторы урона
    auto additionModifier = std::make_shared<AdditionDamageModifier>(3.0f); // Добавлен для демонстрации
    auto multiplicationModifier = std::make_shared<MultiplicationDamageModifier>(1.2f); // Добавлен для демонстрации
    character.AddModifier(additionModifier);
    character.AddModifier(multiplicationModifier);
    // Установка оружия и вывод урона базового и модифицированного
    character.SetWeapon(bow);
    character.SetWeapon(magic);
    character.SetWeapon(sword);
    return 0;
}

