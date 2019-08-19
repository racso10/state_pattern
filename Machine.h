//
// Created by Racso on 2019/8/13.
//

#ifndef STATE_PATTERN_MACHINE_H
#define STATE_PATTERN_MACHINE_H

#include<iostream>

using namespace std;

//����Ϊ��Ķ��岿��
class Machine;//�����ǰ����
//����״̬
class State {
public:
    virtual void insertQuarter()=0;//��Ͷ�ҡ���ť������
    virtual void ejectQuarter()=0;//���˱ҡ���ť������
    virtual void turnCrank()=0;//����ֽ����ť������
    virtual void dispense()=0;//��������ֽ��
};

//����״̬
class SoldOutState : public State {//ֽ������״̬
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

class NoQuarterState : public State {//û��Ͷ��״̬
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

class HasQuarterState : public State {//��2ԪǮ����Ͷ��״̬��
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

class SoldState : public State {//����ֽ��״̬
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

//������
class Machine {
private:
    State *state;
    int count;//ֽ����
public:
    explicit Machine(int numbers) {//���캯���������ʼ״̬��ֽ���������ж���ֽ��
        this->count = numbers;
        if (count > 0) {
            this->state = new NoQuarterState(this);//��ʼΪû��Ͷ�ҵ�״̬
        }
    };

    //���Ÿ����������õķ���
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

    //���ݴ��ݵ�getter��setter
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
