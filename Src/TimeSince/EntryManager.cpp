#include "EntryManager.h"


int EntryManager::addEntry(const Entry &entry)
{
	int id = mEntries.size();
	mEntries[id] = entry;

	return id;
}


int EntryManager::createEntry(const QString &title)
{
	return addEntry(Entry(title));
}


void EntryManager::importEntries(QSharedPointer<QByteArray> entries)
{
	addEntry(Entry());
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