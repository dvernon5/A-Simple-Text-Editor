#ifndef REQUEST_MANAGER_HPP
#define REQUEST_MANAGER_HPP

#include <iostream>
#include <string>
#include "text_editor.hpp"

class RequestManager {
    public:
        RequestManager();
        // Additional methods for managing requests can be added here
        int getQueryCount();
        int getQueryType();
        int getIndex();
        std::string getString();
        void processQueries();

    private:
        int queryCount;
        int queryType;
        size_t index;
        std::string str;
        TextEditor editor; 
};

#endif
