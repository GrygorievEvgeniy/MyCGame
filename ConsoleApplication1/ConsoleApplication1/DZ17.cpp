#include <iostream>
#include <vector>

using namespace std;

class Building {
private:
    int id;
    int maxAge;
    int initialCost;
    int currentAge = 0;

    public:
    Building(int id, int maxAge, int initialCost) : id(id), maxAge(maxAge), initialCost(initialCost) {}

    int GetCost() const {
        if (maxAge == 0) return 0; // Если maxAge = 0, то возвращаем 0
        // Калькуляция стоимости здания
        return static_cast<int>(initialCost * (1 - static_cast<double>(currentAge) / maxAge));
    }

    void ToAge(int years) {
        currentAge += years; // Увеличиваем возраст здания
        if (currentAge > maxAge) {
            Destroy();
        } else {
            cout << "Building with id " << id << " aged " << years << " years" << endl;
        }
    }

    void Destroy() const {
        cout << "Building with id " << id << " was destroyed due to exceeding max age" << endl;
    }
};

int main() {
    int numberOfBuildings;
    cout << "Enter number of buildings: ";
    cin >> numberOfBuildings;

    vector<Building> buildings;

    for (int i = 0; i < numberOfBuildings; ++i) {
        int id, maxAge, initialCost, yearsToAge;
        cout << "Enter details for building " << i + 1 << " (id maxAge initialCost): ";
        cin >> id >> maxAge >> initialCost;
        buildings.emplace_back(id, maxAge, initialCost);

        cout << "Enter number of years to age building " << i + 1 << ": ";
        cin >> yearsToAge;
        buildings.back().ToAge(yearsToAge); // Увеличиваем возраст здания
    }

    for (const auto& building : buildings) {
        // Выводим стоимость здания
        cout << "Building cost: " << building.GetCost() << endl;
    }
}
