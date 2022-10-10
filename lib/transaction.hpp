#include <memory>

class Account;

class Transaction
{
    double m_amount;
    std::shared_ptr<Account> m_debitAccount{};

  public:
    [[nodiscard]] double Amount() const;
    void Amount(double);

    [[nodiscard]] std::shared_ptr<Account> DebitAccount() const;
    void DebitAccount(const std::shared_ptr<Account> &);

    [[nodiscard]] std::shared_ptr<Account> CreditAccount() const;
    void CreditAccount(const std::shared_ptr<Account> &);
};
