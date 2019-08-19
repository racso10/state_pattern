//
// Created by Racso on 2019/8/13.
//

#ifndef STATE_PATTERN_MACHINE_H
#define STATE_PATTERN_MACHINE_H

#include<iostream>

using namespace std;

//以下为类的定义部分
class Machine;//类的提前引用
//抽象状态
class State {
public:
    virtual void insertQuarter()=0;//“投币”按钮被按下
    virtual void ejectQuarter()=0;//“退币”按钮被按下
    virtual void turnCrank()=0;//“出纸巾”按钮被按下
    virtual void dispense()=0;//正在卖出纸巾
};

//具体状态
class SoldOutState : public State {//纸巾售完状态
private:
    Machine *machine;
public:
    explicit SoldOutState(Machine *machine1) {
        this->machine = machine1;
    }

    void insertQuarter() override;

    void ejectQuarter() override;

    void turnCrank() override;

    void dispense() override;
};

class NoQuarterState : public State {//没有投币状态
private:
    Machine *machine;
public:
    explicit NoQuarterState(Machine *machine) {
        this->machine = machine;
    }

    void insertQuarter() override;

    void ejectQuarter() override;

    void turnCrank() override;

    void dispense() override;
};

class HasQuarterState : public State {//有2元钱（已投币状态）
private:
    Machine *machine;
public:
    explicit HasQuarterState(Machine *machine) {
        this->machine = machine;
    }

    void insertQuarter() override;

    void ejectQuarter() override;

    void turnCrank() override;

    void dispense() override;
};

class SoldState : public State {//出售纸巾状态
private:
    Machine *machine;
public:
    explicit SoldState(Machine *machine) {
        this->machine = machine;
    }

    void insertQuarter() override;

    void ejectQuarter() override;

    void turnCrank() override;

    void dispense() override;
};

//上下文
class Machine {
private:
    State *state;
    int count;//纸巾数
public:
    explicit Machine(int numbers) {//构造函数，定义初始状态有纸巾售卖机有多少纸巾
        this->count = numbers;
        if (count > 0) {
            this->state = new NoQuarterState(this);//开始为没有投币的状态
        }
    };

    //开放给主函数调用的方法
    void insertQuarter() {
        state->insertQuarter();
    }

    void ejectQuarter() {
        state->ejectQuarter();
    }

    void turnCrank() {
        state->turnCrank();
        state->dispense();
    }

    //数据传递的getter与setter
    void setState(State *state) {
        this->state = state;
    }

    int getCount() {
        return count;
    };

    void setCount(int numbers) {
        this->count = numbers;
    };
};


#endif //STATE_PATTERN_MACHINE_H
