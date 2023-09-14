#include <iostream>


int main()
{
    int slaptas_skaicius = rand()%10;
    int spejimas{};
    std::cout << "Bandykite speti slapta skaiciu nuo 1 iki 10:";
    do{
        std::cin >> spejimas;
    if(spejimas > slaptas_skaicius)
        std::cout << "Slaptas skaicius yra mazesnis.";
    else if(spejimas < slaptas_skaicius)
        std::cout << "Slaptas skaicius yra didesnis.";
    else
        std::cout << "Atspejote!";
    }

    while(spejimas != slaptas_skaicius);


    return 0;
}
