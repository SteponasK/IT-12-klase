#include <iostream>
#include <fstream>

int n{}; // juosteliu kruveliu skaicius


struct Veliavele // veliavele (kruvele) turi spalva ir kieki
{
    char spalva;
    int kiekis = 0;
};
Veliavele veliavele[3]; // 3 spalvos

void skaityti()
{
    std::ifstream fin;
    fin.open("U1.txt");
    fin >> n;

    veliavele[0].spalva = 'G'; // sukuriame spalvas
    veliavele[1].spalva = 'Z';
    veliavele[2].spalva = 'R';

    for(int i = 0; i < n; ++i)
    {
        char spalva;
        fin >> spalva;
        for(int j = 0; j < 3; ++j) // pridedame juosteliu kieki prie atitinkamos veliaveles strukturos
        {
            if(spalva == veliavele[j].spalva)
            {
                int kiekis;
                fin >> kiekis;
                veliavele[j].kiekis+=kiekis;
            }
        }

    }
}
int pagaminta = 0; // pagamintu veliaveliu skaicius
void skaiciuoti()
{
    while(veliavele[0].kiekis >=2 && veliavele[1].kiekis >=2 && veliavele[2].kiekis >=2)
    {
        ++pagaminta;
        veliavele[0].kiekis-=2;
        veliavele[1].kiekis-=2;
        veliavele[2].kiekis-=2;
    }
}
void spausdinti()
{
    std::ofstream fout;
    fout.open("U1rez.txt");
    fout << pagaminta << std::endl;
    fout << "G = " << veliavele[0].kiekis << std::endl;
    fout << "Z = " << veliavele[1].kiekis << std::endl;
    fout << "R = " << veliavele[2].kiekis << std::endl;
}
int main()
{
    skaityti();
    skaiciuoti();
    spausdinti();
    return 0;
}
