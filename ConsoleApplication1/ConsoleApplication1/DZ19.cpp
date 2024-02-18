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

// Класс модификатора урона добавления
class AdditionDamageModifier : public DamageModifier {
    float m_value;
public: 
    AdditionDamageModifier(float value) : m_value(value) {}
    float CalculateDamage(float Damage) const override {
        return Damage + m_value;
    }
};
// Классы модификатора урона умножения
class MultiplicationDamageModifier : public DamageModifier {
    float m_value;
public:
    MultiplicationDamageModifier(float value) : m_value(value) {}
    float CalculateDamage(float Damage) const override {
        return Damage * m_value;
    }
};

// Класс персонажа
class Character {
    std::unique_ptr<Weapon> m_weapon;
    std::vector<std::unique_ptr<DamageModifier>> m_modifiers;
public:
    void SetWeapon(std::unique_ptr<Weapon> weapon) {
        m_weapon = std::move(weapon);
        std::cout << "Using " << m_weapon->GetName() << ", Basic Damage: " << m_weapon->GetDamage() << std::endl;
        OutputModifiedDamage();
    }

    void AddModifier(std::unique_ptr<DamageModifier> modifier) {
        m_modifiers.push_back(std::move(modifier));
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
        character.AddModifier(std::make_unique<AdditionDamageModifier>(3.0f));
        character.AddModifier(std::make_unique<MultiplicationDamageModifier>(1.2f));
        character.SetWeapon(std::make_unique<Bow>());
        character.SetWeapon(std::make_unique<Magic>());
        character.SetWeapon(std::make_unique<Sword>());
        return 0;
}

