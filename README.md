Judge & Convict Management System
A C++ implementation of a Multi-Linked List (General Tree/Parent-Child relationship) to manage judicial records and sentencing statistics.

👥 Group Members
1. Muhamad Atallah Alimusa (103012440001)
2. Amalina Mukhsis (103012340448)
3. Axella Negyacahya Hartono (103012440018)

📌 Project Overview
This system is designed to manage the relationship between Judges and the Convicts they have sentenced. It utilizes two types of linked lists:
- Judges: A Doubly Linked List (DLL) allowing bidirectional traversal.
- Convicts: A Singly Linked List (SLL) nested within each Judge node (a 1-to-N relationship).
The system automatically calculates the average sentencing time for each judge and allows for ranking judges based on their sentencing severity.

🏗️ Data Structures
Judge (Parent)
Attributes: ID, Name, License, and Average Sentence Months.
Pointers: next (to next judge), prev (to previous judge), and firstConvict (to the head of the convict list).

Convict (Child)
Attributes: ID, Name, Crime, and Sentenced Months.
Pointers: next (to the next convict under the same judge).

🚀 Key Features
CRUD Operations: Create, Read, Update, and Delete both Judges and Convicts.
Automatic Statistics: The AverageSentenceMonths for a Judge is automatically updated whenever a convict is added, deleted, or their sentence length is edited.
Advanced Search: Search for a convict across all judges or find which judge is responsible for a specific convict (searchParent).
Ranking System: Sort and display judges from the highest to lowest average sentencing time.

📂 File Structure
tubes.h: Header file containing struct definitions and function prototypes.
tubes.cpp: The implementation of all logic (Allocation, Insertion, Deletion, Editing, Searching, and Calculations).
main.cpp: The menu-driven interface for user interaction.

🛠️ How to Run
Ensure you have a C++ compiler installed (e.g., GCC/MinGW).

Compile the files:
bash
g++ -o JudgeSystem main.cpp tubes.cpp

Run the executable:
bash
./JudgeSystem


