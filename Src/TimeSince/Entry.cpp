#include "Entry.h"


Entry::Entry(QDate date, String eventText, std::vector<String> tags)
{
	mDate = date;
	mEventText = eventText;
	mTags = tags;
}