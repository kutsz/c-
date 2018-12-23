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
            ;
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

    //cout << "OK" << endl;


}

