#include <vector>
#include <list>
#include <deque>
#include <algorithm>
#include<iostream>
using namespace std;

void show(deque<deque<int> >W);
//void Rotate (deque<deque<int> >W, int size);/////////////
void show1(deque<deque<int> > W, int size);

int main()
{

    int size = 10;
    deque<deque<int> >W(size);

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
            W[i].push_back(j * i);

    show(W);
    ////....................................................................
    char ch;
    cout << "enter  w,a,d,z   or q to quit" << endl;
    bool flag = true;
    //while (ch != 'q' && cin >> ch)
    while (flag)
    {
        //cout << "enter  w,a,d,z   or q to quit" << endl;
        cin >> ch;

        switch (ch) {
            case'w':
                system("clear");
                rotate(W.begin(), W.begin() + 1, W.end());
                show(W);
                break;
            case'a':
                system("clear");
                for (int i = 0; i < size; i++)
                    rotate(W[i].begin(), W[i].begin() + 1, W[i].end());
                show(W);
                break;
            case'd':
                system("clear");
                for (int i = 0; i < size; i++)
                    rotate(W[i].rbegin(), W[i].rbegin() + 1, W[i].rend());
                show(W);
                break;
            case'z':
                system("clear");
                rotate(W.rbegin(), W.rbegin() + 1, W.rend());
                show(W);
                break;
            case'q':
                flag = false;
                break;
            default:
                //cout << "enter  w,a,d,z   or q to quit" << endl;
                cout << "Oops" << endl;
        }
        if(flag)
        cout << "enter  w,a,d,z   or q to quit" << endl;
    }


    return 0;
}

//void Rotate (deque<deque<int> >W, int size)
//{
//    for (int i = 0; i < size; i++)
//    rotate (W[i].begin(), W[i].begin() + 1, W[i].end());
//}

void show(deque<deque<int> >W)
{
    deque<int>::iterator it_c1;
    deque<deque<int> >::iterator it_r1;
    for (it_r1 = W.begin(); it_r1 != W.end(); it_r1++)
    {
        for (it_c1 = it_r1->begin(); it_c1 != it_r1->end(); it_c1++)
        {
            cout.width(4);
            cout << *it_c1;
        }
        cout << endl;
    }
    cout << endl;
}

void show1(deque<deque<int> >W, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout.width(4);
            cout << W[i][j];
        }
        cout << endl;
    }
    cout << endl;

}