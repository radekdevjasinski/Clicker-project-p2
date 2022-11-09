#include<cstdio>
#include<iostream>
#include<ctime>
#include<stdlib.h>
#include<windows.h>
#include<list>
#include<string>
#include <limits>
using namespace std;
class Money
{
public:
    int cash;
    Money() 
    {
        cash = 1;
    }
    string WriteMoney() 
    {
        int num = cash, count = 0, d = 1;
        string str = "";
        while (cash) {
            cash /= 10;
            count++;
            if (cash) d *= 10;
        }
        cash = num;

        while (num) {
            if (count-- % 3 == 0 and cash != num) str += ",";

            str += to_string(num / d);
            num %= d;
            d /= 10;
        }
        return str;
    }
    void MoneyAdd(int cash_) 
    {
        cash = cash_;
    }
}money;
class Job {
public:
    string name;
    string desc;
    bool isLocked;
    int level;
    int maxLevel;
    int price;
    int reward;
    time_t startTime;
    int secondsToGo;
    float timeToShow;
    Job(string name_, string desc_, int level_, int maxLevel_, int price_, int reward_,int secondsToGo_, bool isLocked_) {
        name = name_;
        desc = desc_;
        level = level_;
        maxLevel = maxLevel_;
        price = price_;
        isLocked = isLocked_;
        reward = reward_;
        secondsToGo = secondsToGo_;
        timeToShow = 0;
    }
    void StartWorking() 
    {
        startTime = time(NULL);
    }
    void CheckWorkDone()
    {
        if (!isLocked)
        {
            cout << startTime;
            int CirclesDoneInt = (time(NULL) - startTime) / secondsToGo;
            float CirclesDoneFloat = (time(NULL) - startTime) / secondsToGo - CirclesDoneInt;
            if (CirclesDoneInt >= 1)
            {
                money.MoneyAdd(reward * CirclesDoneInt);
                startTime += CirclesDoneInt * secondsToGo;
            }
            timeToShow = (float)(CirclesDoneFloat / secondsToGo);
        }
        
    }
};
class Game {
public:
    list<Job> jobs;
    list<Job>::iterator it;
    Job j1 = Job("Biznes1", "Zwykly biznes", 0, 500, 500, 1, 5, false);
    Job j2 = Job("Biznes2", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j3 = Job("Biznes3", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j4 = Job("Biznes4", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j5 = Job("Biznes5", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j6 = Job("Biznes6", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j7 = Job("Biznes7", "Zwykly biznes", 0, 500, 500, 1, 5, true);
    Job j8 = Job("Biznes8", "Zwykly biznes", 0, 500, 500, 1, 5, true);
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
        cout << "IT CAPITALIST \n";
        cout << "CASH: " << money.WriteMoney() << " CPU's \n\n";
        for (it = jobs.begin(); it != jobs.end(); ++it)
        {
            cout << it->name << endl;
            cout << it->desc << endl;
            if (!it->isLocked)
            {
                cout << "PRICE: " << it->price << endl;
                cout << "TIME: " << it->timeToShow << endl;
                cout << "LEVEL: " << it->level << " / " << it->maxLevel << "\n\n";
                it->StartWorking();
            }
            else
            {
               cout << "LOCKED\n\n";
            }
            
        }
    }
    void CheatCodesGame(string code)
    {
        string codes[] = { "AllDone", "UnlockAll", "FirstDay" };
        if (code == codes[0]) 
        {
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                   it->isLocked = false;
                   //it->price;
                   it->level = 100;

            }
        }
        else if (code == codes[1])
        {
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                if (it->isLocked)
                {
                    it->isLocked = false;
                    //it->price;
                    it->level = 1;
                }
            }
        }
        else if (code == "FirstDay")
        {
            jobs.begin()->level = 500;
        }
        
    }

    void ClearScreen()
    {
        cout << string(100, '\n');
    }
    void CheckWorkDone() 
    {
        for (it = jobs.begin(); it != jobs.end(); ++it)
        {
            it->CheckWorkDone();
        }
    }
}game;

int main() {
    string cheats;
    for (;;) {
        game.Menu();
        cin >> cheats;
        if (cin.get() != '\n')   
            game.CheatCodesGame(cheats);      
        game.ClearScreen();
        game.CheckWorkDone();
    }
    return 0;

}