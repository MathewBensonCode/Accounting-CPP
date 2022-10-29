#include <memory>
#include "entitybase.hpp"

class Account;

class Transaction : public EntityBase
{
    double m_amount;
    std::weak_ptr<Account> m_debitAccount{};

  public:
    [[nodiscard]] double Amount() const;
    void Amount(double);

    [[nodiscard]] const std::weak_ptr<Account> &DebitAccount() const;
    void DebitAccount(const std::weak_ptr<Account> &);

    [[nodiscard]] const std::weak_ptr<Account> &CreditAccount() const;
    void CreditAccount(const std::weak_ptr<Account> &);
};
