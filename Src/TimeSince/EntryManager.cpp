#include "EntryManager.h"
#include <QtCore/QXMLStreamWriter>
#include <iostream>

int EntryManager::addEntry(const Entry &entry)
{
	int id = mEntries.size();
	mEntries[id] = entry;

	return id;
}


void EntryManager::exportEntries(QIODevice &device) const
{
	QXmlStreamWriter w(&device);
	w.setAutoFormatting(true);
	w.writeStartDocument();
	w.writeStartElement("entries");

	EntryMap::ConstIterator iter = mEntries.constBegin();
	while (iter != mEntries.constEnd())
	{
		iter->writeToXmlStream(w);
		iter++;
	}

	w.writeEndElement();
	w.writeEndDocument();
}


void EntryManager::importEntries(QIODevice &entries)
{
	QXmlStreamReader xml(&entries);

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
		QString str = xml.errorString();
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