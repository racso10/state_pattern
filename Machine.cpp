//
// Created by Racso on 2019/8/13.
//

#include "Machine.h"
//ֽ������״̬
void SoldOutState::insertQuarter() {
    cout << "������ֽ�����˻�Ӳ�ң�" << endl;
}

void SoldOutState::ejectQuarter() {
    cout << "�Զ��ۻ�������û��Ӳ�ң�" << endl;
}

void SoldOutState::turnCrank() {
    cout << "������ֽ���벻Ҫ��������" << endl;
}

void SoldOutState::dispense() {
}

//û��Ͷ��״̬
void NoQuarterState::insertQuarter() {
    machine->setState(new HasQuarterState(machine));
    cout << "��Ͷ�ң�" << endl;
}

void NoQuarterState::ejectQuarter() {
    cout << "�Զ��ۻ�������û��Ӳ�ң�" << endl;
}

void NoQuarterState::turnCrank() {
    cout << "��Ͷ��" << endl;
}

void NoQuarterState::dispense() {
}

//��2ԪǮ����Ͷ��״̬��
void HasQuarterState::insertQuarter() {
    cout << "��Ͷ�ң��벻Ҫ�ظ�Ͷ�ң����˻��ظ�Ͷ�ң�" << endl;
}

void HasQuarterState::ejectQuarter() {
    machine->setState(new NoQuarterState(machine));
    cout << "��ȡ�ң�" << endl;
}

void HasQuarterState::turnCrank() {
    machine->setState(new SoldState(machine));
    cout << "��ȴ��Զ��ۻ�����ֽ��" << endl;
}

void HasQuarterState::dispense() {
}

//����ֽ��״̬
void SoldState::insertQuarter() {
    cout << "��ȴ��Զ��ۻ�����ֽ���벻ҪͶ�ң����˻�Ͷ�ң�" << endl;
}

void SoldState::ejectQuarter() {
    machine->setState(new NoQuarterState(machine));
    cout << "��ȴ��Զ��ۻ�����ֽ���޷�ȡ�������ѵ�Ӳ�ң�" << endl;
}

void SoldState::turnCrank() {
    cout << "��ȴ��Զ��ۻ�����ֽ������Ӧ��Ĳ�����" << endl;
}

void SoldState::dispense() {//�۳�ֽ����
    if (machine->getCount() > 0) {
        machine->setState(new NoQuarterState(machine));
        machine->setCount(machine->getCount() - 1);
        cout << "���ֽ�����úã�" << endl;
    } else {
        machine->setState(new SoldOutState(machine));
        cout << "���˻����Ӳ�ң�ֽ�������⣬�ȴ�������" << endl;
    }
}