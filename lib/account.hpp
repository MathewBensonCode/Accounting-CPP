#include <string_view>
#include <string>
#include <memory>
#include <vector>
#include "entitybase.hpp"

class Transaction;

class Account : public EntityBase
{
    std::string m_name;
    float m_amount{ 0.0F };
    std::vector<std::shared_ptr<Transaction>> m_debits{};
    std::vector<std::shared_ptr<Transaction>> m_credits{};

  public:
    Account() = default;
    explicit Account(std::string_view);

    [[nodiscard]] std::string_view name() const;
    void name(std::string_view);

    [[nodiscard]] float amount() const;
    void amount(float);

    [[nodiscard]] const std::vector<std::shared_ptr<Transaction>> &Debits() const;
    [[nodiscard]] const std::vector<std::shared_ptr<Transaction>> &Credits() const;
};
