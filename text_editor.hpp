#ifndef TEXT_EDITOR_HPP
#define TEXT_EDITOR_HPP

#include <iostream>
#include <string>
#include <stack>

class TextEditor {
    public:
        TextEditor();
        std::string append(const std::string& str);
        std::string deleteChar(size_t index);
        void printChars(size_t count);
        void undo();

    private:
        std::string text;
        std::stack<std::string> undoStack;
};

#endif