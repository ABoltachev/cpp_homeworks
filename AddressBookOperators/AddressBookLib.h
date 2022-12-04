#ifndef HOMEWORKS_TESTS_ADDRESSBOOKLIB_H
#define HOMEWORKS_TESTS_ADDRESSBOOKLIB_H

namespace AddressBookLib {
    using std::forward_list;
    class Employee;

    class AddressBook {
        std::forward_list<Employee> m_recordList;
    public:
        AddressBook() = default;
        AddressBook(const AddressBook &book) = default;
        AddressBook& operator= (const AddressBook &another);

        void addNewRecord(uint32_t new_id, const std::string &new_name, uint16_t new_grade);
        void addNewRecord(Employee &new_record);
        void removeRecordById(uint32_t id);
        Employee& findRecordById(uint32_t id);
        Employee& findRecordByName(const std::string &name);
        [[nodiscard]] Employee const& findRecordById(uint32_t id) const;
        [[nodiscard]] Employee const& findRecordByName(const std::string &name) const;
        void clear();

        friend std::ostream& operator<< (std::ostream &out, const AddressBook &book);
        void print() const;

        AddressBook& operator+= (Employee &employee);
        AddressBook& operator-= (Employee &employee);

        Employee const& operator[] (const int index) const;
        Employee const& operator[] (const std::string& index_name) const;

        Employee& operator[] (const int index);
        Employee& operator[] (const std::string& index_name);
    };
};


#endif //HOMEWORKS_TESTS_ADDRESSBOOKLIB_H
