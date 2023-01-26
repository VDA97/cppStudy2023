#pragma once
#include <algorithm>
#include "menu.h"

namespace ui {

    int Menu::Show() const {

        int i;
        int sel;

        do {

            std::cout << std::endl << std::endl;
            std::cout << " ------" << heading << "--------" << std::endl;
            i = 1;
            std::for_each(items.begin(), items.end(),
                [&i](auto& mi) {std::cout << i++ << " -> " << mi->Title() << std::endl; });
            i--;

            std::cout << " Choose from 1 - " << i << ": " << std::flush;
            

            std::string tmp;
            std::cin >> tmp;

            try {
                sel = std::stoi(tmp);
            }
            catch (const std::invalid_argument&) { sel = -1; }

            sel--;

            if(sel >= 0 && sel < i) {

                items[sel]->Select();
            }

        } while (sel<0 || sel >= i);
    
        return sel+1;// sel + 1;
    
    }

}









