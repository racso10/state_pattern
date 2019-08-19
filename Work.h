//
// Created by Racso on 2019/8/13.
//

#ifndef STATE_PATTERN_WORK_H
#define STATE_PATTERN_WORK_H


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


#endif //STATE_PATTERN_WORK_H
