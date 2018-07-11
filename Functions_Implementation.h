#ifndef FUNCTIONS_IMPLEMENTATION_H_INCLUDED
#define FUNCTIONS_IMPLEMENTATION_H_INCLUDED
#include "Implementation.h"
#include "Functions.h"
#include <fstream>
#include <iostream>
#include <string>
#include "MembersAndCoaches.h"


using namespace std ;


 /// Insert Functions
 void Functions::Insert()
 {
int Select ;
cout << "1)Member.\n";
cout << "2)Coach.\n";
cout << "3)Machine.\n";
cout << "4)Back.\n";
cin >> Select ;
/// Validation

system("cls");
switch (Select)
{
case 1 :
    Insert_Member();
    break;
case 2 :
    Insert_Coach();
    break;
case 3 :
    Insert_Machine();
    break;
case 4 :
    break;
}

 }

///  Insert START

///# Insert Member START
void SPACE (int S,int MAX)
{
    for (int i =S ; i < MAX ; i++)
        cout << ' ';
}

void Functions::Insert_Member ()
{

    Member M ;
    M.SetId ();
    M.SetData();
    fstream Mem ;
    Info Tem ;
    Tem = M.GetInfo();
    Mem.open("Data/Members.txt", ios::app );

    Mem << M.GetId() << "#" << M.GetName() << "#" << M.GetAge() << "#" << Tem.Hight << "#"
        << Tem.Wight << "#" <<M.GetProgram() << "#" << M.GetSubscription() << '#' <<M.GetPhone() << "\n";
    Mem.close() ;


}
///# Insert Member END


///# Insert Coach START

void Functions::Insert_Coach ()
{
    Coach C ;
    C.SetId();
    C.SetData();
    fstream Trainer ;
    Info Tem ;
    Tem = C.GetInfo();
    Trainer.open("Data/Coaches.txt", ios::app );

    Trainer << C.GetId() << "#" << C.GetName() << "#" << C.GetAge() << "#" << Tem.Hight << "#"
            << Tem.Wight << "#" <<C.GetProgram() << "#" <<C.GetPhone() << "\n";

    Trainer.close();
}
///# Insert Coach END


///# Insert Machine START
void Functions::Insert_Machine()
{
    fstream Tool ;
    Machines H ;
    H.SetId();
    H.SetData();

    Tool.open("Data/Machines.txt", ios::app );
    Tool<< H.GetId() << "#" << H.GetName() << "#" << H.GetProgram() << "#" <<H.GetNumber() << "\n";
    Tool.close();
}
///# Insert Machine END


/// Insert END

/// #######################################################################################################################

/// Delete Functions
void Functions::Delete()
{

int Select ;
cout << "1)Member.\n";
cout << "2)Coach.\n";
cout << "3)Machine.\n";
cout << "4)Back.\n";
cin >> Select ;
/// Validation

system("cls");
switch (Select)
{
case 1 :
    Delete_Member();
    break;
case 2 :
    Delete_Coach();
    break;
case 3 :
    Delete_Machine();
    break;
case 4 :
    break ;
}


}
///  Delete START


///# Delete Member START
void Functions::Delete_Member()
{
    bool Exisit =0  ;
    int Id ;
//    Display_Mamber();
    cout << "Enter Id You Want To Delete \n";
    cin >> Id ;
/// Validation
    fstream M ;
    string T ;
    M.open("Data/Members.txt", ios::in );
    while (1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            break ;
        }
        getline(M,T,'\n');


    }
    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
        return ;
    }
    fstream M1 ;

    M.open("Data/Members.txt", ios::in );
    M1.open("Data/Members1.txt", ios::out );
    while(1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            getline(M,T,'\n');
            continue ;
        }

        M1 << T << '#' ;

        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'\n');
        M1 << T << '\n' ;

    }
    M.close();
    M1.close();
    remove("Data/Members.txt");
    rename("Data/Members1.txt", "Data/Members.txt");
    cout << "Done\n";



}

///# Delete Member END


///# Delete Coach START
void Functions::Delete_Coach()
{

    bool Exisit =0  ;
    int Id ;
//    Display_Coach();
    cout << "Enter Id You Want To Delete \n";
    cin >> Id ;
/// Validation
    fstream C ;
    string T ;
    C.open("Data/Coaches.txt", ios::in );
    while (1)
    {
        getline(C,T,'#');
        if (C.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            break ;
        }
        getline(C,T,'\n');


    }
    C.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
        return ;
    }
    fstream M1 ;

    C.open("Data/Coaches.txt", ios::in );
    M1.open("Data/Coaches1.txt", ios::out );
    while(1)
    {
        getline(C,T,'#');
        if (C.eof())
            break ;
        if ( Id == GetInt(T))
        {
            getline(C,T,'\n');
            continue ;
        }

        M1 << T << '#' ;

        getline(C,T,'#');
        M1 << T << '#' ;
        getline(C,T,'#');
        M1 << T << '#' ;
        getline(C,T,'\n');
        M1 << T << '\n' ;


    }
    C.close();
    M1.close();
    remove("Data/Coaches.txt");
    rename("Data/Coaches1.txt", "Data/Coaches.txt");
    cout << "Done\n";


}
///# Delete Coach END


///# Delete Machine START
void Functions::Delete_Machine()
{
    bool Exisit =0  ;
    int Id ;
//    Display_Machine();
    cout << "Enter Id You Want To Delete \n";
    cin >> Id ;
/// Validation
    fstream H ;
    string T ;
    H.open("Data/Machines.txt", ios::in );
    while (1)
    {
        getline(H,T,'#');
        if (H.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            break ;
        }
        getline(H,T,'\n');


    }
    H.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
        return ;
    }
    fstream M1 ;

    H.open("Data/Machines.txt", ios::in );
    M1.open("Data/Machines1.txt", ios::out );
    while(1)
    {
        getline(H,T,'#');
        if (H.eof())
            break ;
        if ( Id == GetInt(T))
        {
            getline(H,T,'\n');
            continue ;
        }

        M1 << T << '#' ;

        getline(H,T,'#');
        M1 << T << '#' ;
        getline(H,T,'#');
        M1 << T << '#' ;
        getline(H,T,'\n');
        M1 << T << '\n' ;


    }
    H.close();
    M1.close();
    remove("Data/Machines.txt");
    rename("Data/Machines1.txt", "Data/Machines.txt");
    cout << "Done\n";




}
///# Delete Machine END

/// Delete END



///  Update START ##############################

/// Update Functions
void Functions::Update()
{
    int Select ;
cout << "1)Member.\n";
cout << "2)Coach.\n";
cout << "3)Machine.\n";
cout << "4)Back.\n";
cin >> Select ;
/// Validation

system("cls");
switch (Select)
{
case 1 :
    Update_Member();
    break;
case 2 :
    Update_Coach();
    break;
case 3 :
    Update_Machine();
    break;
case 4 :
    break ;
}

}
///# Update Member START

void Functions::Update_Member ()
{

    int Id ;
//  Display_Mamber();
    cout << "Enter Id To Update \n";
    cin >> Id ;
    fstream M ;
    string T ;
    bool Exisit = 0 ;
    M.open("Data/Members.txt", ios::in );
    while (1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            break ;
        }
        getline(M,T,'\n');


    }
    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
        return ;
    }
    fstream M1 ;

    M.open("Data/Members.txt", ios::in );
    M1.open("Data/Members1.txt", ios::out );
    while(1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            M1 << T << '#' ;
            Member TMember ;
            TMember.SetData();
            Info Tem ;
            Tem = TMember.GetInfo();
            M1 << TMember.GetName() << '#' << TMember.GetAge() << '#' << Tem.Hight << '#'
               << Tem.Wight << '#' <<TMember.GetProgram() << '#' <<TMember.GetPhone() << "\n";
            getline(M,T,'\n');

            continue ;
        }



        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'\n');
        M1 << T << '\n' ;

    }
    M.close();
    M1.close();
    remove("Data/Members.txt");
    rename("Data/Members1.txt", "Data/Members.txt");
    cout << "Done\n";



}

///# Update Member END


///# Update Coach START
void Functions::Update_Coach()
{

    int Id ;
//  Display_Mamber();
    cout << "Enter Id To Update \n";
    cin >> Id ;
    fstream M ;
    string T ;
    bool Exisit = 0 ;
    M.open("Data/Coaches.txt", ios::in );
    while (1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            break ;
        }
        getline(M,T,'\n');


    }
    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
        return ;
    }
    fstream M1 ;

    M.open("Data/Coaches.txt", ios::in );
    M1.open("Data/Coaches1.txt", ios::out );
    while(1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            M1 << T << '#' ;
            Coach C ;
            C.SetData();
            Info Tem ;
            Tem = C.GetInfo();
           M1 << C.GetId() << "#" << C.GetName() << "#" << C.GetAge() << "#" << Tem.Hight << "#"
            << Tem.Wight << "#" <<C.GetProgram() << "#" <<C.GetPhone() << "\n";

            getline(M,T,'\n');

            continue ;
        }



        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'\n');
        M1 << T << '\n' ;

    }
    M.close();
    M1.close();
    remove("Data/Coaches.txt");
    rename("Data/Coaches1.txt", "Data/Coaches.txt");
    cout << "Done\n";



}
///# Update Coach END


///# Update Machine START
void  Functions::Update_Machine()
{
       int Id ;
//  Display_Mamber();
    cout << "Enter Id To Update \n";
    cin >> Id ;
    fstream M ;
    string T ;
    bool Exisit = 0 ;
    M.open("Data/Machines.txt", ios::in );
    while (1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            break ;
        }
        getline(M,T,'\n');


    }
    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
        return ;
    }
    fstream M1 ;

    M.open("Data/Machines.txt", ios::in );
    M1.open("Data/Machines1.txt", ios::out );
    while(1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            M1 << T << '#' ;
            Machines TM ;
            TM.SetData();

          M1<< TM.GetId() << "#" << TM.GetName() << "#" << TM.GetProgram() << "#" <<TM.GetNumber() << "\n";
          getline(M,T,'\n');

            continue ;
        }



        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'#');
        M1 << T << '#' ;
        getline(M,T,'\n');
        M1 << T << '\n' ;

    }
    M.close();
    M1.close();
    remove("Data/Machines.txt");
    rename("Data/Machines1.txt", "Data/Machines.txt");
    cout << "Done\n";


}

///# Update Machine END


/// Update END


///  Search START
/// Search Functions
void Functions::Search()
{
int Select ;
cout << "1)Member.\n";
cout << "2)Coach.\n";
cout << "3)Machine.\n";
cout << "4)Back.\n";
cin >> Select ;
/// Validation

system("cls");
switch (Select)
{
case 1 :
    Search_Members();
    break;
case 2 :
    Search_Coaches();
    break;
case 3 :
    Search_Machines();
    break;
case 4 :
    break ;
}
}
void Functions::Search_Members()
{
system("cls");
int Select ;
cout << "Search By : \n";
cout << "1)Id. \n";
cout << "2)Program. \n";
cout << "3)Subscription. \n";
cout << "4)Age.\n";
cout << "5)Back.\n";
cin >> Select ;
/// Validation
switch (Select)
{
case 1 :
    Search_Member_Id();
    break ;
case 2 :
    Search_Member_Program();
     break ;
case 3 :
    Search_Member_Subscription();
     break ;
case 4 :
    Search_Member_Age();
     break ;
case 5 :
     break;
     break ;

}
}
void Functions::Search_Coaches()
{
system("cls");
int Select ;
cout << "Search By : \n";
cout << "1)Id. \n";
cout << "2)Program. \n";
cout << "3)Age.\n";
cout << "4)Back.\n";
cin >> Select ;
/// Validation
switch (Select)
{
case 1 :
    Search_Coach_Id();
    break ;
case 2 :
    Search_Coach_Program();
     break ;
case 3 :
    Search_Coach_Age();
     break ;
case 4 :
     break;
     break ;

}
}
void Functions::Search_Machines()
{
system("cls");
int Select ;
cout << "Search By : \n";
cout << "1)Id. \n";
cout << "2)Program. \n";
cout << "3)Back.\n";
cin >> Select ;
/// Validation
switch (Select)
{
case 1 :
    Search_Machine_Id();
    break ;
case 2 :
    Search_Machine_Program();
     break ;
case 3 :
     break;
     break ;

}
}

///# Search Member  By Id START

void Functions::Search_Member_Id ()
{
    int Id ;
    cout << "Enter Id You Search For \n";
    cin >> Id ;
    fstream M ;
    string T ;
    bool Exisit = 0 ;
    M.open("Data/Members.txt", ios::in );
    while (1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            cout << "Found \n";

        cout << "Id" << "  " << "Name" << "\t" << "Age" << "  " << "Hight" << "  " << "Wight" << "  "<<"Program"<< "       "<<"Subscription"<< "    "<<"Phone\n";



            cout << T ; SPACE(T.size(),3) ;
            getline(M,T,'#');
            cout << T ; SPACE(T.size(),13) ;

            getline(M,T,'#');
            cout << T ; SPACE(T.size(),5) ;

            getline(M,T,'#');
            cout << T ; SPACE(T.size(),7) ;

            getline(M,T,'#');
            cout << T ; SPACE(T.size(),7) ;


            getline(M,T,'#');
            cout << T ; SPACE(T.size(),15);


            getline(M,T,'#');
            cout << T  ;SPACE(T.size(),15) ;

            getline(M,T,'\n');
            cout << T  ;
            cout << "\n";



            break ;

        }
        getline(M,T,'\n');


    }

    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }

}

///# Search Member  By Id END

///# Search Member  By Program START
void Functions::Search_Member_Program ()
{
    string  ProgramS ;
    cout << "Enter Program You Search For \n";
    cin >> ProgramS ;
    fstream M ;
    string T1, T2,T3, T4, T5, T6, T7, T8 ;
    bool Exisit = 0 ;
    M.open("Data/Members.txt", ios::in );
    while (1)
    {
        getline(M,T1,'#');
        if (M.eof())
            break ;
        getline(M,T2,'#');
        getline(M,T3,'#');
        getline(M,T4,'#');
        getline(M,T5,'#');
        getline(M,T6,'#');
        getline(M,T7,'#');
        getline(M,T8,'\n');

        if ( ProgramS == T6)
        {
            Exisit = 1 ;


            cout << T1 << setw(3) ;

            cout << T2 << setw(3) ;


            cout << T3 << setw(3) ;


            cout << T4 << setw(3) ;


            cout << T5 << setw(3) ;


            cout << T6 << setw(3) ;
            cout << T7 << setw(3) ;
            cout << T8 << setw(3) ;


            cout << "\n";



        }


    }

    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }
}

///# Search Member  By Program END


///# Search Member  By Subscription START

void Functions::Search_Member_Subscription ()
{
    string  Subscription ;
    cout << "Enter Program You Search For \n";
    cin >> Subscription ;
    fstream M ;
    string T1, T2,T3, T4, T5, T6, T7, T8 ;
    bool Exisit = 0 ;
    M.open("Data/Members.txt", ios::in );
    while (1)
    {
        getline(M,T1,'#');
        if (M.eof())
            break ;
        getline(M,T2,'#');
        getline(M,T3,'#');
        getline(M,T4,'#');
        getline(M,T5,'#');
        getline(M,T6,'#');
        getline(M,T7,'#');
        getline(M,T8,'\n');

        if ( Subscription == T7)
        {
            Exisit = 1 ;


            cout << T1 << setw(3) ;

            cout << T2 << setw(3) ;


            cout << T3 << setw(3) ;


            cout << T4 << setw(3) ;


            cout << T5 << setw(3) ;


            cout << T6 << setw(3) ;
            cout << T7 << setw(3);
            cout << T8 << setw(3);


            cout << "\n";



        }


    }

    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }

}
///# Search Member  By Subscription END
///# Search Member  By Age START
void Functions::Search_Member_Age()
{
    int   TAge ;
    cout << "Enter Age You Search For \n";
    cin >> TAge ;
    fstream M ;
    string T1, T2,T3, T4, T5, T6, T7, T8 ;
    bool Exisit = 0 , Once = 0  ;
    M.open("Data/Members.txt", ios::in );
    while (1)
    {
        getline(M,T1,'#');
        if (M.eof())
            break ;
        getline(M,T2,'#');
        getline(M,T3,'#');
        getline(M,T4,'#');
        getline(M,T5,'#');
        getline(M,T6,'#');
        getline(M,T7,'#');
        getline(M,T8,'\n');

        if ( TAge == GetInt(T3))
        {
            Exisit = 1 ;



            if (Exisit&&!Once){
                    cout << "Id" << "  " << "Name" << "\t" << "Age" << "  " << "Hight" << "  " << "Wight" << "  "<<"Program"<< "       "<<"Subscription"<< "    "<<"Phone\n";
                    Once=1 ;
                }
            cout << T1 ; SPACE(T1.size(),3) ;

            cout << T2 ; SPACE(T2.size(),13) ;

            cout << T3 ; SPACE(T3.size(),5) ;


            cout << T4 ; SPACE(T4.size(),7) ;


            cout << T5 ; SPACE(T5.size(),7) ;



            cout << T6 ; SPACE(T6.size(),15);



            cout << T7  ;SPACE(T7.size(),15) ;

            cout << T8  ;
            cout << "\n";



        }


    }

    M.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }

}
///# Search Member  By Age END



///# Search Coach START

///# Search Coach  By Id START

void Functions::Search_Coach_Id ()
{
    int Id ;
    cout << "Enter Id You Search For \n";
    cin >> Id ;
    fstream C ;
    string T ;
    bool Exisit = 0 ;
    C.open("Data/Coaches.txt", ios::in );
    while (1)
    {
        getline(C,T,'#');
        if (C.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            cout << "Found \n";

            cout << T << setw(3) ;
            getline(C,T,'#');
            cout << T << setw(3) ;

            getline(C,T,'#');
            cout << T << setw(3) ;

            getline(C,T,'#');
            cout << T << setw(3) ;

            getline(C,T,'#');
            cout << T << setw(3) ;

            getline(C,T,'#');
            cout << T << setw(3) ;

            getline(C,T,'\n');
            cout << T << setw(3) ;
            cout << "\n";
            break ;

        }
        getline(C,T,'\n');


    }

    C.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }

}

///# Search Coach  By Id END


///# Search Coach  By Age START
void Functions::Search_Coach_Age()
{
   int   TAge ;
    cout << "Enter Age You Search For \n";
    cin >> TAge ;
    fstream C ;
    string T1 , T2 ,T3 , T4 , T5 , T6 , T7 , T8 ;
    bool Exisit = 0 ;
    C.open("Data/Coaches.txt", ios::in );
    while (1)
    {
        getline(C,T1,'#');
        if (C.eof())
            break ;
        getline(C,T2,'#');
        getline(C,T3,'#');
        getline(C,T4,'#');
        getline(C,T5,'#');
        getline(C,T6,'#');
        getline(C,T7,'\n');

        if ( TAge == GetInt(T3))
        {
            Exisit = 1 ;


            cout << T1 << setw(3) ;
            cout << T2 << setw(3) ;
            cout << T3 << setw(3) ;
            cout << T4 << setw(3) ;
            cout << T5 << setw(3) ;
            cout << T6 << setw(3) ;
            cout << T7 << setw(3);


            cout << "\n";



        }


    }

    C.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }

}
///# Search Coach  By Age END


///# Search Coach  By Program START
void Functions::Search_Coach_Program ()
{
 string  ProgramS ;
    cout << "Enter Program You Search For \n";
    cin >> ProgramS ;
    fstream C ;
    string T1 , T2 ,T3 , T4 , T5 , T6 , T7  ;
    bool Exisit = 0 ;
    C.open("Data/Coaches.txt", ios::in );
    while (1)
    {
        getline(C,T1,'#');
        if (C.eof())
            break ;
        getline(C,T2,'#');
        getline(C,T3,'#');
        getline(C,T4,'#');
        getline(C,T5,'#');
        getline(C,T6,'#');
        getline(C,T7,'\n');

        if ( ProgramS == T6)
        {
            Exisit = 1 ;


            cout << T1 << setw(3) ;

            cout << T2 << setw(3) ;


            cout << T3 << setw(3) ;


            cout << T4 << setw(3) ;


            cout << T5 << setw(3) ;


            cout << T6 << setw(3) ;
            cout << T7 << setw(3) ;

            cout << "\n";



        }


    }

    C.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }
}

///# Search Coach  By Program END



///# Search Coach END


///# Search Machine START




///# Search Machine  By Id START


void Functions::Search_Machine_Id ()
{
    int Id ;
    cout << "Enter Id You Search For \n";
    cin >> Id ;
    fstream H ;
    string T ;
    bool Exisit = 0 ;
    H.open("Data/Machines.txt", ios::in );
    while (1)
    {
        getline(H,T,'#');
        if (H.eof())
            break ;
        if ( Id == GetInt(T))
        {
            Exisit = 1 ;
            cout << "Found \n";

            cout << T << setw(3) ;
            getline(H,T,'#');
            cout << T << setw(3) ;

            getline(H,T,'#');
            cout << T << setw(3) ;

            getline(H,T,'\n');
            cout << T << setw(3) ;
            cout << "\n";
            break ;

        }
        getline(H,T,'\n');


    }

    H.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }

}

///# Search Machines  By Id END




///# Search Machine  By Program START
void Functions::Search_Machine_Program ()
{
 string  ProgramS ;
    cout << "Enter Program You Search For \n";
    cin >> ProgramS ;
    fstream H ;
    string T1 , T2 ,T3 , T4  ;
    bool Exisit = 0 ;
    H.open("Data/Machines.txt", ios::in );
    while (1)
    {
        getline(H,T1,'#');
        if (H.eof())
            break ;
        getline(H,T2,'#');
        getline(H,T3,'#');
        getline(H,T4,'\n');


        if ( ProgramS == T3)
        {
            Exisit = 1 ;


            cout << T1 << setw(3) ;

            cout << T2 << setw(3) ;


            cout << T3 << setw(3) ;


            cout << T4 << setw(3) ;


            cout << "\n";



        }


    }

    H.close() ;
    if (!Exisit)
    {
        cout << "Not Exist \n";
    }
}

/// Search END



///  Display START
/// Display Functions
void Functions::Display()
{
      int Select ;
cout << "1)Member.\n";
cout << "2)Coach.\n";
cout << "3)Machine.\n";
cout << "4)Back.\n";
cin >> Select ;
/// Validation

system("cls");
switch (Select)
{
case 1 :
    Display_Mamber();
    break;
case 2 :
    Display_Coaches();
    break;
case 3 :
    Display_Machines();
    break;
case 4 :
    break ;
}

}



///# Display Member START
void Functions::Display_Mamber ()
{

    fstream M ;
    string T ;
    bool Exisit = 0 ;
    M.open("Data/Members.txt", ios::in );
    if (!M)
    {
        M.close();
        cout << "Not Exist \n";
        return ;
    }
    cout << "Id" << "  " << "Name" << "\t" << "Age" << "  " << "Hight" << "  " << "Wight" << "  "<<"Program"<< "       "<<"Subscription"<< "    "<<"Phone\n";
    while (1)
    {
        getline(M,T,'#');
        if (M.eof())
            break ;
            cout << T ; SPACE(T.size(),3) ;
            getline(M,T,'#');
            cout << T ; SPACE(T.size(),13) ;

            getline(M,T,'#');
            cout << T ; SPACE(T.size(),5) ;

            getline(M,T,'#');
            cout << T ; SPACE(T.size(),7) ;

            getline(M,T,'#');
            cout << T ; SPACE(T.size(),7) ;


            getline(M,T,'#');
            cout << T ; SPACE(T.size(),15);


            getline(M,T,'#');
            cout << T  ;SPACE(T.size(),15) ;

            getline(M,T,'\n');
            cout << T  ;
            cout << "\n";


    }

    M.close() ;


}
///# Display Member END



///# Display Coach START
void Functions::Display_Coaches ()
{

    fstream T ;
    string M ;
    bool Exisit = 0 ;
    T.open("Data/Coaches.txt", ios::in );
    if (!T)
    {
        T.close();
        cout << "Not Exist \n";
        return ;
    }
    cout << "Id" << "  " << "Name" << "\t" << "Age" << "        " << "Hight" << "     " << "Wight" << "     "<<"Program"<< "  "<< " "<<"Phone\n";
    while (1)
    {
        getline(T,M,'#');
        if (T.eof())
            break ;
            cout << M ; SPACE(M.size(),3) ;
            getline(T,M,'#');
            cout << M ; SPACE(M.size(),14) ;

            getline(T,M,'#');
            cout << M ; SPACE(M.size(),10) ;

            getline(T,M,'#');
            cout << M ; SPACE(M.size(),10) ;

            getline(T,M,'#');
            cout << M ; SPACE(M.size(),10) ;


            getline(T,M,'#');
            cout << M ; SPACE(M.size(),10);



            getline(T,M,'\n');
            cout << M  ;
            cout << "\n";


     }

    T.close() ;


}

///# Display Coach END



///# Display Machine START
void Functions::Display_Machines ()
{

    fstream H ;
    string Tool ;
    bool Exisit = 0 ;
    H.open("Data/Machines.txt", ios::in );
    if (!H)
    {
        H.close();
        cout << "Not Exist \n";
        return ;
    }
    cout << "Id" << "  " << "Name" << "\t" << "program" << "  " <<"Number \n";
    while (1)
    {
        getline(H,Tool,'#');
        if (H.eof())
            break ;
            cout << Tool ; SPACE(Tool.size(),4) ;
            getline(H,Tool,'#');
            cout << Tool ; SPACE(Tool.size(),12) ;

            getline(H,Tool,'#');
            cout << Tool ; SPACE(Tool.size(),10) ;

            getline(H,Tool,'\n');
            cout << Tool ; SPACE(Tool.size(),10) ;

            cout << "\n";


     }

    H.close() ;


}

///# Display Machine END

/// Display END


#endif // FUNCTIONS_IMPLEMENTATION_H_INCLUDED
