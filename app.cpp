#include <memory>
#include "menu.h"
#include "menu.cpp"
#include "objeto.h"

using namespace std;
using namespace ui;

void ShowFunc(MenuItem& mi) {

	cout << mi.Title() << " selected " << endl;

}


void QuitFunc(MenuItem&) {
	exit(0);
}



int main()
{
    ShowCmd show;
    QuitCmd quit;
	DataRGB newRGB;

	//Realizar esse mesmo código no visual studio code.
	//Utilizar o github pra fazer o upload 

   bool running = true;
   Menu mainMenu("Database das cores");
	// note - Menu has an AddItem overload that accepts a 
	// std::initializer_list.  The compiler will automatically create one
	// when a list of objects is enclosed in { } 
   mainMenu.AddItem({  MenuItem("Criar",[&newRGB](MenuItem&) {newRGB.createItem(); }),
					   MenuItem("Verificar",[&newRGB](MenuItem&) {newRGB.getObjShow(); }),
					   MenuItem("Editar",[&newRGB](MenuItem&) {newRGB.getObjEdit(); }),
					   MenuItem("Lista",[&newRGB](MenuItem&) {newRGB.showAll(); }),
		               MenuItem("Deletar",[&newRGB](MenuItem&) {newRGB.getObjDel(); }),
					   MenuItem("Quit",[&running](MenuItem&) {running = false; }) });

	while (running) mainMenu.Show();
}

