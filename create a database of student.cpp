#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
class db {
    int roll;
    char name[20];
    char Class[10];
    char Div[10];
    char dob[10];
    char bg[3], contact[10];
    char phone[10], license[12];
public:
    static int stdno;
    static void count() {
        cout << "\nNo. of objects created: " << stdno;
    }
    void fin() { cout << "\nInline Function!"; }
    db() {
        roll = 0;
        strcpy(name, "Sachin");
        strcpy(Class, "I");
        strcpy(Div, "A");
        strcpy(dob, "11/11/1111");
        strcpy(bg, "A");
        strcpy(contact, "city");
        strcpy(phone, "9000000000");
        strcpy(license, "A0101010");
        ++stdno;
    }
    db(db *ob) {
        strcpy(name, ob->name);
        strcpy(dob, ob->dob);
        strcpy(Class, ob->Class);
        strcpy(Div, ob->Div);
        strcpy(bg, ob->bg);
        strcpy(contact, ob->contact);
        strcpy(phone, ob->phone);
        strcpy(license, ob->license);
        ++stdno;
    }
    void getdata() {
        cout << "\nEnter Name Of Student: ";
        cin >> name;
        cout << "\nEnter Roll Number: ";
        cin >> roll;
        cout << "\nEnter Class: ";
        cin >> Class;
        cout << "\nEnter Division: ";
        cin >> Div;
        cout << "\nEnter Date Of Birth: ";
        cin >> dob;
        cout << "\nEnter Blood Group: ";
        cin >> bg;
        cout << "\nEnter Address: ";
        cin >> contact;
        cout << "\nEnter Contact Number: ";
        cin >> phone;
        cout << "\nEnter License No.: ";
        cin >> license;
    }
    friend void display(const db &d);
    ~db() {
        cout << "\n\n" << this->name << "(Object) is destroyed!";
    }
};
void display(const db &d) {
    cout << setw(12) << d.name << setw(5) << d.roll << setw(4) << d.Class << setw(3) << d.Div << setw(12) <<
        d.dob << setw(4) << d.bg << setw(12) << d.contact << " " << setw(12) << d.phone << " " << setw(12) <<
        d.license << endl;
}
int db::stdno = 0;
int main() {
    db defaultObj;
    cout << "\nDefault values of the object:\n";
    display(defaultObj);

    int n, i, delIndex;
    cout << "\nHow many objects do you want to create?: ";
    cin >> n;
    db** ptr = new db*[n];
    for (i = 0; i < n; i++) {
        ptr[i] = new db();
        ptr[i]->getdata();
    }
    cout << "\n" << setw(12) << "Index" << setw(12) << "name" << setw(5) << "roll" << setw(4) << "Class" << setw(4) << "Div" << setw(12) <<
        "dob" << setw(4) << "bg" << setw(12) << "contact" << setw(12) << "phone" << setw(12) << "license" << endl;
    for (i = 0; i < n; i++) {
        cout << setw(12) << i;
        display(*ptr[i]);
    }
    db::count();
    char choice;
    do {
        cout << "\nMenu:\n";
        cout << "1. Add new object\n";
        cout << "2. Delete an object\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1': {
                db** newPtr = new db*[n + 1];
                for (i = 0; i < n; i++) {
                    newPtr[i] = ptr[i];
                }
                newPtr[n] = new db();
                newPtr[n]->getdata();
                ptr = newPtr;
                n++;
                cout << "\n" << setw(12) << "Index" << setw(12) << "name" << setw(5) << "roll" << setw(4) << "Class" << setw(4) << "Div" << setw(12) <<
                    "dob" << setw(4) << "bg" << setw(12) << "contact" << setw(12) << "phone" << setw(12) << "license" << endl;
                for (i = 0; i < n; i++) {
                    cout << setw(12) << i;
                    display(*ptr[i]);
                }
                db::count();
                break;
            }
            case '2': {
                cout << "\nEnter the index of the object you want to delete (0 to " << n-1 << "): ";
                cin >> delIndex;
                if (delIndex >= 0 && delIndex < n) {
                    delete ptr[delIndex];
                    ptr[delIndex] = NULL;
                    cout << "\nObject at index " << delIndex << " deleted!";
                } else {
                    cout << "\nInvalid index!";
                }

                cout << "\nRemaining objects:";
                for (i = 0; i < n; i++) {
                    if (ptr[i] != NULL) {
                        cout << setw(12) << i;
                        display(*ptr[i]);
                    } }
                break;
            }
            case '3':{
                cout << "\nExiting program.";
                break;
            default:
                cout << "\nInvalid choice!";
                break;
            }}
    } while (choice != '3');
    for (i = 0; i < n; i++) {
        if (ptr[i] != NULL) {
            break;
        }
   break;
    int z;
    delete[] ptr[z];
    return 0; 
	}
}

