#ifndef _TIMESINCE_ENTRYMANAGER_H
#define _TIMESINCE_ENTRYMANAGER_H

#include "Entry.h"
#include <QtCore/QMap>
#include <QtCore/QByteArray>

class EntryManager
{
private:
	QMap<int, Entry> mEntries;

public:
	int addEntry(const Entry &entry);
	int createEntry(const QString &title);
	Entry getEntry(int id) const;

	QSharedPointer<QByteArray> exportEntries() { return QSharedPointer<QByteArray>(); }
	void importEntries(QSharedPointer<QByteArray> entries);


	int entryCount() const;
	void erase(int id) { mEntries.erase(mEntries.find(id)); }
};

#endif
