#include<cstdio>
#include<iostream>
#include<ctime>
#include <cmath>
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
    void MoneyAdd(int cash_) 
    {
        cash += cash_;
    }
}money;
class Job {
public:
    string name;
    string desc;
    int level;
    int maxLevel;
    int price;
    int reward;
    time_t startTime;
    int secondsToGo;
    float timeToShow;
    Job(string name_, string desc_, int price_, int reward_,int secondsToGo_) {
        level = 0;
        maxLevel = 20;
        name = name_;
        desc = desc_;
        price = price_;
        reward = reward_;
        secondsToGo = secondsToGo_;
        timeToShow = 0;
        StartWorking();
    }
    void StartWorking() 
    {
        startTime = time(NULL);
    }
    void CheckWorkDone()
    {
        if (level!=0)
        {
            int currentTime = time(NULL);
            
            int secondsPassed = (currentTime - startTime);
            int CirclesDoneInt = secondsPassed / secondsToGo;
            float CirclesDoneFloat = secondsPassed % secondsToGo;
            int secondsSpare = secondsPassed - CirclesDoneInt * secondsToGo;
            
            if (CirclesDoneInt >= 1)
            {
                money.MoneyAdd(reward * CirclesDoneInt);
                startTime = currentTime - secondsSpare;
            }
            timeToShow = (float)(CirclesDoneFloat / secondsToGo);
        }
        
    }
};
class Game {
public:
    list<Job> jobs;
    list<Job>::iterator it;
    Job j1 = Job("Dropshiping", "Kupujesz taniej sprzedajesz drozej", 1, 1, 5);
    Job j2 = Job("Webmaster", "Tworzysz slabe strony na wordpressie", 20, 5, 10);
    Job j3 = Job("Computer technical support", "Wlaczasz i wylaczasz do skutku", 50, 10, 30);
    Job j4 = Job("Service assistant", "Pracujesz w serwisie u wujka", 100, 25, 45);
    Job j5 = Job("Master programmer", "Umiesz uzywac juz petli for i while", 500, 100, 60);
    Job j6 = Job("Unity designer", "Robisz podrobki gier, tyko gorzej", 2000, 500, 75);
    Job j7 = Job("Bitcoin trader", "Kopiesz bitcoina na starym laptopie babci", 10000, 1000, 90);
    Job j8 = Job("Owner of twitter", "Przywracasz wolnosc slowa", 100000, 10000, 120);
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
    string LoadingBar(float time) {
        string loading = "----------", hasz = "";
        float temp = round(time * 10) / 10;
        int y =0;

        for (float i = 0; i <= temp; i += 0.1)
        {
            y++;
            hasz.append("#");
            
        }
        loading.replace(0, y, hasz);
        return loading;
    }
    void Menu() {
        cout << "IT CAPITALIST \n";
        cout << "CASH: " << money.cash << " CPU's \n\n";
        for (it = jobs.begin(); it != jobs.end(); ++it)
        {
            cout << it->name << endl;
            cout << it->desc << endl;
            if (it->level!=0)
            {
                cout << "PRICE: " << it->price << endl;
                cout << "REWARD: " << it->reward << endl;
                cout << "TIME: (" << it->secondsToGo << "s) [" << LoadingBar(it->timeToShow) << "]" << endl;
                cout << "LEVEL: " << it->level << " / " << it->maxLevel << "\n\n";
            }
            else
            {
               cout << "LOCKED\n";
               cout << "PRICE: " << it->price << "\n\n";
            }
            
        }
    }
    void Commands(string code)
    {
        string cheatCodes[] = { "alldone", "unlockall", "firstday" };
        if (code == cheatCodes[0])
        {
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                   it->level = 100;

            }
        }
        else if (code == cheatCodes[1])
        {
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                if (it->level == 0)
                {
                    it->level = 1;
                }
            }
        }
        else if (code == cheatCodes[2])
        {
            jobs.begin()->level = 500;
        }
        else if (code.substr(0, 3) == "buy") 
        {
            char index = code.back();
            int number = index - '1';
            int i = 0;
            for (it = jobs.begin(); it != jobs.end(); ++it)
            {
                if (i == number)
                {
                    if (money.cash >= it->price)
                    {
                        it->level += 1;
                        money.cash -= it->price;
                    }
                }
                i++;
            }
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
    string command;
    for (;;) {
        game.Menu();
        do {
            cout << "Press ENTER" << endl;
            getline(cin, command);
            game.Commands(command);      
        } while (command.length() != 0);
        game.ClearScreen();
        game.CheckWorkDone();
    }
    return 0;

}