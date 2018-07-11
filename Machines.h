#ifndef MACHINES_H_INCLUDED
#define MACHINES_H_INCLUDED
#include <iostream>
using namespace std ;
class Machines
{
private :
    int Id ;
    string Name ;
    string Program ;
    int Number ;
public :
    Machines ();
    void  ShowData();
    void  SetData();
    void  SetName(string );
    void  SetNumber(int );
    void SetProgram(string);
    string  GetName();
    int  GetNumber();
    string  GetProgram();
    int GetId ();
    void SetId();

};

#endif // MACHINES_H_INCLUDED
