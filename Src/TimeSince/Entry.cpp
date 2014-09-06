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

	switch (timeUnit)
	{
	case TimeUnit::Day:
		return QString("%1 days").arg(abs(mDate.daysTo(compareDate)));

	case TimeUnit::Hour:
		return QString("%1 hours").arg(abs(mDate.secsTo(compareDate) / 3600));

	case TimeUnit::Minute:
		return QString("%1 minutes").arg(abs(mDate.secsTo(compareDate) / 60));

	case TimeUnit::Second:
		return QString("%1 seconds").arg(abs(mDate.secsTo(compareDate)));

	default:
		break;
	}
}