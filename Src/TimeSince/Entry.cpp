#include "Entry.h"


Entry::Entry(QDate date, String preText, String postText, std::vector<String> tags)
{
	mDate = date;
	mPreText = preText;
	mPostText = postText;
	mTags = tags;
}