#include "Movie.h"
#include <iostream>

Movie::Movie(const std::string& title,
    const std::string& keyName,
    int rating,
    const std::string& genre,
    int length,
    int yearReleased,
    const std::vector<std::string>& stars)
    : Media('M', title, keyName, rating, genre, length, yearReleased),
    stars(stars)
{
}

const std::vector<std::string>& Movie::getStars() const {
    return stars;
}

void Movie::setStars(const std::vector<std::string>& s) {
    stars = s;
}

void Movie::print(std::ostream& os,
    const std::vector<Media*>& /*mediaList*/) const {
    os << "Movie: " << title << " (" << yearReleased << ")\n"
        << "  Rating: " << rating << "/10\n"
        << "  Genre: " << genre << "\n"
        << "  Length: " << length << " min\n"
        << "  Stars:\n";
    for (const auto& star : stars) {
        os << "    - " << star << "\n";
    }
    os << "---\n";
}
