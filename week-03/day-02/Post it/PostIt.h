#include <string>
#ifndef POST_IT_POSTIT_H
#define POST_IT_POSTIT_H


class PostIt {

public:

    std::string text;
    std::string textColor;
    std::string backgroundColor;

    PostIt(std::string txt, std::string tColor, std::string bColor);
};


#endif
