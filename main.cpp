#include "table.h"

int main()
{
	Website website1("News", "www.npr.com", "National Public Radio homepage", "reliable news source", 5);
        Website website2("Social Media", "www.reddit.com", "Homepage of the internet", "fun way to kill time", 4);
	Table table;
	table.insert(website1);
	table.insert(website2);
	table.display();
	return 0;
}
