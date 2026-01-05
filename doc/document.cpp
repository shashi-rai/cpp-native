// Copyright (c) 2018 Bhojpur Consulting Private Limited, India. All rights reserved.

// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "document.h"

namespace doc {

Document::Document() : name(), created(), expired(), chapters() {

}

Document::Document(const ChapterArray& chapters)
        : name(), created(), expired(), chapters(chapters) {

}

Document::Document(std::string name)
        : name(name), created(), expired(), chapters() {

}

Document::Document(std::string name, const ChapterArray& chapters)
        : name(name), created(), expired(), chapters(chapters) {

}

Document::Document(const act::DateTime& expired)
        : name(), created(), expired(expired), chapters() {

}

Document::Document(const act::DateTime& expired, const ChapterArray& chapters)
        : name(), created(), expired(expired), chapters(chapters) {

}

Document::Document(std::string name, const act::DateTime& expired)
        : name(name), created(), expired(expired), chapters() {

}

Document::Document(std::string name, const act::DateTime& expired, const ChapterArray& chapters)
        : name(name), created(), expired(expired), chapters(chapters) {

}

Document::Document(const act::DateTime& created, const act::DateTime& expired)
        : name(), created(created), expired(expired), chapters() {

}

Document::Document(const act::DateTime& created, const act::DateTime& expired, const ChapterArray& chapters)
        : name(), created(created), expired(expired), chapters(chapters) {

}

Document::Document(std::string name, const act::DateTime& created, const act::DateTime& expired)
        : name(name), created(created), expired(expired), chapters() {

}

Document::Document(std::string name, const act::DateTime& created, const act::DateTime& expired, const ChapterArray& chapters)
        : name(name), created(created), expired(expired), chapters(chapters) {

}

Document::~Document() {

}

bool Document::operator==(const Document& peer) const {
    return (name == peer.name)
        && (created == peer.created)
        && (expired == peer.expired)
        && (chapters == peer.chapters);
}

Document Document::operator+(const Document& peer) const {
    ChapterArray result(chapters);
    result.insert(result.end(), peer.chapters.begin(), peer.chapters.end());
    return Document("+", (created + peer.created), (expired + peer.expired), result);
}

Document Document::operator-(const Document& peer) const {
    ChapterArray result(chapters);
    for (ChapterArray::const_iterator it = peer.chapters.begin(); it != peer.chapters.end(); ++it) {
        ChapterArray::iterator found = std::find(result.begin(), result.end(), *it);
        if (found != result.end()) {
            result.erase(found);
        }
    }
    return Document("-", (created - peer.created), (expired - peer.expired), result);
}

int Document::getChapterCount() const {
    return chapters.size();
}

Chapter Document::get(const int index) const {
    Chapter result;
    if (index < 0) {
        return result;
    }
    if (index >= static_cast<int>(chapters.size())) {
        return result;
    }
    return chapters[index];
}

void Document::set(const int index, const Chapter& object) {
    if (index < 0) {
        return;
    }
    if (index < static_cast<int>(chapters.size())) {
        // replace existing element
        chapters[index] = object;
    } else if (index == static_cast<int>(chapters.size())) {
        // append at end
        chapters.push_back(object);
    } else {
        // index beyond current size: append at end
        chapters.push_back(object);
    }
    return;
}

Document Document::copy() {
    Document fresh(name, created, expired, chapters);
    return fresh;
}

void Document::clear() {
    name.clear();
    created.clear();
    expired.clear();
    chapters.clear();
    return;
}

std::string Document::print() {
    std::stringstream result;
	result << "D:";
    result << name << ",c:";
    result << created.print() << ",x:";
    result << expired.print() << ",sz:";
	result << chapters.size() << "[";
    for (int i = 0; i < chapters.size(); i++) {
        result << "," << chapters[i].print() << std::endl;
    }
    result << "]";
	return result.str();
}

} // namespace doc