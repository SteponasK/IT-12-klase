#include <iostream>
#include <fstream>

int skaiciavimas(std::ifstream &fin);

struct begimas
{
    int diena{};
    int minutes{};
};
int main()
{
    std::ifstream fin;
    fin.open("U1.txt");
    int d{};
    fin >> d;

    begimas begimai[d];
    int geri_begimai{};
    for(int i = 0; i < d; ++i)
    {
        int diena{};
        fin >> diena;

        begimas temp;
        temp.diena = diena;
        temp.minutes = skaiciavimas(fin);
        if( temp.minutes > 0)
        {

            begimai[geri_begimai].diena = temp.diena;
            begimai[geri_begimai].minutes = temp.minutes;
            geri_begimai++;
        }

    }

    for(int i = 0; i < geri_begimai; ++i)
    {
        for(int j = 0; j < geri_begimai-1; ++j)
        {
            if( (begimai[j].minutes > begimai[j+1].minutes))
            {
                begimas temp{};
                temp = begimai[j];
                begimai[j] = begimai[j+1];
                begimai[j+1] = temp;

            }
        }

    }


    std::ofstream fout;

    fout.open("U1rez.txt");

    fout << "Minimalus laikas" << '\n';
    fout << begimai[0].minutes << '\n';
    fout << "Dienos" << '\n';
    for(int i = 0; i < geri_begimai; ++i)
    {
        if(begimai[i].minutes == begimai[0].minutes)
            fout << begimai[i].diena << " ";
    }

    return 0;
}

int skaiciavimas(std::ifstream &fin)
{
    int temp{};

    int begimas_ryte[4]{};
    for(int i = 0; i < 4; ++i)
    {
        fin >> begimas_ryte[i];
        if( !(begimas_ryte[i]) ) // == 0
            ++temp;
        if(temp == 4)
            return 0;
    }

    while(begimas_ryte[2] - begimas_ryte[0] > 0)
    {
        begimas_ryte[3]+=60;
        begimas_ryte[2]--;
    }
    int minutes_ryte = begimas_ryte[3] - begimas_ryte[1];


    int begimas_vakare[4]{};
    temp = 0;
    for(int i = 0; i < 4; ++i)
    {
        fin >> begimas_vakare[i];
        if( !(begimas_vakare[i]) ) // == 0
            ++temp;
        if(temp == 4)
            return 0;
    }
    while(begimas_vakare[2] - begimas_vakare[0] > 0)
    {
        (begimas_vakare[3])+=60;
        (begimas_vakare[2])--;
    }
    int minutes_vakare = begimas_vakare[3] - begimas_vakare[1];

    return (minutes_ryte + minutes_vakare);


}
