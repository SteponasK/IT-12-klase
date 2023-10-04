#include <iostream>
#include <fstream>
#include <string>
// 2019 metu 2 uzd Begimas
struct Sportininkai{
    std::string name{}; // vardas
    bool vaikinas; // lytis
    bool finished; // ar baige lenktynes
    int num{}; // numeris
    int start_h; // starto laikas
    int start_min;
    int start_sec;
    int end_h = -1; // pabaigos laikas (jeigu -1 nebus pakeista reiksme, reiskias nebaige lenktyniu)
    int end_min = 0;
    int end_sec;
    int taikinys[4]; // 4 taikiniai (merginos saudys tik i 2)
    int rezultatas_min;
    int time_h;
    int time_min;
    int time_sec;
    int time_total_sec;
};
Sportininkai sportininkas[30];
int n;
int m;
void rusiuoti()
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n-1; ++j) // surusiuojam pagal laika didejanciai
        {
            if(sportininkas[j].time_total_sec > sportininkas[j+1].time_total_sec)
                std::swap(sportininkas[j], sportininkas[j+1]);
        }
    }
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < n-1; ++j) // surusiuojam pagal varda abeceliskai, jeigu tas pats finisavimo laikas
        {
            if(sportininkas[j].time_total_sec == sportininkas[j+1].time_total_sec)
            {
                if(sportininkas[j].name[0] > sportininkas[j+1].name[0])
                {
                    std::swap(sportininkas[j], sportininkas[j+1]);
                }
            }
        }
    }
}
std::ofstream fout;
void spausdinti(bool lytis)
{
    for(int i = 0; i < n; ++i)
    {
        if(sportininkas[i].vaikinas == lytis && sportininkas[i].finished) // spausdiname duomenis pagal lyti
        {
            fout << sportininkas[i].num << ' ' << sportininkas[i].name << ' ' << sportininkas[i].time_h << ' '
            << sportininkas[i].time_min << ' ' << sportininkas[i].time_sec << std::endl;
        }
    }
}
void skaityti() // skaitome failus
{
   std::ifstream fin;
    fin.open("U2.txt");
    fin >> n;

    {
        std::string temp; // nuskaitome tuscia eilute
        std::getline(fin, temp);
    }
    for(int i = 0; i < n; ++i)
    {
        std::string name{};
        std::getline(fin, name); // paemame visa line, sukurtus substrings paverciam i ints, ir nukerpame string gala.
        int num = stoi(name.substr(20, 22));
        int start_h = stoi(name.substr(24, 25));
        int start_min = stoi(name.substr(27, 28));
        int start_sec = stoi(name.substr(30, 31));
        name = name.erase(20);
        sportininkas[i].name = name;
        sportininkas[i].num = num;
        sportininkas[i].start_h = start_h;
        sportininkas[i].start_min = start_min;
        sportininkas[i].start_sec = start_sec;
    }
    fin >> m;
    for(int i = 0; i < m; ++i)
    {
        int num;
        fin >> num;
        for(int j = 0; j <n; ++j)
        {
            if(num == sportininkas[j].num)
            {
                fin >> sportininkas[j].end_h >> sportininkas[j].end_min >> sportininkas[j].end_sec;
                fin >> sportininkas[j].taikinys[0] >> sportininkas[j].taikinys[1];
                if(num/100 == 1)
                {
                    sportininkas[j].vaikinas = false;
                }
                else
                {
                    sportininkas[j].vaikinas = true;
                    fin >> sportininkas[j].taikinys[2] >> sportininkas[j].taikinys[3];
                }
            }
        }
    }
}
void skaiciuoti()
{
    for(int i = 0; i < n; ++i)
    {
        if(sportininkas[i].end_h == -1)
        {
            sportininkas[i].finished = false;
            continue;
        }
        else
        {
            sportininkas[i].finished = true;
            int end_sec = ( (sportininkas[i].end_h * 3600) + (sportininkas[i].end_min * 60) + (sportininkas[i].end_sec));
            int start_sec =( (sportininkas[i].start_h * 3600) + (sportininkas[i].start_min * 60) + (sportininkas[i].start_sec) );
            int time_sec = end_sec - start_sec;
            int nuobauda_min = 0;
            if(sportininkas[i].vaikinas == true)
            {
                for(int j = 0; j < 4; ++j)
                {
                    nuobauda_min += (5- sportininkas[i].taikinys[j]);
                }
            }
            if(sportininkas[i].vaikinas == false)
            {
                for(int j = 0; j < 2; ++j)
                {
                    nuobauda_min += (5- sportininkas[i].taikinys[j]);
                }
            }
            time_sec = time_sec + (nuobauda_min * 60);
            sportininkas[i].time_total_sec = time_sec;
            int time_h = 0;
            int time_min = 0;
            while(time_sec >= 3600)
            {
                time_sec-=3600;
                time_h++;
            }
            while(time_sec >= 60)
            {
                time_sec-=60;
                time_min++;
            }
            sportininkas[i].time_h = time_h;
            sportininkas[i].time_min = time_min;
            sportininkas[i].time_sec = time_sec;
        }
    }
}
int main()
{
    skaityti();
    skaiciuoti();
    rusiuoti();
    fout.open("U2rez.txt");
    fout << "Merginos" << std::endl;
    spausdinti(false); // true vyras / false moteris
    fout << "Vaikinai" << std::endl;
    spausdinti(true);
    return 0;
}
