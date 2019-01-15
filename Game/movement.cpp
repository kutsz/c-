#include "movement.h"
#include "person.h"
#include "field.h"

void move_Rt(int& step_rt_lt, int step_lth)
{
    step_rt_lt = step_rt_lt + step_lth;

}

int move_rt(int j, int cols, int lim_rt, int step)
{
    //j = (j < cols - 9) ? ++j : j;
    j = (j < cols - lim_rt) ? (j + step) : j;
    return j;

}

void move_rt(char **p_field, int& row_num, int& col_num, int dist_dn, int dist_rt, char ch, int step)
{

    if (checkPath_rt(p_field, row_num, col_num, dist_dn, dist_rt, ch))
        col_num = col_num + step;
}

void move_Lt(int& step_rt_lt, int step_lth)
{
    step_rt_lt = step_rt_lt - step_lth;
}

int move_lt(int j, int num, int step)
{
    //j = (j > num) ? --j : j;
    j = (j > num) ? (j - step) : j;
    return j;
}

void move_lt(char **p_field, int& row_num, int& col_num, int dist_dn, int dist_lt, char ch, int step)
{

    //if (col_num > num && checkPath_lt(p_field,row_num,col_num, dist_dn,dist_lt,ch))
    if (checkPath_lt(p_field, row_num, col_num, dist_dn, dist_lt, ch))
        col_num = col_num - step;

}

void move_Up(int& step_up_dn, int step_lth)
{
    step_up_dn = step_up_dn - step_lth;
}

int move_up(int i, int lim_up)
{
    i = (i > lim_up) ? --i : i;
    return i;
}

void move_up(char **p_field, int& row_num, int& col_num, int dist_up, int dist_rt, char ch)
{
    //    if (row_num > lim_up && checkPath_up(p_field, row_num, col_num, dist_up, dist_rt, ch))
    if (checkPath_up(p_field, row_num, col_num, dist_up, dist_rt, ch))
        --row_num;

}

void move_Dn(int& step_up_dn, int step_lth)
{
    step_up_dn = step_up_dn + step_lth;
}

int move_dn(int i, int rows, int lim_dn)
{
    i = (i < rows - lim_dn) ? ++i : i;
    return i;
}
//bool checkPath_up(char **p_field, int row_num, int col_num, int dist_up, int dist_rt, char ch) //TODO

void jump_Up(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_up, int dist_rt, char ch)
{
    for (int i = 0; i < ht; i++)
    {
        if (checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Up(step_up_dn, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
}

void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim_up)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_up_dn = move_up(step_up_dn, lim_up);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

    }
}

void jump_Dn1(char **p_field, int& step_up_dn, int& step_rt_lt, int step_lth, int dist_dn, int dist_rt, char ch)
{
    while (checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch))
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        move_Dn(step_up_dn, step_lth);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }
}

//bool checkPath_dn(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch)
//void move_Dn(int& step_up_dn, int step_lth)

void jump_Dn(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_dn, int dist_rt, char ch)
{
    for (int i = 0; i < ht; i++)
    {
        if (checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Dn(step_up_dn, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
}

void jump_dn(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim_dn)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_up_dn = move_dn(step_up_dn, rows, lim_dn);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }
}

void jump_Up_Bc(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_up, int dist_dn, int dist_rt, int dist_lt, char ch)
{
    for (int i = 0; i < ht; i++)
    {
        if (checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, ch) &&
                checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_lt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Up(step_up_dn, step_lth);
            move_Lt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
}


void jump_Up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_up, int dist_dn, int dist_rt, char ch)
{
    for (int i = 0; i < ht; i++)
    {
        if (checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, ch) &&
                checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Up(step_up_dn, step_lth);
            move_Rt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
}

void jump_Up_mvFd(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int rt_lth, int step_lth, int dist_up, int dist_dn, int dist_rt, char ch)
{

    for (int i = 0; i < ht; i++)
    {
        if (checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Up(step_up_dn, step_lth);
            //move_Rt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
    for (int i = 0; i < rt_lth; i++)
    {

        if (checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            //move_Up(step_up_dn, step_lth);
            move_Rt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }

}

void jump_Up_mvBc(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int rt_lth, int step_lth, int dist_up, int dist_dn, int dist_rt, int dist_lt, char ch)
{

    for (int i = 0; i < ht; i++)
    {
        if (checkPath_up(p_field, step_up_dn, step_rt_lt, dist_up, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Up(step_up_dn, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
    for (int i = 0; i < rt_lth; i++)
    {

        if (checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_lt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Lt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }

}

void jump_Dn_Bc(char **p_field, int& step_up_dn, int& step_rt_lt, int step_lth, int dist_dn, int dist_rt, int dist_lt, char ch)
{
    while (checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch)) // check down
    {
        if (checkPath_lt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_lt, ch)) // check left
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Lt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        move_Dn(step_up_dn, step_lth);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

    }

}

void jump_Dn_Fd(char **p_field, int& step_up_dn, int& step_rt_lt, int step_lth, int dist_dn, int dist_rt, char ch)
{
    while (checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch)) // check down
    {
        if (checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch)) // check right
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Rt(step_rt_lt, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        move_Dn(step_up_dn, step_lth);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

    }

}

void jump_Dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int ht, int step_lth, int dist_dn, int dist_rt, char ch)
{
    for (int i = 0; i < ht; i++)
    {
        if (checkPath_rt(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch) &&
                checkPath_dn(p_field, step_up_dn, step_rt_lt, dist_dn, dist_rt, ch))
        {
            person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
            move_Rt(step_rt_lt, step_lth);
            move_Dn(step_up_dn, step_lth);
            person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
        }
    }
}

void jump_dn_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int rows, int ht)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_rt_lt = move_rt(step_rt_lt, cols, 9, 1);
        step_up_dn = move_dn(step_up_dn, rows, 9);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }
}

