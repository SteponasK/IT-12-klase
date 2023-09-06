#include <iostream>
#include <fstream>

using namespace std;
bool ArSpes(int atv_diena, int atv_val, int atv_min, int ds, int v, int m); // Funkcijos Deklaracija

int main()
{
    ifstream failasIN; // Input failas (gauname duomenis)
    failasIN.open("Duomenys.txt");
    int ds, v, m; //numatona susitikimo data (diena/val/min)
    int a, b, c; // isvykimo laikas (diena/val/min)
    int d, e; // keliones trukme (val/min)
    failasIN >> a >> b >> c >> d >> e >> ds >> v >> m; // nuskaitau duomenis

    int atv_diena = a; //atvykimo diena (kolkas ta pati)
    int atv_val = 0; // atvykimo valanda
    int  atv_min = 0; // atvykimo minutes

    // sutvarkom minutes
    atv_min = c+e;
    while(atv_min >= 60) // kol minuciu daugiau nei 60
        {
            atv_min -= 60;//atemam 60 minuciu
            atv_val++;//pridedam valanda
        }

    // sutvarkom valandas ir dienas
    atv_val += (b+d);
        while(atv_val >=24) // kol valandu daugiau nei 60
        {
            atv_val -= 24; // atemam 24 valandas
            atv_diena++; // pridedam diena
        }


    ofstream failasOUT; // atidarom output file
    failasOUT.open("Rezultatai.txt");
    failasOUT << atv_diena << ' '<< atv_val << ' ' << atv_min; // i "Rezultatai.txt" atspausdinam atvykimo data
    if(ArSpes(atv_diena, atv_val, atv_min, ds, v, m) == true) // jeigu spes
    {
        failasOUT << std::endl << "TAIP";
    }
    else
    {
        failasOUT << std::endl << "NE";
    }


    return 0; // baigiasi programa
}
bool ArSpes(int atv_diena, int atv_val, int atv_min, int ds, int v, int m) // funkcija
{
    if(atv_diena > ds || atv_val > v || (atv_min > m && atv_val >= v) ) // jeigu atvykimo data velesne uz planuojama data
    {
        return false; //nespes
    }
    return true; //spes
}
