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

int main() {
    // declarations
    map<string, tuple<int, string, string>> villager;
    int userChoice = 0;


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
            string name;
            string species;
            string catchphrase;
            int friendshipLvl;
            cout << "Villager's Name: ";
            getline(cin, name);
            cout << "\nVillager's Species: ";
            getline(cin, species);
            cout << "\nVillager's Catchphrase: ";
            getline(cin, catchphrase);
            cout << "\nFriendship Level: ";
            cin >> friendshipLvl;
            cin.ignore();

            villager[name] = make_tuple(friendshipLvl, species, catchphrase);

        } else if (userChoice == 5) {
            string name;
            cout << "Search Villager: ";
            getline(cin, name);
            cout << endl;
            auto it = villager.find(name);

            if (it != villager.end()) {
                cout << "\nFound " << name << get<0>(it->second);
            } else {
                cout << "Villager does not exist." << endl;
            }
        }
    }
    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    /*villager["Audie"] = {"Orange", "Yellow", "Red"};
    villager["Raymond"] = {"Black", "Gray", "White"};
    villager.insert({"Marshal", {"Blue", "White", "Black"}});

    // access the map using a range-based for loop
    cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    for (auto pair : villager) {
        cout << pair.first << ": ";
        for (auto color : pair.second)
            cout << color << " ";
        cout << endl;
    }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    for (map<string, vector<string>>::iterator it = villager.begin(); 
                                               it != villager.end(); ++it) {
        cout << it->first << ": ";
        for (auto color : it->second) {
            cout << color << " ";
        }
        cout << endl;
    }

    // delete an element
    villager.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
    auto it = villager.find(searchKey);
    if (it != villager.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << "'s favorite colors: ";
        for (auto color : it->second)  // range loop to traverse the value/vector
            cout << color << " ";
        cout << endl;
    } else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    cout << "\nSize before clear: " << villager.size() << endl;
    villager.clear();
    cout << "Size after clear: " << villager.size() << endl;*/

    return 0;
}
