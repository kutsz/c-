
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
#include <thread>


using namespace std;

int main()
{

    int rows = 42; //42
    int cols = 150; //150

    bool flag = true;
    char ch = ' ';

    int rowNumStart = 33;
    int colNumStart = 1;
    int step_rt_lt = colNumStart;
    int step_up_dn = rowNumStart;
    //int count = 0;
    //bool fg = true;
    //const int lim_dn = 9;
    //const int lim_rt = 9;
    //const int lim_up = 1;
    const int dist_up = 1;
    const int dist_rt = 8;
    const int dist_dn = 8;
    const int dist_lt = 1;
    int ht = 10;
    int rt_lth = 4;
    int step_lth = 1;
    char ch_X = 'X';

    const int obst_dist_rt = 10;


    char **p_field = creat_field(rows, cols);
    init(p_field, rows, cols);

    obstacles_horiz(p_field, rowNumStart + 5, colNumStart + 20, obst_dist_rt, 'X');
    obstacles_horiz(p_field, rowNumStart + 3, colNumStart + 40, obst_dist_rt, 'X');
    obstacles_horiz(p_field, rowNumStart, colNumStart + 60, obst_dist_rt, 'X');
    obstacles_horiz(p_field, rowNumStart - 10, colNumStart + 60, obst_dist_rt, 'X');
    obstacles_horiz(p_field, rowNumStart - 3, colNumStart + 80, obst_dist_rt, 'X');
    obstacles_vert(p_field, rowNumStart + 3, colNumStart + 100, 5, 'X');

    obstacles(p_field, '@', 38, 10);

    //        test_checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, 'X');
    //        test_checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X');
    //        test_checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, 0, 'X');
    //        test_checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X');

    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    show_field(p_field, rows, cols);

    menu();

    while (flag)
    {
        cin >> ch;
        //ch = getch();
        //ch = getchar();
        //cin.get(ch);

        switch (ch) {

                // moving left
            case 'a':
            {
                if (checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_lt, 'X') &&
                        !checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X'))
                {
                    person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                    person_lt(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                    system("clear");
                    show_field(p_field, rows, cols);
                    //sleep(1);
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));

                    person_lt(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
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
                    person_rt(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                    system("clear");
                    show_field(p_field, rows, cols);

                    //sleep(1);
                    std::this_thread::sleep_for(std::chrono::milliseconds(500));

                    person_rt(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                    move_Rt(step_rt_lt, 1);
                    person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                }
                break;
            }
                // jump up, down
            case 'w':
            {
                //sit down to move up
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                // move up
                jump_Up(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_up, dist_rt, ch_X);

                system("clear");
                show_field(p_field, rows, cols);

                // sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));

                // move down
                jump_Dn1(p_field, step_up_dn, step_rt_lt, step_lth, dist_dn, dist_rt, ch_X);

                //sit down 
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                // stand up
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                break;
            }


                // jumping up, forward, down 
            case 's':
            {
                //sit down to move up
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                //move up forward
                jump_Up_fd(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_up, dist_dn, dist_rt, ch_X);

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                //move down forward
                jump_Dn_Fd(p_field, step_up_dn, step_rt_lt, step_lth, dist_dn, dist_rt, ch_X);

                //sit down 
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                // stand up
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                break;
            }
                // jumping up, back, down 
            case 'z':
            {
                //sit down to move up
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                //move up back
                jump_Up_Bc(p_field, step_up_dn, step_rt_lt, ht, step_lth, dist_up, dist_dn, dist_rt, dist_lt, ch_X);

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                //move down back
                jump_Dn_Bc(p_field, step_up_dn, step_rt_lt, step_lth, dist_dn, dist_rt, dist_lt, ch_X);

                //sit down 
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                //stand up
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);
                break;
            }
            case 'x':
            {
                //sit down to move up
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');




                //
                //jump_Up_mvFd(p_field, step_up_dn, step_rt_lt, ht, rt_lth, step_lth, dist_up, dist_dn, dist_rt, ch_X);
                jump_Up_mvBc(p_field, step_up_dn, step_rt_lt, ht, rt_lth, step_lth, dist_up, dist_dn, dist_rt, dist_lt, ch_X);

                //sit down 
                //person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                // person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                //                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                //
                //                //stand up
                //                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                //
                //                system("clear");
                //                show_field(p_field, rows, cols);

                break;
            }
            case 'c':
            {
                //sit down to move up
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');




                //
                jump_Up_mvFd(p_field, step_up_dn, step_rt_lt, ht, rt_lth, step_lth, dist_up, dist_dn, dist_rt, ch_X);
                //jump_Up_mvBc(p_field, step_up_dn, step_rt_lt, ht, rt_lth, step_lth, dist_up, dist_dn, dist_rt, dist_lt, ch_X);

                //sit down 
                //person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                // person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                //                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                //
                //                //stand up
                //                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
                //
                //                system("clear");
                //                show_field(p_field, rows, cols);

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

        // movin down if no obstacles
        while (checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X'))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Dn(step_up_dn, 1);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

            if (!(checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, 'X')))
            {
                //sit down 
                person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
                person_mv_jp(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                system("clear");
                show_field(p_field, rows, cols);

                //sleep(1);
                std::this_thread::sleep_for(std::chrono::milliseconds(300));

                person_mv_jp(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');

                // stand up
                person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

                //                system("clear");
                //                show_field(p_field, rows, cols);
            }
        }

        system("clear");
        show_field(p_field, rows, cols);

        menu();

    }

    del_field(p_field, rows);

    return 0;
}

