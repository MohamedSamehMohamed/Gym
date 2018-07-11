// InterFace
#ifndef PROGRAMINFO_H_INCLUDED
#define PROGRAMINFO_H_INCLUDED
#include<iostream>
using namespace std ;
class ProgramInfo
{
private :
    int Id ;
    string Name ;
    int Number ;
public :

    ProgramInfo () ;
    void SetData();
    void ShowData();
    string  GetName();
    int  GetNumber();
    void SetName (string);
    void SetNumber(string);
};


#endif // PROGRAMINFO_H_INCLUDED
