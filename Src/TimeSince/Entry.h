#ifndef _TIMESINCE_ENTRY_H
#define _TIMESINCE_ENTRY_H

#include <string>
#include <vector>
#include <QtCore/QDate>

typedef std::string String;

class Entry
{
private:
	String mTitle;
	QDate mDate;
	String mEventText;
	std::vector<String> mTags;
	unsigned mDecimalPlaces;

public:
	Entry() {}
	Entry(String title) { mTitle = title; }
	Entry(QDate date, String eventText, std::vector<String> tags, unsigned decimalPlaces);

	String getTitle() { return mTitle; }

	QDate getDate() { return mDate; }
	String getEventText() { return mEventText; }
	std::vector<String> getTags() { return mTags; }
	unsigned getDecimalPlaces() { return mDecimalPlaces; }
};

#endif
