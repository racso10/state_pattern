//
// Created by Racso on 2019/8/13.
//

#ifndef STATE_PATTERN_WORKSTATEPATTERN_H
#define STATE_PATTERN_WORKSTATEPATTERN_H


#include <iostream>

using namespace std;

class WorkStatePattern;

class State {
public:
    virtual void writeProgram() = 0;
};

class ForenoonState : public State {
private:
    WorkStatePattern *work;

public:
    explicit ForenoonState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class NoonState : public State {
private:
    WorkStatePattern *work;

public:
    explicit NoonState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class AfternoonState : public State {
private:
    WorkStatePattern *work;

public:
    explicit AfternoonState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class EveningState : public State {
private:
    WorkStatePattern *work;

public:
    explicit EveningState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class ICUState : public State {
private:
    WorkStatePattern *work;

public:
    explicit ICUState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class RestState : public State {
private:
    WorkStatePattern *work;

public:
    explicit RestState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class ForceRestState : public State {
private:
    WorkStatePattern *work;

public:
    explicit ForceRestState(WorkStatePattern *work) {
        this->work = work;
    }

    void writeProgram() override;
};

class WorkStatePattern {
private:
    State *state;
    int hour;
    bool finish;

public:
    WorkStatePattern(int hour, bool finish) {
        this->hour = hour;
        this->finish = finish;
        this->state = new ForenoonState(this);
    }

    void setHour(int hour) {
        this->hour = hour;
    }

    int getHour() {
        return this->hour;
    }

    void setFinish(bool finish) {
        this->finish = finish;
    }

    bool getFinish() {
        return this->finish;
    }

    void setState(State *state) {
        this->state = state;
    }

    void writeProgram() {
        this->state->writeProgram();
    }

};


#endif //STATE_PATTERN_WORKSTATEPATTERN_H
