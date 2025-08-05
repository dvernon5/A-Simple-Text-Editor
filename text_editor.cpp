#include "text_editor.hpp"

TextEditor::TextEditor(): text("") {};

std::string TextEditor::append(const std::string& str) {
    undoStack.push(text);
    text += str;
    return text;
}