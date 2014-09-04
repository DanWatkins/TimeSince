#include "EntryManager.h"


int EntryManager::createEntry(const String &title)
{
	//put the new entry at a key equal to the highest key + 1
	int id = mEntries.size()>0 ? mEntries.rbegin()->first+1 : 0;
	mEntries[id] = Entry(title);

	return id;
}



Entry EntryManager::getEntry(int id) const
{
	return mEntries.at(id);
}


int EntryManager::entryCount() const
{
	return mEntries.size();
}