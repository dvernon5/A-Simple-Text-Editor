#include <iostream>
#include <string>
#include <stack>

class TextEditor {
    public:
        TextEditor(): text("") {};
        
    private:
        std::string text;
        std::stack<std::string> undoStack;
};