#include "gtest/gtest.h"

#include "AddressBook/AddressBook.hpp"
#include <fstream>

class AddressBookFixture : public ::testing::Test {
protected:
    AddressBook ab;
};

TEST_F(AddressBookFixture, TestAddFunction) {
    ab.add({1, "Name1", 5});

    for (const auto &employee: ab.getEmployers()) {
        ASSERT_EQ(employee.id, 1);
        ASSERT_EQ(employee.name, "Name1");
        ASSERT_EQ(employee.grade, 5);
    }
}

TEST_F(AddressBookFixture, TestManyAddFunction) {
    const std::forward_list<Employee> &result = {{3, "Name3", 5},
                                                 {2, "Name2", 4},
                                                 {1, "Name1", 5}};

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employers = ab.getEmployers();
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestDelFunctionExistID) {
    const std::forward_list<Employee> &result = {{1, "Name1", 5}};

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const bool status1 = ab.del(2);
    const bool status2 = ab.del(3);

    ASSERT_EQ(true, status1);
    ASSERT_EQ(true, status2);

    const auto &employers = ab.getEmployers();
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestDelFunctionNotExistID) {
    ab.add({1, "Name1", 5});

    const bool status = ab.del(2);

    ASSERT_EQ(false, status);
}

TEST_F(AddressBookFixture, TestFindFunctionExistID) {
    const Employee &result = {2, "Name2", 4};

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(2);

    ASSERT_EQ(employee.value().id, result.id);
    ASSERT_EQ(employee.value().name, result.name);
    ASSERT_EQ(employee.value().grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistID) {
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(4);

    ASSERT_EQ(employee.has_value(), false);
}

TEST_F(AddressBookFixture, TestFindFunctionExistName) {
    const Employee &result = {2, "Name2", 4};

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name2");

    ASSERT_EQ(employee.begin()->id, result.id);
    ASSERT_EQ(employee.begin()->name, result.name);
    ASSERT_EQ(employee.begin()->grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistName) {
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name4");

    ASSERT_TRUE(employee.empty());
}

TEST_F(AddressBookFixture, TestFindFunctionManyExistName) {
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {3, "Name2", 5}};

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name2", 5});

    const auto &employers = ab.find("Name2");

    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestClearFunction) {
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    ab.clear();

    ASSERT_TRUE(ab.getEmployers().empty());
}

TEST_F(AddressBookFixture, TestEditingFields) {
    const std::forward_list<Employee> &result = {{3, "Name1", 5},
                                                 {1, "Test", 5}};

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    auto el = ab.find(1).value();
    el.name = "Test";
    ab.update(1, el);
    ab.update(2, Employee{3, "Name1", 5});

    const auto &employers = ab.getEmployers();
    ASSERT_EQ(employers, result);
}

TEST_F(AddressBookFixture, TestCopingAddressBook) {
    const std::forward_list<Employee> &result = {{1, "Name2", 4},
                                                 {2, "Name1", 5}};
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    auto ab2 = ab;

    ASSERT_EQ(ab2.getEmployers(), ab.getEmployers());
    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestOutputAddressBook) {
    const auto result = "AddressBook: \n"
                         "\t{id: 2, name: Name2, grade: 4} \n"
                         "\t{id: 1, name: Name1, grade: 5} \n"
                         "\tcount : 2\n\n";

    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    std::ostringstream error;
    error << ab;

    ASSERT_EQ(result, error.str());
}

TEST_F(AddressBookFixture, TestOutputEmployer) {
    const auto result = "\t{id: 1, name: Name1, grade: 5} \n";

    std::ostringstream error;
    error << Employee{1, "Name1", 5};

    ASSERT_EQ(result, error.str());
}

TEST_F(AddressBookFixture, TestEqualEmployees) {
    const bool result1 = (Employee{1, "Name1", 5} == Employee{2, "Name1", 5});
    const bool result2 = (Employee{1, "Name2", 5} == Employee{2, "Name1", 5});
    const bool result3 = (Employee{1, "Name1", 4} == Employee{2, "Name1", 5});

    ASSERT_TRUE(result1);
    ASSERT_FALSE(result2);
    ASSERT_FALSE(result3);
}

TEST_F(AddressBookFixture, TestNotEqualEmployees) {
    const bool result1 = (Employee{1, "Name2", 5} != Employee{2, "Name1", 5});
    const bool result2 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 5});
    const bool result3 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 4});

    ASSERT_TRUE(result1);
    ASSERT_TRUE(result2);
    ASSERT_FALSE(result3);
}

TEST_F(AddressBookFixture, TestTakingByIndexID) {
    const Employee result = {1, "Name1", 5};

    ab.add({1, "Name1", 5});
    auto emp = ab[1];

    ASSERT_EQ(emp, result);
}

TEST_F(AddressBookFixture, TestTakingByIndexName) {
    const Employee result = {1, "Name1", 5};

    ab.add({1, "Name1", 5});

    auto emp = ab["Name1"];

    ASSERT_EQ(emp, result);
}

TEST_F(AddressBookFixture, TestAddToAddressBookWithPlus) {
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {1, "Name1", 5}};

    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4};

    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestDeleteToAddressBookWithPlus) {
    const std::forward_list<Employee> &result = {{2, "Name2", 4}};

    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4} + Employee{3, "Name4", 10};

    ab -= 1;
    ab = ab - 3;

    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestSumTwoBooks) {
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {3, "Test2", 2}};

    ab.add({2, "Name2", 4});
    AddressBook ab2;
    ab2.add({3, "Test2", 2});
    AddressBook c = ab2 + ab;

    ASSERT_EQ(result, c.getEmployers());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
