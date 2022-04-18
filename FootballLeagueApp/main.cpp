//
//  main.cpp
//  FootballLeagueApp
//
//  Created by James Connolly on 18/04/2022.
//

#include <iostream>
#include "CFootballTeam.hpp"

//  Menu Prototypes
void mainMenu(void);
void assistantMenu(void);
void managerMenu(void);

void DoInitialize (void);
void DoDisplayLeague (void);
void DoEnterMatchResult (void);
void DoDeductPoints (void);
void DoBestDefence (void);
void DoRelegationZone (void);
void DoRemoveTeamFromList(void);

//global variable to track league size
const int LEAGUE_SIZE = 5;

CFootballTeam league[LEAGUE_SIZE];

int main() {
    cout << "Welcome to the Football Leage Applicaiton" << endl;
    mainMenu();
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
                cout << "Terminating application!" << endl;
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
                cout << "Returning to main menu!" << endl;
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
                cout << "Returning to main menu!" << endl;
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
            for(int i = 0; i < LEAGUE_SIZE; i++)
                if(league[i].HasName(name))
                    foundInList = true;
            if(foundInList) //  Output to user if student already exists.
                cout << "A team with that name already exists in the league! Try again!" << endl;
        } while(foundInList);
        league[i] = CFootballTeam(name); //  Add Team to list once we are sure they don't already exist
        cout << endl;
    }
}

void DoDisplayLeague (void){
    cout << "DoDisplayLeague should display the league table" << endl;

}

void DoEnterMatchResult (void){
    cout << "DoEnterMatchResult should allow the user to enter a match result in the form:\t hometeam homescore awayteam awayscore." << endl;
    
}

void DoDeductPoints (void){
    cout << "DoDeductPoints should get number of points and team name from user and make relevant change" << endl;
    
}

void DoBestDefence (void){
    cout << "DoBestDefence (callback for option 5) should firstly search the collection league to ascertain the lowest number of goals against. The collection should then be re-searched and the name(s) of the team(s) with the lowest goals against should be displayed." << endl;
    
}

void DoRelegationZone (void){
    cout << "This should display the names and points of the last three teams in the league." << endl;
    
}

void DoRemoveTeamFromList(void){
    cout << "Allows the user to remove a team from the existing list of teams." << endl;
    
}
