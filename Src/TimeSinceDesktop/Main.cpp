#include <iostream>
#include <TimeSince/EntryManager.h>

int main()
{
	EntryManager m;
	Entry e1(QDateTime(QDate(1995, 1, 3), QTime(18, 30)), "I am born", "I was born");
	e1.addTag("car");
	e1.addTag("bus");

	m.addEntry(e1);

	QSharedPointer<QByteArray> byteArray = m.exportEntries();
	
	QString str(*byteArray.data());
	std::cout << str.toStdString() << std::endl;

	EntryManager b;
	b.importEntries(byteArray);


	return 0;
}