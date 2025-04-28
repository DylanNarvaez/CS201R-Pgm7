#include "Media.h"

Media::Media(char type,
    const std::string& title,
    const std::string& keyName,
    int rating,
    const std::string& genre,
    int length,
    int yearReleased)
    : type(type),
    title(title),
    keyName(keyName),
    rating(rating),
    genre(genre),
    length(length),
    yearReleased(yearReleased)
{
}

char Media::getType() const { return type; }
const std::string& Media::getTitle() const { return title; }
const std::string& Media::getKeyName() const { return keyName; }
int Media::getRating() const { return rating; }
const std::string& Media::getGenre() const { return genre; }
int Media::getLength() const { return length; }
int Media::getYearReleased() const { return yearReleased; }

void Media::setRating(int r) { rating = r; }
void Media::setGenre(const std::string& g) { genre = g; }
void Media::setLength(int l) { length = l; }
void Media::setYearReleased(int y) { yearReleased = y; }
