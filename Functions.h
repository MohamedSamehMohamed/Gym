#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<iostream>
using namespace std ;
class Functions
{
public :
    void Insert ();
    void Delete ();
    void Update ();
    void Search ();
    void Display ();

    void Search_Members();
    void Search_Coaches();
    void Search_Machines();
// Insert
    void Insert_Member () ;
    void Insert_Coach () ;
    void Insert_Machine();
// Delete
    void Delete_Member ();
    void Delete_Coach ();
    void Delete_Machine();
//Update
    void Update_Member ();
    void Update_Coach () ;
    void Update_Machine ();
// Search
    void Search_Member_Id ();
    void Search_Member_Program ();
    void Search_Member_Subscription ();
    void Search_Member_Age ();



    void Search_Coach_Id();
    void Search_Coach_Age();
    void Search_Coach_Program();


    void Search_Machine_Id();
    void Search_Machine_Program();
//Display
    void Display_Mamber ();
    void Display_Coaches ();
    void Display_Machines ();
};

#endif // FUNCTIONS_H_INCLUDED
