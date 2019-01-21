#include <iostream>
#include <string>

    // Accidentally I got the wrong URL for a funny subreddit. It's probably "odds" and not "bots"
    // Also, the URL is missing a crucial component, find out what it is and insert it too!

int main(int argc, char* args[])
{
    std::string url("https//www.reddit.com/r/nevertellmethebots");
    std::string from ("bots");
    int startPos = url.find(from);

    url.replace(startPos, from.length(), "oods");

    std::string missing ("//");
    int endPos = url.find(missing);

    url.insert(endPos, ":");

    std::cout << url << std::endl;

    return 0;
}