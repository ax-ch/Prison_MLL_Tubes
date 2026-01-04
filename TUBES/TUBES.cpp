#include "TUBES.h"
#include <iostream>
using namespace std;

void createList(listJudge &L){
    L.first = nullptr;
    L.last = nullptr;
}

adrJudge allocateJudge(string ID, string Name, string License, float AverageSentenceMonths){
    adrJudge J = new Judge;

    J->info.ID = ID;
    J->info.Name = Name;
    J->info.License = License;
    J->info.AverageSentenceMonths = AverageSentenceMonths;
    J->prev = nullptr;
    J->next = nullptr;
    J->firstConvict = nullptr;

    return J;
}

adrConvict allocateConvict(string ID, string Name, string Crime, int SentencedMonths){
    adrConvict C = new Convict;

    C->info.ID = ID;
    C->info.Name = Name;
    C->info.Crime = Crime;
    C->info.SentencedMonths = SentencedMonths;
    C->next = nullptr;

    return C;
}

void insertJudge(listJudge &L, adrJudge j); // Axella
void insertConvict(listJudge &L, adrConvict c, adrJudge j); // Axella - also updates judge's avg sentenced time

adrJudge searchJudge(listJudge L, string judgeID); // Atallah
adrConvict searchConvict(listJudge L, string convictID); // Atallah

void deleteJudge(listJudge &L, string judgeID); // Atallah
void deleteConvict(listJudge &L, string convictID); // Atallah

void editJudgeInfo(listJudge &L, string judgeID); // Atallah
void editConvictInfo(listJudge &L, string convictID); // Atallah

void displayList(listJudge L){
    if (L.first == nullptr){
        cout << "Judge list is empty." << endl;
        return;
    }
    adrJudge P = L.first;
    int i = 1;
    while (P != nullptr) {
        cout << "Judge " << i << endl;
        cout << "ID       : " << P->info.ID << endl;
        cout << "Name     : " << P->info.Name << endl;
        cout << "License  : " << P->info.License << endl;
        cout << "Average Sentence (months): "
             << P->info.AverageSentenceMonths << endl;
        cout << "-------------------------" << endl;
        
        P = P->next;
        i++;
    }
}

float calculateAverageSentencedTime(listJudge L, adrJudge j); // Axella - update avg time every insertConvict
void displayHighestToLowestAverage(listJudge L); // Axella

