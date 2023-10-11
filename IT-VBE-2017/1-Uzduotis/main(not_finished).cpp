#include <iostream>
#include <fstream>
#include <vector>

struct Langelis
{
    int R, G, B;
    std::string skaicius;
};
std::string konvertuoti(int R, int G, int B)
{
    std::string skaicius = "wdafegwgwg";
    char r_1 = static_cast<int>(R/16) ;
    char r_2 = static_cast<int>(R%16);
    char g_1 = static_cast<int>(G/16) ;
    char g_2 = static_cast<int>(G%16);
    char b_1 = static_cast<int>(B/16) ;
    char b_2 = static_cast<int>(B%16);
    switch(r_1)
    {
    case 10:
        r_1 = 'A';
        break;
    case 11:
        r_1 = 'B';
        break;
    case 12:
        r_1 = 'C';
        break;
    case 13:
        r_1 = 'D';
        break;
    case 14:
        r_1 = 'E';
        break;
    case 15:
        r_1 = 'F';
        break;
    default:
        r_1--;
    }
    switch(r_2)
    {
    case 10:
        r_2 = 'A';
        break;
    case 11:
        r_2 = 'B';
        break;
    case 12:
        r_2 = 'C';
        break;
    case 13:
        r_2 = 'D';
        break;
    case 14:
        r_2= 'E';
        break;
    case 15:
        r_2 = 'F';
        break;
    default:
        r_2--;
    }

    switch(g_1)
    {
    case 10:
        g_1 = 'A';
        break;
    case 11:
        g_1 = 'B';
        break;
    case 12:
        g_1 = 'C';
        break;
    case 13:
        g_1 = 'D';
        break;
    case 14:
        g_1 = 'E';
        break;
    case 15:
        g_1 = 'F';
        break;
    default:
        g_1--;
    }
    switch(g_2)
    {
    case 10:
        g_2 = 'A';
        break;
    case 11:
        g_2 = 'B';
        break;
    case 12:
        g_2 = 'C';
        break;
    case 13:
        g_2 = 'D';
        break;
    case 14:
        g_2= 'E';
        break;
    case 15:
        g_2 = 'F';
        break;
    default:
        g_2--;
    }

    switch(b_1)
    {
    case 10:
        b_1 = 'A';
        break;
    case 11:
        b_1 = 'B';
        break;
    case 12:
        b_1 = 'C';
        break;
    case 13:
        b_1 = 'D';
        break;
    case 14:
        b_1 = 'E';
        break;
    case 15:
        b_1 = 'F';
        break;
    default:
        b_1--;
    }
    switch(b_2)
    {
    case 10:
        b_2 = 'A';
        break;
    case 11:
        b_2 = 'B';
        break;
    case 12:
        b_2 = 'C';
        break;
    case 13:
        b_2 = 'D';
        break;
    case 14:
        b_2= 'E';
        break;
    case 15:
        b_2 = 'F';
        break;
    default:
        b_2--;
    }
    //std::cout << r_1 << std::endl;
    skaicius = static_cast<std::string>(r_1) + static_cast<std::string>(r_2)
    + static_cast<std::string>(g_1) + static_cast<std::string>(g_2)
    + static_cast<std::string>(b_1) + static_cast<std::string>(b_2);
    std::cout << skaicius << std::endl;
    return skaicius;
}
int main()
{
    int a, b;
    std::ifstream fin;
    fin.open("U1.txt");
    fin >> a >> b;

    Langelis langelis[a][b];
    for(int i = 0; i < a; ++i)
    {
        for(int j = 0; j < b; ++j)
        {
            fin >> langelis[i][j].R;
            fin >> langelis[i][j].G;
            fin >> langelis[i][j].B;
            langelis[i][j].skaicius = konvertuoti(langelis[i][j].R, langelis[i][j].G, langelis[i][j].B);
        }
    }

    return 0;
}
