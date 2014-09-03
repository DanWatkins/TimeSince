#include "Entry.h"


Entry::Entry(QDateTime date, String preText, String postText, std::vector<String> tags)
{
	mDate = date;
	mPreText = preText;
	mPostText = postText;
	mTags = tags;
}


String Entry::buildBaseText(QDateTime compareDate)
{
	if (compareDate < mDate)
		return String("Until ") + mPreText;
	else if (compareDate >= mDate)
		return String("Since ") + mPostText;
}