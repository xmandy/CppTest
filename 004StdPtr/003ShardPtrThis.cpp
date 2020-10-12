#include <iostream>
#include <memory>
#include <type_traits>

// This Example Shows:
// 从this获取shared_ptr，如果不使用自带的实现，
// 会导致shared_ptr引用计数不正确，释放错误。

class Bad
{
    public:
    std::shared_ptr<Bad> getptr() {
        return std::shared_ptr<Bad>(this);
    }

    ~Bad() {std::cout << "destructor called\n";}

};


struct Good : std::enable_shared_from_this<Good> // 注意：继承
{
public:
	std::shared_ptr<Good> getptr() {
		return shared_from_this();
	}
	~Good() { std::cout << "Good::~Good() called" << std::endl; }
};

int main(int argc, char const *argv[])
{
    std::shared_ptr<Bad> tmp = std::make_shared<Bad>();
    auto tmp1 = tmp->getptr();
    std::cout<< tmp.use_count() << "----" << tmp1.use_count() << "\n";
    return 0;
}
