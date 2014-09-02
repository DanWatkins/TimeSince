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
	String mPreText, mPostText;
	std::vector<String> mTags;

public:
	Entry() {}
	Entry(String title) { mTitle = title; }
	Entry(QDate date, String preText, String postText, std::vector<String> tags);

	String buildBaseText(QDate compareDate);

	String getTitle() { return mTitle; }
	QDate getDate() { return mDate; }
	String getPreText() { return mPreText; }
	String getPostText() { return mPostText; }
	std::vector<String> getTags() { return mTags; }
};

#endif
