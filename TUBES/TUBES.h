#ifndef TUBES_H_INCLUDED
#define TUBES_H_INCLUDED
#include <iostream>
using namespace std;

typedef struct Judge *adrJudge;
typedef struct Convict *adrConvict;

struct infoJudge {
    string ID;
    string Name;
    string License;
    float AverageSentenceMonths;
};

struct infoConvict {
    string ID;
    string Name;
    string Crime;
    int SentencedMonths;
};

struct Judge {
    adrJudge prev;
    adrJudge next;
    infoJudge info;
    adrConvict firstConvict;
};

struct Convict {
    adrConvict next;
    infoConvict info;
};

struct listJudge {
    adrJudge first;
    adrJudge last;
};

void createList(listJudge &L);
bool isEmpty(listJudge L);

adrJudge allocateJudge(string ID, string Name, string License);
adrConvict allocateConvict(string ID, string Name, string Crime, int SentencedMonths);

void insertJudge(listJudge &L, adrJudge J);
void insertConvict(listJudge &L, adrConvict C, adrJudge J);

adrJudge searchJudge(listJudge L, string judgeID);
adrConvict searchConvict(listJudge L, string convictID);
adrJudge searchParent(listJudge L, adrConvict C);

void deleteJudge(listJudge &L, string judgeID);
void deleteConvict(listJudge &L, string convictID);

void editJudgeInfo(listJudge &L, string judgeID);
void editConvictInfo(listJudge &L, string convictID);

void displayList(listJudge L);
float calculateAverageSentencedTime(adrJudge J);
void displayHighestToLowestAverage(listJudge L);

#endif // TUBES_H_INCLUDED
