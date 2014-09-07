#include "Entry.h"


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