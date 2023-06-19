#include <iostream>

using namespace std;

struct TV {

      // 밖에서는 접근 불가
    bool powerOn;
    int channel;
    int volume;
    public:    // 밖에서 접근 가능

    void on() {
        powerOn = true;
        cout << "TV를 켰습니다" << endl;
    }

    void off() {
        powerOn = false;
        cout << "TV를 껐습니다" << endl;
    }

    void setChannel(int cnl) {
        if (cnl >= 1 && cnl <=100) {
            channel = cnl;
            cout << "채널을" << cnl << "으로 바꿨습니다" << endl;
        }
    }

    void setVolume(int vol) {
        if (vol >= 0 && vol <=100) {
            volume = vol;
            cout << "볼륨을" << vol << "으로 바꿨습니다" << endl;
        }
    }
};


int main() {
    TV lg;
    lg.on();
    lg.powerOn = true;
    lg.setChannel(30);
    //lg.channel = 10;
    lg.setVolume(50);
    //lg.volume = 400; //이런식으로 하면 문제가 될 수 있음
}