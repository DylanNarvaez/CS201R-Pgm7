#ifndef BOOK_H
#define BOOK_H

#include "Media.h"
#include <ostream>

class Book : public Media {
private:
    int weeksNYT;

public:
    Book(const std::string& title,
        const std::string& keyName,
        int rating,
        const std::string& genre,
        int length,
        int yearReleased,
        int weeksNYT);

    int getWeeks() const;
    void setWeeks(int w);

    void print(std::ostream& os,
        const std::vector<Media*>& mediaList) const override;
};

#endif // BOOK_H

