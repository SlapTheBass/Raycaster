#include <iostream>
#include <fstream>

int main()
{
    std::ofstream outdata;

    outdata.open("level.lv");

    int data[60][60];

    for (int i = 0; i < 60; ++i)
    {
        for (int j = 0; j < 60; ++j)
        {
            data[i][j] = 0;
            
            if (i == 0)
                data[i][j] = 1;

            else if (j == 0)
                data[i][j] = 1;

            else if (i == 59)
                data[i][j] = 1;

            else if (j == 59)
                data[i][j] = 1;

            outdata << data[i][j];
            if (j == 59)
                outdata << std::endl;
        }
    }

    outdata.close();
}