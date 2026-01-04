#include "TUBES.h"
#include <iostream>
using namespace std;

void createList(listJudge &L) {
    L.first = nullptr;
    L.last = nullptr;
}

adrJudge allocateJudge(string ID, string Name, string License, float AverageSentenceMonths) {
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

adrConvict allocateConvict(string ID, string Name, string Crime, int SentencedMonths) {
    adrConvict C = new Convict;

    C->info.ID = ID;
    C->info.Name = Name;
    C->info.Crime = Crime;
    C->info.SentencedMonths = SentencedMonths;

    C->next = nullptr;

    return C;
}
