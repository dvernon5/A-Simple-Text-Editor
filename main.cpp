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
        
        std::string deleteChar(size_t index) {
            undoStack.push(text);
            if (index > text.length()) {
                text = "";
            } else {
                text = text.erase(text.length() - index);
            }
        }

        void printChars(size_t count) {
            if (count > text.length()) {
                std::cerr << "The text is too short.\n";
            }
            else {
                std::cout << text[count - 1] << "\n";
            }
        }

        void undo() {
            if (!undoStack.empty()) { 
                text = undoStack.top();
                undoStack.pop();
            }
        }

    private:
        std::string text;
        std::stack<std::string> undoStack;
};