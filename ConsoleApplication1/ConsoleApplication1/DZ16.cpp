#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <numeric>

using namespace std;

map<string, vector<pair<string, float>>> clans;


// Функция добавления игрока в клан
void AddPlayer(const string& ClanName, const string& PlayerName, float PlayerStrength) {
    clans[ClanName].push_back({ PlayerName, PlayerStrength });
}

int GetPlayerCount(const string& ClanName) {
    return clans[ClanName].size();
}

// Функция для проведения боя между кланами
int ClanFight(const string& FirstClanName, const string& SecondClanName) {
    float firstClanStrength = accumulate(clans[FirstClanName].begin(), clans[FirstClanName].end(), 0.0f,
                                         [](float sum, const pair<string, float>& player) { return sum + player.second; });
    float secondClanStrength = accumulate(clans[SecondClanName].begin(), clans[SecondClanName].end(), 0.0f,
                                          [](float sum, const pair<string, float>& player) { return sum + player.second; });

    if (firstClanStrength > secondClanStrength) {
        return 1;
    } else if (firstClanStrength < secondClanStrength) {
        return -1;
    } else {
        return 0;
    }
}

// Функция main для демонстрации работы

int main() {
    string ClanName, PlayerName, command;
    float PlayerStrength;

    cout << "Available commands:" << endl;
    cout << "'AddPlayer' to add a new player to a clan." << endl;
    cout << "'END' to finish input and proceed to results." << endl;

    while (true) {
        cout << "\nEnter command: ";
        cin >> command;

        if (command == "END") {
            cout << "Ending input process..." << endl;
            break;
        } else if (command == "AddPlayer") {
            cout << "Enter Clan Name: ";
            cin >> ClanName;
            cout << "Enter Player Name: ";
            cin >> PlayerName;
            cout << "Enter Player Strength: ";
            cin >> PlayerStrength;

            AddPlayer(ClanName, PlayerName, PlayerStrength);
            cout << "Player added successfully!" << endl;
        } else {
            cout << "Unknown command. Please try again." << endl;
        }
    }

    // Вывод результатов
    cout << "\n--- Results ---" << endl;
    cout << "Clan1 Player Count: " << GetPlayerCount("Clan1") << endl;
    cout << "Clan2 Player Count: " << GetPlayerCount("Clan2") << endl;

    int result = ClanFight("Clan1", "Clan2");
    cout << "Clan Fight Result (Clan1 vs Clan2): ";
    if (result == 1) {
        cout << "Clan1 wins!" << endl;
    } else if (result == -1) {
        cout << "Clan2 wins!" << endl;
    } else {
        cout << "It's a draw!" << endl;
    }

    return 0;
}

