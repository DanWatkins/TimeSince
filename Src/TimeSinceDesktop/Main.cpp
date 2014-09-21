#include <iostream>
#include <TimeSince/EntryManager.h>
#include <QtCore/QFile>

int main()
{
	EntryManager m;
	Entry e1(QDateTime(QDate(1995, 1, 3), QTime(18, 30)), "I am born", "I was born");
	e1.addTag("car");
	e1.addTag("bus");

	m.addEntry(e1);

	QFile file("exportedEntries.txt");
	m.exportEntries(file);
	
	EntryManager b;
	b.importEntries(file);


	return 0;
}