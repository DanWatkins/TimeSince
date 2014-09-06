#include "Entry.h"


Entry::Entry(const QDateTime &date, const String &preText, const String &postText, const std::vector<String> &tags)
{
	mDate = date;
	mPreText = preText;
	mPostText = postText;
	mTags = tags;
}


String Entry::buildBaseText(const QDateTime &compareDate) const
{
	if (compareDate < mDate)
		return String("Until ") + mPreText;
	else if (compareDate >= mDate)
		return String("Since ") + mPostText;
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

	value = abs(value);

	if (value == 1)
		return QString::number(value) + unit;

	return QString::number(value) + unit + "s";
}