#include<iostream>
//#include "Machine.h"
//#include "Work.h"
#include "WorkStatePattern.h"

using namespace std;

int main() {
    int startTime = 8;
    int finishWork = 22;
    auto *work = new WorkStatePattern(startTime, false);
    for (int i = startTime; i <= 24; i++) {
        work->setHour(i);
        if (i == finishWork) {
            work->setFinish(true);
        }
        work->writeProgram();
    }
    return 0;

//    int count = 100;
//    int operation;
//    auto *machine = new Machine(1);
//    while(count--) {
//        cout << "ֽ������" << machine->getCount() << endl;
//        cin >> operation;
//        switch (operation) {
//            case 1:
//                machine->insertQuarter();//Ͷ��
//                break;
//            case 2:
//                machine->turnCrank();//ȡֽ��
//                break;
//            case 3:
//                machine->ejectQuarter();//�˱�
//                break;
//            default:
//                cout << "��������" <<endl;
//        }
//    }
//    return 0;
}