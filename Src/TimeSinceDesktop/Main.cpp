#include <QtCore/QDate>
#include <iostream>

int main()
{
	QDate date(1995, 1, 3);
	std::cout << date.toString().toStdString() << std::endl;

	return 0;
}