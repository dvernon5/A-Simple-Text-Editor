#include "request_manager.hpp"

RequestManager::RequestManager() {}

int RequestManager::getQueryCount() {
    std::cin >> queryCount;

    return queryCount;
}

int RequestManager::getQueryType() {
    std::cout << "Enter query type (1-4): ";
    while (!(std::cin >> queryType) || queryType < 1 || queryType > 4) {
        std::cerr << "Invalid input. Please enter a valid query type (1-4): ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    return queryType;
}

int RequestManager::getIndex() {
    std::cout << "Enter index: ";
    while (!(std::cin >> index)) {
        std::cerr << "Invalid input. Please enter a valid index: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the input buffer

    return index;
}

std::string RequestManager::getString() {
    std::cout << "Enter string: ";
    std::getline(std::cin, str);
    return str;
}

void RequestManager::processQueries() {
    queryCount = getQueryCount();
    for (int i = 0; i < queryCount; ++i) {
        std::cout << "Processing query " << (i + 1) << " of " << queryCount << "\n";
        std::cout << "---------------------------------\n";
        queryType = getQueryType();
        switch (queryType) {
            case 1: {
                str = getString();
                std::cout << editor.append(str) << "\n";
                break;
            }
            case 2: {
                index = getIndex();
                std::cout << editor.deleteChar(index) << "\n";
                break;
            }
            case 3: {
                size_t count = getIndex();
                editor.printChars(count);
                break;
            }
            case 4: {
                editor.undo();
                break;
            }
            default:
                std::cerr << "Invalid query type.\n";
                break;
        }
    }
}