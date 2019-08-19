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
        cout << "当前时间：" << this->hour << "点，上午工作" << endl;
    } else if (this->hour < 13) {
        cout << "当前时间：" << this->hour << "点，午休" << endl;
    } else if (this->hour < 17) {
        cout << "当前时间：" << this->hour << "点，下午工作" << endl;
    } else {
        if (this->finish && isICU == 0 || isHome == 1) {
            cout << "当前时间：" << this->hour << "点，下班回家" << endl;
            isHome = 1;
        } else {
            if (this->hour > 19 && isHome == 0) {
                cout << "当前时间：" << this->hour << "点，强制下班" << endl;
                isHome = 1;
            } else if (this->hour < 23) {
                cout << "当前时间：" << this->hour << "点，加班 :-( " << endl;
            } else {
                cout << "当前时间：" << this->hour << "点，ICU x_x " << endl;
                isICU = 1;
            }
        }
    }
}