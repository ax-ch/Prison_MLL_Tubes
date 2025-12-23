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

void createList(listJudge &L); // Kak Alin

adrJudge allocateJudge(string ID, string Name, string License, float AverageSentenceMonths); // Kak Alin
adrConvict allocateConvict(string ID, string Name, string Crime, int SentencedMonths); // Kak Alin
void insertJudge(listJudge &L, adrJudge j); // Axella
void insertConvict(listJudge &L, adrConvict c, adrJudge j); // Axella - also updates judge's avg sentenced time

adrJudge searchJudge(listJudge L, string judgeID); // Atallah
adrConvict searchConvict(listJudge L, string convictID); // Atallah

void deleteJudge(listJudge &L, string judgeID); // Atallah
void deleteConvict(listJudge &L, string convictID); // Atallah

void editJudgeInfo(listJudge &L, string judgeID); // Atallah
void editConvictInfo(listJudge &L, string convictID); // Atallah

void displayList(listJudge L); // Kak Alin

float calculateAverageSentencedTime(listJudge L, adrJudge j); // Axella - update avg time every insertConvict
void displayHighestToLowestAverage(listJudge L); // Axella

#endif // TUBES_H_INCLUDED
