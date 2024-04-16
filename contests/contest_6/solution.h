#ifndef SOLUTION_H
#define SOLUTION_H

#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

enum class CitationType
{
    WebPage,
    Article
};

class Citation
{
public:
    std::string _title;

    Citation(const std::string& title, int year)
        : _title(title), _year(year)
    {
    }

    virtual ~Citation() {}
    virtual void printCitation(std::ostream& ostr) const = 0;
    // task 3 function included here
    virtual std::string getInlineCitation() const
    {
        return "";
    };

protected:
    int _year;
};

class PublishedWork : public Citation
{
public:
    std::string _lastname;

    PublishedWork(const std::string& title, int year,
                  const std::string& firstname, const std::string& lastname)
        : Citation(title, year), _firstname(firstname), _lastname(lastname)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname << " " << _lastname << std::endl;
    }

protected:
    std::string _firstname;
};

class WebPage : public Citation
{
public:
    WebPage(const std::string& title, int year, const std::string& url)
        : Citation(title, year),
          _url(url)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "URL: " << _url << std::endl;
    }

    std::string getInlineCitation() const override
    {
        return "[Web page, " + std::to_string(_year) + "]";
    }

    bool operator>(const WebPage& other) const
    {
        return (_title > other._title);
    }

protected:
    std::string _url;
};


// task 1

class Article : public PublishedWork
{
public:
    Article(const std::string& title, int year,
            const std::string& firstname, const std::string& lastname, const std::string& journal)
        : PublishedWork(title, year, firstname, lastname), _journal(journal)
    {
    }

    void printCitation(std::ostream& ostr) const override
    {
        ostr << "Title: " << _title << std::endl;
        ostr << "Year: " << _year << std::endl;
        ostr << "Author: " << _firstname << " " << _lastname << std::endl;
        ostr << "Journal: " << _journal << std::endl;
    }
    std::string getInlineCitation() const override
    {
        return "[" + _lastname + ", " + std::to_string(_year) + "]";
    }

    bool operator>(const Article& other) const
    {
        return (_lastname > other._lastname);
    }

protected:
    std::string _journal;
};

// example 2 - Book
// included only as an example, not used in the tasks
// class Book : public PublishedWork
// {
// public:
//     Book(const std::string& title, int year, const std::string& firstname, const std::string& lastname, const std::string& publisher)
//         : PublishedWork(title, year, firstname, lastname),
//           _publisher(publisher)
//     {
//     }

//     void printCitation(std::ostream& ostr) const override
//     {
//         PublishedWork::printCitation(ostr);
//         ostr << "Publisher:" << _publisher << std::endl;
//     }

// protected:
//     std::string _publisher;
// };


// task 2
Citation* addCitation(std::map<std::string, Citation*>& citations, CitationType type, const std::map<std::string, std::string> data)
{
    Citation* citationToAdd;
    std::string key, title, year;
    key = data.at("key");
    title = data.at("title");
    year = data.at("year");

    switch (type)
    {
        case CitationType::WebPage: {
            std::string url = data.at("url");
            citationToAdd = new WebPage(title, std::stoi(year), url);
            break;
        }

        case CitationType::Article: {
            std::string firstname = data.at("firstname");
            std::string lastname = data.at("lastname");
            std::string journal = data.at("journal");
            citationToAdd = new Article(title, std::stoi(year), firstname, lastname, journal);
            break;
        }

        default: {
            break;
        }
    }

    citations[key] = citationToAdd;
    return citationToAdd;
}


// task 4
void insertInlineCitations(std::string& text, const std::map<std::string, Citation*>& citations)
{
    for (const auto& cit: citations)
    {
        std::string key = cit.first;
        std::string inlineCitation = cit.second->getInlineCitation();
        // std::cout << "!!!!!" << key << " " << inlineCitation << std::endl;
        size_t pos = text.find(key);
        while (pos != std::string::npos)
        {
            text.replace(pos, key.size(), inlineCitation);
            pos = text.find(key, pos + inlineCitation.size());
        }
    }
}


// task 5
void printBibliographyAppearance(std::string& text, const std::map<std::string, Citation*>& citations)
{
    int count = 1;
    std::set<Citation*> usedCitations;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word)
    {
        if (word[word.size() - 1] == '.')
        {
            word = word.substr(0, word.size() - 1);
        }
        if ((citations.find(word) != citations.end()) && (usedCitations.find(citations.at(word)) == usedCitations.end()))
        {
            std::cout << (count++) << "." << std::endl;
            citations.at(word)->printCitation(std::cout);
            usedCitations.insert(citations.at(word));
        }
    }
}

bool compare(const std::pair<std::string, Citation*>& a, const std::pair<std::string, Citation*>& b)
{
    if (dynamic_cast<Article*>(a.second) && dynamic_cast<WebPage*>(b.second))
    {
        return true;
    }
    else if (dynamic_cast<Article*>(a.second) && dynamic_cast<Article*>(b.second))
    {
        return dynamic_cast<Article*>(a.second)->_lastname > dynamic_cast<Article*>(b.second)->_lastname;
    }
    else if (dynamic_cast<WebPage*>(a.second) && dynamic_cast<WebPage*>(b.second))
    {
        return dynamic_cast<WebPage*>(a.second)->_title > dynamic_cast<WebPage*>(b.second)->_title;
    }
    return false;
}

// task 6
// you may modify classes in any way you want to solve this task
// you may add additional functions
void insertInlineAlphabetical(std::string& text, const std::map<std::string, Citation*>& citations)
{
    std::map<std::string, int> indeces;
    std::vector<std::pair<std::string, Citation*>> temp(citations.begin(), citations.end());
    std::sort(temp.begin(), temp.end(), compare);

    int index = 1;
    for (const auto& pair: temp)
    {
        indeces.insert({pair.first, index++});
    }

    std::stringstream ss(text);
    std::string word;
    while (ss >> word)
    {
        if (word[word.size() - 1] == '.')
        {
            word = word.substr(0, word.size() - 1);
        }
        if ((indeces.find(word) != indeces.end()))
        {
            size_t pos = text.find(word);
            text.replace(pos, word.size(), "[" + std::to_string(indeces.at(word)) + "]");
        }

        // for (const auto& cit: temp)
        // {
        //     std::cout << "!!!!!" << cit.first << " " << cit.second->getInlineCitation() << std::endl;
        // }
    }
}

#endif