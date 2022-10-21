#include <iostream>
#include<string>
using namespace std;

class Money
{
public:
    int cash, count = 0, d = 1;
    string WriteMoney() {
        int num = cash;
        string str = "";
        while (cash) {
            cash /= 10;
            count++;
            if (cash) d *= 10;
        }
        cash = num;

        while (num) {
            if (count-- % 3 == 0 and cash != num) str += ",";

            str += to_string(num/d);
            num %= d;
            d /= 10;
        }
        return str;
    }
}money;

int main() {
    money.cash = 1235678;
    cout << money.WriteMoney();
    return 0;

}