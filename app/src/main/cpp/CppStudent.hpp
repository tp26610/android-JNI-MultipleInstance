//
// Created by Yeh on 2016/11/22.
//

#ifndef JNI_MULTIPLEINSTANCE_CPPSTUDENT_HPP
#define JNI_MULTIPLEINSTANCE_CPPSTUDENT_HPP

#include <string>

class CppStudent {
private:
    std::string mId;
    std::string mName;

public:
    CppStudent(const char *id, const char *name);

    std::string getName();

    std::string getID();
}; // CppStudent

CppStudent::CppStudent(const char *id, const char *name) {
    mId = id;
    mName = name;
}

std::string CppStudent::getName() {
    return mName;
}

std::string CppStudent::getID() {
    return mId;
}


#endif //JNI_MULTIPLEINSTANCE_CPPSTUDENT_HPP
