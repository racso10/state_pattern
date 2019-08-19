//
// Created by Racso on 2019/8/13.
//

#include "Work.h"
#include <iostream>

using namespace std;

Work::Work(int hour, bool finish) {
    this->hour = hour;
    this->finish = finish;
}

void Work::setHour(int hour) {
    this->hour = hour;
}

int Work::getHour() {
    return this->hour;
}

void Work::setFinish(bool finish) {
    this->finish = finish;
}

bool Work::getFinish() {
    return this->finish;
}

void Work::writeProgram() {
    static int isHome = 0;
    static int isICU = 0;
    if (this->hour < 12) {
        cout << "��ǰʱ�䣺" << this->hour << "�㣬���繤��" << endl;
    } else if (this->hour < 13) {
        cout << "��ǰʱ�䣺" << this->hour << "�㣬����" << endl;
    } else if (this->hour < 17) {
        cout << "��ǰʱ�䣺" << this->hour << "�㣬���繤��" << endl;
    } else {
        if (this->finish && isICU == 0 || isHome == 1) {
            cout << "��ǰʱ�䣺" << this->hour << "�㣬�°�ؼ�" << endl;
            isHome = 1;
        } else {
            if (this->hour > 19 && isHome == 0) {
                cout << "��ǰʱ�䣺" << this->hour << "�㣬ǿ���°�" << endl;
                isHome = 1;
            } else if (this->hour < 23) {
                cout << "��ǰʱ�䣺" << this->hour << "�㣬�Ӱ� :-( " << endl;
            } else {
                cout << "��ǰʱ�䣺" << this->hour << "�㣬ICU x_x " << endl;
                isICU = 1;
            }
        }
    }
}