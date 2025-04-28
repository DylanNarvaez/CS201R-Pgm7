#ifndef MOVIE_H
#define MOVIE_H

#include "Media.h"
#include <vector>
#include <string>
#include <ostream>

class Movie : public Media {
private:
    std::vector<std::string> stars;

public:
    Movie(const std::string& title,
        const std::string& keyName,
        int rating,
        const std::string& genre,
        int length,
        int yearReleased,
        const std::vector<std::string>& stars);

    const std::vector<std::string>& getStars() const;
    void setStars(const std::vector<std::string>& s);

    void print(std::ostream& os,
        const std::vector<Media*>& mediaList) const override;
};

#endif // MOVIE_H

