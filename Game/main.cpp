
/* 
 * File:   main.cpp
 * Author: valentine
 *
 * Created on 30 ноября 2018 г., 14:30
 */

#include <cstdlib>
#include <iostream>
#include <unistd.h> // for sleep(sek) ,  usleep(msek)  1/1000
#include "field.h"
#include "person.h"
#include "movement.h"
////#include <ncursesw/curses.h>
//#include <ncursesw/ncurses.h>
//#include <cstdio>
//#include <stdio.h>
//#include <iomanip>


using namespace std;

//void show_field(char **p_field, int rows, int cols);
//void del_field(char **p_field, int rows);
//void init(char **p_field, int rows, int cols);
//char **creat_field(int rows, int cols);

//void obstacles(char **p_field, char ch);
//void danger(char **p_field, int row, int col, char ch);

//void person(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2);
//void person1(char **p_field, int row_num, int col_num, char ch, char ch1, char ch2);

////int move_rt(int j, int cols);
//int move_rt(int j, int cols, int lim, int step);
////int move_lt(int j, int num);
//int move_lt(int j, int num, int step);
//int move_up(int i, int num);
//int move_dn(int i, int rows);
//
//void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht);
//void jump_dn(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht);
//void jump_up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int ht);
//void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht);

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
                //step_rt_lt = move_lt(step_rt_lt, 2);
                person_lt(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                system("clear");
                show_field(p_field, rows, cols);
                sleep(1);
                //usleep(500);
                person_lt(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                step_rt_lt = move_lt(step_rt_lt, 4, 3);
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                break;
            }
            case 'd':
            {

                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                // step_rt_lt = move_rt(step_rt_lt, cols);

                person_rt(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                system("clear");
                show_field(p_field, rows, cols);
                //sleeping(1000000);
                sleep(1);
                //usleep(500);
                person_rt(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                step_rt_lt = move_rt(step_rt_lt, cols, 9, 3);
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                break;
            }

            case 's':
            {
                jump_up(p_field, step_up_dn, step_rt_lt, rows, 10);
                system("clear");
                show_field(p_field, rows, cols);
                sleep(1);
                jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10);
                system("clear");
                show_field(p_field, rows, cols);

                break;
            }

            case 'c':
            {
                //jump_up(p_field, step_up_dn, step_rt_lt, rows);
                jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10);

                break;
            }

            case 'x':
            {
                jump_up_fd(p_field, step_up_dn, step_rt_lt, cols, 10);
                system("clear");
                show_field(p_field, rows, cols);
                sleep(1);
                jump_dn_fd(p_field, step_up_dn, step_rt_lt, cols, rows, 10);
                system("clear");
                show_field(p_field, rows, cols);
                break;
            }

            case 'b':
            {
                //// jump_up_fd(p_field, step_up_dn, step_rt_lt, cols, 10);
                jump_dn_fd(p_field, step_up_dn, step_rt_lt, cols, rows, 10);
                break;
            }
            case 'n':
            {
                //jump_up(p_field, step_up_dn, step_rt_lt, rows);
                jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10);

                break;
            }
            case ';':
            {
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_lt(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
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
        //obstacles(p_field, '@');
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

/*
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
 */
/*
int move_rt(int j, int cols, int lim, int step)
{
    //j = (j < cols - 9) ? ++j : j;
    j = (j < cols - lim) ? (j + step) : j;
    return j;

}

int move_lt(int j, int num, int step)
{
    //j = (j > num) ? --j : j;
    j = (j > num) ? (j - step) : j;


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
*/
/*
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
    while (true)
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
 */
/*
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
        step_rt_lt = move_rt(step_rt_lt, cols, 9, 1);
        step_up_dn = move_up(step_up_dn, 1);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }

}

void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_rt_lt = move_rt(step_rt_lt, cols, 9, 1);
        step_up_dn = move_dn(step_up_dn, rows);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }

}
*/
/*
    (#)
   #####
  # ### #   
  #  #  #
    ###
   #   #
   #   #
  ##   ##
 
 
 */
/*
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
 */

/*
          
    (#)
   ##### #
  # ### #   
   # # 
    # ###
    #  #
    #  ##
    ##  
 
 */
/*
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
    p_field[row_num + 1][col_num + 7] = ch2;

    p_field[row_num + 2][col_num] = ch2;
    p_field[row_num + 2][col_num + 2] = ch2;
    p_field[row_num + 2][col_num + 3] = ch2;
    p_field[row_num + 2][col_num + 4] = ch2;
    p_field[row_num + 2][col_num + 6] = ch2;

    p_field[row_num + 3][col_num + 1] = ch2;
    p_field[row_num + 3][col_num + 3] = ch2;


    p_field[row_num + 4][col_num + 2] = ch2;
    p_field[row_num + 4][col_num + 4] = ch2;
    p_field[row_num + 4][col_num + 5] = ch2;
    p_field[row_num + 4][col_num + 6] = ch2;

    p_field[row_num + 5][col_num + 2] = ch2;
    p_field[row_num + 5][col_num + 5] = ch2;

    p_field[row_num + 6][col_num + 2] = ch2;
    p_field[row_num + 6][col_num + 5] = ch2;
    p_field[row_num + 6][col_num + 6] = ch2;

    p_field[row_num + 7][col_num + 2] = ch2;
    p_field[row_num + 7][col_num + 3] = ch2;



}
 */
