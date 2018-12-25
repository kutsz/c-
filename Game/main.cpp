
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

    char **p_field = creat_field(rows, cols);
    init(p_field, rows, cols);


    int rowNum = 33;
    int colNum = 4;

    person(p_field, rowNum, colNum, '(', ')', '#');
    show_field(p_field, rows, cols);


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

        system("clear");
        show_field(p_field, rows, cols);

    }

    del_field(p_field, rows);

    return 0;
}

