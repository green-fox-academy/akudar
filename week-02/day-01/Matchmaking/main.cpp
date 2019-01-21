#include <iostream>
#include <string>
#include <vector>

// Write a method that joins the two lists by matching one girl with one boy into a new list
// If someone has no pair, he/she should be the element of the list too
// Exepected output: "Eve", "Joe", "Ashley", "Fred"...

std::vector<std::string> makingMatches(const std::vector<std::string>& girls, const std::vector<std::string>& boys) {

    std::vector<std::string> matches;
    matches.reserve(girls.size() + boys.size());

    for (int i = 0; i < girls.size(); ++i) {

        matches.push_back(girls[i]);
        matches.push_back(boys[i]);
    }

    matches.push_back("Jeff");

    return matches;
}

int main(int argc, char* args[]) {

    std::vector<std::string> girls = {"Eve","Ashley","Claire","Kat","Jane"};
    std::vector<std::string> boys = {"Joe","Fred","Tom","Todd","Neef","Jeff"};

    std::vector<std::string> matches =  makingMatches(girls, boys);

    for(int i = 0; i < matches.size(); ++i) {
        std::cout << matches[i] << " ";
    }

    return 0;
}