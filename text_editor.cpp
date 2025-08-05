#include "text_editor.hpp"

TextEditor::TextEditor(): text("") {};

std::string TextEditor::append(const std::string& str) {
    undoStack.push(text);
    text += str;
    return text;
}

std::string TextEditor::deleteChar(size_t index) {
    undoStack.push(text);
    if (index > text.length()) {
        text = "";
    } else {
        text.erase(text.length() - index);
    }
    return text;
}

void TextEditor::printChars(size_t count) {
    if (count > text.length()) {
        std::cerr << "The text is too short.\n";
    } else {
        std::cout << text[count - 1] << "\n";
    }
}