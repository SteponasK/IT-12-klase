//1 uzduotis. Balsavimo rezultatai
#include <iostream>
#include <fstream>

int apskaiciuoti_taskus(int &logo1, int &logo2, int &logo3, int &balsai1, int &balsai2, int &balsai3);
int geriausias_logotipas(std::ifstream &fin, int &logo1, int &logo2, int &logo3);
int main()
{
    int logo1{}; // tasku skaiciai
    int logo2{};
    int logo3{};

    int balsai1{}; // balsu skaiciai
    int balsai2{};
    int balsai3{};

    int isrinktas =  apskaiciuoti_taskus(logo1, logo2, logo3, balsai1, balsai2, balsai3);

    std::ofstream fout;
    fout.open("U1rez.txt");
    fout << balsai1 << ' ' << balsai2 << ' ' << balsai3 << '\n';
    fout << logo1 << ' ' <<logo2 << ' '<< logo3 << '\n' << isrinktas;

    return 0;
}
int apskaiciuoti_taskus(int &logo1, int &logo2, int &logo3, int &balsai1, int &balsai2, int &balsai3)
{
    std::ifstream fin;
    fin.open("U1.txt");

    int k{};
    fin >> k;
    for(int i = 0; i < k; ++i) // sukam k kartu
    {
        int temp_1{};
        int temp_2{};
        int temp_3{};

        fin >> temp_1 >> temp_2 >> temp_3;
        balsai1 += temp_1;
        balsai2 += temp_2;
        balsai3 += temp_3;
        if( (temp_1 == temp_2) && (temp_2 == temp_3) )
        {
            //nieko nedarom
        }
        else if(temp_1 > temp_2 && temp_1 > temp_3)
        {
            logo1+=4;
        }
        else if(temp_2 > temp_1 && temp_2 > temp_3)
        {
            logo2+=4;
        }
        else if(temp_3 > temp_1 && temp_3 > temp_2)
        {
            logo3+=4;
        }
        else if(temp_3 > temp_1 && temp_3 > temp_2)
        {
            logo3+=4;
        }
        else if(temp_1 == temp_2)
        {
            logo1+=2;
            logo2+=2;
        }
        else if(temp_1 == temp_3)
        {
            logo1+=2;
            logo3+=2;
        }
        else if(temp_2 == temp_3)
        {
            logo2+=2;
            logo3+=2;
        }
    }

    return geriausias_logotipas(fin, logo1, logo2, logo3); // skambinam funkcijai kuri grazina geriausio logotipo reiksme
}
int geriausias_logotipas(std::ifstream &fin, int &logo1, int &logo2, int &logo3)
{
    int director1{};
    int director2{};
    int director3{};
    fin >> director1 >> director2 >> director3; //skaitom direktoriaus taskus

    if( (logo1 == logo2) && (logo2 == logo3) && (logo1 == logo3) )
    {
        logo1+=director1;
        logo2+=director2;
        logo3+=director3;
    }
    if(logo1 > logo2 && logo1 > logo3) // grazinam daugiausia tasku surinkusio algoritmo skaiciu
    {
        return 1;
    }
    else if(logo2 > logo3 && logo2 > logo1)
    {
        return 2;
    }
    else if(logo3 > logo2 && logo3 > logo1)
    {
        return 3;
    }

    return -1;
}
