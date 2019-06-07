#include "pch.h"

struct interface {
	virtual ~interface() noexcept = default;
	virtual int get() const = 0;
};

class implementation : public interface {
public:
	int get() const override { return 42; }
};

struct example {
	example(std::shared_ptr<interface> i) {
		assert(42 == i->get());
	}
};

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 2);
  EXPECT_TRUE(true);
  EXPECT_TRUE(true);
  
  const auto injector = di::make_injector(
	  di::bind<interface>.to<implementation>()
  );

  injector.create<std::unique_ptr<example>>();
  
}
