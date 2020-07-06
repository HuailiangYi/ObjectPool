class NonCopyable
{
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;
    NonCopyable(const NonCopyable &) = delete;
    //禁用赋值构造
    NonCopyable &operator=(const NonCopyable &) = delete;
};
