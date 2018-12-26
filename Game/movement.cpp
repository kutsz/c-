#include "movement.h"
#include "person.h"

int move_rt(int j, int cols, int lim_rt, int step)
{
    //j = (j < cols - 9) ? ++j : j;
    j = (j < cols - lim_rt) ? (j + step) : j;
    return j;

}

int move_lt(int j, int num, int step)
{
    //j = (j > num) ? --j : j;
    j = (j > num) ? (j - step) : j;


    return j;
}

int move_up(int i, int lim_up)
{
    i = (i > lim_up) ? --i : i;
    return i;
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

