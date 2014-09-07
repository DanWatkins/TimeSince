#ifndef _TIMESINCE_ENTRYMANAGER_H
#define _TIMESINCE_ENTRYMANAGER_H

#include "Entry.h"
#include <QtCore/QMap>

class EntryManager
{
private:
	QMap<int, Entry> mEntries;

public:
	int createEntry(const QString &title);
	Entry getEntry(int id) const;

	int entryCount() const;
	void erase(int id) { mEntries.erase(mEntries.find(id)); }
};

#endif
