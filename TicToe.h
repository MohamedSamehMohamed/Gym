#ifndef TICTOE_H_INCLUDED
#define TICTOE_H_INCLUDED

char Borad [3][3];
void reset ()
{
    for (int i =0 ;i < 3  ;i ++)
    {
        for (int j =0 ;j < 3 ; j ++)
            Borad[i][j] = ' ';
    }
}
bool Check_Won ()
{

    for (int i= 0 ;i < 3 ; i++)
    {

        if ( (Borad[i][0] == Borad[i][1])&&(Borad[i][1] == Borad[i][2]) && Borad[i][2]!= ' '  )
            return true ;
    }

    for (int i= 0 ;i < 3 ; i++)
    {

        if ( (Borad[0][i] == Borad[1][i] ) && (Borad[1][i]   == Borad[2][i]) && Borad[2][i]!= ' ' )
            return true ;
    }

    if ( ( ( Borad[0][0] == Borad[1][1] ) && Borad[1][1]  == Borad[2][2] && Borad[2][2]!= ' ' ) || ( ( Borad[0][2] == Borad[1][1] ) && Borad[0][2] == Borad[2][0] && Borad[2][0]!= ' ' ) )
        return true ;


    return false ;
}
bool End ()
{

    for (int i =0 ;i < 3 ; i++)
        for (int j =0 ;j < 3; j++)
        if (Borad[i][j] == ' ' )
        return false ;
    return true ;
}
void Print ()
{

  for (int i =0 ;i < 3 ; i++)
        {
            cout << i+1 << " ";
            for (int j =0 ;j < 3; j++)
            cout << Borad[i][j] << " ";
            cout <<"\n";
        }
    cout << "# 1 2 3 \n";
}
void Start ()
{

    bool Man1 = true ;
    bool Ok = 0 ;
    reset();


    while (1)
    {

        Print();
        int x , y ;
        cin >> x >> y ;
        while (x > 3 || x < 1 || y > 3 || y < 1 )
        {
            cout << "Out Of Range";
            cin >> x >> y ;
        }
        while (Borad[y-1][x-1]!= ' ' )
        {
            cout << "Used \n";
            cin >> x >> y ;
        }
        x-- ; y-- ;
        Borad[y][x]= (Man1 ? 'O' : 'X');
        if ( Check_Won() )
            {
                system("cls");
                Print();
                Ok =1 ;
                break ;
            }

            if (End())
                break ;

        Man1 = !Man1 ;
        system("cls");
    }

    if (Ok)
        cout << "The Winner Is  : " << (Man1 ?1 : 2  ) << "\n";
    else
        cout << "Draw \n";
}


#endif // TICTOE_H_INCLUDED
