#ifndef _TIMESINCE_ENTRYMANAGER_H
#define _TIMESINCE_ENTRYMANAGER_H

#include "Entry.h"
#include <map>

class EntryManager
{
private:
	std::map<int, Entry> mEntries;

public:
	int createEntry(String title);
	Entry getEntry(int id);

	int entryCount();
	void erase(int id) { mEntries.erase(mEntries.find(id)); }
};

#endif
