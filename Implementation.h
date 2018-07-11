#ifndef IMPLEMENTATION_H_INCLUDED
#define IMPLEMENTATION_H_INCLUDED
#include "BaseInfo.h"
#include "Machines.h"
#include "MembersAndCoaches.h"
#include "ProgramInfo.h"
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std ;
/// ### Base Class Implementation START

void BaseInfo::SetData()
{

    cout << "Enter Name \n";
    cin >> Name ;

    cout << "Enter Age\n";
    cin >> Age ;

    cout << "Enter Phone \n";
    cin >> Phone ;

    cout << "Enter Program \n";
    cin >> Program ;

    cout  << "Enter Hight \n";
    cin >> BodyInfo.Hight ;

    cout << "Enter Wight\n";
    cin >> BodyInfo.Wight ;

}
Info BaseInfo::GetInfo()
{
    return BodyInfo ;
}

void BaseInfo::ShowData()
{
    cout << setw(3)<< Id << setw (20) ;
    cout << Name << setw (3);
    cout << Age << setw(3) ;
    cout << BodyInfo.Hight << setw(3);
    cout << BodyInfo.Wight << setw(10);
    cout << Program << setw(13);
    cout << Phone << "\n";
}
int BaseInfo::GetId()
{
    return Id ;
}
string BaseInfo::GetPhone()
{
    return Phone ;
}
string BaseInfo::GetProgram()
{
    return Program ;
}
int BaseInfo::GetAge()
{
    return Age ;
}
string BaseInfo::GetName()
{
    return Name ;
}
void BaseInfo::SetInfo (Info T )
{
    BodyInfo.Hight = T.Hight  ;

    /// Validation

    BodyInfo.Wight = T.Wight  ;

    /// Validation

}
void BaseInfo::SetPhone(string P )
{
    Phone = P ;
// Validation
}
void BaseInfo::SetProgram(string P )
{

    Program = P  ;
    // Validation

}
void BaseInfo::SetAge(int A )
{
    Age = A ;
    // Validation

}
void BaseInfo::SetName(string N )
{

    Name = N  ;
}

/// ### Base Class Implementation END

///#################
/// ### Machines class Implementation START
Machines::Machines()
{

}
void Machines::ShowData()
{

    cout << setw(3)<< Id << setw (20) ;
    cout << Name << setw (3);
    cout << Program << setw(13);
    cout << Number << "\n";
}
void Machines::SetData()
{
    cout << "Enter Name \n";
    cin >> Name ;

    cout << "Enter Program \n";
    cin >> Program ;

    cout << "Enter Number of Machines \n";
    cin >> Number ;
}
void Machines::SetName(string N )
{
    Name = N ;
}
void Machines::SetProgram(string P )
{
    Program = P ;
}
void Machines::SetNumber(int  N )
{
    Number = N ;
}
int Machines::GetId()
{
    return Id ;
}
string Machines::GetName()
{
    return Name ;
}
int Machines::GetNumber()
{
    return Number ;
}
string Machines::GetProgram()
{
    return Program ;

}
/// ### Machines class Implementation END

/// ### MembersAndCoaches Header  Implementation START

/// ### Member class  Implementation START
int GetInt (string T )
{
    int Num =0 ;
    int b = 1 ;
    for (int i = T.size() - 1 ; i  >= 0 ; i--)
    {
        Num+=int (T[i] - '0') * b ;
        b*=10;
    }
    return Num ;
}
Member::Member()
{
Id = 0 ;
}
void Member::SetId ()
{
    fstream TT ;
    TT.open("IDS/MemberId.txt" , ios::in);
    string R ;
    getline(TT,R);
    Id = GetInt(R);
    int t = Id ;
    t++;
    TT.close();
    TT.open("IDS/MemberId.txt" , ios::out);
    TT << t ;


}
void Member::ShowData()
{

    cout << setw(3)<< Id << setw (20) ;
    cout << Name << setw (3);
    cout << Age << setw(3) ;
    cout << BodyInfo.Hight << setw(3);
    cout << BodyInfo.Wight << setw(10);
    cout << Program << setw(13);
    cout << Subscription << setw(12);
    cout << Phone << "\n";

}
void Member::SetData()
{
    BaseInfo::SetData();
    cout << "Select SetSubscription \n" ;
    cin >> Subscription ;
}
void Member::SetSubscription(string S )
{
    Subscription = S ;
}
string Member::GetSubscription()
{
    return Subscription ;
}

/// ### Member class  Implementation END

/// ### Coach class Implementation START
/// ### Coach class Implementation END

/// ### MembersAndCoaches Header  Implementation END

void Coach::SetId()
{
    fstream TT ;
    TT.open("IDS/CoachId.txt" , ios::in);
    string R ;
    getline(TT,R);
    Id = GetInt(R);
    int t = Id ;
    t++;
    TT.close();
    TT.open("IDS/CoachId.txt" , ios::out);
    TT << t ;
}
void Machines::SetId ()
{
   fstream TT ;
    TT.open("IDS/MachineId.txt" , ios::in);
    string R ;
    getline(TT,R);
    Id = GetInt(R);
    int t = Id ;
    t++;
    TT.close();
    TT.open("IDS/MachineId.txt" , ios::out);
    TT << t ;
}

#endif // IMPLEMENTATION_H_INCLUDED
