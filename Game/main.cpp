
/* 
 * File:   main.cpp
 * Author: valentine
 *
 * Created on 30 ноября 2018 г., 14:30
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <unistd.h> // for sleep()
//#include <ncursesw/curses.h>
#include <ncursesw/ncurses.h>
#include <cstdio>
#include <stdio.h>


using namespace std;

void show_field(char **p_field, int rows, int cols);
void del_field(char **p_field, int rows);
void init(char **p_field, int rows, int cols);
char **creat_field(int rows, int cols);
void person(char **p_field, int i, int j, char ch);
int move_rt(int j, int cols);
int move_lt(int j, int num);
int move_up(int i, int num);
int move_dn(int i, int rows);

void obstacles(char **p_field, char ch);
void person(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2);
void person1(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2);
void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht);
void jump_dn(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht);
void jump_up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int ht);
void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht);

void danger(char **p_field, int row, int col, char ch);

int main()
{

    int rows = 42; //42
    int cols = 150; //150

    char **p_field = creat_field(rows, cols);
    init(p_field, rows, cols);


    int rowNum = 33;
    int colNum = 4;
    //person(p_field, rowNum, colNum, '*');
    person(p_field, rowNum, colNum, '(', ')', '#');
    show_field(p_field, rows, cols);
    ////person(p_field, 32, 5);
    //system("clear");
    //sleep(5);

    bool flag = true;
    char ch = ' ';
    int step_rt_lt = colNum;
    int step_up_dn = rowNum;
    int count = 0;
    bool fg = true;
    while (flag)
    {
        cin >> ch;
        //ch = getch();
        //ch = getchar();
        //cin.get(ch);

        switch (ch) {
            case 'w':
            {

                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                step_up_dn = move_up(step_up_dn, 1);
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                break;
            }
            case 'z':
            {

                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                step_up_dn = move_dn(step_up_dn, rows);
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                break;
            }
            case 'a':
            {

                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                step_rt_lt = move_lt(step_rt_lt, 2);
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                break;
            }
            case 'd':
            {

                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                step_rt_lt = move_rt(step_rt_lt, cols);
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                break;
            }

            case 'x':
            {
                jump_up(p_field, step_up_dn, step_rt_lt, rows, 10);
                //jump_dn(p_field, step_up_dn, step_rt_lt, rows);

                break;
            }

            case 'c':
            {
                //jump_up(p_field, step_up_dn, step_rt_lt, rows);
                jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10);

                break;
            }

            case 'v':
            {
                jump_up_fd(p_field, step_up_dn, step_rt_lt, cols, 10);
                ////jump_dn_fd(p_field, step_up_dn, step_rt_lt, cols, rows, 10);
                break;
            }

            case 'b':
            {
                //// jump_up_fd(p_field, step_up_dn, step_rt_lt, cols, 10);
                jump_dn_fd(p_field, step_up_dn, step_rt_lt, cols, rows, 10);
                break;
            }

            case 'q':
            {
                flag = false;
                break;
            }

            default:
            {
                cout << " inne " << endl;
                break;
            }
        }
        //        obstacles(p_field, '@');
        ////sleep(2);
        system("clear");
        //        person(p_field, 32, 5, '(',')','#');
        //show_field(p_field, rows, cols);
        //
//        if (count == 2)
//            fg = true;
//        if (count == 148)
//            fg = false;
//
//        danger(p_field, 20, count, ' ');
//        count = fg ? ++count : --count;
      //danger(p_field, 20, count, '@');

        show_field(p_field, rows, cols);

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

void person(char **p_field, int i, int j, char ch)
{
    p_field[i][j] = ch;
    p_field[i + 1][j] = ch;
    p_field[i + 2][j] = ch;
    p_field[i + 3][j] = ch;
}

int move_rt(int j, int cols)
{
    j = (j < cols - 9) ? ++j : j;
    return j;

}

int move_lt(int j, int num)
{
    j = (j > num) ? --j : j;
    //if(j > 1 && j < cols - 2) --j;

    return j;
}

int move_up(int i, int num)
{
    i = (i > num) ? --i : i;
    return i;
}

int move_dn(int i, int rows)
{
    i = (i < rows - 9) ? ++i : i;
    return i;
}
//    void move_up(Map & M){
//            if(M.is_cell_free(pt.x,pt.y++)) /////???????????????????????????????
//                 pt.y++;
//  //else cout<<"Car run into obstacle";   // throw 1 ????
//
//    }

void obstacles(char **p_field, char ch)
{
    int c = rand() % (149 - 100) + 100;
    int r = rand() % (20 - 10) + 10;

    p_field[r][c] = ch;

}

void danger(char **p_field, int row, int col, char ch)
{   
    int count = 0;
    bool fg = true;
    while(true)
    {
        if (count == 2)
            fg = true;
        if (count == 148)
            fg = false;

        p_field[row][count] = ' ';
        count = fg ? ++count : --count;
       
      p_field[row][count] = ch;
    }

}

void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_up_dn = move_up(step_up_dn, 1);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

        ////system("clear");
    }


}

void jump_dn(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_up_dn = move_dn(step_up_dn, rows);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }

}

void jump_up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int ht)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_rt_lt = move_rt(step_rt_lt, cols);
        step_up_dn = move_up(step_up_dn, 1);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }

}

void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_rt_lt = move_rt(step_rt_lt, cols);
        step_up_dn = move_dn(step_up_dn, rows);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }

}

void person(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2)
{
    //head
    p_field[row_num][col_num + 2] = ch;
    p_field[row_num][col_num + 3] = ch2;
    p_field[row_num][col_num + 4] = ch1;
    //body
    p_field[row_num + 1][col_num + 1] = ch2;
    p_field[row_num + 1][col_num + 2] = ch2;
    p_field[row_num + 1][col_num + 3] = ch2;
    p_field[row_num + 1][col_num + 4] = ch2;
    p_field[row_num + 1][col_num + 5] = ch2;

    p_field[row_num + 2][col_num] = ch2;
    p_field[row_num + 2][col_num + 2] = ch2;
    p_field[row_num + 2][col_num + 3] = ch2;
    p_field[row_num + 2][col_num + 4] = ch2;
    p_field[row_num + 2][col_num + 6] = ch2;

    p_field[row_num + 3][col_num] = ch2;
    p_field[row_num + 3][col_num + 3] = ch2;
    p_field[row_num + 3][col_num + 6] = ch2;
    // legs
    p_field[row_num + 4][col_num + 2] = ch2;
    p_field[row_num + 4][col_num + 3] = ch2;
    p_field[row_num + 4][col_num + 4] = ch2;

    p_field[row_num + 5][col_num + 1] = ch2;
    p_field[row_num + 5][col_num + 5] = ch2;

    p_field[row_num + 6][col_num + 1] = ch2;
    p_field[row_num + 6][col_num + 5] = ch2;

    p_field[row_num + 7][col_num] = ch2;
    p_field[row_num + 7][col_num + 1] = ch2;
    p_field[row_num + 7][col_num + 5] = ch2;
    p_field[row_num + 7][col_num + 6] = ch2;


}

void person1(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2)
{
    p_field[row_num][col_num + 2] = ch;
    p_field[row_num][col_num + 3] = ch2;
    p_field[row_num][col_num + 4] = ch1;

    p_field[row_num + 1][col_num + 1] = ch2;
    p_field[row_num + 1][col_num + 2] = ch2;
    p_field[row_num + 1][col_num + 3] = ch2;
    p_field[row_num + 1][col_num + 4] = ch2;
    p_field[row_num + 1][col_num + 5] = ch2;

    p_field[row_num + 2][col_num] = ch2;
    p_field[row_num + 2][col_num + 2] = ch2;
    p_field[row_num + 2][col_num + 3] = ch2;
    p_field[row_num + 2][col_num + 4] = ch2;
    p_field[row_num + 2][col_num + 6] = ch2;

    p_field[row_num + 3][col_num] = ch2;
    p_field[row_num + 3][col_num + 3] = ch2;
    p_field[row_num + 3][col_num + 6] = ch2;

    p_field[row_num + 4][col_num + 2] = ch2;
    p_field[row_num + 4][col_num + 3] = ch2;
    p_field[row_num + 4][col_num + 4] = ch2;

    p_field[row_num + 5][col_num + 1] = ch2;
    p_field[row_num + 5][col_num + 5] = ch2;

    p_field[row_num + 6][col_num + 1] = ch2;
    p_field[row_num + 6][col_num + 5] = ch2;

    p_field[row_num + 7][col_num] = ch2;
    p_field[row_num + 7][col_num + 1] = ch2;
    p_field[row_num + 7][col_num + 5] = ch2;
    p_field[row_num + 7][col_num + 6] = ch2;


}

