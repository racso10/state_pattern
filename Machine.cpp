//
// Created by Racso on 2019/8/13.
//

#include "Machine.h"
//纸巾售完状态
void SoldOutState::insertQuarter() {
    cout << "机器无纸巾，已退回硬币！" << endl;
}

void SoldOutState::ejectQuarter() {
    cout << "自动售货机根本没有硬币！" << endl;
}

void SoldOutState::turnCrank() {
    cout << "机器无纸巾，请不要操作机器" << endl;
}

void SoldOutState::dispense() {
}

//没有投币状态
void NoQuarterState::insertQuarter() {
    machine->setState(new HasQuarterState(machine));
    cout << "已投币！" << endl;
}

void NoQuarterState::ejectQuarter() {
    cout << "自动售货机根本没有硬币！" << endl;
}

void NoQuarterState::turnCrank() {
    cout << "请投币" << endl;
}

void NoQuarterState::dispense() {
}

//有2元钱（已投币状态）
void HasQuarterState::insertQuarter() {
    cout << "已投币！请不要重复投币！已退回重复投币！" << endl;
}

void HasQuarterState::ejectQuarter() {
    machine->setState(new NoQuarterState(machine));
    cout << "已取币！" << endl;
}

void HasQuarterState::turnCrank() {
    machine->setState(new SoldState(machine));
    cout << "请等待自动售货机出纸巾！" << endl;
}

void HasQuarterState::dispense() {
}

//出售纸巾状态
void SoldState::insertQuarter() {
    cout << "请等待自动售货机出纸巾！请不要投币！已退回投币！" << endl;
}

void SoldState::ejectQuarter() {
    machine->setState(new NoQuarterState(machine));
    cout << "请等待自动售货机出纸巾！无法取回已消费的硬币！" << endl;
}

void SoldState::turnCrank() {
    cout << "请等待自动售货机出纸巾！已响应你的操作！" << endl;
}

void SoldState::dispense() {//售出纸巾动作
    if (machine->getCount() > 0) {
        machine->setState(new NoQuarterState(machine));
        machine->setCount(machine->getCount() - 1);
        cout << "你的纸巾，请拿好！" << endl;
    } else {
        machine->setState(new SoldOutState(machine));
        cout << "已退回你的硬币！纸巾已卖光，等待进货！" << endl;
    }
}