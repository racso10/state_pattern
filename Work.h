//
// Created by Racso on 2019/8/13.
//

#ifndef TEST_WORK_H
#define TEST_WORK_H


class Work {
private:
    int hour;
    bool finish;
public:
    Work(int, bool);
    void setHour(int);
    int getHour();
    void setFinish(bool);
    bool getFinish();

    void writeProgram();
};


#endif //TEST_WORK_H
