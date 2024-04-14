#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <exception>
#include <stdexcept>
#include <string>

class FileException : public std::runtime_error
{
public:
    explicit FileException(const std::string &message) : std::runtime_error(message) {}
};

#endif // EXCEPTION_HPP

class MatrixKosongException : public std::exception{
public:
    const char* what() const noexcept override {
        return "Storage Kosong";
    }
};
class NofoodException : public std::exception{
public:
    const char* what() const noexcept override {
        return "Tidak ada makanan!";
    }
};
