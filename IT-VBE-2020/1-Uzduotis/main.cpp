#include <iostream>
#include <fstream>

struct Geles
{
    bool diena[92]; // Vasaros dienos
};

//  Funkcija kuri randa pirmos dienos, kai zydi daugiausia skirtingu geliu, vieta  vasaros dienu sarase.
void rasti_diena(Geles gele[], int n, int& max_pradzia, int& max_pabaiga, int& max_skaicius); // Funkcija randandi
int main()
{
    std::ifstream fin;
    fin.open("U1.txt");

    int n{}; // Geliu skaicius
    fin >> n;
    Geles gele[n];

    for(int i = 0; i < n; ++i)
    {
        int prM{}; // Pradzios menesis
        int prD{};// Pradzios diena
        int pabM{};// Pabaigos menesis
        int pabD{};// Pabaigos diena
        int numeris{}; // numeris mums nera reikalingas
        fin >> numeris >> prM >> prD >> pabM >> pabD;
        int prad_interval{};
        int pab_interval{};
        // Surandame kiekvienos geles zydejimo pradzios ir pabaigos intervalus
        if(prM == 7)
            prad_interval+=30;
        else if(prM == 8)
            prad_interval+=61;

        prad_interval+=prD;

        if(pabM == 7)
            pab_interval+=30;
        else if(pabM == 8)
            pab_interval+=61;

        pab_interval+=pabD;

        // Uzpildome masyva reiksmemis 1 - Jeigu ta diena zymi, 0 - jeigu nezydi
        for(int j = 0; j < 92; ++j)
        {
            if(j >= prad_interval-1 && j <= pab_interval-1)
            {
                gele[i].diena[j] = 1;
            }
            else
               gele[i].diena[j] = 0;
        }
    }
    fin.close();
    int max_pradzia = 0;
    int max_pabaiga = 0;
    int max_skaicius = 0;
    rasti_diena(gele, n, max_pradzia, max_pabaiga, max_skaicius);

    for(int i = max_pradzia; i < 92; ++i) // Einame nuo didziausio zydejimo kiekio intervalo ir ieskome kol sumazes skaicius
    {
        int count = 0;
        for(int j = 0; j < n; ++j)
        {
            if(gele[j].diena[i] == 1)
                ++count;
        }
        if(count < max_skaicius)
        {
            max_pabaiga = i-1; //Daugiausiai geliu zydejo diena pries mazejima
            break;
        }


    }
    // Atnaujiname reikmes (masyvas prasidejo nuo 0, reikia perskaiciuoti nuo 1)
    int prDiena = max_pradzia +1;
    int prMen = 6;
    int pabDiena = max_pabaiga + 1;
    int pabMen = 6;
    // Atnaujinsime menesiu ir dienu reiksmes
    if(prDiena > 61)
    {
        prDiena-=61;
        prMen+=2;
    }
    else if(prDiena > 30)
    {
        prDiena-=30;
        ++prMen;
    }
    if(pabDiena > 61)
    {
        pabDiena-=61;
        pabMen+=2;
    }
    else if(pabDiena > 30)
    {
        pabDiena-=30;
        ++pabMen;
    }

    std::ofstream fout;
    fout.open("U1rez.txt");
    fout << max_skaicius << std::endl << prMen << ' ' << prDiena << ' ' << std::endl << pabMen << ' ' << pabDiena;
    fout.close();
    return 0;
}
void rasti_diena(Geles gele[], int n, int& max_pradzia, int& max_pabaiga, int& max_skaicius)
{
    for(int i = 0; i < 92; ++i) // Einame per kiekviena diena
    {
        int count = 0;
        for(int j = 0; j < n; ++j) // Einame per kiekviena gele
        {
            if(gele[j].diena[i] == 1)
            {
                ++count;
                if(count > max_skaicius) // Jeigu bus daugiau zydinciu geliu nei pries tai, atnaujinsime reiksmes
                {
                    max_pradzia = i;
                    max_skaicius = count;
                }
            }
        }
    }
}
