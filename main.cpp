#include <iostream>
#include <stdlib.h>
#include <list>
#include <windows.h>
using namespace std;
class Job {
public:
    string name;
    string desc;
    int level;
    int maxLevel;
    Job(string name_, string desc_, int level_, int maxLevel_) {
        name = name_;
        desc = desc_;
        level = level_;
        maxLevel = maxLevel_;
    }

};
class Game {
public:
    list<Job> jobs;
    list<Job>::iterator it;
    Job j1 = Job("Biznes1", "Zwykly biznes", 0, 500);
    Job j2 = Job("Biznes2", "Zwykly biznes", 0, 500);
    Job j3 = Job("Biznes3", "Zwykly biznes", 0, 500);
    Job j4 = Job("Biznes4", "Zwykly biznes", 0, 500);
    Job j5 = Job("Biznes5", "Zwykly biznes", 0, 500);
    Job j6 = Job("Biznes6", "Zwykly biznes", 0, 500);
    Job j7 = Job("Biznes7", "Zwykly biznes", 0, 500);
    Job j8 = Job("Biznes8", "Zwykly biznes", 0, 500);
    Game() {
        jobs.push_back(j1);
        jobs.push_back(j2);
        jobs.push_back(j3);
        jobs.push_back(j4);
        jobs.push_back(j5);
        jobs.push_back(j6);
        jobs.push_back(j7);
        jobs.push_back(j8);
    }
    void Menu() {
        cout << "IT CAPITALIST" << endl;
        cout << "CASH: " << endl;
        for (it = jobs.begin(); it != jobs.end(); ++it)
        {
            cout << it->name << endl;
            cout << it->desc << endl;
            cout << "[-------------]" << endl;
            cout << it->level << " / " << it->maxLevel << endl << endl;
        }
    }
    void ClearScreen()
    {
        cout << string(100, '\n');
    }
}game;
int main() {
    for (;;) {
        game.Menu();
        cin.ignore();
        game.ClearScreen();
    }
    return 0;
}