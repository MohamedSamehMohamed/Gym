// InterFace
#ifndef BASEINFO_H_INCLUDED
#define BASEINFO_H_INCLUDED
#include<iostream>
using namespace std ;
struct Info
{
    int Wight ;
    int Hight ;
};
class BaseInfo
{
protected  :
    int Id =1  ;
    string Phone ;
    int Age ;
    Info BodyInfo ;
    string Name ;
    string Program ;
public :
    void SetData();
    Info GetInfo () ;
    void ShowData();
    string GetPhone ();
    string GetProgram ();
    int GetAge ();
    string GetName ();
    int GetId();
    void SetInfo (Info);
    void SetPhone(string);
    void SetProgram(string);
    void SetAge(int);
    void SetName(string);

};

#endif
