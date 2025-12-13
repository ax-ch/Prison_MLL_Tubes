#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct Judge *adrJudge;
typedef struct Convict *adrConvict;

struct infoJudge {
    ID int;
    Name string;
    License string;
    ActiveConvictedCount int;
};

struct infoConvict {
    ID int;
    Name string;
    ConvictedDate string;
    Crime string;
};

struct Judge {
    prev adrJudge;
    next adrJudge;
    info infoJudge;
};

struct Convict {
    prev adrConvict;
    next adrConvict;
    info infoJudge;
};

struct listJudge {
    first adrJudge;
    last adrJudge;
};

struct listConvict {
    first adrConvict;
    last adrConvict;
};

#endif // TUBES_H_INCLUDED
