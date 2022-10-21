#include<cstdio>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<future>
#include<chrono>
#include<list>
using namespace std;
class Job {
public:
    string name;
    string desc;
    int level;
    int maxLevel;
    int price;
    Job(string name_, string desc_, int level_, int maxLevel_, int price_) {
        name = name_;
        desc = desc_;
        level = level_;
        maxLevel = maxLevel_;
        price = price_;
    }
};
class Timer {
public:
    unsigned long int time;
    Timer() {
        time = 0;
    }
}timer;
void startTimer() {
    timer.time = 0;
    cout << "Start\n";
    for (;;)
    {
        timer.time++;
        cout << timer.time << '\n';
        this_thread::sleep_for(chrono::seconds(1));
    }
}
class Game {
public:
    list<Job> jobs;
    list<Job>::iterator it;
    Job j1 = Job("Biznes1", "Zwykly biznes", 0, 500, 500);
    Job j2 = Job("Biznes2", "Zwykly biznes", 0, 500, 500);
    Job j3 = Job("Biznes3", "Zwykly biznes", 0, 500, 500);
    Job j4 = Job("Biznes4", "Zwykly biznes", 0, 500, 500);
    Job j5 = Job("Biznes5", "Zwykly biznes", 0, 500, 500);
    Job j6 = Job("Biznes6", "Zwykly biznes", 0, 500, 500);
    Job j7 = Job("Biznes7", "Zwykly biznes", 0, 500, 500);
    Job j8 = Job("Biznes8", "Zwykly biznes", 0, 500, 500);
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
            cout <<"CENA: " << it->price << endl;
            cout << "CZAS: " << "[-------------]" << endl;
            cout << "POZIOM: " << it->level << " / " << it->maxLevel << endl << endl;
        }
    }
    void ClearScreen()
    {
        cout << string(100, '\n');
    }
}game;
int main() {
    auto future = async(startTimer);
    for (;;) {
        game.Menu();
        //cout << timer.time;
        cin.ignore();
        game.ClearScreen();
    }
    return 0;
}