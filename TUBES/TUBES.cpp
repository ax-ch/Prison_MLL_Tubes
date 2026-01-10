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

adrJudge searchJudge(listJudge L, string judgeID){
    adrJudge Judge;

    Judge = L.first;
    while (Judge != nullptr){
        if (Judge->info.ID == judgeID){
            return Judge;
        }
        Judge = Judge->next;
    }

    return nullptr;

}; // Atallah

adrConvict searchConvict(listJudge L, string convictID){
    adrConvict Convict;
    adrJudge Judge;

    Judge = L.first;
    while (Judge != nullptr){
        Convict = Judge->firstConvict;
        while (Convict != nullptr){
            if (Convict->info.ID == convictID){
                return Convict;
            }
            Convict = Convict->next;
        }
        Judge = Judge->next;
    }

    return nullptr;

}; // Atallah

void deleteJudge(listJudge &L, string judgeID){
    adrJudge Judge = searchJudge(L, judgeID);
    if (Judge == nullptr) {
        cout << "Judge not found." << endl;
        return;
    }

    adrConvict Convict;
    Convict = Judge->firstConvict;
    while (Convict != nullptr){
        adrConvict temp;
        temp = Convict;
        delete temp;
    }

    if (Judge == L.first){
        L.first = Judge->next;
        Judge->next == nullptr;
        delete Judge;
    } else if (Judge->next != nullptr) {
        adrJudge first;
        first = L.first;
        while (first->next != Judge){
            first = first->next;
        }
        first->next = Judge->next;
        Judge->next = nullptr;
        delete Judge;
    } else {
        adrJudge first;
        first = L.first;
        while (first->next != Judge){
            first = first->next;
        }
        first->next = nullptr;
        delete Judge;
    }

}; // Atallah
void deleteConvict(listJudge &L, string convictID){
   adrConvict Convict;
   adrJudge j;
   adrConvict c = searchConvict(L, convictID);
   adrJudge Judge;

   if (c == nullptr){
        cout << "Convict not found." << endl;
        return;
   }

    Judge = L.first;
    while (Judge != nullptr){
        Convict = Judge->firstConvict;
        while (Convict != nullptr){
            if (Convict->info.ID == convictID){
                j = Judge;
            }
            Convict = Convict->next;
        }
        Judge = Judge->next;
    }

    if (j->firstConvict == c){
        j->firstConvict = c->next;
        delete c;
    } else if (c->next != nullptr ){
        adrConvict helper;
        helper = j->firstConvict;
        while (helper->next != c){
            helper = helper->next;
        }
        helper->next = c->next;
        c->next = nullptr;
        delete c;
    } else {
        adrConvict helper;
        helper = j->firstConvict;
        while (helper->next != c){
            helper = helper->next;
        }
        helper->next = nullptr;
        delete c;
    }


}; // Atallah

void editJudgeInfo(listJudge &L, string judgeID){
    adrJudge j = searchJudge(L, judgeID);
    int num;
    if (j == nullptr){
        cout << "judge not found." << endl;
    } else {
        cout << "Judge Info:" << endl;
        cout << "1. ID: " << j->info.ID << endl;
        cout << "2. Name: " << j->info.Name << endl;
        cout << "3. License: " << j->info.License << endl;
        cout << "Enter number (1-3): ";
        cin >> num;
        cout << endl;
        if (num == 1){
            string newID;
            cout << "Enter new ID: ";
            cin >> newID;
            j->info.ID = newID;
            cout << "ID has Successfully Changed" << endl;
        } else if (num == 2){
            string newName;
            cout << "Enter new Name: ";
            cin >> newName;
            j->info.Name = newName;
            cout << "Name has Successfully Changed" << endl;
        } else if (num == 3){
            string newLicense;
            cout << "Enter new License: ";
            cin >> newLicense;
            j->info.License = newLicense;
            cout << "License has Successfully Changed" << endl;
        } else {
            cout << "Invalid Number!" << endl;
        }

    }

}; // Atallah

void editConvictInfo(listJudge &L, string convictID){
    adrConvict c = searchConvict(L,convictID);
    int num;
    if (c == nullptr){
        cout << "Convict not found." << endl;
    } else {
        cout << "Convict Info:" << endl;
        cout << "1. ID: " << c->info.ID << endl;
        cout << "2. Name: " << c->info.Name << endl;
        cout << "3. Crime: " << c->info.Crime << endl;
        cout << "4. Sentenced Months: " << c->info.SentencedMonths << endl;
        cout << "Enter number (1-4): ";
        cin >> num;
        cout << endl;
        if (num == 1){
            string newID;
            cout << "Enter new ID: ";
            cin >> newID;
            c->info.ID = newID;
            cout << "ID has Successfully Changed" << endl;
        } else if (num == 2){
            string newName;
            cout << "Enter new Name: ";
            cin >> newName;
            c->info.Name = newName;
            cout << "Name has Successfully Changed" << endl;
        } else if (num == 3) {
            string newCrime;
            cout << "Enter new Crime: ";
            cin >> newCrime;
            c->info.Crime = newCrime;
            cout << "Crime has Successfully Changed" << endl;

        } else if (num == 4){
            int newSentence;
            cout << "Enter new Sentence: ";
            cin >> newSentence;
            c->info.SentencedMonths = newSentence;
            cout << "Sentenced Months has Successfully Changed" << endl;
        } else {
            cout << "Invalid Number!" << endl;
        }

    }
}; // Atallah

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


