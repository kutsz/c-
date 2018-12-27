#include "movement.h"
#include "person.h"
#include "field.h"

int move_rt(int j, int cols, int lim_rt, int step)
{
    //j = (j < cols - 9) ? ++j : j;
    j = (j < cols - lim_rt) ? (j + step) : j;
    return j;

}
//bool checkPath_rt(char **p_field, int row_num, int col_num, int dist_dn, int dist_rt, char ch)


int move_lt(int j, int num, int step)
{
    //j = (j > num) ? --j : j;
    j = (j > num) ? (j - step) : j;


    return j;
}
//bool checkPath_lt(char **p_field, int row_num, int col_num, int dist_dn, int dist_lt, char ch)

void move_lt(char **p_field, int& row_num, int& col_num, int dist_dn, int dist_lt, char ch, int num, int step)
{

    //if (col_num > num && checkPath_lt(p_field,row_num,col_num, dist_dn,dist_lt,ch))
        if (checkPath_lt(p_field,row_num,col_num, dist_dn,dist_lt,ch))
        col_num = col_num - step;

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

int move_dn(int i, int rows, int lim_dn)
{
    i = (i < rows - lim_dn) ? ++i : i;
    return i;
}

void jump_up(char **p_field, int& step_up_dn, int& step_rt_lt, int rows, int ht, int lim_up)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_up_dn = move_up(step_up_dn, lim_up);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');

        ////system("clear");
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

void jump_up_fd(char **p_field, int& step_up_dn, int& step_rt_lt, int cols, int ht, int lim_rt)
{
    for (int i = 0; i < ht; i++)
    {
        person(p_field, step_up_dn, step_rt_lt, ' ', ' ', ' ');
        step_rt_lt = move_rt(step_rt_lt, cols, lim_rt, 1);
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
        step_up_dn = move_dn(step_up_dn, rows, 9);
        person(p_field, step_up_dn, step_rt_lt, '(', ')', '#');
    }

}

