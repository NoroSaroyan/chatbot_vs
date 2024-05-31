#include <exception>
#include <string>

class QANotFoundException : public std::exception
{
public:
    QANotFoundException(const std::string &id) : id_(id) {}

    const char *what() const noexcept override
    {
        // return string("Question with ID '" + id_ + "' not found in the database");
        return "ffff";
    }

private:
    std::string id_;
};
