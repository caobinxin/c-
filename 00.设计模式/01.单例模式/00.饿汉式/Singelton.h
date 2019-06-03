class Singelton
{
private:
    /* data */
    Singelton(/* args */);
    ~Singelton();

public:
    static Singelton *getInstance();
    static void freeInstance();

private:
    static Singelton *m_psl;
    
};