#include "EntryManager.h"


int EntryManager::createEntry(const QString &title)
{
	//put the new entry at a key equal to the highest key + 1
	int id = mEntries.size();
	mEntries[id] = Entry(title);

	return id;
}



Entry EntryManager::getEntry(int id) const
{
	QMap<int, Entry>::const_iterator i = mEntries.find(id);

	if (i == mEntries.end())
		throw std::out_of_range(QString("No entry for key=%1").arg(id).toStdString());

	return i.value();
}


int EntryManager::entryCount() const
{
	return mEntries.size();
}