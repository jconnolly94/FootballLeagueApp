//
//  CFootballTeam.hpp
//  FootballLeagueApp
//
//  Created by James Connolly on 18/04/2022.
//

#ifndef CFootballTeam_hpp
#define CFootballTeam_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>

#endif /* CFootballTeam_hpp */

using namespace std;

class CFootballTeam{
private:
    string m_Name;
    int m_GamesPlayed;
    int m_GoalsFor;
    int m_GoalsAgainst;
    int m_Points;
    
public:
    //  Constructors
    CFootballTeam(void);
    CFootballTeam(string name);
    CFootballTeam(string name, int gamesPlayed, int goalsFor, int goalsAgainst, int points);
    
    //  Getters
    string GetName(void);
    int GetGamesPlayed(void);
    int GetGoalsFor(void);
    int GetGoalsAgainst(void);
    int GetPoints(void);
    
    //  Setters
    
    //  Functions
    bool HasName(string searchName);
    
    void Display(void);
    
    void UpdateOnResult(int goalsFor, int goalsAgainst);
    
    void DeductPoints(int num);
};
