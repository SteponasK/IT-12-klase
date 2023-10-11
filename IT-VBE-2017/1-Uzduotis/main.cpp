#include <iostream>
#include <fstream>
#include <vector>
std::string skaiciuoti(int R, int G, int B)
{
    std::string skaiciusR;
    std::string skaiciusG;
    std::string skaiciusB;
    int num1;


    //std::string skaicius = skaiciusR + skaiciusG + skaiciusB;
    std::string skaicius = "lol";
    return skaicius;
}
int main()
{
    int a;
    int b;
    std::ifstream fin;
    fin.open("U1.txt");
    fin >> a >> b;
    std::vector<std::string> skaiciai;
    for(int i = 0; i < a*b; ++i)
    {
        int R;
        int G;
        int B;
        fin >> R >> G >> B;
        std::string skaicius = skaiciuoti(R, G, B);
        skaiciai.push_back(skaicius);
    }

    return 0;
}
