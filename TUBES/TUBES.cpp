#include "TUBES.h"
#include <iostream>

using namespace std;

void createList(listJudge &L){
    L.first = nullptr;
    L.last = nullptr;
}

bool isEmpty(listJudge L) {
    return L.first == nullptr && L.last == nullptr;
}

adrJudge allocateJudge(string ID, string Name, string License){
    adrJudge J = new Judge;

    J->info.ID = ID;
    J->info.Name = Name;
    J->info.License = License;
    J->info.AverageSentenceMonths = 0.0;
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

void insertJudge(listJudge &L, adrJudge J) {
    if (isEmpty(L)) {
        L.first = J;
        L.last = J;
    } else {
        J->prev = L.last;
        L.last->next = J;
        L.last = J;
    }
}

void insertConvict(listJudge &L, adrConvict C, adrJudge J) {
    if (J->firstConvict == nullptr) {
        J->firstConvict = C;
    } else {
        C->next = J->firstConvict;
        J->firstConvict = C;
    }

    J->info.AverageSentenceMonths = calculateAverageSentencedTime(J);
}

adrJudge searchJudge(listJudge L, string judgeID){
    adrJudge J = L.first;
    adrJudge found = nullptr;

    while (J != nullptr && found == nullptr){
        if (J->info.ID == judgeID){
            found = J;
        } else {
            J = J->next;
        }
    }

    return found;
}

adrConvict searchConvict(listJudge L, string convictID){
    adrJudge J = L.first;
    adrConvict found = nullptr;

    while (J != nullptr && found == nullptr){
        adrConvict C = J->firstConvict;
        while (C != nullptr && found == nullptr){
            if (C->info.ID == convictID){
                found = C;
            } else {
                C = C->next;
            }
        }
        if (found == nullptr) {
            J = J->next;
        }
    }

    return found;
}

adrJudge searchParent(listJudge L, adrConvict C) {
    if (C == nullptr) return nullptr;

    adrJudge J = L.first;
    adrJudge found = nullptr;

    while (J != nullptr && found == nullptr) {
        adrConvict helper = J->firstConvict;
        while (helper != nullptr && found == nullptr) {
            if (helper == C) {
                found = J;
            } else {
                helper = helper->next;
            }
        }
        if (found == nullptr) {
            J = J->next;
        }
    }

    return found;
}

void deleteJudge(listJudge &L, string judgeID){
    adrJudge J = searchJudge(L, judgeID);

    if (J == nullptr) {
        cout << "Judge not found." << endl;
    } else {
        adrConvict C = J->firstConvict;
        while (C != nullptr){
            adrConvict temp = C;
            C = C->next;
            delete temp;
        }

        if (J == L.first) {
            if (L.first == L.last) {
                createList(L);
            } else {
                L.first = J->next;
                L.first->prev = nullptr;
            }
        } else if (J == L.last) {
            L.last = J->prev;
            L.last->next = nullptr;
        } else {
            J->prev->next = J->next;
            J->next->prev = J->prev;
        }
        delete J;
    }
}

void deleteConvict(listJudge &L, string convictID){
    adrConvict C = searchConvict(L, convictID);

    if (C == nullptr){
        cout << "Convict not found." << endl;
    } else {
        adrJudge targetJudge = searchParent(L, C);

        if (targetJudge != nullptr) {
            if (targetJudge->firstConvict == C){
                targetJudge->firstConvict = C->next;
            } else {
                adrConvict prev = targetJudge->firstConvict;
                while (prev->next != C){
                    prev = prev->next;
                }
                prev->next = C->next;
            }
            delete C;
            targetJudge->info.AverageSentenceMonths = calculateAverageSentencedTime(targetJudge);
        }
    }
}

void editJudgeInfo(listJudge &L, string judgeID){
    adrJudge J = searchJudge(L, judgeID);
    int num;

    if (J == nullptr){
        cout << "Judge not found." << endl;
    } else {
        cout << "Judge Info:" << endl;
        cout << "ID: " << J->info.ID << endl;
        cout << "1. Name: " << J->info.Name << endl;
        cout << "2. License: " << J->info.License << endl;
        cout << "Enter number (1-2): ";
        cin >> num;

        if (num == 1){
            cout << "Enter new Name: "; cin >> J->info.Name;
            cout << "Name Successfully Changed" << endl;
        } else if (num == 2){
            cout << "Enter new License: "; cin >> J->info.License;
            cout << "License Successfully Changed" << endl;
        } else {
            cout << "Invalid Number!" << endl;
        }
    }
}

void editConvictInfo(listJudge &L, string convictID){
    adrConvict C = searchConvict(L, convictID);
    int num;

    if (C == nullptr){
        cout << "Convict not found." << endl;
    } else {
        cout << "Convict Info:" << endl;
        cout << "ID: " << C->info.ID << endl;
        cout << "1. Name: " << C->info.Name << endl;
        cout << "2. Crime: " << C->info.Crime << endl;
        cout << "3. Sentenced Months: " << C->info.SentencedMonths << endl;
        cout << "Enter number (1-3): ";
        cin >> num;

        if (num == 1){
            cout << "Enter new Name: "; cin >> C->info.Name;
            cout << "Name Successfully Changed" << endl;
        } else if (num == 2) {
            cout << "Enter new Crime: "; cin >> C->info.Crime;
            cout << "Crime Successfully Changed" << endl;
        } else if (num == 3){
            cout << "Enter new Sentence: "; cin >> C->info.SentencedMonths;

            adrJudge parent = searchParent(L, C);
            if (parent != nullptr) {
                parent->info.AverageSentenceMonths = calculateAverageSentencedTime(parent);
            }

            cout << "Sentence Changed and Judge Average Updated." << endl;
        } else {
            cout << "Invalid Number!" << endl;
        }
    }
}

void displayList(listJudge L){
    if (isEmpty(L)){
        cout << "Judge list is empty." << endl;
    } else {
        adrJudge J = L.first;
        int i = 1;
        while (J != nullptr) {
            cout << endl;
            cout << "============================================" << endl;
            cout << " JUDGE " << i << " DATA" << endl;
            cout << "============================================" << endl;
            cout << "  ID              : " << J->info.ID << endl;
            cout << "  Name            : " << J->info.Name << endl;
            cout << "  License         : " << J->info.License << endl;
            cout << "  Avg Sentence    : " << J->info.AverageSentenceMonths << " months" << endl;
            cout << "--------------------------------------------" << endl;
            cout << "  >> ASSIGNED CONVICTS:" << endl;

            adrConvict C = J->firstConvict;
            if (C == nullptr) {
                cout << "     (No convicts assigned)" << endl;
            } else {
                int k = 1;
                while (C != nullptr) {
                    cout << "     " << k << ". " << C->info.Name << " (" << C->info.ID << ")" << endl;
                    cout << "        - Crime    : " << C->info.Crime << endl;
                    cout << "        - Sentence : " << C->info.SentencedMonths << " months" << endl;
                    C = C->next;
                    k++;
                }
            }
            cout << "============================================" << endl;

            J = J->next;
            i++;
        }
    }
}

float calculateAverageSentencedTime(adrJudge J) {
    if (J == nullptr || J->firstConvict == nullptr) {
        return 0.0;
    }

    float avg = 0.0;
    int countCases = 0;
    int totalMonths = 0;
    adrConvict C = J->firstConvict;

    while (C != nullptr) {
        countCases++;
        totalMonths += C->info.SentencedMonths;
        C = C->next;
    }

    if (countCases > 0) {
        avg = (float)totalMonths / countCases;
    }
    return avg;
}

void displayHighestToLowestAverage(listJudge L) {
    if (isEmpty(L)) {
        cout << "Judge list is empty." << endl;
    } else {
        adrJudge p = L.first;

        while (p != nullptr) {
            adrJudge maxNode = p;
            adrJudge q = p->next;
            while (q != nullptr) {
                if (q->info.AverageSentenceMonths > maxNode->info.AverageSentenceMonths) {
                    maxNode = q;
                }
                q = q->next;
            }
            if (maxNode != p) {
                auto tempInfo = p->info;
                p->info = maxNode->info;
                maxNode->info = tempInfo;

                adrConvict tempConvict = p->firstConvict;
                p->firstConvict = maxNode->firstConvict;
                maxNode->firstConvict = tempConvict;
            }
            p = p->next;
        }

        cout << "=== SORTED JUDGE LIST (Highest to Lowest Average) ===" << endl;
        displayList(L);
    }
}
