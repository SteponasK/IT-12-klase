#include <iostream>
#include <fstream>
#include <string>

int n; // slidininku skaicius
int m; // finisavusiu slidininku skaicius
struct Slidininkai
{
    std::string vardas;
    int s_val; // starto laikai
    int s_min;
    int s_sec;
    int f_val; // finiso laikai
    int f_min;
    int f_sec;
    bool finisavo = false;
    int trukme; // kiek isviso sekundziu uztruko finisuoti
    int u_val = 0; // kiek uztruko laikai
    int u_sec = 0;
    int u_min = 0;
};
Slidininkai slidininkas[30];
void skaityti()
{
    std::ifstream fin;
    fin.open("U2.txt");
    fin >> n;

    std::string temp;
    std::getline(fin, temp); // nuskaitome tuscia eilute

    for(int i = 0; i < n; ++i)
    {
        std::string vardas;
        std::getline(fin, vardas);
        int val = stoi(vardas.substr(21));
        int min = stoi(vardas.substr(24));
        int sec = stoi(vardas.substr(26));
        vardas = vardas.erase(20);
        slidininkas[i].vardas = vardas;
        slidininkas[i].s_val = val;
        slidininkas[i].s_min = min;
        slidininkas[i].s_sec = sec;
    }
    fin >> m;
    std::string temp2;
    std::getline(fin, temp2); // nuskaitome tuscia eilute
    for(int i = 0; i < m; ++i)
    {
        std::string vardas;
        std::getline(fin, vardas);
        int val = stoi(vardas.substr(21));
        int min = stoi(vardas.substr(24));
        int sec = stoi(vardas.substr(26));
        vardas = vardas.erase(20);
        for(int j = 0; j < n; ++j)
        {
            if(slidininkas[j].vardas.compare(vardas) == 0 )// jeigu vardai vienodi
            {
                slidininkas[j].finisavo = true;
                slidininkas[j].f_val = val;
                slidininkas[j].f_min = min;
                slidininkas[j].f_sec = sec;
            }
        }
    }
}
void skaiciuoti()
{
    for(int i = 0; i < n; ++i)
    {
        if(slidininkas[i].finisavo)
        {
            int finiso_laikas = slidininkas[i].f_val * 3600 + slidininkas[i].f_min * 60 + slidininkas[i].f_sec;
            int starto_laikas = slidininkas[i].s_val * 3600 + slidininkas[i].s_min * 60 + slidininkas[i].s_sec;
            int trukme = finiso_laikas - starto_laikas; // surandame kiek sekundziu uztruko
            slidininkas[i].trukme = trukme;
            while(trukme >= 3600) // surandame valandas
            {
                slidininkas[i].u_val++;
                trukme -= 3600;
            }
            while(trukme >= 60) // surandame minutes
            {
                slidininkas[i].u_min++;
                trukme -= 60;
            }
            slidininkas[i].u_sec = trukme; // surandame sekundes
        }
    }
}
void rusiuoti()
{
    for(int i = 0; i < n; ++i) // surusiuojame, kad priekyje butu slidininkai kurie finisavo
    {
        for(int j = 0; j < n-1; ++j)
        {
            if(!slidininkas[j].finisavo && slidininkas[j+1].finisavo)
                    std::swap(slidininkas[j], slidininkas[j+1]);
        }

    }
    for(int i = 0; i < m; ++i) // surusiuojame pagal trukme didejanciai
    {
        for(int j = 0; j < m-1; ++j)
        {
            if(slidininkas[j].trukme > slidininkas[j+1].trukme)
                std::swap(slidininkas[j], slidininkas[j+1]);
        }
    }

    for(int i = 0; i < m; ++i) // jeigu trukme ta pati, surusiuojame abeceliskai
    {
        for(int j = 0; j < m-1; ++j)
        {
            if(slidininkas[j].trukme == slidininkas[j+1].trukme &&
                slidininkas[j].vardas[0] < slidininkas[j+1].vardas[0])
                std::swap(slidininkas[j], slidininkas[j+1]);
        }
    }
}
void spausdinti()
{
    std::ofstream fout;
    fout.open("U2rez.txt");
    for(int i = 0; i < m; ++i)
        fout << slidininkas[i].vardas << " " << slidininkas[i].u_min << " " << slidininkas[i].u_sec << std::endl;
}
int main()
{
    skaityti();
    skaiciuoti();
    rusiuoti();
    spausdinti();
    return 0;
}
