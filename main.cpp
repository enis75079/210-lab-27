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

// function prototypes
void villagerOutput (const map<string, tuple<int, string, string>>&);

// main function
int main() {
    // creates a villager map
    map<string, tuple<int, string, string>> villager;
    int userChoice = 0;

    // creates the variables that will be affected throughout the runtime of the while loop
    string name;
    string species;
    string catchphrase;
    int friendshipLvl;


    while (userChoice != 6) {
        // menu that user can interact with
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
            // creates a new villager based on user input
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
            cout << name << " added." << endl;

        } else if (userChoice == 2) {
            cout << "Delete Villager: ";
            cin >> name;
            // deletes the villager from the map
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
                // if user chooses to increase friendship level
                if (userChoice == 3) {
                    int& vLvl = get<0>(it->second);
                    if (vLvl < 10) {
                        // increases the level by 1
                        vLvl++;
                        cout << "Your friendship with " << name << " has increased to " << vLvl << "." << endl;
                        cout << endl;
                    } else {
                        // if the friendship level is higher than 10
                        cout << "You have reached maximum friendship points with this villager." << endl;
                        cout << endl;
                        
                    }
                // if user chooses to increase friendship level
                } else if (userChoice == 4) {
                    int& vLvl = get<0>(it->second);
                    if (vLvl > 0) {
                        // decreases the level by 1
                        vLvl--;
                        cout << "Your friendship with " << name << " has decreased to " << vLvl << "." << endl;
                        cout << endl;
                    } else {
                        // if the friendship level is lower than 0
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
            // finds the villager with the user input name
            auto it = villager.find(name);

            if (it != villager.end()) {
                cout << "\nFound: " << name << "[" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
                cout << endl;
            } else {
                cout << "Villager " << name << " does not exist." << endl;
            }
        }
    }

    // calls the villagerOutput function to display all the remaining villagers
    villagerOutput(villager);
    cout << endl;

    return 0;
}

// villagerOutput function. outputs the information of all the villagers after userChoice = 6 (exit)
void villagerOutput (const map<string, tuple<int, string, string>>& villager) {
    cout <<"Villager details: " << endl;
    for (const auto& vProfile : villager) {
        cout << vProfile.first << "[" << get<0>(vProfile.second) << ", " << get<1>(vProfile.second) << ", " << get<2>(vProfile.second) << "]" << endl;
    }
}
