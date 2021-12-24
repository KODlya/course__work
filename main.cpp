#include <iostream>
#include "List.cpp"
using namespace std;

int main() {
    List<int> a;
    int b = 2, c = 3,n = 6;
    int arr[25];
    for (int i = 0; i<20;i++)
    {
        arr[i]=i;
        a.Add(arr[i]);
    //    a.ListPrint();
       //a.ListPrintBack();
       // cout<<"\n";

    }
    a.ListPrintBack();

//    a.Delete(7);
//    a.Delete(7);
//    a.Delete(7);
//    a.Delete(7);
//    a.Delete(7);
//    a.Delete(7);
//    a.Delete(7);
   // a.ListPrint();
    a.Delete(5);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(0);
//    a.Delete(5);
    a.ListPrint();
    //a.ListPrintBack();
    //cout<<*a.Delete(0);

//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(c);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(c);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(c);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(b);
//    a.ListPrint();
//    cout<<"\n";
//    a.Add2(c);
//    a.ListPrint();
//    cout<<"\n";
}
