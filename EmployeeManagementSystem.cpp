#include<iostream> //This library initiates the input output process
#include<fstream> //This library helps in file handling
#include<string> //This library helps to use and manipulate strings
#include<iomanip> //This library helps to manipulate the outputs. I used it to make output tables
#include<windows.h> //This library is used to clear screen and add loading effects using sleep(), as well as color changes function in my program
#include<conio.h> //only getch() function is used from this library in this code
using namespace std;
string Employee[501][6]; //I have declared my main arrays at the start so that it is easier for me to call them in every function
string EmployeeIDs[501];
bool proceedInp = true; // This variable includes the access to proceed with input. this is also declared globally because it seemed easier for me to do so, since it was required in two functions

void WriteFile(string Employee[][6]) { //This is the function to write the array contents into the file.
    fstream Newfile;
    Newfile.open("DataBase.txt",ios::out);
    if(!Newfile)
    {
    cout<<"File not found\n";
    }
    else
    {
    cout<<"Writing Data to file\n";
    for (int i =0; i < 500; i++) {
    for (int j =0; j<=5; j++) {
        if (Employee[i][j]!="") {
    Newfile << Employee[i][j] << endl;
                }
    }
    }
    }
    Newfile.close();
}

void RegisterNew(string Employee[][6], int &Row) { //This function Inputs and validates entries of any new employees
Row++;
long long temporary; //This will store the number inputs
cout << "Enter details of new employee: \n";
    cout << "First Name: ";
    cin.ignore(); //This is placed because initially, the code was not taking input and proceeding to address
    getline(cin, Employee[Row][0]);
    cout << "Address: ";
    getline(cin, Employee[Row][1]);
    cout << "For phone number:\nNo need to add 0, as it is understood in Pakistan, the initial code is +92\n";
    cout << "Phone number: ";
    cin >> temporary;
    while (cin.fail() || temporary <= 0) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Phone number includes alphabets or is negative.\nPlease enter again: ";
        cin >> temporary;
    }
    Employee[Row][2] = to_string(temporary); //Phone number is stored in the array using the function to_string
    cout << "Salary: ";
    cin >> temporary;
    while (cin.fail() || temporary <= 0) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered salary includes alphabets or is negative.\nPlease enter again: ";
        cin >> temporary;
    }
    Employee[Row][3] = to_string(temporary);

    bool proceed = false;
    cout << "For Employee ID:\nLength should be 4\nIt shoud not start with 0\nShould only be numbers\n";
    cout << "Employee ID: ";
    cin >> temporary;
    while (proceed == false){
            for(int i=0; i<=Row; i++){ //This loop checks whether the id already exists or not
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
    for(int i=0; i<=Row; i++){
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
     for(int i=0; i<=Row; i++){
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
     proceed = true; //assigning true to proceed so that if all the conditions are met, then loop can be exited.
    }
    for (int i = 0; i<=Row; i++) {  //If the person keeps entering the same id which is already taken, then program abandons inputing new Employee data
        if (EmployeeIDs[i] == to_string(temporary))
        proceedInp = false;
    }
    if (proceedInp == false) {
        cout << "The ID already exists. Please check our records.\n";
        Row--; //This is to counter the fact that i incremented Row at the start of this function, and Row is being passed by reference to its location in memory. since i am not going to waste this attempt at entering data for new employee.
    }
    if(proceedInp == true) {
    Employee[Row][4] = to_string(temporary);
    cout << "Designation: ";
    cin.ignore();
    getline(cin,Employee[Row][5]);
    }
}


void Menu() { //This function contains the menu for the program
cout << "=================================MENU====================================\n1) Add record of an employee\n2) Search record using employee ID\n3) List employees having a certain designation\n4) Display all employees\n5) Update record of an employee\n6) Delete record of an employee\n7) Exit the program\n========================================================================== ";
}

void Sort(string Employee[][6], int Row) { //This function is used to sort employee array using its employee id
    string temp;
    for(int i=0;i<=Row;i++){
        for(int j=0;j<=Row;j++){
        if(Employee[i][4]<Employee[j][4]){
            for(int k=0; k<=5; k++){ //using a third loop to transfer all 6 elements of an employee
                temp=Employee[i][k];
                Employee[i][k]=Employee[j][k];
                Employee[j][k]=temp;
            }
        }
        }
    }
}

void SortByName(string Employee[][6], int Row) { //This is a function used to sort the employee array by their names
    string temp;
for(int i=0;i<=Row;i++){
  for(int j=0;j<=Row;j++){
    if(Employee[i][0]<Employee[j][0]){
        for(int k=0; k<=5; k++) {
      temp=Employee[i][k];
      Employee[i][k]=Employee[j][k];
      Employee[j][k]=temp;
        }
     }
   }
}
}

void Search(string Employee[][6], int Row, string ID) { // This function is used to search the ID of Employee in the array and output the employee details
    int index;
for(int i=0; i<=Row; i++)
    {
        if(Employee[i][4]==ID)
        {
            index = i;
            break;//exiting the loop as soon as position is found
        }
    }
    cout << "Printing Employee details" << endl;
    cout << setw(20) << "Name|" << setw(20) << "Address|"<< setw(20) << "Phone Number|"<< setw(20) << "Salary|"<< setw(20) << "Employee ID|"<< setw(20) << "Position|\n\n";
    for(int i=0; i<=5; i++) {
        cout << setw(19) << Employee[index][i] << "|";
    }
}

void SearchDes(string Employee[][6], int Row, string Designation) { //This function searches the Designation of an employee
    bool check =true;
    cout << "Printing Employee details" << endl;
    cout << setw(20) << "Name|" << setw(20) << "Address|"<< setw(20) << "Phone Number|"<< setw(20) << "Salary|"<< setw(20) << "Employee ID|"<< setw(20) << "Position|\n\n";
    for(int i=0; i<=Row; i++){
        if(Employee[i][5]==Designation){
            for(int j=0; j<=5; j++) {
            cout << setw(19) << Employee[i][j] << "|";
            }
            cout << endl;
            check = false;
        }
    }
    if (check == true) {
        cout << "No such designation exists in our records\n";
    }
}

void UpdateRecord(string Employee[][6], int Row, string ID) {//This function is called when updating the record of an Employee
    int index;
    for(int i=0; i<=Row; i++){
        if(Employee[i][4]==ID){
            index = i;
            break;
        }
    }
    long long temporary;
    cout << "Name: ";
    cin.ignore(); //This is placed because initially, the code was not taking input and proceeding to address
    getline(cin, Employee[index][0]);
    cout << "Address: ";
    getline(cin, Employee[index][1]);
    cout << "For phone number:\nNo need to add 0, as it is understood in Pakistan, the initial code is +92\n";
    cout << "Phone number: ";
    cin >> temporary;
    while (cin.fail() || temporary <= 0) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Phone number includes alphabets or is negative.\nPlease enter again: ";
        cin >> temporary;
    }
    Employee[index][2] = to_string(temporary); //Phone number is stored in the array using the function to_string
    cout << "Salary: ";
    cin >> temporary;
    while (cin.fail() || temporary <= 0) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered salary includes alphabets or is negative.\nPlease enter again: ";
        cin >> temporary;
    }
    Employee[index][3] = to_string(temporary);

    bool proceed = false;
    cout << "For Employee ID:\nLength should be 4\nIt should not start with 0\nShould only be numbers\n";
    cout << "Employee ID: ";
    cin >> temporary;
    while (proceed == false){
            for(int i=0; i<=Row; i++){ //This loop checks whether the id already exists or not
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
    for(int i=0; i<=Row; i++){
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
     for(int i=0; i<=Row; i++){
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
      for(int i=0; i<=Row; i++){
        if(EmployeeIDs[i] == to_string(temporary)){
            cout << "Sorry, This Employee ID is already taken, please enter some other: ";
            cin >> temporary;
        }
    }
    while (cin.fail() || temporary <= 0 || to_string(temporary).length() != 4) {
        if (cin.fail()) {
            cin.clear();
            string garbage;
            getline(cin,garbage);
        }
        cout << "Entered Employee ID is not in accordance with our rules, please enter again: ";
        cin >> temporary;
     }
     proceed = true;
    }
    Employee[index][4] = to_string(temporary);
    cout << "Designation: ";
    cin.ignore();
    getline(cin,Employee[index][5]);
}


void RemoveEmployee(string Employee[][6], int &Row, string ID){ //This function is called to remove an employee
    int index;
    for(int i=0; i<=Row; i++)
    {
        if(Employee[i][4]==ID)
        {
            index = i;
            break;
        }
    }
    for (int i = index + 1; i <= Row; i++){ //This loop moves the values one index up
        for(int j =0; j<=5; j++) {
            Employee[i-1][j] = Employee[i][j];
        }
    }
    for(int k =0; k<=5; k++) { //This loop sets the last index of the array to ""
            Employee[Row][k] = "";
        }
    Row--; //Decrementing Row to indicate
}

void Display(string Employee[][6], int Row) { //This function displays the contents of the array
    cout << setw(20) << "Name|" << setw(20) << "Address|"<< setw(20) << "Phone Number|"<< setw(20) << "Salary|"<< setw(20) << "Employee ID|"<< setw(20) << "Position|\n\n";
    for (int i =0; i<=Row; i++) {
        for(int j=0; j<=5; j++) {
            cout << setw(19) <<  Employee[i][j] << "|";
        }
        cout << endl;
    }
}

int main() {
    system("color D7");
    cout << "\n\n\n\n\n\n\n\t\t\t\t Welcome to Employee Management System program by Hassan Ali.\n\n\n";
    cout << "\t\t\t\t\t\t Press any key to continue.\n";
    getch();
    system("cls");
    int Row = 0;
int maxsize;
for (int i =0; i < 500; i++) {
    for (int j =0; j<=5; j++) {
            Employee[i][j] = "";
    }
}

     string Fileline;
    int index = 0;
    fstream Newfile;
    Newfile.open("DataBase.txt",ios::in);
    if (!Newfile) {
        cout << "It seems our data base does not exist, we are creating a new file...\n";
        fstream Newfile;
    Newfile.open("DataBase.txt",ios::out);
    if(!Newfile)
    {
    cout<<"File creation failed";
    }
    else
    {
    cout<<"New file created, please restart the program, thank you.";
    Newfile.close();

    }
    return 0;
    }
    else {
    while (!Newfile.eof()) { //This loops until the end of file is approached.
            for (int i =0; i<=5; i++) {
            getline(Newfile, Fileline);
            Employee[index][i] = Fileline;
            }
            index++;
}
    }
    system("color 5B");
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t Welcome to Employee Management System program by Hassan Ali.\n\n\n";
    cout<< "\t\t\t\t We will now proceed to fetch data from our database. Please wait\n";
    cout << "\t\t\t\t Initializing";
    for (int i =0; i<6; i++){
    Sleep(300);
    cout <<".";}
    system("cls");
   cout << "\n\n\n\n\n\n\t\t\t\t Welcome to Employee Management System program by Hassan Ali.\n\n\n";
    cout<< "\t\t\t\t We will now proceed to fetch data from our database. Please wait\n";
    cout << "\t\t\t\t Fetching data";
    for (int i =0; i<6; i++){
    Sleep(300);
    cout <<".";}
    system("cls");
    cout << "\n\n\n\n\n\n\t\t\t\t Welcome to Employee Management System program by Hassan Ali.\n\n\n";
     cout << "\t\t\t\t Data Fetched successfuly, press any key to proceed.";
     getch();
     system("cls");
Row = index;
Row--;
maxsize = Row; //This is so i can remove data which is accidentally read in the last index of the array
Row--;
for (int i =0; i<=Row; i++) { //making a seperate array for employe ids to make input verification easier
    EmployeeIDs[i] = Employee[i][4];
}
int Userchoice;
string searchid, Answer, Designation;
Answer = "Y";
Menu();
cout << "\nEnter your choice: ";
cin >> Userchoice;
while(cin.fail() || Userchoice <=0 || Userchoice >=8) {
    cin.clear();
    string garbage;
    getline(cin, garbage);
    cout << "Entered value is not in accordance with our rules, PLease enter again: ";
    cin >> Userchoice;
}
system("color 8F");
while (Answer == "Y") {
if (Userchoice == 1) {
    system("cls");
    RegisterNew(Employee,Row);
    if (proceedInp == true) { //Data is only written if the ID does not exist in original records
    WriteFile(Employee);}
    for (int i =0; i<=Row; i++) {
    EmployeeIDs[i] = Employee[i][4];
    }
}
else if (Userchoice == 2) {
    system("cls");
    bool proceed= false; //This is verifying whether the entered id exists in our records or not
    cout << "Enter the ID to search: ";
    cin >> searchid;
    for(int i=0; i<=Row; i++)
    {
        if(EmployeeIDs[i] == searchid){
            proceed = true;
        }
    }
    if (proceed == false) {
        cout << "Sorry, this ID does not exist\n";
    }
    if (proceed == true) {
            Search(Employee,Row,searchid);
        }
}
else if( Userchoice == 3) {
    system("cls");
    cout << "Enter their designation: ";
    cin.ignore();
    getline(cin,Designation);
    SearchDes(Employee,Row,Designation);
}
else if (Userchoice == 4) {
    system("cls");
        string sortChoice;
        cout << "Would you like to sort by:\n1) Employee ID\n2) Name\n";
        cin >> sortChoice;
    while (sortChoice != "1" && sortChoice != "2") {
             cout << "Invalid response, please enter again: ";
    cin >> sortChoice;
}
if (sortChoice == "1") {
    Sort(Employee, Row);
}
else if (sortChoice == "2") {
    SortByName(Employee, Row);
}
    system("cls");
    Display(Employee, Row);
}
else if (Userchoice == 5) {
    system("cls");
        cout << "Enter ID of employee to update record: ";
    bool proceed= false;
    cin >> searchid;
    for(int i=0; i<=Row; i++)
    {
        if(EmployeeIDs[i] == searchid){
            proceed = true;
        }
    }
    if (proceed == false) {
        cout << "Sorry, this ID does not exist \n";
    }
    if (proceed == true) {
        UpdateRecord(Employee,Row,searchid);
        for (int i=0; i<=5; i++) {
        Employee[maxsize][i]= "";
        }
        WriteFile(Employee);
        for (int i =0; i<=Row; i++) {
        EmployeeIDs[i] = Employee[i][4];
        }
        }

}
else if (Userchoice == 6) {
    system("cls");
   cout << "Enter ID of user to remove: ";
    bool proceed= false;
    cin >> searchid;
    for(int i=0; i<=Row; i++)
    {
        if(EmployeeIDs[i] == searchid){
            proceed = true;
        }
    }
    if (proceed == false) {
        cout << "Sorry, this ID does not exist\n";
    }
    if (proceed == true) {
            RemoveEmployee(Employee, Row, searchid);
   for (int i=0; i<=5; i++) { //This is emptying the contents of the last index which was mis-interpretted as the input
    Employee[maxsize][i]= "";
    }
   WriteFile(Employee);
        }
}
else if (Userchoice == 7) {
    return 0;
}
else {
    //cout << "Entered value is not in accordance with our rules, PLease enter again: ";
    //cin >> Userchoice;
    while(cin.fail() || Userchoice <=0 || Userchoice >=8) {
    cin.clear();
    string garbage;
    getline(cin, garbage);
    cout << "Entered value is not in accordance with our rules, PLease enter again: ";
    cin >> Userchoice;
}
}
cout << "\nEnter \"Y\" to continue, \"N\" to quit\n";
cin >> Answer;
while (Answer != "Y" && Answer != "N") {
   cout << "Incorrect response, please enter again\n";
   cin >> Answer;
}
if (Answer != "N") {
        system("cls");
Menu();
cout << "\nEnter your choice: ";
cin >> Userchoice;
}
}
return 0;
}
/*CITATIONS:
https://www.guru99.com/cpp-file-read-write-open.html
i just learned file handling from here.
other libraries i learnt about from random google searches and a lot of different websites
*/
