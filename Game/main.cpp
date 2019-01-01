
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
//#include <ncursesw/ncurses.h>


using namespace std;

int main()
{

    int rows = 42; //42
    int cols = 150; //150

    int rowNum = 33;
    int colNum = 4;

    bool flag = true;
    char ch = ' ';
    int step_rt_lt = colNum;
    int step_up_dn = rowNum;
    //int count = 0;
    //bool fg = true;
    const int lim_dn = 9;
    const int lim_rt = 9;
    const int lim_up = 1;
    const int dist_up = 1;
    const int dist_rt = 8;
    const int dist_dn = 8;
    const int dist_lt = 1;
    int ht = 10;
    int step_lth = 1;
    char ch_X = 'X';

    const int obst_dist_rt = 10;


    char **p_field = creat_field(rows, cols);
    init(p_field, rows, cols);

    //obstacles_horiz(p_field, rowNum - 3, colNum, obst_dist_rt, 'X');
    //obstacles_vert(p_field, rowNum - 2, colNum, dist_dn, 'X');

    //    test_checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, 'X');
    //    test_checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X');
    //    test_checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, 0, 'X');
    //    test_checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X');

    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    show_field(p_field, rows, cols);

    while (flag)
    {
        cin >> ch;
        //ch = getch();
        //ch = getchar();
        //cin.get(ch);

        switch (ch) {
                // moving up
            case 'w':
            {

                if (checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, 'X'))
                {
                    person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                    //step_up_dn = move_up(step_up_dn, lim_up);
                    move_Up(step_up_dn, 1);
                    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                }


                //                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                //                move_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, 'X');
                //
                //                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                break;
            }
                // moving down
            case 'z':
            {
                if (checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X'))
                {
                    person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                    move_Dn(step_up_dn, 1);
                    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                }
                break;
            }
                // moving left
            case 'a':
            {
                if (checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_lt, 'X') &&
                        !checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X'))
                {
                    person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                    //step_rt_lt = move_lt(step_rt_lt, 2);
                    person_lt(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                    system("clear");
                    show_field(p_field, rows, cols);
                    sleep(1);
                    //usleep(500);
                    person_lt(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                    //step_rt_lt = move_lt(step_rt_lt, 4, 3);
                    //move_lt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_lt, 'X', 1);
                    move_Lt(step_rt_lt, 1);
                    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                }
                break;
            }
                //moving right
            case 'd':
            {
                if (checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X') &&
                        !checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X'))
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
                    //step_rt_lt = move_rt(step_rt_lt, cols, lim_rt, 3);
                    //move_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X', 3);
                    move_Rt(step_rt_lt, 1);
                    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                }
                break;
            }
                // jump up, down
            case 's':
            {
                ////jump_up(p_field, step_up_dn, step_rt_lt, rows, 10, lim_up);
                jump_Up(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_up, dist_rt, ch_X);
                system("clear");
                show_field(p_field, rows, cols);
                sleep(1);
                ////jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10, lim_dn);
                //jump_Dn(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_dn, dist_rt, ch_X);
                jump_Dn1(p_field, step_up_dn, step_rt_lt, step_lth, dist_dn, dist_rt, ch_X);
                system("clear");
                show_field(p_field, rows, cols);

                break;
            }

            case 'c':
            {
                //jump_up(p_field, step_up_dn, step_rt_lt, rows);
                jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10, lim_dn);

                break;
            }
                // jumping up, forward, down 
            case 'x':
            {
                ////jump_up_fd(p_field, step_up_dn, step_rt_lt, cols, 10, lim_rt);
                jump_Up_fd(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_up, dist_dn, dist_rt, ch_X);
                system("clear");
                show_field(p_field, rows, cols);
                sleep(1);
                ////jump_dn_fd(p_field, step_up_dn, step_rt_lt, cols, rows, 10);
                //jump_Dn_fd(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_dn, dist_rt, ch_X);
                jump_Dn_fd1(p_field, step_up_dn, step_rt_lt, step_lth, dist_dn, dist_rt, ch_X);
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
                jump_dn(p_field, step_up_dn, step_rt_lt, rows, 10, lim_dn);

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

        system("clear");
        show_field(p_field, rows, cols);

    }

    del_field(p_field, rows);

    return 0;
}

