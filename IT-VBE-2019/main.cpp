#include <iostream>
#include <fstream>
    int truksta1 = 0; // trukstamu indu skaicius
    int truksta3 = 0;
    int truksta5 = 0;
    int panaudota1 = 0; // panaudotu indu skaicius
    int panaudota3 = 0;
    int panaudota5 = 0;
    int panaudotaAL = 0;
    int like1 = 0; // likusiu indu skaicius
    int like3 = 0;
    int like5 = 0;
    int likeAL = 0;
    int n1 = 0; // turimu indu skaicius is pat pradziu
    int n3 = 0;
    int n5 = 0;
    int k = 0; // aliejaus litru skaicius
void skaiciavimas();
int main()
{
    std::ifstream fin;
    fin.open("U1.txt");
    fin >> n1 >> n3 >> n5;
    like1 = n1;
    like3 = n3;
    like5 = n5;

    fin >> k;

    int kaina1, kaina3, kaina5; // aliejaus indu pardavimo kaina
    int kainaAL{};// aliejaus kaina
    fin >> kainaAL >> kaina1 >> kaina3 >> kaina5;

    likeAL = k;

    skaiciavimas();

    int pelnas = (( (panaudota1+ truksta1) * kaina1) + ((panaudota3+ truksta3) * kaina3) + ((panaudota5+ truksta5) * kaina5)) - kainaAL;//(panaudotaAL/256.0)*kainaAL;

    std::ofstream fout;
    fout.open("U1rez.txt");
    fout << panaudota1 << ' ' << panaudota3 << ' ' << panaudota5 << ' ' <<likeAL <<  std::endl;
    fout << like1 << ' ' << like3 << ' ' << like5 << std::endl;
    fout <<  truksta1 << ' '<< truksta3  << ' ' <<  truksta5 << std::endl; // kiek 1 3 ir 5 litru reikejo papildomai
    fout << pelnas;
    return 0;
}
void skaiciavimas()
{
    while(like5 > 0 && likeAL >= 5)
    {
        like5--;
        likeAL-=5;
    }
    while(like3 > 0 && likeAL >= 3)
    {
        like3--;
        likeAL-=3;
    }
    while(like1 > 0 && likeAL >= 1)
    {
        like1--;
        likeAL--;
    }

    if(likeAL > 0)
    {
        int ALtemp = likeAL;
        while(ALtemp >= 5)
        {
            ALtemp-=5;
            truksta5++;
        }
        while(ALtemp >=3)
        {
             ALtemp-=3;
            truksta3++;
        }
        while(ALtemp >=1)
        {
             ALtemp--;
            truksta1++;
        }
    }
    panaudotaAL = k - likeAL;
    panaudota1 = n1 -  like1;
    panaudota3 = n3 -  like3;
    panaudota5 = n5 -  like5;
}
