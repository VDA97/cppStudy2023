#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <unordered_map>

namespace ui
{
	
	class RGB {
	public:
		//constructos - Parametrized
		//RGB(int r, int g, int b) :red(r),green(g),blue(b) {};
		//sets - not necessary
		void setColors() {
			std::cout << "Digite a cor vermelha" << std::endl;
			std::cin >> red; 
			std::cout << "Digite a cor verde" << std::endl;
			std::cin >> green;
			std::cout << "Digite a cor azul" << std::endl;
			std::cin >> blue; 
		}
		//gets - Retornar todos de uma vez
		int getRed() {
			return red;
		};
		int getGreen() {
			return green;
		};
		int getBlue() {
			return blue;
		};
		
		//Como irei printar o valor setado na cor ?
		void colorsShow() {
			
			std::cout << "Red: " << red << "Green: " << green << "Blue: " << blue << std::endl;
		};
	private:
		//data
		int red = 0, green = 0, blue = 0;
	};


	typedef std::unique_ptr<RGB> RGBItemUp;

	class DataRGB
	{
	public:
		//DataRGB() :{};

		void createItem()
		{
			std::cout << "Digite um nome" <<std::endl;
			std::cin >> rgbName;
			RGB newItem;
			newItem.setColors();
			addItem(newItem);
	

		};


		void addItem(RGB& rgb)
		{
			rgbs.insert(make_pair(rgbName, std::make_unique<RGB>(rgb)));
			
		};
		
		void showAll() {
				
			if (rgbs.size() == 0) {
				std::cout << "No colors created" << std::endl;
			}
			else {
				for (auto& it : rgbs) {
					std::cout << it.first << std::endl;
				}
			}
		
		};

		void getObjShow() {

			std::cout << "Digite o nome: " << std::endl;
			std::cin >> key;
			
			if (rgbs.find(key) == rgbs.end()) {
				std::cout << "Not Found, check the list: " << std::endl;
			}
			else{
				std::cout << "Found name: " << rgbs.find(key)->first << std::endl;// "RGB colors: " << rgbs.find(key)->second->colorsShow() << std::endl;
				rgbs.find(key)->second->colorsShow();
			}
			
		};

		void getObjDel() {

			std::cout << "Digite o nome: " << std::endl;
			std::cin >> key;

			if (rgbs.find(key) == rgbs.end()) {
				std::cout << "Not Found, check the list: " << std::endl;
			}
			else {
				std::cout << "Found name: " << rgbs.find(key)->first << std::endl;// "RGB colors: " << rgbs.find(key)->second->colorsShow() << std::endl;
				rgbs.find(key)->second->colorsShow();
				rgbs.erase(key);
				std::cout << "Erased, new list is:  "<< std::endl;
				showAll();

			}


		};

		void getObjEdit() {

			std::cout << "Digite o nome: " << std::endl;
			std::cin >> key;

			if (rgbs.find(key) == rgbs.end()) {
				std::cout << "Not Found, check the list: " << std::endl;
			}
			else {
				std::cout << "Found name: " << rgbs.find(key)->first << std::endl;// "RGB colors: " << rgbs.find(key)->second->colorsShow() << std::endl;
				rgbs.find(key)->second->setColors();
				std::cout << "Edit, new color is:  " << std::endl;
				rgbs.find(key)->second->colorsShow();

			}


		};

	private:
		std::string rgbName ="";
		std::string key = "";
		std::unordered_map<std::string, RGBItemUp> rgbs;
		
	};


}