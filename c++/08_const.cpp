#include <iostream>

using namespace std;

class Account {
public:
    Account() : money(0) {}
    Account(int money) : money(money) {}

    void Deposit(const int d) {
        money += d;
        cout << d << "원 예금" << endl;
    }

    void Draw(const int d) {
        if (money >= d) {
            money -= d;
            cout << d << "원 인출" << endl;
        }
    }

    int ViewMoney() const {
        return money;
    }

private:
    int money;
};

int main() {
    Account doodle(200);
    doodle.Deposit(100);
    doodle.Draw(20);

    cout << doodle.ViewMoney() << endl;
}