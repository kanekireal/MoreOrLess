//
//  time_s.cpp
//  MoreOrLess
//
//  Created by LEVASSEUR Wesley on 26/01/2019.
//  Copyright © 2019 LEVASSEUR Wesley. All rights reserved.
//

#include <stdio.h>
#include <sstream>

class time_s {
    
private:
    int hours;
    int minutes;
    int seconds;
    std::string hour;
    std::string minute;
    std::string second;
    std::string a;
    
public:
    enum Lang {FR, EN};
    
    time_s(int seconds, Lang lang) {
        this->hours = seconds / 3600;
        this->minutes = (seconds - this->hours * 3600) / 60;
        this->seconds = seconds - this->minutes * 60 - this->hours * 3600;
        this->lang(lang);
    }
    
    std::string format() {
        std::stringstream ss;
        if (this->hours > 0)
            ss << this->hours << this->hour << (this->hours > 1 ? "s" + this->a : this->a);
        if (this->minutes > 0)
            ss << this->minutes << this->minute << (this->minutes > 1 ? "s" + this->a : this->a);
        ss << this->seconds << this->second << (this->seconds > 1 ? "s." : ".");
        return ss.str();
    }
    
private:
    void lang(Lang lang) {
        switch (lang) {
            case Lang::EN:
                this->hour = " hour";
                this->minute = " minute";
                this->second = " second";
                this->a = " and ";
                break;
            default:
                this->hour = " heure";
                this->minute = " minute";
                this->second = " seconde";
                this->a = " et ";
                break;
        }
    }
    
};
