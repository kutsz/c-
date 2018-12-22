//#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    /*
    int num = 26;
    char ch_arr[num] = {' '};
    char l = 'a';
    for (int i = 0; i < num; i++)
    {
        ch_arr[i] = l;
        l++;
    }

    for (int i = 0; i < num; i++)
    {
        cout << ch_arr[i] << " ";

    }

    cout << endl;
     */

    int n = 0;
    std::cout << " Enter number (type 'int'): ";
    std::cin >> n;
    std::cout << std::endl;

    n = n * 2 - 1;

    char ch = 'a';
    bool flag = true;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i % 2 == 0)
            {

                if ((j < (n / 2 - i / 2)) || (j > (n / 2 + i / 2)))
                {
                    std::cout << " ";

                } else
                {
                    if (ch == 'z')
                        flag = false;
                    if (ch == 'a')
                        flag = true;
                    
                    if (flag)
                    {
                        cout << ch;
                        ch = ch + 1;
                    } else
                    {
                        cout << ch;
                        ch = ch - 1;
                    }
                }
            } else
            {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl << std::endl;


    return 0;
}

