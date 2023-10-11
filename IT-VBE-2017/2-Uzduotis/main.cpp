#include <iostream>
#include <fstream>

struct Staciakampis
{
    int x, y;
    int dx, dy;
    int R, G, B;
};
struct Langelis
{
   int R = 255;
   int G = 255;
   int B = 255;
};
void uzdeti_staciakampi(int i, int n, Langelis langelis[100][100], Staciakampis staciakampis[])
{
    int x = staciakampis[i].x;
    int y = staciakampis[i].y;
    int dx= staciakampis[i].dx;
    int dy= staciakampis[i].dy;
    for(int j = y; j < dy + y; ++j)
    {
        for(int k = x; k < dx+x; ++k)
        {
            if(k <= dx && j <= dy) // sitas nera reikalingas
            {
                langelis[j][k].R = staciakampis[i].R; // nupiesame staciakampi ant lenteles
                langelis[j][k].G = staciakampis[i].G;
                langelis[j][k].B = staciakampis[i].B;
            }
        }
    }
}
int main()
{
    Staciakampis staciakampis[100];
    int n; // staciakampiu skaicius
    std::ifstream fin;
    fin.open("U2.txt");
    fin >> n;
    for(int i = 0; i < n; ++i)
    {
        fin >> staciakampis[i].x >> staciakampis[i].y
        >> staciakampis[i].dx >> staciakampis[i].dy
        >> staciakampis[i].R >> staciakampis[i].G
        >> staciakampis[i].B;
    }

    Langelis langelis[100][100]; // sukuriame 100*100 piesini
    for(int i = 0; i < n; ++i)
    {
        uzdeti_staciakampi(i, n, langelis, staciakampis); // uzdedam staciakampi
    }
    int max_x = 0;
    int max_y = 0;
    for(int i = 0; i < n; ++i)
    {
        int x = staciakampis[i].x;
        int dx = staciakampis[i].dx;
        max_x  = (max_x < (x + dx) ?  (x + dx) : max_x); // surandam max_x naudojant ternary operation  (condition ? true : false)

        int y = staciakampis[i].y;
        int dy = staciakampis[i].dy;

        max_y  = (max_y < (y + dy) ?  (y + dy) : max_y); // surandam max_y naudojant ternary operation  (condition ? true : false)
    }

    std::ofstream fout;
    fout.open("U2rez.txt");
    fout << max_y << " " << max_x << std::endl;
    for(int j = 0; j < max_y; ++j)
    {
        for(int i = 0; i < max_x; ++i)
        {
            fout << langelis[j][i].R << ' ' <<langelis[j][i].G << ' ' <<langelis[j][i].B << std::endl; // spausdinam langeliu R G B reiksmes
        }
    }

    return 0;
}
