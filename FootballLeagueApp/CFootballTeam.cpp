//
//  CFootballTeam.cpp
//  FootballLeagueApp
//
//  Created by James Connolly on 18/04/2022.
//

#include "CFootballTeam.hpp"

//string m_Name;
//int m_GamesPlayed;
//int m_GoalsFor;
//int m_GoalsAgainst;
//int m_Points;

//  Default Constuctor
CFootballTeam::CFootballTeam(void){
    m_Name = "";
    m_GamesPlayed = 0;
    m_GoalsFor = 0;
    m_GoalsAgainst = 0;
    m_Points = 0;
}

//  Constuctor for name
CFootballTeam::CFootballTeam(string name){
    m_Name = name;
    m_GamesPlayed = 0;
    m_GoalsFor = 0;
    m_GoalsAgainst = 0;
    m_Points = 0;
}

//  Database constructor for file IO
CFootballTeam::CFootballTeam(string name, int gamesPlayed, int goalsFor, int goalsAgainst, int points){
    m_Name = name;
    m_GamesPlayed = gamesPlayed;
    m_GoalsFor = goalsFor;
    m_GoalsAgainst = goalsAgainst;
    m_Points = points;
}

string CFootballTeam::GetName(){
    return m_Name;
}

int CFootballTeam::GetGamesPlayed(){
    return m_GamesPlayed;
}

int CFootballTeam::GetGoalsFor(){
    return m_GoalsFor;
}

int CFootballTeam::GetGoalsAgainst(){
    return m_GoalsAgainst;
}

int CFootballTeam::GetPoints(){
    return m_Points;
}


//  Checks if object has given string as name
bool CFootballTeam::HasName(string searchName){
    if(m_Name == searchName)
        return true;
    return false;
}

//  Display a single line for the league table
void CFootballTeam::Display(void){
    cout << m_Name << "\t" << m_GamesPlayed << "\t" << m_GoalsFor << "\t" << m_GoalsAgainst <<
    m_Points << endl;
}

//  Update points based on goals for/against.
void CFootballTeam::UpdateOnResult(int goalsFor, int goalsAgainst){
    if(goalsFor > goalsAgainst)
        m_Points += 3;
    if(goalsFor == goalsAgainst)
        m_Points += 1;
}


//  Deduct a given number of points, error checking to be handled in main class
void CFootballTeam::DeductPoints(int num){
    m_Points -= num;
}
