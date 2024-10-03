#include <iostream>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

struct Fixture {
    string homeTeam;
    string awayTeam;
    string stadium;
    string hometown;
    int leg;
    int weekend;
};

vector<string> teams;
vector<string> hometowns;
vector<string>stadiums;
vector<Fixture> fixtures;

int count = 0;

int main(){
      fstream myFile;


    myFile.open("teams_csvFile.csv", ios::in);
    string line = "";

    if(myFile.is_open()) {
        getline(myFile, line);

        while(getline(myFile, line)) {
            stringstream ss(line);
            string team_name, hometown, stadium;

            getline(ss, team_name, ',');
            getline(ss, hometown, ',');
            getline(ss, stadium, ',');

            teams.push_back(team_name);
            hometowns.push_back(hometown);
            stadiums.push_back(stadium);
            count++;
        }
    }

    myFile.close();

    return 0;
}
