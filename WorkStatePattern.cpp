//
// Created by Racso on 2019/8/13.
//

#include "WorkStatePattern.h"

void ForenoonState::writeProgram() {
    if (this->work->getHour() < 12) {
        cout << "当前时间：" << this->work->getHour() << "点，上午工作" << endl;
    } else {
        this->work->setState(new NoonState(this->work));
        this->work->writeProgram();
    }
}

void NoonState::writeProgram() {
    if (this->work->getHour() < 13) {
        cout << "当前时间：" << this->work->getHour() << "点，午休" << endl;
    } else {
        this->work->setState(new AfternoonState(this->work));
        this->work->writeProgram();
    }
}

void AfternoonState::writeProgram() {
    if (this->work->getHour() < 17) {
        cout << "当前时间：" << this->work->getHour() << "点，下午工作" << endl;
    } else {
        this->work->setState(new EveningState(this->work));
        this->work->writeProgram();
    }
}

void EveningState::writeProgram() {
    if (this->work->getFinish()) {
        this->work->setState(new RestState(this->work));
        this->work->writeProgram();
    } else {
        if (this->work->getHour() > 19) {
            this->work->setState(new ForceRestState(this->work));
            this->work->writeProgram();
        } else if (this->work->getHour() < 23) {
            cout << "当前时间：" << this->work->getHour() << "点，加班 :-( " << endl;
        } else {
            this->work->setState(new ICUState(this->work));
            this->work->writeProgram();
        }
    }
}

void ICUState::writeProgram() {
    cout << "当前时间：" << this->work->getHour() << "点，ICU x_x " << endl;
}

void RestState::writeProgram() {
    cout << "当前时间：" << this->work->getHour() << "点，下班回家" << endl;
}

void ForceRestState::writeProgram() {
    cout << "当前时间：" << this->work->getHour() << "点，强制下班" << endl;
    this->work->setState(new RestState(this->work));
    this->work->writeProgram();
}