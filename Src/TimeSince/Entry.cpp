#include "Entry.h"
#include <iostream>

Entry::Entry(const QDateTime &date, const QString &preText, const QString &postText)
{
	mDate = date;
	mPreText = preText;
	mPostText = postText;
}


QString Entry::buildBaseText(const QDateTime &compareDate) const
{
	if (compareDate < mDate)
		return QString("until ") + mPreText;
	else if (compareDate >= mDate)
		return QString("since ") + mPostText;
}


QString Entry::buildTimeText(const QDateTime &compareDate, TimeUnit timeUnit) const
{
	int value = 0;
	QString unit = " ";
	unit.reserve(10);

	switch (timeUnit)
	{
	case TimeUnit::Day:
		value = mDate.daysTo(compareDate);
		unit += "day";
		break;

	case TimeUnit::Hour:
		value = mDate.secsTo(compareDate) / 3600;
		unit += "hour";
		break;

	case TimeUnit::Minute:
		value = mDate.secsTo(compareDate) / 60;
		unit += "minute";
		break;

	case TimeUnit::Second:
		value = mDate.secsTo(compareDate);
		unit += "second";
		break;
	}

	//value will be negative if compareDate is before mDate
	//we are only concerned about the unsigned difference
	value = abs(value);

	if (value == 1)
		return QString::number(value) + unit;

	return QString::number(value) + unit + "s";
}


QString Entry::buildFullText(const QDateTime &compareDate, TimeUnit timeUnit) const
{
	return buildTimeText(compareDate, timeUnit) + " " + buildBaseText(compareDate);
}


//TODO are thre enough tests for this method?
bool Entry::operator == (const Entry &rhs) const
{
	return mDate == rhs.mDate &&
			mPreText == rhs.mPreText &&
			mPostText == rhs.mPostText &&
			mTags == rhs.mTags;
}


void Entry::writeToXmlStream(QXmlStreamWriter &stream) const
{
	stream.writeStartElement("entry");
	{
		stream.writeAttribute("date", mDate.toString());
		stream.writeAttribute("preText", mPreText);
		stream.writeAttribute("postText", mPostText);

		TagsMap::ConstIterator iter = mTags.constBegin();
		while (iter != mTags.constEnd())
		{
			if (iter.value() == true)
				stream.writeTextElement("tag", iter.key());

			iter++;
		}
	}
	stream.writeEndElement();
}


void Entry::readFromXmlStream(QXmlStreamReader &xml)
{
	QXmlStreamAttributes attributes = xml.attributes();

	if (attributes.hasAttribute("date"))
		mDate = QDateTime::fromString(attributes.value("date").toString());
	
	if (attributes.hasAttribute("preText"))
		mPreText = attributes.value("preText").toString();

	if (attributes.hasAttribute("postText"))
		mPostText = attributes.value("postText").toString();

	while (xml.tokenType() != QXmlStreamReader::EndElement || xml.name() == "tag")
	{
		if (xml.tokenType() == QXmlStreamReader::StartElement)
		{
			if (xml.name() == "tag")
			{
				xml.readNext();
				addTag(xml.text().toString());
			}
		}

		xml.readNext();
	}
}