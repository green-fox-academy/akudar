#include <string>
#ifndef BLOGPOST_BLOGPOST_H
#define BLOGPOST_BLOGPOST_H


class BlogPost {

    std::string authorName, title, text, publicationDate;

public:

    BlogPost(std::string aName, std::string cTitle, std::string cText, std::string pDate);
};


#endif
