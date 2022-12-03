#include "gtest/gtest.h"

#include "AddressBook/AddressBook.hpp"
#include <fstream>

class AddressBookFixture : public ::testing::Test {
protected:
    AddressBook ab;
};

TEST_F(AddressBookFixture, TestAddFunction) {
<<<<<<< HEAD
    ab.add({1, "Name1", 5});

=======
    // Act
    ab.add({1, "Name1", 5});

    // Assert
>>>>>>> hw_vvtsygankov
    for (const auto &employee: ab.getEmployers()) {
        ASSERT_EQ(employee.id, 1);
        ASSERT_EQ(employee.name, "Name1");
        ASSERT_EQ(employee.grade, 5);
    }
}

TEST_F(AddressBookFixture, TestManyAddFunction) {
<<<<<<< HEAD
=======
    //Average
>>>>>>> hw_vvtsygankov
    const std::forward_list<Employee> &result = {{3, "Name3", 5},
                                                 {2, "Name2", 4},
                                                 {1, "Name1", 5}};

<<<<<<< HEAD
=======
    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    const auto &employers = ab.getEmployers();
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestDelFunctionExistID) {
<<<<<<< HEAD
    const std::forward_list<Employee> &result = {{1, "Name1", 5}};

=======
    //Average
    const std::forward_list<Employee> &result = {{1, "Name1", 5}};

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

<<<<<<< HEAD
    const bool status1 = ab.del(2);
    const bool status2 = ab.del(3);

=======
    bool status1 = ab.del(2);
    bool status2 = ab.del(3);

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(true, status1);
    ASSERT_EQ(true, status2);

    const auto &employers = ab.getEmployers();
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestDelFunctionNotExistID) {
<<<<<<< HEAD
    ab.add({1, "Name1", 5});

    const bool status = ab.del(2);

=======
    // Act
    ab.add({1, "Name1", 5});

    bool status = ab.del(2);

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(false, status);
}

TEST_F(AddressBookFixture, TestFindFunctionExistID) {
<<<<<<< HEAD
    const Employee &result = {2, "Name2", 4};

=======
    //Average
    const Employee &result = {2, "Name2", 4};

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(2);

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(employee.value().id, result.id);
    ASSERT_EQ(employee.value().name, result.name);
    ASSERT_EQ(employee.value().grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistID) {
<<<<<<< HEAD
=======
    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find(4);

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(employee.has_value(), false);
}

TEST_F(AddressBookFixture, TestFindFunctionExistName) {
<<<<<<< HEAD
    const Employee &result = {2, "Name2", 4};

=======
    //Average
    const Employee &result = {2, "Name2", 4};

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name2");

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(employee.begin()->id, result.id);
    ASSERT_EQ(employee.begin()->name, result.name);
    ASSERT_EQ(employee.begin()->grade, result.grade);
}

TEST_F(AddressBookFixture, TestFindFunctionNotExistName) {
<<<<<<< HEAD
=======
    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    const auto &employee = ab.find("Name4");

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_TRUE(employee.empty());
}

TEST_F(AddressBookFixture, TestFindFunctionManyExistName) {
<<<<<<< HEAD
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {3, "Name2", 5}};

=======
    //Average
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {3, "Name2", 5}};

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name2", 5});

    const auto &employers = ab.find("Name2");

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(result, employers);
}

TEST_F(AddressBookFixture, TestClearFunction) {
<<<<<<< HEAD
=======
    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});
    ab.add({3, "Name3", 5});

    ab.clear();

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_TRUE(ab.getEmployers().empty());
}

TEST_F(AddressBookFixture, TestEditingFields) {
<<<<<<< HEAD
    const std::forward_list<Employee> &result = {{3, "Name1", 5},
                                                 {1, "Test", 5}};

=======
    //Average
    const std::forward_list<Employee> &result = {{3, "Name1", 5},
                                                 {1, "Test", 5}};

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    auto el = ab.find(1).value();
    el.name = "Test";
    ab.update(1, el);
    ab.update(2, Employee{3, "Name1", 5});

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    const auto &employers = ab.getEmployers();
    ASSERT_EQ(employers, result);
}

TEST_F(AddressBookFixture, TestCopingAddressBook) {
<<<<<<< HEAD
    const std::forward_list<Employee> &result = {{1, "Name2", 4},
                                                 {2, "Name1", 5}};
=======
    //Average
    const std::forward_list<Employee> &result = {{1, "Name2", 4},
                                                 {2, "Name1", 5}};
    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    auto ab2 = ab;

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(ab2.getEmployers(), ab.getEmployers());
    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestOutputAddressBook) {
<<<<<<< HEAD
    const auto result = "AddressBook: \n"
                         "\t{id: 2, name: Name2, grade: 4} \n"
                         "\t{id: 1, name: Name1, grade: 5} \n"
                         "\tcount : 2\n\n";

=======
    //Average
    std::string result = "AddressBook: \n"
                         "\t{2, Name2, 4} \n"
                         "\t{1, Name1, 5} \n"
                         "\tcount : 2\n\n";

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});
    ab.add({2, "Name2", 4});

    std::ostringstream error;
    error << ab;

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(result, error.str());
}

TEST_F(AddressBookFixture, TestOutputEmployer) {
<<<<<<< HEAD
    const auto result = "\t{id: 1, name: Name1, grade: 5} \n";

    std::ostringstream error;
    error << Employee{1, "Name1", 5};

=======
    //Average
    std::string result = "\t{1, Name1, 5} \n";

    // Act
    std::ostringstream error;
    error << Employee{1, "Name1", 5};

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(result, error.str());
}

TEST_F(AddressBookFixture, TestEqualEmployees) {
<<<<<<< HEAD
    const bool result1 = (Employee{1, "Name1", 5} == Employee{2, "Name1", 5});
    const bool result2 = (Employee{1, "Name2", 5} == Employee{2, "Name1", 5});
    const bool result3 = (Employee{1, "Name1", 4} == Employee{2, "Name1", 5});

=======
    // Act
    bool result1 = (Employee{1, "Name1", 5} == Employee{2, "Name1", 5});
    bool result2 = (Employee{1, "Name2", 5} == Employee{2, "Name1", 5});
    bool result3 = (Employee{1, "Name1", 4} == Employee{2, "Name1", 5});

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_TRUE(result1);
    ASSERT_FALSE(result2);
    ASSERT_FALSE(result3);
}

TEST_F(AddressBookFixture, TestNotEqualEmployees) {
<<<<<<< HEAD
    const bool result1 = (Employee{1, "Name2", 5} != Employee{2, "Name1", 5});
    const bool result2 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 5});
    const bool result3 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 4});

=======
    // Act
    bool result1 = (Employee{1, "Name2", 5} != Employee{2, "Name1", 5});
    bool result2 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 5});
    bool result3 = (Employee{1, "Name1", 4} != Employee{2, "Name1", 4});

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_TRUE(result1);
    ASSERT_TRUE(result2);
    ASSERT_FALSE(result3);
}

TEST_F(AddressBookFixture, TestTakingByIndexID) {
<<<<<<< HEAD
    const Employee result = {1, "Name1", 5};

    ab.add({1, "Name1", 5});
    auto emp = ab[1];

=======
    //Average
    Employee result = Employee{1, "Name1", 5};

    // Act
    ab.add({1, "Name1", 5});
    auto emp = ab[1];

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(emp, result);
}

TEST_F(AddressBookFixture, TestTakingByIndexName) {
<<<<<<< HEAD
    const Employee result = {1, "Name1", 5};

=======
    //Average
    Employee result = Employee{1, "Name1", 5};

    // Act
>>>>>>> hw_vvtsygankov
    ab.add({1, "Name1", 5});

    auto emp = ab["Name1"];

<<<<<<< HEAD
=======
    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(emp, result);
}

TEST_F(AddressBookFixture, TestAddToAddressBookWithPlus) {
<<<<<<< HEAD
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {1, "Name1", 5}};

    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4};

=======
    //Average
    const std::forward_list<Employee> &result = {{2, "Name2", 4},
                                                 {1, "Name1", 5}};

    // Act
    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4};

    // Assert
>>>>>>> hw_vvtsygankov
    ASSERT_EQ(result, ab.getEmployers());
}

TEST_F(AddressBookFixture, TestDeleteToAddressBookWithPlus) {
<<<<<<< HEAD
    const std::forward_list<Employee> &result = {{2, "Name2", 4}};

=======
    //Average
    const std::forward_list<Employee> &result = {{2, "Name2", 4}};

    // Act
>>>>>>> hw_vvtsygankov
    ab += Employee{1, "Name1", 5};
    ab = ab + Employee{2, "Name2", 4} + Employee{3, "Name4", 10};

    ab -= 1;
    ab = ab - 3;

<<<<<<< HEAD
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

=======
    // Assert
    ASSERT_EQ(result, ab.getEmployers());
}

>>>>>>> hw_vvtsygankov
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
