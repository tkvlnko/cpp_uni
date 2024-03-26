#include "bank_accounts.h"


const std::string dataPath = "data/transactions_accounts.csv";

// void test1()
// {
//     std::cout << "Test #1\n";
//     // here and below all uuids have been reduced to 8 symbols for code readability
//     // ad901393-93fd-45d8-9fed-aa590d055dd5 -> ad901393
//     Account person1("05c054e2", "Ivan");
//     Account person2("90599b00", "Anton", 1836992435);

//     person1.printInfo();
//     person2.printInfo();

//     std::cout << "Test #1 end!\n\n";
// }

// void test2()
// {
//     std::cout << "Test #2\n";

//     Transaction trans1{"ad901393", 1710928800, "deposit", "", "05c054e2", 2024};
//     Transaction trans2{"afe700a5", 1710928801, "transfer", "05c054e2", "90599b00", 100};
//     Transaction trans3{"bfe700a5", 1710928801, "transfer", "05c054e2", "90599b00", 100};

//     std::cout << (trans1 < trans2) << (trans2 < trans3);

//     std::cout << "Test #2 end!\n\n";
// }

// void test3()
// {
//     std::cout << "Test #3\n";

//     Account person("05c054e2", "Ivan");
//     person.addTransaction({"ad901393", 1710928800, "deposit", "", "05c054e2", 2024});
//     person.addTransaction({"afe700a5", 1710930600, "transfer", "05c054e2", "90599b00", 100});
//     person.addTransaction({"6ba3d9e4", 1710934200, "withdraw", "05c054e2", "", 63});
//     person.addTransaction({"afe700a5", 1710930600, "transfer", "05c054e2", "05c054e2", 100});

//     std::cout << (person.getBalance() == 1861 ? "ok!" : "not ok(") << '\n';
//     std::cout << "Test #3 end!\n\n";
// }

void test4()
{
    std::cout << "Test #4\n";

    Account person("05c054e2", "Ivan");

    Transaction trans1{"ad901393", 1710928800, "deposit", "", "05c054e2", 2024};
    Transaction trans2{"afe700a5", 1710930600, "transfer", "05c054e2", "90599b00", 10.10};
    Transaction trans3{"afe700a6", 1710930600, "transfer", "05c054e2", "90599b00", 256.512};
    Transaction trans4{"afe700a7", 1710930600, "withdraw", "05c054e2", "", 3.1415};

    person.addTransaction(trans1);
    person.getBalance();


    person.addTransaction(trans2);
    person.getBalance();

    person.addTransaction(trans3);
    person.getBalance();

    person.addTransaction(trans4);
    person.getBalance();


    std::cout << (person.getTransactionsCount() == 3 ? "ok!" : "not ok(") << '\n';
    // std::cout << trans1.amount << '\n';
    // std::cout << trans2.amount << '\n';

    // std::cout << trans3.amount << '\n';

    // std::cout << trans4.amount << '\n';


    std::cout << "Test #4 end!\n\n";
}

void test5()
{
    std::cout << "Test #5\n";

    std::ifstream fileStream(dataPath);
    if (!fileStream)
    {
        std::cerr << "file not found\n";
    }

    TransactionContainer transactions = readTransactions(fileStream);

    std::cout << "Transaction list:\n";
    for (const TransactionContainer::value_type& trans: transactions)
        std::cout << trans.id << ' ' << trans.date << ' ' << trans.type << ' ' << trans.amount << '\n';


    AccountContainer accounts = readAccounts(fileStream);
    fillAccounts(accounts, transactions);

    std::cout << "Account list:\n";
    for (const AccountContainer::value_type& pair: accounts)
        std::cout << pair.first << '\t' << pair.second.getBalance() << '\n';

    std::cout << "Test #5 end!\n\n";
}


int main()
{
    // uncomment test for task
    // test1();
    // test2();
    // test3();
    test4();
    // test5();

    return 0;
}
