#include "Entry.h"
#include <map>

class EntryManager
{
private:
	std::map<int, Entry> mEntries;

public:
	int createEntry(std::string title);
	Entry getEntry(int id);

	int entryCount();
};