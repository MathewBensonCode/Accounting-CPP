#include <string_view>
#include <string>
#include <memory>
#include <vector>

class Transaction;

class Account
{
    uint m_id;
    std::string m_name;
    float m_amount{0.0F};
    std::vector<std::shared_ptr<Transaction>> m_debits{};
    std::vector<std::shared_ptr<Transaction>> m_credits{};

  public:
    Account() = default;
    explicit Account(std::string_view);

    uint Id() const;
    void Id(const uint);

    [[nodiscard]] std::string_view name() const;
    void name(std::string_view);

    [[nodiscard]] float amount() const;
    void amount(float);

    [[nodiscard]] const std::vector<std::shared_ptr<Transaction>>& Debits() const;
    [[nodiscard]] const std::vector<std::shared_ptr<Transaction>>& Credits() const;
};
