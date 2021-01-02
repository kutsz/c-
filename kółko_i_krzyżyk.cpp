

#include <iostream>
#include <cstdlib> 
#include <string> 
using namespace std;

void show_field(char **p_field, int rows, int cols);
void del_field(char **p_field, int rows);
void init(char **p_field, int rows, int cols);
char **creat_field(int rows, int cols);
void X_Oinit(char **p_field, int rows_num, int cols_num, char O_X);
bool check_field(char **p_field, int rows_num, int cols_num);
bool winning(char **p_field, char O_X);

int main()
{

    int rows = 3;
    int cols = 3;
    //char **p_field = NULL;
    int wiersz = 0;
    int kolumne = 0;

    char **p_field = creat_field(rows, cols);
    init(p_field, rows, cols);
    //show_field(p_field, rows, cols);
    bool flag = true;
    string str = " ";
    char O_X = ' ';
    bool o_xFlag = true;
    int counter = 0;
    
    while (flag)
    {
        show_field(p_field, rows, cols);
        counter++;
        if (o_xFlag)
        {
            str = "krzyżyk";
            O_X = 'X';
            o_xFlag = false;
        } else
        {
            str = "kółko";
            O_X = 'O';
            o_xFlag = true;
        }
        cout << "\n\n Gdzie chcesz wstawić " << str << " - podaj wiersz: ";
        cin >> wiersz;
        cout << "\n Podaj kolumnę: ";
        cin >> kolumne;

        system("clear");

        if ((wiersz < 0 || wiersz > 2) || (kolumne < 0 || kolumne > 2))
        {
            cout << " \nEnter number [0 - 2]\n " << endl;
            o_xFlag = o_xFlag ? false : true ;
            counter--;
        } else
        {
            if (check_field(p_field, wiersz, kolumne))
            {
                cout << " \nthe cell is occupied, select other\n " << endl;
                o_xFlag = o_xFlag ? false : true ;
                counter--;
            }
            else
                X_Oinit(p_field, wiersz, kolumne, O_X);
        }
        if (winning(p_field, O_X))
        {
            flag = false;
            cout << "\nYou are winning\n" << endl;
            show_field(p_field, rows, cols);
        }
        
        if (counter == 10)
        {
            flag = false;
            cout << "\nNo one winner\n" << endl;
            
        }

        //        system("clear");
        //show_field(p_field, rows, cols);
    }


    del_field(p_field, rows);


    return 0;
}

char **creat_field(int rows, int cols)
{
    char **p_field = new char*[rows];

    for (int i = 0; i < rows; i++)
    {
        p_field[i] = new char[cols];
    }



    return p_field;
}

void X_Oinit(char **p_field, int rows_num, int cols_num, char O_X)
{
    p_field[rows_num][cols_num] = O_X;
}

void init(char **p_field, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            p_field[i][j] = '-';
            //cout << p_field[i][j] << " ";
        }

    }
}

bool check_field(char **p_field, int rows_num, int cols_num)
{
    if (p_field[rows_num][cols_num] == 'X' || p_field[rows_num][cols_num] == 'O')
        return true;
    else
        return false;


}

bool winning(char **p_field, char O_X)
{
    if (
            (p_field[0][0] == O_X && p_field[0][1] == O_X && p_field[0][2] == O_X) ||
            (p_field[1][0] == O_X && p_field[1][1] == O_X && p_field[1][2] == O_X) ||
            (p_field[2][0] == O_X && p_field[2][1] == O_X && p_field[2][2] == O_X) ||
            (p_field[0][0] == O_X && p_field[1][0] == O_X && p_field[2][0] == O_X) ||
            (p_field[0][1] == O_X && p_field[1][1] == O_X && p_field[2][1] == O_X) ||
            (p_field[0][2] == O_X && p_field[1][2] == O_X && p_field[2][2] == O_X) ||
            (p_field[0][0] == O_X && p_field[1][1] == O_X && p_field[2][2] == O_X) ||
            (p_field[2][0] == O_X && p_field[1][1] == O_X && p_field[0][2] == O_X)
            )
        return true;
    else
        return false;


}

void show_field(char **p_field, int rows, int cols)
{
    if (p_field != NULL)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                cout << " " << p_field[r][c] << " ";
            }

            cout << endl;
        }

    } else
    {
        cout << " \nNO created field " << std::endl;
    }

}

void del_field(char **p_field, int rows)
{
    for (int i = 0; i < rows; i++)
    {
        delete [] p_field[i];
    }

    delete [] p_field;

    //cout << "OK" << endl;


}



 
