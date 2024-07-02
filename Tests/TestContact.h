#ifndef TESTCONTACT_H
#define TESTCONTACT_H

#include <gtest/gtest.h>
#include "Task.h"
#include <QString>


class TestContact : public ::testing::Test {
public:
    TestContact();
    ~TestContact();
    Task *task;
    void SetUp();
    void TearDown();
};

#endif //TESTCONTACT_H
