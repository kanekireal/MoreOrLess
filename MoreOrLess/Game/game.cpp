//
//  game.cpp
//  MoreOrLess
//
//  Created by LEVASSEUR Wesley on 26/01/2019.
//  Copyright © 2019 LEVASSEUR Wesley. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <random>
#include <boost/algorithm/string/predicate.hpp>
#include "../Utils/time_s.cpp"

const static std::string PREFIX = "CONSOLE » ";

class Game {
    
private:
    std::string again_s, lang_s, TITLE, YES, NO, M_OO1, M_OO2, M_OO3, E_OO1;
    time_t started;
    int mysteryNumber, try_ = 0;
    bool finded = false;
    
public:
    
    Game() {
        this->init();
    }
    
    void init(){
        std::random_device random_device;
        std::default_random_engine random_engine(random_device());
        std::uniform_int_distribution<int> uniform_dist(1, 100);
        this->mysteryNumber = uniform_dist(random_engine);;
        this->started = std::time(nullptr);
        
        std::cout << "----------[ Languages ]----------\n"
        << "- FR\n"
        << "- EN\n"
        << "-----------------------------------"
        << std::endl;
        
        do{
            std::cout << PREFIX << "Select a language." << std::endl;
            std::cout << "» ";
            std::cin >> this->lang_s;
        }while (!boost::iequals(this->lang_s, "fr") && !boost::iequals(this->lang_s, "en"));
        
        this->lang(this->lang_s);
        
        this->start();
        
        do{
            this->loop_game();
        }while(!this->finded);
        
        do{
            this->loop_again();
        }while(!boost::iequals(this->again_s, this->YES) && !boost::iequals(this->again_s, this->NO));
        
        this->end();
    }
    
private:
    
    void lang(std::string lang_s) {
        this->TITLE = boost::iequals(lang_s, "en") ? "MoreOrLess" : "PlusOuMoins";
        this->YES = boost::iequals(lang_s, "en") ? "Yes" : "Oui";
        this->NO = boost::iequals(lang_s, "en") ? "No" : "Non";
        this->M_OO1 = boost::iequals(lang_s, "en") ? "Beginning of the game." : "Commencement du jeu.";
        this->M_OO2 = boost::iequals(lang_s, "en") ? "Developped by" : "Développé par";
        
        this->E_OO1 = boost::iequals(lang_s, "en") ? "Do you want to start the game again? (Yes / No)" : "Voulez-vous recommencer le jeu? (Oui / Non)";
        
    }
    
    void start() {
        std::cout << "----------[ " << this->TITLE << " ]----------\n"
        << this->M_OO1 <<"\n"
        << this->M_OO2 <<" LEVASSEUR Wesley.\n"
        << "-----------------------------------"
        << std::endl;
    }
    
    void loop_game() {
        
    }
    
    void loop_again() {
        std::cout << PREFIX << this->E_OO1 << std::endl;
        std::cout << "» ";
        std::cin >> again_s;
    }
    
    void end() {
        
    }
    
};
