#include "compiladores.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Compiladores w;
	w.show();
	return a.exec();
}
