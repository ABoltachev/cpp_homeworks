#include "gtest/gtest.h"

#include "AddressBook/AddressBook.hpp"
#include <fstream>

class AddressBookFixture : public ::testing::Test {
protected:
    AddressBook ab;
};

TEST_F(AddressBookFixture, TestAddFunction) {
    // Act
    ab.add({1, "Name1", 5});

    // Assert
    for (const auto &employee: ab.getEmployers()) {
        ASSERT_EQ(employee.id, 1);
        ASSERT_EQ(employee.name, "Name1");
        ASSERT_EQ(employee.grade, 5);
    }
}

TEST_F(AddressBookFixture, TestManyAddFunction) {
    //Average
    const std::forward_list<Employee> &result = {{3, "Name3", 5},
                                                 {2, "Name2", 4},
                                                 {1, "Name1", 5}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    // Assert
    const auto &employers = ab.getEmployers();
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestDelFunctionExistID) {
    //Average
    const std::forward_list<Employee> &result = {{1, "Name1", 5}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    bool status1 = ab.del(2);
    bool status2 = ab.del(3);

    // Assert
    ASSERT_EQ(true, status1);
    ASSERT_EQ(true, status2);

    const auto &employers = ab.getEmployers();
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestDelFunctionNotExistID) {
    // Act
    ab.add({1, "Name1", 5});

    bool status = ab.del(2);

    // Assert
    ASSERT_EQ(false, status);
}

TEST_F(AddressBookFixture, TestFindFunctionExistID) {
    //Average
    const Employee &result = {2, "Name2", 4};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(2);

    // Assert
    ASSERT_EQ(employee.value().id, result.id);
    ASSERT_EQ(employee.value().name, result.name);
    ASSERT_EQ(employee.value().grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistID) {
    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(4);

    // Assert
    ASSERT_EQ(employee.has_value(), false);
}

TEST_F(AddressBookFixture, TestFindFunctionExistName) {
    //Average
    const Employee &result = {2, "Name2", 4};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name2");

    // Assert
    ASSERT_EQ(employee.begin()->id, result.id);
    ASSERT_EQ(employee.begin()->name, result.name);
    ASSERT_EQ(employee.begin()->grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistName) {
    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name4");

    // Assert
    ASSERT_TRUE(employee.empty());
}

TEST_F(AddressBookFixture, TestFindFunctionManyExistName) {
    //Average
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {3, "Name2", 5}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name2", 5});

    const auto &employers = ab.find("Name2");

    // Assert
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestClearFunction) {
    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    ab.clear();

    // Assert
    ASSERT_TRUE(ab.getEmployers().empty());
}

TEST_F(AddressBookFixture, TestEditingFields) {
    //Average
    const std::forward_list<Employee> &result = {{3, "Name1", 5},
                                                 {1, "Test", 5}};

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    auto el = ab.find(1).value();
    el.name = "Test";
    ab.update(1, el);
    ab.update(2, Employee{3, "Name1", 5});

    // Assert
    const auto &employers = ab.getEmployers();
    ASSERT_EQ(employers, result);
}

TEST_F(AddressBookFixture, TestCopingAddressBook) {
    //Average
    const std::forward_list<Employee> &result = {{1, "Name2", 4},
                                                 {2, "Name1", 5}};
    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    auto ab2 = ab;

    // Assert
    ASSERT_EQ(ab2.getEmployers(), ab.getEmployers());
    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestOutputAddressBook) {
    //Average
    std::string result = "AddressBook: \n"
                         "\t{2, Name2, 4} \n"
                         "\t{1, Name1, 5} \n"
                         "\tcount : 2\n\n";

    // Act
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    std::ostringstream error;
    error << ab;

    // Assert
    ASSERT_EQ(result, error.str());
}

TEST_F(AddressBookFixture, TestOutputEmployer) {
    //Average
    std::string result = "\t{1, Name1, 5} \n";

    // Act
    std::ostringstream error;
    error << Employee{1, "Name1", 5};

    // Assert
    ASSERT_EQ(result, error.str());
}

TEST_F(AddressBookFixture, TestEqualEmployees) {
    // Act
    bool result1 = (Employee{1, "Name1", 5} == Employee{2, "Name1", 5});
    bool result2 = (Employee{1, "Name2", 5} == Employee{2, "Name1", 5});
    bool result3 = (Employee{1, "Name1", 4} == Employee{2, "Name1", 5});

    // Assert
    ASSERT_TRUE(result1);
    ASSERT_FALSE(result2);
    ASSERT_FALSE(result3);
}

TEST_F(AddressBookFixture, TestNotEqualEmployees) {
    // Act
    bool result1 = (Employee{1, "Name2", 5} != Employee{2, "Name1", 5});
    bool result2 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 5});
    bool result3 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 4});

    // Assert
    ASSERT_TRUE(result1);
    ASSERT_TRUE(result2);
    ASSERT_FALSE(result3);
}

TEST_F(AddressBookFixture, TestTakingByIndexID) {
    //Average
    Employee result = Employee{1, "Name1", 5};

    // Act
    ab.add({1, "Name1", 5});
    auto emp = ab[1];

    // Assert
    ASSERT_EQ(emp, result);
}

TEST_F(AddressBookFixture, TestTakingByIndexName) {
    //Average
    Employee result = Employee{1, "Name1", 5};

    // Act
    ab.add({1, "Name1", 5});

    auto emp = ab["Name1"];

    // Assert
    ASSERT_EQ(emp, result);
}

TEST_F(AddressBookFixture, TestAddToAddressBookWithPlus) {
    //Average
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {1, "Name1", 5}};

    // Act
    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4};

    // Assert
    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestDeleteToAddressBookWithPlus) {
    //Average
    const std::forward_list<Employee> &result = {{2, "Name2", 4}};

    // Act
    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4} + Employee{3, "Name4", 10};

    ab -= 1;
    ab = ab - 3;

    // Assert
    ASSERT_EQ(result, ab.getEmployers());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
