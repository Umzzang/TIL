#include <iostream>

using namespace std;

struct TV {

      // �ۿ����� ���� �Ұ�
    bool powerOn;
    int channel;
    int volume;
    public:    // �ۿ��� ���� ����

    void on() {
        powerOn = true;
        cout << "TV�� �׽��ϴ�" << endl;
    }

    void off() {
        powerOn = false;
        cout << "TV�� �����ϴ�" << endl;
    }

    void setChannel(int cnl) {
        if (cnl >= 1 && cnl <=100) {
            channel = cnl;
            cout << "ä����" << cnl << "���� �ٲ���ϴ�" << endl;
        }
    }

    void setVolume(int vol) {
        if (vol >= 0 && vol <=100) {
            volume = vol;
            cout << "������" << vol << "���� �ٲ���ϴ�" << endl;
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
    //lg.volume = 400; //�̷������� �ϸ� ������ �� �� ����
}