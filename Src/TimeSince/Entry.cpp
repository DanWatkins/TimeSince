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


String Entry::buildTimeText(const QDateTime &compareDate) const
{
	return "35 minutes";
}