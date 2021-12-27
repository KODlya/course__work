#include <iostream>
#include "List.cpp"
#include <fstream>
//include <conio.h>
//#include <cstdlib>
using namespace std;

void MenuPoints() {
    cout << "\t************************************\n";
    cout << "\t*  [1] - Add new element           *\n";
    cout << "\t*  [2] - Insert by logical number  *\n";
    cout << "\t*  [3] - Delete by logical number  *\n";
    cout << "\t*  [4] - Get by logical number     *\n";
    cout << "\t*  [5] - Sorting                   *\n";
    cout << "\t*  [6] - Insert with order keep    *\n";
    cout << "\t*  [7] - Balancing                 *\n";
    cout << "\t*  [8] - Save to binary file       *\n";
    cout << "\t*  [9] - Load from binary file     *\n";
    cout << "\t*  [10] - Show                     *\n";
    cout << "\t*  [11] - Show in reverse order    *\n";
    cout << "\t*  [0] - Quit                      *\n";
    cout << "\t************************************\n";
    cout << "What do you want to do? Enter int number from 0 to 9\n";
}

void menu() {
    List <int> a;
    int* str;
    ofstream f;
    ifstream f1;
    int pos = 0;
    int x = 0; int i = 0;
    bool flag = true;
    while (true) {
        system("cls");
        MenuPoints();
        cin >> x;
        switch (x) {
            case 1: {
                cout << "Enter string\n";
                str = new int;
                cin >> *str;
                a.Add2(*str);
                break;
            }
            case 2: {
                cout << "Enter string\n";
                str = new int;
                cin >> *str;
                cout << "Enter logical number\n";
                cin >> pos;
                a.InsertPos(str, pos);
                break;
            }

            case 3: {
                cout << "Enter logical number\n";
                cin >> pos;
                cout << "Deleted element\n";
                cout << *a.Delete(pos) << "\n";
                break;
            }

            case 4: {
                cout << "Enter logical number\n";
                cin >> pos;
                cout << "Element with logical number " << pos << "\n";
                cout << *a[pos];
                break;
            }
            case 5: {
                cout << "*Sort*";
                a.Sort();
                break;
            }
            case 6: {
                cout << "Enter string\n";
                str = new int;
                cin >> *str;
                a.InSort(str);
                break;
            }

            case 7: {
                cout << "*Balancing*";
                a.Balance();
                break;
            }

            case 8: {
                ofstream fileOut;
                fileOut.open("..\\text.dat");
                a.SaveToBin(fileOut);
                fileOut.close();
                    break;
                }

            case 9: {
                ifstream fileIn;
                fileIn.open("..\\text.dat", ios::in | ios::binary);
                if (fileIn.peek() == std::ifstream::traits_type::eof()) {
                    cout << "! The file is empty. Save something there first\n\n";
                } else {
                    if (fileIn.is_open()) {
                        a.LoadFromBin(fileIn);
                    }
                }
                fileIn.close();
                break;
            }
            case 10: {
                a.ListPrint();
                break;
            }
            case 11: {
                a.ListPrintBack();
                break;
            }
            case 12: {
                a.FreeMemory();
                break;
            }
            case 0:
                flag = false;
                break;
            default:
                cout << "Eror";
                break;
        }
        if (flag == 0)
            break;
    }
}
int main() {
    menu();
}
