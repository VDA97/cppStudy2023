#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <initializer_list>
#include <algorithm>
#include <functional>


namespace ui
{

	//forward declaration of Menu Item
	class MenuItem;//the command class references menu item and also menu item goes to reference.

	class Command {
	public:
		virtual void operator () (MenuItem& mi) = 0;
		virtual ~Command() {};
		
	};

	//Function signature.
	using CommandFunc = std::function<void(MenuItem&)>;


	class MenuItem {
	public:
	
		MenuItem(std::string tx, CommandFunc cd) :title(tx), cmd(cd) {}
		void Select() {
			cmd(*this);
		}
		std::string Title() const {
			return title;
		}

	private:
		std::string title;
		CommandFunc cmd;

	};

	typedef std::unique_ptr<MenuItem> MenuItemUp;

	class Menu
	{
	public:
		Menu(std::string hd) : heading(hd) {};

		void AddItem(const MenuItem& mi) {
			items.push_back(std::make_unique<MenuItem>(mi));
		}
		void AddItem(std::initializer_list<MenuItem> items) {

			std::for_each(items.begin(), items.end(),
				[this](auto item) { AddItem(item); }
			);
		}

		int Show() const;
		
		
	private:
		std::string heading;
	    std::vector<MenuItemUp> items;
	
	
	};


	class ShowCmd : public Command {
	public:
		void operator()(MenuItem& mi) override
		{
			std::cout << mi.Title() << " selected" << std::endl;
		}
	};

	class QuitCmd : public Command {
	public:
		void operator()(MenuItem& mi) override
		{
			std::cout << mi.Title() << " Bye" << std::endl;
			exit(0);
		}
	};

	

}