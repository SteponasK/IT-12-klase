#include <iostream>
#include <fstream> // del std::ifstream ir std::ofstream
#include <iomanip> // del std::fixed ir std::setprecision

void calculatePercent(double &fat, double &protein, double &carbs, int mass);
int main()
{

    std::ifstream fin; // atidaryti faila
    fin.open("Duomenys.txt");
    int n{}; // eiluciu skaicius
    fin >> n; // nuskaitome kintamaji n is failo "doumenyx.txt"

    double fat{}; // riebalu, baltymu ir angliavandeniu kintamieji
    double protein{};
    double carbs{};
    int mass{}; // mase
    for(int i = 0; i < n; ++i) // eisime pro 'n' eiluciu (nuskaitysime visus duomenis)
    {
        double fat_temp{}; // temporary (laikini) kintamieji, juos naudosime, kad nuskaityti duomenis ir juos pridesime prie originalaus fat, protein, carbs kintamuju.
        double protein_temp{};
        double carbs_temp{};
        int mass_temp{};
        fin >> fat_temp >> protein_temp >> carbs_temp >> mass_temp; // nuskaitom eilute

        fat+=fat_temp; // prisumuojam gautus skaicius
        protein+=protein_temp;
        carbs += carbs_temp;
        mass+= mass_temp;
    }

    calculatePercent(fat, protein, carbs, mass); // funkcija kuri skaiciuoja procentu kieki

    std::ofstream fout; // atidarome faila i kuri spausdinsime duomenis
    fout.open("Rezultatai.txt");
    fout << std::fixed << std::setprecision(2) <<fat << '\n' << protein << '\n' <<  carbs; // fixed ir setprecision padarys kad butu 2 skaiciai po kablelio, '\n' padaro nauja eilute.


    return 0; // baigias programa
}
void calculatePercent(double &fat, double &protein, double &carbs,int mass) // funkcijos logika
{
    fat = fat * 100 / mass; // matematika surasti procentam
    protein = protein * 100 / mass;
    carbs = carbs * 100 / mass;
}
