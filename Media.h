#ifndef MEDIA_H
#define MEDIA_H

#include <string>
#include <vector>
#include <ostream>

class Media {
protected:
    char type;
    std::string title;
    std::string keyName;
    int rating;
    std::string genre;
    int length;
    int yearReleased;

public:
    // Constructor
    Media(char type,
        const std::string& title,
        const std::string& keyName,
        int rating,
        const std::string& genre,
        int length,
        int yearReleased);

    virtual ~Media() = default;

    // Accessors
    char getType() const;
    const std::string& getTitle() const;
    const std::string& getKeyName() const;
    int getRating() const;
    const std::string& getGenre() const;
    int getLength() const;
    int getYearReleased() const;

    // Mutators
    void setRating(int rating);
    void setGenre(const std::string& genre);
    void setLength(int length);
    void setYearReleased(int year);

    // Pure virtual print: makes Media abstract
    virtual void print(std::ostream& os,
        const std::vector<Media*>& mediaList) const = 0;
};

#endif // MEDIA_H

