#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>

class FileException : public std::runtime_error
{
public:
    explicit FileException(const std::string &message) : std::runtime_error(message) {}
};

#endif // EXCEPTION_HPP
