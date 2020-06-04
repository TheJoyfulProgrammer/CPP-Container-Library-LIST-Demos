#include <iostream>
#include <list>
#include <string>
#include <algorithm>

namespace USA_PresidentsNS
{
    struct President
    {
        std::string FirstName;
        std::string MiddleInitial;
        std::string LastName;
        uint32_t Presidency;
    };
}

int main()
{
    // Create a list container (a double (bi-directional) linked list) for the US Presidents
    std::list<USA_PresidentsNS::President> Presidents;

    // Create an iterator which we can use to find a President in the list
    std::list<USA_PresidentsNS::President>::iterator PresidentIterator;
    
    // Add some US Presidents to the list
    Presidents.push_back(USA_PresidentsNS::President{"George", "", "Washington", 1});
    Presidents.push_back(USA_PresidentsNS::President{"Abraham", "", "Lincoln", 16});
    Presidents.push_back(USA_PresidentsNS::President{"Ulysses", "S.", "Grant", 18});
    Presidents.push_back(USA_PresidentsNS::President{"Theodore", "", "Roosevelt", 26});
    Presidents.push_back(USA_PresidentsNS::President{"Franklin", "D.", "Roosevelt", 32});
    
    // Find a President in the list and use a Lamda.
    PresidentIterator = std::find_if(Presidents.begin(), Presidents.end(), 
                        [](const USA_PresidentsNS::President& ListItem) {
                        return (ListItem.FirstName == "Franklin") & (ListItem.LastName == "Roosevelt"); });
    
    // Insert a President in the list
    if (PresidentIterator != Presidents.end()) {
        Presidents.insert(PresidentIterator, USA_PresidentsNS::President{"Woodrow", "", "Wilson", 28});
    }
    
    Presidents.erase(PresidentIterator);
    
    // Print the list of Presidents
    for(auto PresidentIterator2 : Presidents)
    {
        std::cout << "United States President #" 
                  << PresidentIterator2.Presidency 
                  << ": - "
                  << PresidentIterator2.FirstName
                  << " "
                  << PresidentIterator2.MiddleInitial
                  << (PresidentIterator2.MiddleInitial == "" ? "" : " ")
                  << PresidentIterator2.LastName
                  << "\n";
    }
}


