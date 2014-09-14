#include "EntryManager.h"
#include <QtCore/QXMLStreamWriter>
#include <iostream>

int EntryManager::addEntry(const Entry &entry)
{
	int id = mEntries.size();
	mEntries[id] = entry;

	return id;
}


QSharedPointer<QByteArray> EntryManager::exportEntries() const
{
	QSharedPointer<QByteArray> byteArray(new QByteArray());
	QXmlStreamWriter w(byteArray.data());
	w.setAutoFormatting(true);
	w.writeStartDocument();

	EntryMap::ConstIterator iter = mEntries.constBegin();
	while (iter != mEntries.constEnd())
	{
		iter->writeToXmlStream(w);
		iter++;
	}

	w.writeEndDocument();

	return byteArray;
}



void EntryManager::importEntries(QSharedPointer<QByteArray> entries)
{
	QXmlStreamReader xml(*entries.data());

	while (!xml.atEnd()  && !xml.hasError())
    {
		QXmlStreamReader::TokenType type = xml.readNext();

		if (type == QXmlStreamReader::StartDocument)
		{
			continue;
		}
		else if (type == QXmlStreamReader::StartElement)
		{
			if (xml.name() == "entry")
			{
				Entry newEntry;
				newEntry.readFromXmlStream(xml);
				addEntry(newEntry); 
			}
		}
    }

	if (xml.hasError())
	{
		std::cout << "Error: " << xml.errorString().toStdString() << std::endl;
	}

	xml.clear();
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