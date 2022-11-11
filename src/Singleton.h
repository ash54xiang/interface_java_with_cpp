template <typename T>

class Singleton
{
public:
    static T &instance()
    {
        static T inst;
        return inst;
    };
    virtual bool init(void) { return true; };

    Singleton(Singleton const &) = delete;            // Copy construct
    Singleton(Singleton &&) = delete;                 // Move construct
    Singleton &operator=(Singleton const &) = delete; // Copy assign
    Singleton &operator=(Singleton &&) = delete;      // Move assign

protected:
    Singleton(){};
    ~Singleton(){};
};