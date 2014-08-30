#include "Entry.h"


Entry::Entry(QDate date, String eventText, std::vector<String> tags, unsigned decimalPlaces)
{
	mDate = date;
	mEventText = eventText;
	mTags = tags;
	mDecimalPlaces = decimalPlaces;
}