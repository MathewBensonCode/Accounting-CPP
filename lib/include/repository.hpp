#include "account.hpp"
#include "businessentity.hpp"
#include <vector>

template <typename entity> class Repository {

public:
  std::vector<entity> GetAll() const { return std::vector<entity>{}; }
};
