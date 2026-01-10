#include "TUBES.h"
#include <iostream>
#include <string>

using namespace std;

void populateDummyData(listJudge &L, int &jCount, int &cCount) {
    string jID1 = "J" + to_string(jCount++);
    adrJudge J1 = allocateJudge(jID1, "Atallah_Alimusa", "LIC-999");
    insertJudge(L, J1);

    string cID1 = "C" + to_string(cCount++);
    insertConvict(L, allocateConvict(cID1, "Erick_Octo", "Treason", 120), J1);

    string cID2 = "C" + to_string(cCount++);
    insertConvict(L, allocateConvict(cID2, "Farrell_Barrell", "Arson", 24), J1);

    string jID2 = "J" + to_string(jCount++);
    adrJudge J2 = allocateJudge(jID2, "Alin_Mukhsis", "LIC-777");
    insertJudge(L, J2);

    string cID3 = "C" + to_string(cCount++);
    insertConvict(L, allocateConvict(cID3, "Anita_Mardi", "Hustling", 5), J2);

    string jID3 = "J" + to_string(jCount++);
    adrJudge J3 = allocateJudge(jID3, "Axella_Cahya", "LIC-123");
    insertJudge(L, J3);

    cout << ">> Dummy data loaded (3 Judges, 3 Convicts)." << endl;
}

int main() {
    listJudge L;
    createList(L);

    int jCounter = 1;
    int cCounter = 1;

    // comment populateDummyData if not used
    populateDummyData(L, jCounter, cCounter);

    int choice = -1;
    string jID, jName, jLicense;
    string cID, cName, cCrime;
    int cSentence;
    adrJudge J;
    adrConvict C;

    while (choice != 0) {
        cout << "\n============================================" << endl;
        cout << "       COURT & JUDGE MANAGEMENT SYSTEM      " << endl;
        cout << "============================================" << endl;
        cout << " 1.  Add New Judge" << endl;
        cout << " 2.  Add Convict to Judge" << endl;
        cout << " 3.  Edit Judge Info" << endl;
        cout << " 4.  Edit Convict Info" << endl;
        cout << " 5.  Delete Judge" << endl;
        cout << " 6.  Delete Convict" << endl;
        cout << " 7.  Search Judge" << endl;
        cout << " 8.  Search Convict" << endl;
        cout << " 9.  Display All Data" << endl;
        cout << " 10. Display Sorted (Highest Avg Sentence)" << endl;
        cout << " 0.  Exit" << endl;
        cout << "============================================" << endl;
        cout << "Select Menu: ";
        cin >> choice;
        cout << endl;

        if (choice == 1) {
            jID = "J" + to_string(jCounter);
            jCounter++;

            cout << "Generated ID     : " << jID << endl;
            cout << "Enter Judge Name : "; cin >> jName;
            cout << "Enter License    : "; cin >> jLicense;

            J = allocateJudge(jID, jName, jLicense);
            insertJudge(L, J);
            cout << ">> Judge Added Successfully." << endl;
        } else if (choice == 2) {
            cout << "Enter Target Judge ID: "; cin >> jID;
            J = searchJudge(L, jID);
            if (J == nullptr) {
                cout << ">> Judge not found." << endl;
            } else {
                cID = "C" + to_string(cCounter);
                cCounter++;

                cout << "Judge Found: " << J->info.Name << endl;
                cout << "Generated Convict ID : " << cID << endl;
                cout << "Enter Name           : "; cin >> cName;
                cout << "Enter Crime          : "; cin >> cCrime;
                cout << "Enter Sentence (Mos) : "; cin >> cSentence;

                C = allocateConvict(cID, cName, cCrime, cSentence);
                insertConvict(L, C, J);
                cout << ">> Convict Added Successfully." << endl;
            }
        } else if (choice == 3) {
            cout << "Enter Judge ID to Edit: "; cin >> jID;
            editJudgeInfo(L, jID);
        } else if (choice == 4) {
            cout << "Enter Convict ID to Edit: "; cin >> cID;
            editConvictInfo(L, cID);
        } else if (choice == 5) {
            cout << "Enter Judge ID to Delete: "; cin >> jID;
            deleteJudge(L, jID);
            cout << ">> (Process Complete)" << endl;
        } else if (choice == 6) {
            cout << "Enter Convict ID to Delete: "; cin >> cID;
            deleteConvict(L, cID);
            cout << ">> (Process Complete)" << endl;
        } else if (choice == 7) {
            cout << "Enter Judge ID: "; cin >> jID;
            J = searchJudge(L, jID);
            if (J) cout << "Found: " << J->info.Name << " (" << J->info.License << ")" << endl;
            else cout << "Not Found." << endl;
        } else if (choice == 8) {
            cout << "Enter Convict ID: "; cin >> cID;
            C = searchConvict(L, cID);
            if (C) cout << "Found: " << C->info.Name << " - " << C->info.Crime << endl;
            else cout << "Not Found." << endl;
        } else if (choice == 9) {
            displayList(L);
        } else if (choice == 10) {
            displayHighestToLowestAverage(L);
        } else if (choice == 0) {
            cout << "Exiting..." << endl;
        } else {
            cout << "Invalid choice." << endl;
        }

        if (choice != 0) {
            cout << "\nPress Enter to continue...";
            cin.ignore(); cin.get();
        }

    }

    return 0;
}
