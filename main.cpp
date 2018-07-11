#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Functions_Implementation.h"
using namespace std   ;
int Select  , Out =1  ;
int  main ()
{
    Functions F ;

    cout << "\t\t\t\t Welcome To :  Gym   \nSelect What You Want \n";
    do {
    cout << "1)Insert.\n";
    cout << "2)Show.\n";
    cout << "3)Delete.\n";
    cout << "4)Update.\n";
    cout << "5)Search.\n";
    cout << "6)Out.\n";
    cin >> Select ;
    /// Validation To Make Input between 1 : 6
    system("cls");
    switch (Select)
    {
    case 1 :
        F.Insert();
        system("cls");
        break ;
    case 2 :
        F.Display();
        break ;
    case 3 :
        F.Delete();
        system("cls");
        break ;
    case 4 :
        F.Update();
        system("cls");
        break ;
    case 5 :
        F.Search();
        break ;
    case 6 :
        Out = 0 ;
        break ;

    }
    }while (Out!=0);
            return 0;
        }
