//
// Created by Racso on 2019/8/13.
//

#include "WorkStatePattern.h"

void ForenoonState::writeProgram() {
    if (this->work->getHour() < 12) {
        cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬���繤��" << endl;
    } else {
        this->work->setState(new NoonState(this->work));
        this->work->writeProgram();
    }
}

void NoonState::writeProgram() {
    if (this->work->getHour() < 13) {
        cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬����" << endl;
    } else {
        this->work->setState(new AfternoonState(this->work));
        this->work->writeProgram();
    }
}

void AfternoonState::writeProgram() {
    if (this->work->getHour() < 17) {
        cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬���繤��" << endl;
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
            cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬�Ӱ� :-( " << endl;
        } else {
            this->work->setState(new ICUState(this->work));
            this->work->writeProgram();
        }
    }
}

void ICUState::writeProgram() {
    cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬ICU x_x " << endl;
}

void RestState::writeProgram() {
    cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬�°�ؼ�" << endl;
}

void ForceRestState::writeProgram() {
    cout << "��ǰʱ�䣺" << this->work->getHour() << "�㣬ǿ���°�" << endl;
    this->work->setState(new RestState(this->work));
    this->work->writeProgram();
}