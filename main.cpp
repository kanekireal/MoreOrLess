#include <iostream>
#include <boost/algorithm/string/predicate.hpp>
#include <sstream>
#include <iomanip>
#include <random>

struct time_s {
    int h;
    int m;
    int s;
};

time_s toTime(int s) {
    time_s t1{};
    t1.h = s / 3600;
    t1.m = s / 60 - t1.h;
    t1.s = s - t1.m * 60 - t1.h * 3600;
    return t1;
}

static std::string time_sFormat(time_s t) {
    std::stringstream ss;
    if (t.h > 0)
        ss << t.h << " heure" << (t.h > 1 ? "s et " : " et ");
    if (t.m > 0)
        ss << t.m << " minute" << (t.m > 1 ? "s et " : " et ");
    ss << t.s << " seconde" << (t.s > 1 ? "s." : ".");
    return ss.str();
}

int main() {
    std::string again;
    do {
        std::cout << "----------[ PlusOuMoins ]----------\n"
                  << "Commencement du jeu.\n"
                  << "Développé par LEVASSEUR Wesley.\n"
                  << "-----------------------------------"
                  << std::endl;
        std::random_device random_device;
        std::default_random_engine random_engine(random_device());
        std::uniform_int_distribution<int> uniform_dist(1, 100);
        time_t t = std::time(nullptr);
        const int r = uniform_dist(random_engine);;
        int tr = 0, te;
        bool find = false;
        std::cout << "debug: " << r << std::endl;
        std::cout
                << "CONSOLE » Tentez de trouver le nombre aléatoire entre 0 et 100, dans un court délai et en moins de coups possible."
                << std::endl;
        do {
            try {
                ++tr;
                std::cin >> te;
                if (std::cin.fail()) throw std::runtime_error("Input is not an integer\n");
                if (r > te)
                    std::cout << "CONSOLE » Plus!" << std::endl;
                else if (r < te)
                    std::cout << "CONSOLE » Moins!" << std::endl;
                else {
                    std::cout << "CONSOLE » GAGNEZ!" << std::endl;
                    std::cout << "CONSOLE » Vous avez mis " << time_sFormat(toTime(std::difftime(time(nullptr), t))) << std::endl;
                    std::cout << "CONSOLE » En " << tr << " coup" << (tr > 1 ? "s." : ".") << std::endl;
                    find = true;
                }
            } catch (const std::runtime_error &e) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "CONSOLE » Veuillez saisir un nombre entier. (Ex: 50)" << std::endl;
            }
        } while (!find);
        do {
            std::cout << "CONSOLE » Voulez-vous recommencer le jeu? (Oui / Non)" << std::endl;
            std::cin >> again;
            std::cin.ignore();
            std::cin.clear();
        } while (!boost::iequals(again, "oui") && !boost::iequals(again, "non"));
    } while (boost::iequals(again, "oui"));
    return 0;
}


