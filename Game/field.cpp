#include "field.h"

char **creat_field(int rows, int cols)
{
    char **p_field = new char*[rows];

    for (int i = 0; i < rows; i++)
    {
        p_field[i] = new char[cols];
    }

    return p_field;
}

void init(char **p_field, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            if ((j > 0 && j < cols - 1) && (i > 0 && i < rows - 1))
                p_field[i][j] = ' ';
            else
                p_field[i][j] = 'X';
        }
    }
}

void show_field(char **p_field, int rows, int cols)
{
    if (p_field != NULL)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                cout << p_field[r][c];
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
}

void obstacles(char **p_field, char ch, int numRow, int numCol)
{
    p_field[numRow][numCol] = ch;
}

void obstacles_horiz(char **p_field, int row_num, int col_num, int dist_rt, char ch)
{
    for (int i = 0; i < dist_rt; i++)
    {
        p_field[row_num][col_num + i] = ch;
    }
}

void obstacles_vert(char **p_field, int row_num, int col_num, int dist_dn, char ch)
{
    for (int i = 0; i < dist_dn; i++)
    {
        p_field[row_num + i][col_num] = ch;
    }
}
// step_rt_lt-2  step_rt_lt+8
//step_up_dn-1  step_up_dn+8

// dist_up = 1

bool checkPath_up(char **p_field, int row_num, int col_num, int dist_up, int dist_rt, char ch)
{

    for (int i = 1; i < dist_rt; i++)
    {
        if (p_field[row_num - dist_up][col_num + i] == ch)
            return false;
    }
    return true;
}

bool checkPath_dn(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch)
{

    for (int i = 1; i < dist_rt; i++)
    {
        if (p_field[row_num + dist_dn][col_num + i] == ch)
            return false;
    }
    return true;
}

bool checkPath_rt(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch)
{

    for (int i = 0; i < dist_dn; i++)
    {
        if (p_field[row_num + i][col_num + dist_rt] == ch)
            return false;
    }
    return true;
}

bool checkPath_lt(char **p_field, int row_num, int col_num, int dist_dn, int dist_lt, char ch)
{

    for (int i = 0; i < dist_dn; i++)
    {
        if (p_field[row_num + i][col_num - dist_lt] == ch)
            return false;
    }
    return true;
}
//-------- show checking path -------

void test_checkPath_up(char **p_field, int row_num, int col_num, int dist_up, int dist_rt, char ch)
{

    for (int i = 1; i < dist_rt; i++)
    {
        p_field[row_num - dist_up][col_num + i] = ch;
        std::cout << p_field[row_num - dist_up][col_num + i];

    }
}

void test_checkPath_dn(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch)
{

    for (int i = 1; i < dist_rt; i++)
    {
        p_field[row_num + dist_dn][col_num + i] = ch;
        std::cout << p_field[row_num + dist_dn][col_num + i];
    }
}

void test_checkPath_rt(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch)
{

    for (int i = 0; i < dist_dn; i++)
    {
        p_field[row_num + i][col_num + dist_rt] = ch;
        std::cout << p_field[row_num + i][col_num + dist_rt];

    }
}

void test_checkPath_lt(char **p_field, int row_num, int col_num, int dist_dn, int dist_lt, char ch)
{

    for (int i = 0; i < dist_dn; i++)
    {
        p_field[row_num + i][col_num - dist_lt] = ch;
        std::cout << p_field[row_num + i][col_num - dist_lt];
    }

}
//----------

void menu()
{
    cout << "[w - jump up,a - move left,d - move right,s - jump up forward,z - jump up back,x - jump up a bit of back,e - jump up a bit of forward,q - quit]:  ";
}

