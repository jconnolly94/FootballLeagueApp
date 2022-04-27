//
//  main.cpp
//  FootballLeagueApp
//
//  Created by James Connolly on 18/04/2022.
//

#include <iostream>
#include <iomanip>
#include "CFootballTeam.hpp"

//  Menu Prototypes
void mainMenu(void);
void assistantMenu(void);
void managerMenu(void);

// Main Function Prototypes
void DoInitialize (void);
void DoDisplayLeague (void);
void DoEnterMatchResult (void);
void DoDeductPoints (void);
void DoBestDefence (void);
void DoRelegationZone (void);
void DoRemoveTeamFromList(void);

// Support Function Prototpes
bool teamExistsInLeague(string);
void sortLeague();


//global variable to track league size
int LEAGUE_SIZE = 5;

CFootballTeam* league = new CFootballTeam[LEAGUE_SIZE];

int main() {
    cout << "Welcome to the Football Leage Applicaiton" << endl;
    mainMenu();
    delete[] league;
}


// Main Menu, functionality will eventually  be replaced with login functionality using CUser class.
void mainMenu(){
    int selection;
    do{
        cout << "PLease make a selection below." << endl;
        cout << "1. Manager Menu." << endl;
        cout << "2. Assistant Menu." << endl;
        cout << "3. Quit." << endl;
        cin >> selection;
        switch(selection){
            case 1:
                managerMenu();
                break;
            case 2:
                assistantMenu();
                break;
            case 3:
                cout << "Terminating application." << endl;
                selection = -1;
                break;
            default:
                cout << "Invalid selection, please try again..." << endl;
        }
    }while (selection != -1);
}

void managerMenu(){
    int selection;
    do{
        cout << "PLease make a selection below." << endl;
        cout << "1. Initalise League Table." << endl;
        cout << "2. Display League Table" << endl;
        cout << "3. Enter a Match Result" << endl;
        cout << "4. Deduct Points." << endl;
        cout << "5. Best Defence." << endl;
        cout << "6. Relegation Zone." << endl;
        cout << "7. Remove Team from List." << endl;
        cout << "8. Add User." << endl;
        cout << "9. Edit User." << endl;
        cout << "0. Quit" << endl;
        cin >> selection;
        switch(selection){
            case 1:
                DoInitialize();
                break;
            case 2:
                DoDisplayLeague();
                break;
            case 3:
                DoEnterMatchResult();
                break;
            case 4:
                DoDeductPoints();
                break;
            case 5:
                DoBestDefence();
                break;
            case 6:
                DoRelegationZone();
                break;
            case 7:
                DoRemoveTeamFromList();
                break;
            case 8:
                cout << "Functionality not yet implemented" << endl;
                break;
            case 9:
                cout << "Functionality not yet implemented" << endl;
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                selection = -1;
                break;
            default:
                cout << "Invalid selection, please try again..." << endl;
        }
    }while (selection != -1);
}

void assistantMenu(){
    int selection;
    do{
        cout << "PLease make a selection below." << endl;
        cout << "1. Display League Table" << endl;
        cout << "2. Enter a Match Result" << endl;
        cout << "3. Best Defence." << endl;
        cout << "4. Relegation Zone." << endl;
        cout << "0. Quit" << endl;
        cin >> selection;
        switch(selection){
            case 1:
                DoDisplayLeague();
                break;
            case 2:
                DoEnterMatchResult();
                break;
            case 3:
                DoBestDefence();
                break;
            case 4:
                DoRelegationZone();
                break;
            case 0:
                cout << "Returning to main menu." << endl;
                selection = -1;
                break;
            default:
                cout << "Invalid selection, please try again..." << endl;
        }
    }while (selection != -1);
    
}

void DoInitialize (void){
    string name, kNum;
    bool foundInList; //  Boolean to check if leage found in list
    cout << "Please enter the following information and to initalise the program." << endl;
    for(int i = 0; i < LEAGUE_SIZE; i++){
        do{ //  Do While loop to check if name league already exists
            cout << "Team " << (i+1) << endl << "\tName: ";
            foundInList = false;
            cin >> name;
            foundInList = teamExistsInLeague(name);
            if(foundInList) //  Output to user if student already exists.
                cout << "A team with that name already exists in the league! Try again." << endl;
        } while(foundInList);
        league[i] = CFootballTeam(name); //  Add Team to list once we are sure they don't already exist
        cout << endl;
    }
}

void DoDisplayLeague(void) {
   
    cout << "DoDisplayLeague should display the league table" << endl;
    // Added table headers as requested in project spec
    cout << "|" << left << setw(10) << "Name" << "\t|\t"
                << left << setw(7) << "Played" << "\t|\t"
                << left << setw(7) << "For" << "\t|\t"
                << left << setw(7) << "Against" << "\t|\t"
                << left << setw(7) << "Points" << "\t|" << endl;
    for (int i = 0; i < LEAGUE_SIZE; i++) {
//        Formatting output as table
//        cout << "Name: " << league[i].GetName() << endl;
//        cout << "games Played: " << league[i].GetGamesPlayed() << endl;
//        cout << "goals for: " << league[i].GetGoalsFor() << endl;
//        cout << "goals Against: " << league[i].GetGoalsAgainst() << endl;
//        cout << "points: " << league[i].GetPoints() << endl;
        cout << "|" << left << setw(10) << league[i].GetName() << "\t|\t";
        cout << right << setw(7) << league[i].GetGamesPlayed() << "\t|\t";
        cout << setw(7) << league[i].GetGoalsFor() << "\t|\t";
        cout << setw(7) << league[i].GetGoalsAgainst() << "\t|\t";
        cout << setw(7) << league[i].GetPoints() << "\t|" << endl;
       
    }
    
}

void DoEnterMatchResult(void){
    string hometeam, awayteam;
    int homescore, awayscore;

    cout << "Enter match result in the form 'hometeam homescore awayteam awayscore': ";
    cin >> hometeam >> homescore >> awayteam >> awayscore;

    for (int i = 0; i < LEAGUE_SIZE; i++){
        if (league[i].HasName(hometeam)) {
            league[i].UpdateOnResult(homescore, awayscore);
        }
    
        else if (league[i].HasName(awayteam)) {
            league[i].UpdateOnResult(awayscore, homescore);
        }
    }
    sortLeague();
}

void DoDeductPoints (void){
    bool found;
    string name;
    int points;
    cout << "DoDeductPoints should get number of points and team name from user and make relevant change" << endl;
    cout << "Please enter a Team name:";
    // check if team exists and propt user again if not found
    do{
        cin >> name;
        found = teamExistsInLeague(name);
        if(!found)
            cout << "Team does not exist in the league, please try again." << endl;
    } while(!found);
    cout << "How many points would you like to deduct? ";
    cin >> points;
    for(int i = 0; i < LEAGUE_SIZE; i++)
        if(league[i].HasName(name)){
            if(league[i].GetPoints() >= points)
                league[i].DeductPoints(points);
            else
                cout << "Error: Leagues total points exceeded, no change made." << endl;
        }
            
}

void DoBestDefence (void){
    cout << "DoBestDefence (callback for option 5) should firstly search the collection league to ascertain the lowest number of goals against. The collection should then be re-searched and the name(s) of the team(s) with the lowest goals against should be displayed." << endl;
    double BestDef;
    BestDef = league[0].GetGoalsAgainst();
    for (int i = 0; i < LEAGUE_SIZE; i++)
    {
//        Consiceness
//        Def = league[i].GetGoalsAgainst();
//        if (BestDef > Def)
//        {
//            BestDef = Def;
//        }
        if(league[i].GetGoalsAgainst() < BestDef)
            BestDef = league[i].GetGoalsAgainst();
    }
    cout << "The team(s) with the best defence:";
    cout << "Name\tGoals Against";
    for (int i = 0; i < LEAGUE_SIZE; i++){
        if (league[i].GetGoalsAgainst() == BestDef)
        {
            cout << league[i].GetName() << "\t" << league[i].GetGoalsAgainst();
//            cout << "Name: "<< league[i].GetName() <<" Games Played: " << league[i].GetGamesPlayed() << " Goals for: "<< league[i].GetGoalsFor()
//                << " Goals Against: " << league[i].GetGoalsAgainst() << " Points: " << league[i].GetPoints() << endl;
            
        }
    }
}

void DoRelegationZone(void) {
    for (int i = LEAGUE_SIZE; i >= LEAGUE_SIZE - 2; i--) {
        cout << league[i - 1].GetName() << ", " << league[i - 1].GetPoints() << "\n";
    }
}

void DoRemoveTeamFromList(void){
    cout << "Allows the user to remove a team from the existing list of teams." << endl;
    string name;
    int position = -1, mod = 0;
    cout << "Please enter the team name you wish to delete." << endl;
    cin >> name;
    // Loop through the league to locate position of the team in the array
    for (int i = 0; i < LEAGUE_SIZE; i++)
    {
        if (name == league[i].GetName()){
            position = i;
        }
    }
    // Create a new array to temporarily hold the elements while we resize, this isn't the most efficent solution but it works.
    CFootballTeam* newLeague = new CFootballTeam[LEAGUE_SIZE-1];
    // Output to user if team not found in collection
    if (position == -1)
        cout << "Team wasn't found in the league\n";
    else
        // loop through the array
        for(int i = 0; i < LEAGUE_SIZE; i++)
            // if the position matches i we don't want to swap anything but we need to account for this by increasing a mod variable
            if(position == i)
                mod++;
            // else (all elements except the one to be removed) we add the element to temp array i-mod insures we account for the element we passed over.
            else
                newLeague[i-mod] = league[i];
    league = newLeague;// set our original league variable equal to the temp array we created
    LEAGUE_SIZE--;// Update LEAGUE_SIZE
    delete [] newLeague;// Delete temp array from the heap in memory
    cout << endl;
}

bool teamExistsInLeague(string name){
    for(int i = 0; i < LEAGUE_SIZE; i++)
        if(league[i].HasName(name))
            return true;
    return false;
}

void sortLeague(){
    for(int i = 0; i < LEAGUE_SIZE; i++){
        for(int j = 0; j < LEAGUE_SIZE - i - 1; j++)
            if(league[j].GetPoints() < league[j+1].GetPoints())
                swap(league[j], league[j+1]);
    }
}
