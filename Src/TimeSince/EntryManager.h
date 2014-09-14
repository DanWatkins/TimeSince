#ifndef _TIMESINCE_ENTRYMANAGER_H
#define _TIMESINCE_ENTRYMANAGER_H

#include "Entry.h"
#include <QtCore/QMap>
#include <QtCore/QByteArray>

class EntryManager
{
private:
	typedef QMap<int, Entry> EntryMap;
	EntryMap mEntries;

public:
	int addEntry(const Entry &entry);
	Entry getEntry(int id) const;

	QSharedPointer<QByteArray> exportEntries() const;
	void importEntries(QSharedPointer<QByteArray> entries);

	int entryCount() const;
	void erase(int id) { mEntries.erase(mEntries.find(id)); }
};

#endif
