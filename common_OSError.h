#ifndef OSERROR_H
#define OSERROR_H

#include <exception>
#define BUF_LEN 256

class OSError: public std::exception{
    private:
        char msg_error[BUF_LEN];
    
    public:
        explicit OSError(const char* fmt, ...) noexcept;
        virtual const char *what() const noexcept;
        virtual ~OSError() noexcept;
};

#endif
