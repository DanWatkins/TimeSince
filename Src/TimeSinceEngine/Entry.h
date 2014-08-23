#include <string>

class Entry
{
private:
	std::string mTitle;

public:
	Entry() {}
	Entry(std::string title) { mTitle = title; }
	std::string getTitle() { return mTitle; }
};