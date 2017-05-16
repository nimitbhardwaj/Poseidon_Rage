#include <iostream>
#include <cstring>
#include <cctype>
#include <stdexcept>
#ifndef BIG_NUMBERS_
#define BIG_NUMBERS_
class BigNumber
{
    private:
        char *p;
        int len;
        bool sign;
        void normalize();
    public:
        BigNumber()
            :p(NULL), len(0){}
        BigNumber(const char *num);
        BigNumber(int n);
        ~BigNumber();
        BigNumber(const BigNumber&);
        BigNumber &operator=(const BigNumber&);
        BigNumber operator-(void) const ;
        BigNumber operator+(const BigNumber&) const;
        BigNumber operator-(const BigNumber&) const;
        bool operator<(const BigNumber&) const;
        bool operator>(const BigNumber&) const;
        bool operator>=(const BigNumber&) const;
        bool operator<=(const BigNumber&) const;
        bool operator==(const BigNumber&) const;
        bool operator!=(const BigNumber&) const;
        void operator+=(const BigNumber &);
        char &operator[](const int n){ return p[n]; }
        const char &operator[](const int n) const { return p[n]; }
        const int length() const { return len; }
        friend std::ostream &operator<<(std::ostream &dout, const BigNumber &big);
        friend std::istream &operator>>(std::istream &din, BigNumber &big);
};

inline bool BigNumber::operator>(const BigNumber &num) const
{
    return num.operator<(*this);
}

inline bool BigNumber::operator==(const BigNumber &num) const
{
    return !operator<(num) && !operator>(num);
}

inline bool BigNumber::operator>=(const BigNumber &num) const
{
    return operator>(num) || operator==(num);
}

inline bool BigNumber::operator<=(const BigNumber &num) const
{
    return operator<(num) || operator==(num);
}

inline bool BigNumber::operator!=(const BigNumber &num) const
{
    return !operator==(num);
}

#endif


BigNumber::BigNumber(const char *str)
{
    int k = 0;
    sign = false;
    if(str[k] == '-' || str[k] == '+')
        if(str[k] == '-')
            k = 1, sign = true;
        else
            k = 1, sign = false;
    len = strlen(str) - k;
    //std::cout << len << std::endl;
    p = new char[len + 10]();
    std::strcpy(p, str + k);
    for(int i = 0, j = len - 1; i < j; i++, j--)
    {
        if(!std::isdigit(p[i]) || !std::isdigit(p[j]))
            throw std::domain_error("Only the Pure numbers are allowed, the given input was not the number");
        char c;
        c = p[i];
        p[i] = p[j];
        p[j] = c;
    }
    normalize();
}

BigNumber::BigNumber(int n)
{
    len = n;
    sign = false;
    p = new char[len + 10]();
}

BigNumber::BigNumber(const BigNumber& num)
{
    len = num.len;
    sign = num.sign;
    p = new char[num.len + 10]();
    std::strcpy(p, num.p);
}

BigNumber::~BigNumber()
{
    delete [] p;
    len = 0;
    sign = false;
}

BigNumber &BigNumber::operator=(const BigNumber& num)
{
    delete [] p;
    len = num.len;
    sign = num.sign;
    p = new char[num.len + 10]();
    std::strcpy(p, num.p);
}

BigNumber BigNumber::operator-(void) const
{
    BigNumber num(*this);
    num.sign = !num.sign;
    return num;
}

BigNumber BigNumber::operator+(const BigNumber& num) const
{
    int mx = num.len > len ? num.len : len;
    int mn = num.len + len - mx;
    BigNumber ret(mx + 1);
    ret.len -= 1;
    int carry = 0, i;
    if(sign == true && num.sign == true)
        ret.sign = true;
    if(sign == false && num.sign == true)
        return operator-(-num);
    else if(sign == true && num.sign == false)
        return num.operator-(-(*this));
    for(i = 0; i < mn; i++)
    {
        int a = p[i] - '0' + num.p[i] - '0' + carry;
        carry = 0;
        if(a >= 10)
            carry = a / 10, a = a % 10;
        ret.p[i] = a + '0';
    }
    BigNumber *kapa;
    if(mx == num.len)
        kapa = const_cast<BigNumber *> (&num);
    else
        kapa = const_cast<BigNumber *> (this);
    for(; i < mx; i++)
    {
        int a = kapa->operator[](i) + carry - '0';
        if(a >= 10)
            carry = a / 10, a = a % 10;
        ret[i] = a + '0';
        ret.p[i] = kapa->operator[](i);
    }
    if(carry)
    {
        ret[i] = carry + '0';
        ret.len = ret.len + 1;
    }
    ret.normalize();
    return ret;
}

BigNumber BigNumber::operator-(const BigNumber& num) const
{
    if(sign == false && num.sign == true)
        return *this + (-num);
    if(sign == true && num.sign == false)
        return *this + (-num);
    BigNumber a, b, ret;
    if(*this == num)
        return BigNumber("0");
    else if(*this > num)
    {
        a = *this;
        b = num;
        ret = BigNumber(len);
        ret.sign = false;
    }
    else
    {
        a = num;
        b = *this;
        ret = BigNumber(a.len);
        ret.sign = true;
    }
    int borrow = 0, i;
    for(i = 0; i < b.len; i++)
    {
        int k = a[i] - b[i] - borrow;
        borrow = 0;
        if(k < 0)
            k = k + 10, borrow = 1;
        ret[i] = k + '0';
    }
    while(borrow)
    {
        int k = a[i] - borrow - '0';
        borrow = 0;
        if(k < 0)
            k = k + 10, borrow = 1;
        ret[i] = k + '0';
        i++;
    }
    for(; i < a.len; i++)
        ret[i] = a[i];
    ret.normalize();
    return ret;
}

void BigNumber::operator+=(const BigNumber &num)
{
    int mx = num.len > len ? num.len : len;
    int mn = num.len + len - mx;
    int carry = 0, i;
    for(i = 0; i < mn; i++)
    {
        int a = p[i] - '0' + num.p[i] - '0' + carry;
        carry = 0;
        if(a >= 10)
            carry = a / 10, a = a % 10;
        p[i] = a + '0';
    }
    char *kapa;
    if(mx == num.len)
        kapa = num.p;
    else
        kapa = p;
    while(carry)
    {
        //std::cout << "Hello";
        int a = kapa[i] + carry - '0';
        if(a >= 10)
            carry = a / 10, a = a % 10;
        p[i] = a + '0';
        i++;
    }
    for(; i < mx; i++)
    {
        int a = kapa[i] + carry - '0';
        if(a >= 10)
            carry = a / 10, a = a % 10;
        p[i] = a + '0';
    }
    if(carry)
    {
        p[i] = '1';
        len++;
    }
}

bool BigNumber::operator<(const BigNumber &num) const
{
    bool ret = true;
    if(sign == true && num.sign == true)
        ret = false;
    if(len < num.len)
        return ret;
    if(sign == true && num.sign == false)
        return true;
    if(sign == false && num.sign == true)
        return false;
    else if(len == num.len)
    {
        for(int i = len - 1; i >= 0; i--)
        {
            if(p[i] < num.p[i])
                return ret;
            else if(p[i] == num.p[i])
                continue;
            else
                return !ret;
        }
        return false;
    }
    else
        return !ret;
}


std::ostream &operator<<(std::ostream &dout, const BigNumber &big)
{
    if(big.sign == true)
        dout << '-';
    for(int i = big.len - 1; i >= 0; i--)
        dout << big.p[i];
    return dout;
}

std::istream &operator>>(std::istream &din, BigNumber &big)
{
    char tmpArr[100000] = {0};
    din >> tmpArr;
    delete[] big.p;
    big.sign = false;
    int ck = 0;
    if(tmpArr[0] == '-')
        big.sign = true;
    if(tmpArr[0] == '+' || tmpArr[0] == '-')
        ck = 1;
    big.len = std::strlen(tmpArr) - ck;
    big.p = new char[big.len + 10]();
    int j, i;
    for(i = big.len - 1, j = 0; i >= ck; i--, j++)
    {
        big.p[j] = tmpArr[i];
    }
    return din;
}


//Private Methods

void BigNumber::normalize(void)
{
    int i, fl = 0;
    for(i = len - 1; i >= 0; i--)
    {
        if(p[i] == '0')
        {
            fl += 1;
            continue;
        }
        else
            break;
    }
    if(fl == len)
        p[0] = '0', p[1] = 0, len = 1;
    else 
        p[i + 1] = 0, len -= fl;
    if(p[0] == '0' && len == 1)
        sign = false;
}

int main()
{
    BigNumber num;
    while(std::cin >> num)
    {
        if(num == "0" || num == "1")
        {
            std::cout << 1 << std::endl;
            continue;
        }
        num = num + num - "2";
        std::cout << num << std::endl;
    }
    return 0;
}
