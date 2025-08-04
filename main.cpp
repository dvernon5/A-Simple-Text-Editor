#include <iostream>
#include <string>
#include <stack>

class TextEditor {
    public:
        TextEditor(): text("") {};
        std::string append(const std::string& str) {
            undoStack.push(text);
            text += str;
            return text;
        }

    private:
        std::string text;
        std::stack<std::string> undoStack;
};