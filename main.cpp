/*

lab27: villager map
COMSC-210
Naveen Islam

*/
#include <iostream>
#include <map>
#include <vector> 
#include <tuple>
#include <string>
using namespace std;

void villagerOutput (const map<string, tuple<int, string, string>>&);

int main() {
    // declarations
    map<string, tuple<int, string, string>> villager;
    int userChoice = 0;
    string name;
    string species;
    string catchphrase;
    int friendshipLvl;


    while (userChoice != 6) {
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Choice: ";
        cin >> userChoice;
        cout << endl;

        if (userChoice == 1) {
            cout << "Villager's Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "\nVillager's Species: ";
            getline(cin, species);
            cout << "\nVillager's Catchphrase: ";
            getline(cin, catchphrase);
            cout << "\nFriendship Level: ";
            cin >> friendshipLvl;
            cin.ignore();

            villager[name] = make_tuple(friendshipLvl, species, catchphrase);
            cout << name << "added." << endl;

        } else if (userChoice == 2) {
            cout << "Delete Villager: ";
            cin >> name;
            if (villager.erase(name)) {
                cout << "Villager " << name << " has been deleted." << endl; 
                cout << endl;
            } else {
                cout << name << " not found" << endl;
                cout << endl;
            }
        } else if (userChoice == 3 || userChoice == 4) {
            cout << "Villager Name: ";
            cin >> name;
            auto it = villager.find(name);
            if (it != villager.end()) {
                if (userChoice == 3) {
                    int& vLvl = get<0>(it->second);
                    if (vLvl < 10) {
                        vLvl++;
                        cout << "Your friendship with " << name << " has increased to " << vLvl << "." << endl;
                        cout << endl;
                    } else {
                        cout << "You have reached maximum friendship points with this villager." << endl;
                        cout << endl;
                        
                    }
                } else if (userChoice == 4) {
                    int& vLvl = get<0>(it->second);
                    if (vLvl > 0) {
                        vLvl--;
                        cout << "Your friendship with " << name << " has decreased to " << vLvl << "." << endl;
                        cout << endl;
                    } else {
                        cout << "You are at 0 friendship with this villager." << endl;
                        cout << endl;
                        
                    }
                }
            }
            

        }
         else if (userChoice == 5) {
            cout << "Search Villager: ";
            cin >> name;
            cout << endl;
            auto it = villager.find(name);

            if (it != villager.end()) {
                cout << "\nFound: " << name << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
                cout << endl;
            } else {
                cout << "Villager " << name << " does not exist." << endl;
            }
        }
    }
    return 0;
}

void villagerOutput (const map<string, tuple<int, string, string>>& villager) {
    cout <<"Villager details: " << endl;
    for (const auto& vProfile : villager) {
        cout << vProfile.first << "[" << get<0>(vProfile.second) << ", " << get<1>(vProfile.second) << ", " << get<2>(vProfile.second) << "]" << endl;
    }
}
